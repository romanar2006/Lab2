#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_checkButton_clicked();

    void on_checkButton_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    bool checkDateFormat(const QString& dateStr);
};

#endif // MAINWINDOW_H
