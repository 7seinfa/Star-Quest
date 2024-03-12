#include "headers/mainwindow.h"
#include <QApplication>
 
int main(int argc, char *argv[]) 
{
  QApplication app(argc, argv);
  MainWindow* mainMenu = new MainWindow(); // create an instance of the class Game, using the pointer declared previously
  mainMenu->show(); // display the contents of the class Game on the screen
  mainMenu->displayMainMenu();
  return app.exec();
}