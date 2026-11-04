//Authors: Ari Chai, Axl Burtleson, Evalynn 
//currently includes file i/o stuff, check if guess is valid, and score guess

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

class SpellingBee {
private:
    const char centerLetter;
    const char letters[7];
    int score;
    string validWords[100];
    string guessedWords[100];
public:
    SpellingBee(char cent, char c1, char c2, char c3, char c4, char c5, char c6, char c7) : centerLetter(cent), letters{c1, c2, c3, c4, c5, c6, c7} { score = 0; }
    ~SpellingBee() { cout<<"Game over."<<endl; }
    void checkGuess(string guess);
    void scoreGuess(string guess);
};

void SpellingBee::checkGuess (string guess) {
    if((guess == "quit") || (guess == "q")) {
        //endGame();
        return;
    }
    int len = guess.length();
    int validLen = sizeof(validWords) / sizeof(validWords[0]);
    int guessedLen = sizeof(guessedWords) / sizeof(guessedWords[0]);
    if(len < 4) {
        cout<<"Guess must be at least 4 letters!"<<endl;
        return;
    }
    bool center = false;
    for(int i = 0; i < len; i++) {
        if(guess[i] == centerLetter) {
            center = true;
        }
    }
    if(center == false) {
        cout<<"Guess must contain center letter!"<<endl;
        return;
    }
    bool valid = false;
    for(int i = 0; i < validLen; i++) {
        if(guess == validWords[i]) {
            valid = true;
        }
    }
    if(valid == false) {
        cout<<"Guess not in dictionary!"<<endl;
        return;
    }
    bool guessed = false;
    for(int i = 0; i < guessedLen; i++) {
        if(guess == guessedWords[i]) {
            guessed = true;
        }
    }
    if(guessed == true) {
        cout<<"Word already guessed!"<<endl;
        return;
    } else {
        //append word to guessed list
    }
    scoreGuess(guess);
    //Call score guess and display game
}

void SpellingBee::scoreGuess(string guess) {
    char letters[7];
    int len = guess.length();
    int points = len - 3;
    bool pangram = true;
    bool found = false;
    for (int i; i < len; i++) {
        found = false;
        for(int j; j < 7; j++) {
            if(guess[i] == letters[j]) {
                found = true;
            }
        }
        if(found == false) {
            pangram = false;
        }
    }

    if(pangram == true) {
        points += 7; 
    }
    cout<<"+ "<<points<<" points!"<<endl;
    score += points; 
    cout<<"Score: "<<score<<endl;
}

int main() {
    //variable declarations
    int randomBee;
    string letters, temp;
    string validWords[100];
    int i=0, j=0, k=0; //iterators lol

    //randomizes the spelling bee (1-5 at the moment)
    srand(time(0));
    randomBee = rand() % (5) + 1;

    //opens file
    ifstream bee("examplespellingbee.txt");

    //reads in the spelling bee letters and valid words 
    //basically reading all of them in and emptying variables until it's the right one lol
    for (k=0; k<randomBee; k++) {
        for (i=0; i<100; i++) {     //resets
            validWords[i] = "";
        }
        i=0;

        getline(bee, letters);   //collects valid letters

        while (getline(bee, validWords[i])) {  //collects valid words
            if (validWords[i] == string("*")) {  //stops at "*"
                break;
            }
            i++;
        }
    }

    //closes file
    bee.close();

    //prints for sanity check
    cout<<"\n\nSpelling Bee: "<<randomBee<<endl;
    cout<<"Letters: "<<letters<<endl;
    cout<<"Valid Words: "<<endl;

    for (j=0; j<i; j++) {
        cout<<validWords[j]<<endl;
    }
}
