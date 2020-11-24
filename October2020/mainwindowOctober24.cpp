#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <Cryptpass.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::generates() //Функция генерации паролей- password-generation
                             // function
{ //готово-ready

  srand(time(NULL)); //Рандомайзер-randomazer

  QStatusBar *stat = new QStatusBar(this);
  stat->setGeometry(10, 60, 100, 170);

  QStatusBar *statB = new QStatusBar(this);
  statB->setGeometry(49, 60, 100, 170);

  int a = rand();
  QString s = QString::number(a); //Перевод в QString-translate in QString

  int b = rand();
  QString c = QString::number(b);

    stat->showMessage(s); // Так как эта функция принимает только QString, то
    stat->show();                     // переводим все в этот тип данных-translate in
    statB->showMessage(c);
    statB->show();                   // "String", because function can get only QString

}

//-------------------------------------------------------------------------------------------------------------------
void MainWindow::memory() { // Функция записывает пароли пользователя- function
  // write user passwords
// готово-ready

  QStatusBar *howmany = new QStatusBar(this);
  howmany->setGeometry(20, 20, 1000, 140);
  howmany->showMessage("Вводите пароли и название соцсети или аккаунта на английском. "
                       "Например: 1234567 VK.");
  howmany->show();

  QTextEdit *t = new QTextEdit(this);
  QTextEdit *p = new QTextEdit(this);
  t->setGeometry(40, 120, 100, 40);
  p->setGeometry(140, 120, 100, 40);
  t->show();
  p->show();

  QPushButton *savepass = new QPushButton(this);
  savepass->setText("Сохранить пароли");
  savepass->setGeometry(250, 200, 150, 50);
  connect(savepass, &QPushButton::clicked, this, [=](){
      save ("\n" + t->toPlainText ().toUtf8() + " " + p->toPlainText ().toUtf8 ()+ "\n");
  });
  savepass->show();

}
//--------------------------------------------------------------------------------------------------------------------

void MainWindow::save(const QString &s) {

  QFile file("pass.txt");
  file.open(QFile::WriteOnly| QFile::Append); //Открытие файла с паролями(или создание, если
                               //файла нет)-open file with passwords(if file
                               // dont be - create file)
  if (file.isOpen()) {

     (QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    file.write(s.toLatin1 ());
    file.close();

  }
  else {

    QStatusBar *notfound = new QStatusBar(this);
    notfound->setGeometry(60, 80, 1000, 140);
    notfound->showMessage("Ошибка, файл не найден. Перезапустите приложение. ");
    notfound->show();

  }
}

//---------------------------------------------------------------------------------------------------------------

void MainWindow::delites() { //готово-ready

  QFile filet("pass.txt");
  filet.open(QFile::WriteOnly);

  if (filet.isOpen()) { // Проверка открытия файла - check open-file

    for (int i = 0; i < 10;
         i++) { //Если открылся, то записываем пробелы, тем самым стирая данные
      //- if file is open, write null, null delite user-data
      filet.write("                                                            "
                  "                                 ");
    }
    filet.close();

    QStatusBar *delitefile = new QStatusBar(this); //
    delitefile->setGeometry(20, 20, 1000, 140);
    delitefile->showMessage("Пароли удалены успешно.");
    delitefile->show();

  }

  else if (!filet.exists()) {
    QStatusBar *Nodelitefile = new QStatusBar(this);
    Nodelitefile->setGeometry(20, 20, 1000, 140);
    Nodelitefile->showMessage(
        "Ошибка, не удалось удалить пароли. Файл с паролями еще не создан.");
    Nodelitefile->show();
  }
}
//------------------------------------------------------------------------------------------------------------------
void MainWindow::account() {

    QPushButton *readpass = new QPushButton("Посмотеть пароли");
    readpass->setGeometry(250, 200, 150, 50);
    connect(readpass, &QPushButton::clicked, this,&MainWindow::read);
    readpass->show();

  }

void MainWindow::read() {
  QFile file("pass.txt");
  file.open(QFile::ReadOnly);
  if(file.isOpen())
  {

   QString data =file.readAll();
   QStatusBar *readData  = new QStatusBar(this);
   readData->setGeometry(20, 20, 1000, 1400);
   readData->showMessage(data);
   readData->show();

   file.close();
  }

  else {
    QStatusBar *Nodelitefile = new QStatusBar(this);
    Nodelitefile->setGeometry(20, 20, 1000, 140);
    Nodelitefile->showMessage("Ошибка, не удалось найти пароли. Невозможно "
                              "найти соответствующий файл.");
    Nodelitefile->show();
  }
}
