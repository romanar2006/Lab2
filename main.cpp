//Архипов Роман, группа 6, проверка даты на корректность, вывод сколько осталось/прошло и занесение в таблицу

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
