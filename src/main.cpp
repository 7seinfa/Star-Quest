/**
 * @file main.cpp
 * @brief Entry point for the game application.
 *
 * Initializes the application and displays the main menu. This is where the game loop starts, and the main window of the game is shown to the player.
 * The main function is responsible for setting up the QApplication, creating an instance of MainWindow (the main menu), and entering the application execution loop.
 *
 * @author [Your Name or Team Name]
 * @date [Current Date or Version Date]
 */

#include "headers/mainwindow.h"
#include <QApplication>

/**
 * @brief The main function, entry point of the application.
 *
 * Initializes the QApplication object with command-line arguments, creates the main window of the application, displays it, and starts the event loop.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return Returns the exit status of the application.
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow* mainMenu = new MainWindow(); // create an instance of the class Game, using the pointer declared previously
    mainMenu->show(); // display the contents of the class Game on the screen
    mainMenu->displayMainMenu();
    return app.exec();
}
