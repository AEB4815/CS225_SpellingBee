#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <sstream>
#include <stdexcept>
#include <cctype>

class SpellingBee {
private:
    const char centerLetter;
    char letters[7];
    int score;
    int validWordCount;
    int guessedWordCount;
    string validWords[100];
    string guessedWords[100];
    bool gameOver;
public:
    SpellingBee(char center, char letter1, char letter2,
                char letter3, char letter4, char letter5,
                char letter6);
    ~SpellingBee();
    void showRules() const;
    void displayGame();
    void checkGuess(string guess);
    void scoreGuess(string guess);
    void endGame() const;
    void setValidWords(string words[], int count);
    SpellingBee& operator+=(int points);
    friend ostream& operator<<(ostream& output, const SpellingBee& game);
};
