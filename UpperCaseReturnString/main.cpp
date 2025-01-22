#include <iostream>
#include <cwchar> //Library for changing the font type and size in the output console
#include <windows.h> //Library for using Windows System Colours and Font Size Of Terminal screen
#include <cctype> //Required for tolower and toupper() methods

//This function will create a flashing effect and upper case a string entered in to
//the console.

using namespace std;

//Function Prototype for returning a string entered using pass by reference &str

    string ReturnString(string &str);
 
    //Return String Function
    string ReturnString(string &str) {
    system("COLOR 2");   
    cout << "Please enter your name: ";
    //Ignore the spaces in the user input usign getline()
    getline(cin, str);
    
    
    //We have to format the position of the text outside of the following for loop 
    //for converting the strign to upper case as the final output is characters
    //converted to upeprcase and if we mix spaces as a string the output becomes
    //garbled as we are tring to mix data types, so we will format the allignment
    //below
    cout << "\n\n\n\n\n\n";
    cout << "                                              "; 
    //return the value of str
    str = "Your name is:- " + str;
    return str;  
         
    } 

int main() {
        //Maximize the terminal window requires the windows.h library
        keybd_event(VK_MENU,0x38,0,0);
        keybd_event(VK_RETURN,0x1c,0,0);
        keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
   
        keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
    
        //Change The Font Type and Size In the Console
        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(cfi);
        cfi.nFont = 0;
        cfi.dwFontSize.X = 0;                   // Width of each character in the font
        cfi.dwFontSize.Y = 22;                  // Height
        cfi.FontFamily = FF_DONTCARE;
        cfi.FontWeight = FW_BOLD;
        std::wcscpy(cfi.FaceName, L"ComicSans"); // Choose your font
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	
    //We have to define the variable we are going to use for the function to
    //pass as a parameter then when the function runs it will make a copy
    //of the value returned from the function in to this variable
    //so that the value is returned from the function back to the main
    //program, the funciton has to be declared before main if you want to run
    //more than one function in main
    string str{};
    
    system("CLS");
    ReturnString(str);
    
    system("CLS");
    cout << "\n\n\n\n\n\n\n\n";
    cout << "                             "<< str << endl;
    system("PAUSE");
    return 0;
}

