//Author: Ari Chai
//testing file i/o stuff

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

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
