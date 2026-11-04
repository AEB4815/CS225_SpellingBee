#include <iostream>
#include <string>

using namespace std;

void checkGuess (string guess, string* validWords, int validLen, string* guessedWords, int guessedLen, char centerLetter) {
    if((guess == "quit") || (guess == "q")) {
        //endGame();
        return;
    }
    int len = guess.length();
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
    //Call score guess and display game
}

void scoreGuess(string guess) {
    //need an array of all the letters
    char letters[7]; //idk how this gon work
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
    //score += points; //tie ts to the class
    //cout<<"Score: "<<score<<endl;
}

int main () {

    return 0;
}
