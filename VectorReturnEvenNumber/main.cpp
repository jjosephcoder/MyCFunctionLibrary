#include <iostream>
#include <windows.h> //Library for using Windows System Colours and Font Size Of Terminal screen
#include <cwchar> //Library for changing the font type and size in the output console
#include <vector>

//This function will create a flashing effect and upper case a string entered in to
//the console.

using namespace std;

//Function Prototype for returning a vector of integers entered using pass by reference &str
    void printV(vector<int> &vec);
    void windowfont(); 
    //Return String Function
    void printV(vector<int> &vec) {
       //Display original vector
        cout << "Original Vector looks like this:- ";
            for (unsigned i = 0; i<vec.size(); i++) {
                cout << vec[i]; 
        }
         cout << endl;
    
    //Display only the even numbers of the vector
    cout << "The Even Numbers Of Your Vector Are:-";
     
            for (unsigned i = 0; i<vec.size(); i++) {
                if(vec[i]%2==0)
                    cout <<vec[i];
        }
        
        cout << endl;
         
    } 
        
    void windowfont(){
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
	
    }
        
   

int main() {
        
    windowfont();
    vector <int> vec={1,2,3,4,5,6,7,8,9,10};   

    printV(vec);
  
    system("PAUSE");
    return 0;
}

