#include <iostream>
#include <cwchar> //Library for changing the font type and size in the output console
#include <windows.h> //Library for using Windows System Colours and Font Size Of Terminal screen
#include <cctype> //Required for tolower and toupper() methods

//This function will create a flashing effect and upper case a string entered in to
//the console.

using namespace std;

//Function Prototype
void flash(string name);

//////////////////////
//Flash Function///// 
////////////////////
void flash(string name){
    string surname{};
    cout << "Please enter a surname: ";
    cin >> surname;
    
    //Flash Effect
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   
    int counter = 5;
    for(int i=1; i<=counter; i++){
        for(int k = 1; k < 10; k++)
        {
        // pick the colorattribute k you want
        SetConsoleTextAttribute(hConsole, k);
        cout << "\n\n\n\n\n\n";
        
        string output = "                                         My name is " + name + surname;
        
        //Convert a string to upper case characters using a for loop
        char upperoutput;
        for (unsigned i = 0; i<= output.size(); i++) {

        // convert output[i] to uppercase and assign to upperoutput variable
        upperoutput = toupper(output[i]);
        
        //output upperoutput 
        cout << upperoutput;
        }
               
        Sleep(2);
        system("CLS");
        }
    }
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
	
    flash("Jonathan ");
    
    return 0;



         
         
} 