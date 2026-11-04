//Authors: Ari Chai, Axl Burtleson, Evalynn 
//currently includes file i/o stuff, check if guess is valid, and score guess

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
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
