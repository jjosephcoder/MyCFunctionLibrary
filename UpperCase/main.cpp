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
void UpperCase(string &uppercasestr);
void setupWindowSize();
void fontSize22(); //Standard Font Size for all my applications
void fontSize100();
void flash();

////////////////////Functions/////////////////////
//UpperCase Function 
    void UpperCase(string &uppercasestr){
    system("COLOR 2");   
    string userinput{};
    //string uppercasestr{};
    cout << "Please enter a string to upper case: ";
    //Ignore the spaces in the user input usign getline()
    getline(cin, userinput);
    
    
    //We have to format the position of the text outside of the following for loop 
    //for converting the strign to upper case as the final output is characters
    //converted to upeprcase and if we mix spaces as a string the output becomes
    //garbled as we are tring to mix data types, so we will format the allignment
    //below
    cout << "\n\n\n\n\n\n";
    cout << "                                              "; 
    
        //Convert a string to upper case characters using a for loop
        char character;
        for (unsigned i = 0; i<= userinput.size(); i++) {

        // convert output[i] to uppercase and assign to upperoutput variable
        character = toupper(userinput[i]);
          
        //Below code was used to debug and test characters being processed by
        //the for loop
        //cout << character;
        
        //For each iteration of the for loop assign the value of the current 
        //character to the uppercasestr variable
        
        uppercasestr+=character;
        
        }
        
        cout << endl;       
        //Sleep(2);
        //system("PAUSE");         
} 

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

//////////////////////////////////
//FONT SIZE 50 FUNCTION//////////
////////////////////////////////
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

//////////////////////
//Flash Function///// 
////////////////////
void flash(){
  
    int counter = 20;
    for(int i=1; i<=counter; i++){
    system("COLOR 2");
    Sleep(30);
    system("COLOR 3");
    Sleep(30);
    system("COLOR 4");
    }
}

int main() {
    
    setupWindowSize();
    fontSize22();
	
    //We declare a pass by refeence string variable for the funciton to use and 
    //to return a value to as the parameter
    string uppercasestr{};
    cout << "This is the first UpperCase function call" << endl;
    UpperCase(uppercasestr);
    cout << "This is your returned upper case string: " << uppercasestr << endl<< endl;
    
    //Define a variable to build a string containing the two strings input
    //and concerted to Upper Case
    string result = string{};
    //Assign the value from the first UpperCase funciton call to result variable
    result =uppercasestr;
    
    cout << "This is the second UpperCase function call" << endl;
    //We have to reset the uppercasestr string variable to zero, as the second
    //function call appends to the previous varaible value
    //Escluding this could be useful for building a string from multiple
    //function calls
    uppercasestr={};
    UpperCase(uppercasestr);
    
    //Concatenate the second function call value with a seperating space to the
    //result variable
    result += " " + uppercasestr;
    cout << "This is your second returned upper case string: " << uppercasestr << endl;
    cout << "\n\n\n\n\n";
     
    
    system("CLS"); 
    cout << "Both of the lower case strings you entered in upper case:-" <<endl;
    Sleep(3000);
    system("CLS");    
    cout << "\n\n\n";
    fontSize50(); 
        
    cout << "    " + result << endl;
    
    //Flash function to make the final output text flash different colours
    flash();
   
    
    return 0;
}

