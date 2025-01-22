#include <algorithm>        
#include <iostream>         
#include <iterator>         // (istream_iterator, back_inserter)
#include <sstream>          // (istringstream)
#include <string>           // (string)
#include <vector>       
#include <windows.h> //Library for using Windows System Colours and Font Size Of Terminal screen
#include <cwchar> //Library for changing the font type and size in the output console    


///////Function Prototypes//////
void windowfont();


///windowfont fucntion declaration/////
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



using namespace std;

    int main() {
        
        system("COLOR 2");
        windowfont();
        //Prompt and get the user to enter a sentence and store in user_input
        cout << "Please enter your sentence:-"; 
        string user_input;
        getline( cin, user_input );
        
        //Create a vector to store the words in to from user_input later
        vector<string> words;
        cout << endl;
        
        //Prompt the user to enter a word to seach for in the vector
        string search{};
        cout << "Please enter your search word:-";
        cin >> search;
        
        //Use the istringstream method to take the imput from the user_input
        //variable which is a string and then copy each word in to a seperate
        //element of the words vector
     
        istringstream input_as_stream( user_input );
            copy(
                istream_iterator<string>( input_as_stream ),
                istream_iterator<string>(),
                back_inserter( words )
                );
 
        //Search vector for the seach word entered by the user
        for(size_t i =0; i<=words.size(); i++){
            //If the value of the words vector at the current element
            //equals the value in the seach variable(Search word)
            //output the cout statement with the value of that element
            //of the vector
            if(words[i]==search){
                cout << "Found your search word:-" << words[i] << endl;
        }
    }

    system("PAUSE");
    return 0;
}