/**
 * @file MainWindow.cpp
 * @brief Main window setup and main menu display for the game.
 *
 * This file contains the implementation of the MainWindow class, responsible for setting up the main window of the game and displaying the main menu. It includes functionality to start the game or exit the application through user interaction with the main menu.
 *
 * @author Laila El Attar
 * @date March 01, 2024
 */

#include "headers/mainwindow.h"
#include "headers/Game.h"

/**
 * @brief Constructor for MainWindow class.
 *
 *constructor is used to set up the window of the main menu *
 *
 * @param parent pointer for the parent QWidget for the Game instance
 * @return none
 */
MainWindow::MainWindow(QWidget *parent) {

    // set up the screen by adjusting horizontal and vertical scrolling, and setting a fixed size to the window.
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(600,750);

    // set up the scene by creating a new scene and setting it's size and coordinates
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768); // x-coordinate: 0, y-coordinate: 0, width: 1024, height: 768
    setScene(scene);
};

/**
 * @brief Displays the main menu with buttons for game control.
 *
 * Creates and displays buttons like 'Play' and 'Quit' on the main menu, and connects them to their respective slots for handling user actions.
 * @param none
 * @return none, displays buttons on screen
 */
void MainWindow::displayMainMenu(){

    QFont font;
    font.setPointSize(20); // font size of text on screen

    // create the title text "Star Quest"
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Star Quest"));
    titleText->setFont(font);
    scene->addItem(titleText); // add the title to the scene

    // set the position of the title within the scene
    titleText->setPos(455, 200); // x-coordinate: 445, y-coordinate: 290

    // create the play button, make "this" the parent
    playButton = new QPushButton("Play", this);

    // set size and location of the play button
    playButton->setGeometry(QRect(QPoint(200, 250), QSize(200, 50))); // x-coordinate: 320, y-coordinate: 250, width: 200, height: 50

    // display the play button and connect button signal to function that handles play button operations
    playButton->show();
    connect(playButton, &QPushButton::released, this, &MainWindow::handlePlayButton);

    // create the quit button, make "this" the parent
    quitButton = new QPushButton("Quit", this);

    // set size and location of the quit button
    quitButton->setGeometry(QRect(QPoint(200, 300), QSize(200, 50))); // x-coordinate: 320, y-coordinate: 300, width: 200, height: 50

    // display the quit button and connect button signal to function that handles quit button operations
    quitButton->show();
    connect(quitButton, &QPushButton::released, this, &MainWindow::handleQuitButton);


}

/**
 * @brief Handles the 'Play' button click event.
 *
 * begins game by creating an instance of MainWindow class and deleting the current instance of Game (main menu)
 * @param none
 * @return none, displays main menu
 */
void MainWindow::handlePlayButton()
{
    // close the main menu window and delete instance to avoid memory leak
    close();
    connect(this, &MainWindow::destroyed, this, &QObject::deleteLater);

    // create new instance of the game and display it
    Game* game = new Game();
    game->showMaximized();

    // delete instance of the game to avoid  memory leak
}

/**
 * @brief Handles the 'Quit' button click event.
 *
 * quits game by closing current window and deleting the current instance of main menu
 *
 * @param none
 * @return none
 */
void MainWindow::handleQuitButton()
{
    // close the main menu window and delete instance to avoid memory leak
    close();
    connect(this, &MainWindow::destroyed, this, &QObject::deleteLater);
}

