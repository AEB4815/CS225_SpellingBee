//Authors: Ari Chai, Axl Burtleson, Evalynn Hartunian

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include "SpellingBeeHeader.h"

using namespace std;

SpellingBee::SpellingBee(char center, char letter1, char letter2, char letter3, char letter4, char letter5, char letter6) : centerLetter(center), score(0), validWordCount(0), guessedWordCount(0), gameOver(false) {
    letters[0] = letter1;
    letters[1] = letter2;
    letters[2] = letter3;
    letters[3] = letter4;
    letters[4] = letter5;
    letters[5] = letter6;
    letters[6] = center;
}

SpellingBee::~SpellingBee() {
}

void SpellingBee::showRules() const {
    cout << "\n=====================================\n";
    cout << "        WELCOME TO SPELLING BEE\n";
    cout << "=====================================\n\n";
    cout << "How to play:\n";
    cout << "1. Create words using the seven displayed letters.\n";
    cout << "2. Every word must contain the center letter.\n";
    cout << "3. Words must contain at least four letters.\n";
    cout << "4. Letters may be used more than once.\n";
    cout << "5. You earn one point for every letter above three.\n";
    cout << "6. Pangrams use all seven letters and earn seven bonus points.\n";
    cout << "7. Type \"end\" or \"quit\" to finish the game.\n\n";
    cout << "Press Enter to begin...";

    string pause; //keeps window open until a key is pressed
    getline(cin, pause);
}

ostream& operator<<(ostream& output, const SpellingBee& game) {
    const string yellow = "\033[1;33m";
    const string reset = "\033[0m";
    output << "\n\n";
    output << "        [" << game.letters[0] << "]\n";
    output << "    [" << game.letters[1] << "]     ["
           << game.letters[2] << "]\n";
    output << "        "
           << yellow << "[" << game.centerLetter << "]"
           << reset << "\n";
    output << "    [" << game.letters[3] << "]     ["
           << game.letters[4] << "]\n";
    output << "        [" << game.letters[5] << "]\n\n";

    output << "Current score: " << game.score << "\n";

    return output;
}

void SpellingBee::setValidWords(string words[], int count) {
    if (count < 0 || count > 100) {
        throw invalid_argument("Invalid number of valid words");
    }
    validWordCount = count;
    for (int i = 0; i < validWordCount; i++) {
        validWords[i] = words[i];
    }
}

void SpellingBee::displayGame() {
    string guess;
    while (!gameOver) {
        cout << *this;
        cout << "\nEnter a word, or type \"end\" to finish: ";
        getline(cin, guess);
        checkGuess(guess);
    }
}

void SpellingBee::checkGuess (string guess) {
    // converts guess to lowercase
    for (int i = 0; i < guess.length(); i++) {
        guess[i] = static_cast<char>(
            tolower(static_cast<unsigned char>(guess[i]))
        );
    }
    // lets player end the game
    if(guess == "end" || guess == "quit" || guess == "q") {
        gameOver = true;
        endGame();
        return;
    }

    if (guess.length() < 4) {
        cout<<"Guess must be at least 4 letters!"<<endl;
    return;
    }

    char lowercaseCenter = static_cast<char>(
        tolower(static_cast<unsigned char>(centerLetter))
    );

    bool containsCenter = false;

    for (int i = 0; i < guess.length(); i++) {
        if (guess[i] == lowercaseCenter) {
            containsCenter = true;
            break;
        }
    }

    if (!containsCenter) {
        cout << "Guess must contain center letter!" << endl;
        return;
    }

    // checks if word is in word bank
    bool isValidWord = false;

    for (int i = 0; i < validWordCount; i++) {
        if (guess == validWords[i]) {
            isValidWord = true;
            break;
        }
    }

    if (!isValidWord) {
        cout << "Guess not in dictionary!" << endl;
        return;
    }

    // checks if word was already guessed

    for (int i = 0; i < guessedWordCount; i++) {
        if (guess == guessedWords[i]) {
            cout << "Word already guessed!" << endl;
            return;
        }
    }

    // stores guess
    guessedWords[guessedWordCount] = guess;
    guessedWordCount++;
    scoreGuess(guess);

    // ends game if every word was found
    if (guessedWordCount == validWordCount) {
        cout << "\nYou found every word!\n";
        gameOver = true;
        endGame();
    }
}

void SpellingBee::scoreGuess(string guess) {
    int points = guess.length() - 3;
    bool isPangram = true;

    for (int i = 0; i < 7; i++) {
        bool letterFound = false;

        char lowercaseLetter = static_cast<char>(
            tolower(static_cast<unsigned char>(letters[i]))
        );
    
        for(int j = 0; j < guess.length(); j++) {
            if(guess[j] == lowercaseLetter) {
                letterFound = true;
                break;
            }
        }

        if(!letterFound) {
            isPangram = false;
            break;
        }
    }

    if(isPangram) {
        points += 7; 
        cout << "Pangram! You earned 7 points!\n";
    }
    cout << "+" << points << " points!" << endl;
    *this += points; 
    cout << "Total score: " << score << "\n";
}

// adds points to score
SpellingBee& SpellingBee::operator+=(int points) {
    score += points;
    return *this;
}

// displays end game info
void SpellingBee::endGame() const {
    cout << "\n=====================================\n";
    cout << "              GAME OVER\n";
    cout << "=====================================\n";
    cout << "Final score: " << score << "\n";
    cout << "Words found: " << guessedWordCount << "/" << validWordCount << "\n\n";
    cout << "All valid words:\n";

    for (int i = 0; i < validWordCount; i++) {
        cout << "- " << validWords[i] << "\n";
    }

    cout << "\nThank you for playing!\n";
}

SpellingBee generateSpellingBee(int &wordCount) {
    int randomBee;
    string validWords[100];
    string letters, garbage;
    int i=0, j=0, k=0;

    //randomizes the spelling bee (1-5 at the moment)
    srand(time(0));
    randomBee = rand() % (5) + 1;

    try {
        //opens file
        ifstream bee("GameList.txt");
        if (!bee) {
            throw runtime_error("GameList.txt");
        }

        //reads in the spelling bee letters and valid words 
        //basically reading all of them into "garbage" until it's the right one lol
        for (k = 0; k < randomBee; k++) {
            i = 0;
            if (k == (randomBee-1)) {              //if correct pre-set spelling bee
                if (!getline(bee, letters)) {
                    throw runtime_error("Could not read game letters");
                }

                while (getline(bee, validWords[i])) {
                    if (validWords[i] == string("*")) {
                        validWords[i] = string("");   //nuke "*" character
                        break;                        //stops after asterisk
                    }
                    i++;
                }
            }

            else {                           //if not correct pre-set spelling bee
                if (!getline(bee, letters)) {
                    throw runtime_error("Could not read game letters");
                }
                while (getline(bee, garbage)) {
                    if (garbage == string("*")) {
                        break;
                    }
                    i++;
                }
            }
        }
        if (i >= 100) {
            throw runtime_error("a game contains more than 100 words");
        }

        //closes file
        bee.close();
    }
    catch (const exception& error) {
        cout << "error: " << error.what() << endl;
    }

    wordCount = i;

    SpellingBee game(letters[0], letters[2], letters[4], letters[6], letters[8], letters[10], letters[12]);
    game.setValidWords(validWords, wordCount);
    return(game);
}

int main() {
    //variable declarations
    int wordCount = 0;

    SpellingBee game = generateSpellingBee(wordCount);
    game.showRules();
    game.displayGame();
}

