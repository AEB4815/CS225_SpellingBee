//Authors: Ari Chai, Axl Burtleson, Evalynn Hartunian

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

class Profile {
    public:
        string username;
        int score;
        int guessedWordCount;
};

class WordsAndLetters {
    public:
        //friend class SpellingBee;
        char centerLetter;
        char letters[7];
        string validWords[100];
        string guessedWords[100];
        int validWordCount;
};

class SpellingBee : public WordsAndLetters {
private:
    bool gameOver;
public:
    Profile player;
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
    //friend class WordsAndLetters;
};
