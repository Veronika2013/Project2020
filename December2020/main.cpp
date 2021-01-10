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
   QPixmap generic("generic");
  QAction *generate = new QAction(generic, "&Generate passwords",  this);
  generate->setShortcut(tr("CTRL+N"));

  QPixmap accoric("accoric");
  QAction *acc = new QAction(accoric, "&Passwords for account", this);
  acc->setShortcut(tr("ALT+C"));
  QPixmap delitec("delitec");
  QAction *deliteall = new QAction(delitec, "&Delete all passwords", this);
  QPixmap newic("newic");
  QAction *newp = new QAction(newic, "&New password", this);
  newp->setShortcut(tr("SHIFT+O"));

  QAction *aboutversion = new QAction("&Version 2.7");
  QAction *aboutdevelop = new QAction("&jprogram@bk.ru");

  QMenu *file;
  file = menuBar()->addMenu("&Passwords");
  file->addAction(generate);
  file->addSeparator();

  QMenu *memory;
  memory = menuBar()->addMenu("&Memory");
  memory->addAction(acc);
  memory->addSeparator();
  memory->addAction(deliteall);
  memory->addSeparator();
  memory->addAction(newp);

  QMenu *aboutdev;
  aboutdev = menuBar()->addMenu("&About app");
  aboutdev->addAction(aboutversion);
  aboutdev->addSeparator();
  aboutdev->addAction(aboutdevelop);


  connect(newp, &QAction::triggered, this, &MainWindow::memory);
  connect(generate, &QAction::triggered, this, &MainWindow::generates);
  connect(deliteall, &QAction::triggered, this, &MainWindow::delites);
  connect(acc, &QAction::triggered, this, &MainWindow::account);
}

int main(int argc, char *argv[]) {
    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("imageformats");
    paths.append("platforms");
    paths.append("sqldrivers");
    QCoreApplication::setLibraryPaths(paths);
  QApplication a(argc, argv);
  Skilet w;
  w.setWindowTitle("My passwords");
  w.setWindowIcon(QIcon("icon"));
  w.resize(700, 470);
  w.show();
  return a.exec();
}
