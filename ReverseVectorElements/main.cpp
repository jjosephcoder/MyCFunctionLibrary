#include <iostream>
#include <cwchar> //Library for changing the font type and size in the output console
#include <windows.h> //Library for using Windows System Colours and Font Size Of Terminal screen
#include <cctype> //Required for tolower and toupper() methods
#include <vector>
#include <algorithm> //Library with method for reversing the order of a vector

//This function will create a flashing effect and upper case a string entered in to
//the console.

using namespace std;

//Function Prototype for returning a string entered using pass by reference &str

    void printV(vector<char> &c);
    
    
 
    //Return String Function
   void printV(vector<char> &c) {
       //Display original vector
       cout << "Original Vector looks like this:- ";
            for (unsigned i = 0; i<c.size(); i++) {
                cout << c[i]; 
    }
    cout << endl;
       //Display vector in reverse order
       cout << "New Vector looks like this:- ";
            reverse(c.begin(), c.end());
            for (unsigned i = 0; i<c.size(); i++) {
                cout <<c[i];
    }
    cout << endl;
         
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
	

    //Enter a string value
   
    string str = "";
    cout<<"Enter the string:\n";
	
	getline(cin,str);

    //create a character array called arr with a legnth of the str variable +1
	char arr[str.length() + 1]; 

    //copy the elements of the str in to the array arr with this inline method
	strcpy(arr, str.c_str()); 
    
    //Useful inline function for iterating through a vector and outputing each
    //element
    //for (auto i : str) cout << i << " ";
    
    // Convert array to a vector
    int n = sizeof(arr); // sizeof(arr[0]);
    //create a new vector called c and assign the start and end positions
    vector<char> c(arr, arr + n);

    //for (auto i : c);
    
    //vector<char> c = {'J', 'O', 'N','N','Y'};
    printV(c);
    system("PAUSE");
    return 0;
}

