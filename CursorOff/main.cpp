#include <iostream>
#include <windows.h> //Library for using Windows System Colours
#include <mmsystem.h> //Library for accessing windows multimedia method

using namespace std;

//Function Prototype
void cursoroff();
void cursoron();

//////Function to turn off the blinking cursor in the terminal
void cursoroff(){
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}

//////Function to turn off the blinking cursor in the terminal
void cursoron(){
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}


int main() {
	
    string input={};
    cout << "Please Enter A String The Cursor Is Off" << endl;
    cursoroff();
    cin >> input;
    cout << "The string you entered is:-" << endl;
    cout << input << endl;
    
    //Turn the cursor back on
    input={};
    cin.clear();
    cout << "Please Enter A Second String The Cursor Is On" << endl;
    cursoron();
    cin >> input;
    cout << "The string you entered is:-" << endl;
    cout << input << endl;
    system("PAUSE");
	return 0;
}
