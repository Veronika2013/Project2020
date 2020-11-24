#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStatusBar>
#include <MyCrypt.h>
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::generates()
{
  srand(time(NULL)); //Randomizer

  QLabel *stat = new QLabel;
  stat->resize(700, 470);
  stat->setWindowTitle("Менеджер паролей");
  stat->setTextInteractionFlags(Qt::TextSelectableByMouse);

  int a = rand();
  QString s = QString::number(a); // Translate in QString

  char mass[10];
  for(int i = 0; i <10; i++)
  {
      mass[i] = rand()   %26+0x61;
  }

  int b = rand();
  QString c = QString::number(b);//Passwords

  QString numPass;// 1th password
  numPass = mass[1]+ s + mass[2] + s + mass[3] + mass[4] + mass[5];

  QString numpass2;//2th password
  numpass2 = mass[3]+ c + mass[4] + c + mass[5] + mass[6] + mass[7];

  QString numpass3;//3th password
  numpass3 = mass[5]+ c + mass[6] + s + mass[7] + mass[8] + mass[9];

  QString numpass4;//4th password
  numpass4 = mass[7]+ s + mass[2] + c + mass[0] + mass[4] + mass[1];

  QString numpass5;//5th passwords
  numpass5 = mass[9]+ c +  s +mass[9] + mass[6] + mass[0] + mass[8];

  QString numpass6;//6th password
  numpass6 = mass[7]+ c + mass[6]  + mass[5] + mass[4]  + s + mass[3];

  stat->setText(numPass + "\n" +numpass2 + "\n" + numpass3 + "\n" + numpass4 + "\n" + numpass5 + "\n" + numpass6 );
  //Insert passwords in QLabel
  stat->show();
}

void MainWindow::memory() {

  QStatusBar *howmany = new QStatusBar(this);
  howmany->setGeometry(20, 20, 1000, 140);
  howmany->showMessage("Вводите пароли и название соцсети или аккаунта на английском. "
                       "Например: 1234567 VK.");
  howmany->show();

  QTextEdit *t = new QTextEdit(this);//Input passwords in system
  QTextEdit *p = new QTextEdit(this);
  t->setGeometry(40, 120, 100, 40);
  p->setGeometry(140, 120, 100, 40);
  t->show();
  p->show();

  QPushButton *savepass = new QPushButton(this);
  savepass->setText("Сохранить пароли");
  savepass->setGeometry(250, 200, 150, 50);

  connect(savepass, &QPushButton::clicked, this, [=](){
      save (t->toPlainText ().toUtf8() + "   " + p->toPlainText ().toUtf8 ()+ "\n" ); //Saving and registration passwords in system
  });
  savepass->show();
}

void MainWindow::save(const QString &s) { //Slot for saving passwords

  QFile file("pass.txt");
  file.open(QFile::WriteOnly| QFile::Append);
  if (file.isOpen()) {

  (QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);

  file.write(s.toLatin1 ());
  file.close();
  }
  else {//If file not found
    QMessageBox *notfound = new QMessageBox(this);
    notfound->setGeometry(250, 200, 1000, 140);
    notfound->setText("Ошибка, файл не найден. Перезапустите приложение. ");
    notfound->setWindowTitle("Менеджер паролей");
    notfound->show();
  }
}

void MainWindow::delites() {

  QFile filet("pass.txt");
  filet.remove();//Delete file containing passwords
  if (!filet.exists()) {

    QMessageBox *delitefile = new QMessageBox(this);
    delitefile->setWindowTitle("Менеджер паролей");
    delitefile->setGeometry(800, 500, 100, 40);
    delitefile->setText("Пароли удалены успешно.");
    delitefile->show();

  }
  else if (!filet.remove() || !filet.exists()) {
    QMessageBox *Nodelitefile = new QMessageBox(this);
    Nodelitefile->setWindowTitle("Менеджер паролей");
    Nodelitefile->setGeometry(40, 120, 100, 40);
    Nodelitefile->setText(
        "Ошибка, не удалось удалить пароли.");
    Nodelitefile->show();
  }
}

void MainWindow::account() {//Function shoved passwords of file

    QFile file("pass.txt");
    file.open(QFile::ReadOnly);
    if(file.isOpen())
    {

     QString data = file.readAll();

     QLabel *lyrics = new QLabel(data);
     lyrics->setText("      " + data + "    ");
     lyrics->resize(700, 470);
     lyrics->setWindowTitle("Менеджер паролей");
     lyrics->setTextInteractionFlags(Qt::TextSelectableByMouse);
     lyrics->show();
     //I would like put protection on data, but I don't know how to do it yet
     file.close();
    }
    else {
        QMessageBox *Nodelitefile = new QMessageBox(this);
        Nodelitefile->setWindowTitle("Менеджер паролей");
        Nodelitefile->setGeometry(250, 200, 1000, 140);
        Nodelitefile->setText(
            "Файл с паролями удалён, прочесть данные невозможно.");
        Nodelitefile->show();
    }
  }
