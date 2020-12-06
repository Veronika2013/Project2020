#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QTextStream>
#include <QAction>
#include <QTextEdit>
#include <QFile>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent =0);
    ~MainWindow();

Ui::MainWindow *ui;

private slots:

public slots:
      void generates();
      void memory();
      void delites();
      void account();
      void save(const QString &s);


};


#endif // MAINWINDOW_H

