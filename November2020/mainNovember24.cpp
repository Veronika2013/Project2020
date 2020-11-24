#include "mainwindow.h"
#include <QAction>
#include <QApplication>
#include <QFile>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QSpinBox>
#include <QStatusBar>
#include <QTextEdit>
#include <QToolBar>
#include <QWidget>
#include <cstdlib>
#include <ctime>
#include <QHBoxLayout>
#include <QLabel>
#include <QShortcut>
class Skilet : public MainWindow // Skeleton for app
{

public:
  Skilet(QWidget *parent = 0);
};

Skilet::Skilet(QWidget *parent) : MainWindow(parent) {

  QAction *generate = new QAction("&Генерировать пароли",  this);

  QAction *acc = new QAction("&Пароли от раззных аккаунтов", this);
  QAction *deliteall = new QAction("&Удалить все пароли", this);
  QAction *newp = new QAction("&Новый пароль", this);

  QAction *aboutversion = new QAction("&Версия 2.7");
  QAction *aboutdevelop = new QAction("&jprogram@bk.ru");

  QAction *autosave = new QAction("&Автосохранение паролей", this);

  QMenu *file;
  file = menuBar()->addMenu("&Пароли");
  file->addAction(generate);
  file->addSeparator();

  QMenu *memory;
  memory = menuBar()->addMenu("&Память");
  memory->addAction(acc);
  memory->addSeparator();
  memory->addAction(deliteall);
  memory->addSeparator();
  memory->addAction(newp);

  QMenu *aboutdev;
  aboutdev = menuBar()->addMenu("О приложении");
  aboutdev->addAction(aboutversion);
  aboutdev->addSeparator();
  aboutdev->addAction(aboutdevelop);

  QMenu *settings;
  settings = menuBar()->addMenu("&Настройки");
  settings->addAction(autosave);

  connect(newp, &QAction::triggered, this, &MainWindow::memory);
  connect(generate, &QAction::triggered, this, &MainWindow::generates);
  connect(deliteall, &QAction::triggered, this, &MainWindow::delites);
  connect(acc, &QAction::triggered, this, &MainWindow::account);
}

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Skilet w;
  w.setWindowTitle("Менеджер паролей");
  w.setWindowIcon(QIcon("D:\\Qt images\\gradient"));
  w.resize(700, 470);
  w.show();
  return a.exec();
}
