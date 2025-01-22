#include <iostream>
#include <cwchar> //Library for changing the font type and size in the output console
#include <windows.h> //Library for using Windows System Colours and Font Size Of Terminal screen
#include <cctype> //Required for tolower and toupper() methods

//This function will take a string entered by the user and return an Upper Case 
//string to main. Take out the informational cout statements used for debugging
//if youn want to use this function to simply retrieve the upper case string
//there are two function calls in main that also concatenate the two strings
//entered, this would enable users to be prompted numerous times to enter
//strings that would be made upper case, the function calls could be encapsulated
//in to a while loop to control users enter a number of strings

using namespace std;

///////////////////Function ProtoTypes////////////
void flash();
void setupWindowSize();
void fontSize22();
void fontSize50();
void toUpper();
////////////////////////////
/////Setup Window Size/////
///////////////////////////

void setupWindowSize(){
     //Maximize the terminal window requires the windows.h library
        keybd_event(VK_MENU,0x38,0,0);
        keybd_event(VK_RETURN,0x1c,0,0);
        keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
   
        keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

////////////////////////////
//Font Size 50 function/////
///////////////////////////
void fontSize50(){

     //Change The Font Type and Size In the Console 
        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(cfi);
        cfi.nFont = 0;
        cfi.dwFontSize.X = 0;                   // Width of each character in the font
        cfi.dwFontSize.Y = 50;                  // Height
        cfi.FontFamily = FF_DONTCARE;
        cfi.FontWeight = FW_BOLD;
        std::wcscpy(cfi.FaceName, L"ComicSans"); // Choose your font
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi); 
}

////////////////////////////
//Font Size 22 function/////
///////////////////////////
void fontSize22(){

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

//////////////////////
//Flash Function///// 
////////////////////
void flash(){
  
    int counter = 15;
    for(int i=1; i<=counter; i++){
    system("COLOR 2");
    Sleep(30);
    system("COLOR 3");
    Sleep(30);
    system("COLOR 4");
    }
}

////////////////////////////
////UPPER CASE FUNCTION///// 
///////////////////////////
//https://en.cppreference.com/w/cpp/string/basic_string
//basic_string is a class type that treats the characters of a string as objects
//So below we iterate through each character of the input string reference
//variable &s, we set the p.begin and p.end values for so we can iterate
//through the entire string, then for each character which is the current
//iteration of p we apply the toupper method, so in essence we pass a 
//string to the function and then the basic_string class changes the data type
//to a char, upper cases each character and then return a string of upper case
//letters.
void toUpper(basic_string<char>& s) {
   for (basic_string<char>::iterator p = s.begin();
        p != s.end(); ++p) {
      *p = toupper(*p); // toupper is for char
   }
}
    


int main() {
        
        system("COLOR 2");
        //Function to set the terminal window to full screen
        setupWindowSize();
        
        //function to set the font size to 50
        fontSize50();     
        
        cout << "\n\n\n\n";
        
        string str{};
        cout << "Enter The String You Want To Flash:-" << endl;
        
        //getline method to overcome space deliminator issue with cin
        getline(cin, str);
        
        //function to convert input string to Upper Case
        toUpper(str);
        
        system("CLS");
        
        cout << "\n\n\n\n";
        
        cout << "              " << str;
     
        //Flash function
        flash();
      
        //Function to set the font size back to 22
        fontSize22();
       
        system("CLS");
        
        system("COLOR 2");
        
        cout << "\n\n\n\n\n";
        
        system("PAUSE");
    
    return 0;
}

