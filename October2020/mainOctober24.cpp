#include "mainwindow.h"
#include <QWidget>
#include <QApplication>
#include <QToolBar>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QIcon>
#include <QLabel>
#include <QMainWindow>
#include <QLineEdit>
#include  <QStatusBar>
#include <cstdlib>
#include <ctime>


class Skilet:public MainWindow // Скелет приложения
{

public:
   Skilet(QWidget *parent = 0);// "Активируем" класс

};

Skilet::Skilet(QWidget *parent)
    :MainWindow(parent) // Конструктор класса каркаса приложения
{


    QAction *generate = new QAction("&Генерировать пароли", this);
QAction *mem = new QAction("&Вспомнить пароль", this);
QAction *criter = new QAction("&Критерии генерации", this);

QAction *acc = new QAction("&Пароли от раззных аккаунтов", this);
QAction *deliteall = new QAction("&Удалить все пароли", this);
QAction *delite = new QAction("&Удалить выборочно", this);
QAction *newp = new QAction("&Новый пароль", this);

QAction *autosave = new QAction("&Автосохранение паролей", this);

      QMenu *file;
      file = menuBar()->addMenu("&Пароли"); // Добавляем меню
     file->addAction(generate);
     file->addAction(mem);
     file->addAction(criter);


      QMenu *memory;
      memory = menuBar()->addMenu("&Память"); // Добавляем меню
      memory->addAction(acc);
      memory->addAction(deliteall);
      memory->addAction(delite);
      memory->addAction(newp);



      QMenu *settings;
      settings = menuBar()->addMenu("&Настройки"); // Добавляем меню
settings->addAction(autosave);

connect(generate, &QAction::triggered, this, &MainWindow::generates);// Описываем свойства кнопки. Добавляем слоты и сигналы

}
void MainWindow::generates()
{
srand(time (NULL));

//QLineEdit::information(this, QObject::tr("Information"), "Show message menu clicked!");


    QStatusBar *stat = new QStatusBar(this);
   stat->setGeometry(10, 60, 100, 170);

   QStatusBar *statB = new QStatusBar(this);
  statB->setGeometry(49, 60, 100, 170);

int a = rand();
QString s = QString::number(a);

int b = rand();
QString c = QString::number(b);

   stat->showMessage(s);// Так как эта функция принимает только QString, то переводим все в этот тип данных
   stat->show();

   statB->showMessage(c);// Так как эта функция принимает только QString, то переводим все в этот тип данных
   statB->show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
Skilet w;
w.resize(500, 370);
w.show();
return a.exec();
}
