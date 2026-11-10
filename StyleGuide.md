CPSC 225 Spelling Bee Style Guide

Header Files:
Should include Class declarations
Include function prototypes
Header file should be able to compile on its own

Variable Names:
Use single word or camel case naming
Use intuitive names

Logic:
No infinite loops
No “magic numbers” (undefined variables that make the code work)

Format:
Use 4 spaces for indents
Indent every time a line is nested
Use extra new lines to separate segments of code
Put spaces between operators
	ex: cout << “Hi” << endl;
	ex: for(int i = 0; i < 10; i++) { }
No unnecessary line breaks in the middle of a statement
Comments should go above referenced code
	//for single line and /* */ for multi line
Brackets should begin on same line and end on their own line
	ex: for (...) {
	          cout << “whatever this needs to say” << endl;
	      }

Other
Use namespace std
Include authors at the beginning of header and main files
Use logical file names and capitalize first letter of every word
	ex: GameList.txt, SpellingBeeMain.cpp
Do not reuse same/similar file names for files of different types to avoid accidental overwriting
