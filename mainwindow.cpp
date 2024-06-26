#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <QMessageBox>
#include <regex>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "Connecting signal to slot";
    //connect(ui->checkButton, &QPushButton::clicked, this, &MainWindow::on_checkButton_clicked);

    // Set up the table widget
    ui->dateTableWidget->setColumnCount(2);
    QStringList headers;
    headers << "Дата" << "Разница";
    ui->dateTableWidget->setHorizontalHeaderLabels(headers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkDateFormat(const QString& dateStr) {
    std::regex pattern("((0[1-9]|1\\d|2[0-8])/(0[1-9]|1[0-2])/\\d{4})|"
                       "29/02/((\\d{2}(([02468][048])|([13579][26]))|\\d{2}00))|"
                       "(29|30)/(0[13-9]|1[0-2])/\\d{4}|"
                       "31/(0[13578]|1[02])/\\d{4}");
    return std::regex_match(dateStr.toStdString(), pattern);
}

void MainWindow::on_checkButton_clicked() {
    qDebug() << "Button clicked";

    QString input = ui->dateLineEdit->text();

    if (checkDateFormat(input)) {
        QDate date = QDate::fromString(input, "dd/MM/yyyy");
        if (!date.isValid()) {
            ui->resultLabel->setText("Введённая дата не соответствует формату.");
            qDebug() << "Slot exited: invalid date format";
            return;
        }

        QDate currentDate = QDate::currentDate();
        int daysDiff = currentDate.daysTo(date);

        if (daysDiff == 0) {
            ui->resultLabel->setText("Введённая дата - это сегодня.");
        } else if (daysDiff > 0) {
            ui->resultLabel->setText(QString("До введённой даты осталось %1 дней.").arg(daysDiff));
        } else {
            daysDiff = -daysDiff;
            ui->resultLabel->setText(QString("С введённой даты прошло %1 дней.").arg(daysDiff));
        }

        qDebug() << "Adding entry to table";

        // Add entry to the table
        int row = ui->dateTableWidget->rowCount();
        ui->dateTableWidget->insertRow(row);
        ui->dateTableWidget->setItem(row, 0, new QTableWidgetItem(input));
        ui->dateTableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(daysDiff)));
    } else {
        ui->resultLabel->setText("Введённая дата не соответствует формату.");
    }

    qDebug() << "Slot exited";
}

void MainWindow::on_checkButton_clicked(bool checked)
{
}

