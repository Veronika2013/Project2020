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
#include <QCommandLinkButton>
class Skilet : public MainWindow // Skeleton for app
{

public:
  Skilet(QWidget *parent = 0);
};


Skilet::Skilet(QWidget *parent) : MainWindow(parent) {

  QPixmap delitec("delitec");
  QAction *deliteall = new QAction(delitec, "&Delete all passwords", this);
  QPixmap newic("newic");
  QAction *newp = new QAction(newic, "&New password", this);
  newp->setShortcut(tr("CTRL+N"));

  QAction *aboutversion = new QAction("&Version 2.8");
  QAction *aboutdevelop = new QAction("&jprogram@bk.ru");

  QMenu *memory;
  memory = menuBar()->addMenu("&Passwords");
  memory->addAction(deliteall);
  memory->addSeparator();
  memory->addAction(newp);

  QMenu *aboutdev;
  aboutdev = menuBar()->addMenu("&About");
  aboutdev->addAction(aboutversion);
  aboutdev->addSeparator();
  aboutdev->addAction(aboutdevelop);

  QCommandLinkButton *pushHello = new QCommandLinkButton(this);
  pushHello->setText("Generate passwords");
  pushHello->setGeometry(0, 50, 300, 50);
  pushHello->show();

  QCommandLinkButton *foracc = new QCommandLinkButton(this);
  foracc->setText("Your passwords");
  foracc->setGeometry(0, 200, 300, 50);
  foracc->show();


  connect(newp, &QAction::triggered, this, &MainWindow::memory);
  connect(pushHello, &QPushButton::clicked, this, &MainWindow::generates);
  connect(deliteall, &QAction::triggered, this, &MainWindow::delites);
  connect(foracc, &QPushButton::clicked, this, &MainWindow::account);

}

int main(int argc, char *argv[]) {
    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("imageformats");
    paths.append("platforms");
    paths.append("logs");
    QCoreApplication::setLibraryPaths(paths);

  QApplication a(argc, argv);

  Skilet w;
  w.setWindowTitle("My passwords");
  w.setWindowIcon(QIcon("icon"));
  w.resize(700, 470);
  w.show();
  return a.exec();
}
