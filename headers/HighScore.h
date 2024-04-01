/** header that tracks the player's score and highscore
 *
 * @author Theo Mulder
 * Last edit: 1 April, 2024
 */

#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <QLCDNumber>

class HighScore : public QLCDNumber
{
    Q_OBJECT
private:
    int score;
    int highScore;
public:
    HighScore(QWidget *parent = nullptr);
    int getScore();
    int getHighScore();
    void updateScore(int points);
    bool checkNewHighScore();
    void resetScore();
};

#endif // HIGHSCORE_H

