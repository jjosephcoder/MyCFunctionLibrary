#include <iostream>
#include <windows.h> //Library needed for Sleep method
#include <mmsystem.h> //Library for accessing windows multimedia method
#pragma comment(lib, "winmm.lib"); //USE PRAGMA TO ACCESS THE WINDOWS MEDIA LIBRARIES FOR PLAYSOUND


using namespace std;
///Function Prototypes
void setupWindowSize();
void fontsize50();
void flashcursor(string &output);
void cursoroff();

void setupWindowSize(){
     //Maximize the terminal window requires the windows.h library
        keybd_event(VK_MENU,0x38,0,0);
        keybd_event(VK_RETURN,0x1c,0,0);
        keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
   
        keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void fontsize50(){

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

void flashcursor(string &output){
    unsigned char block = 254;
    
    for(size_t i=0; i<output.size(); i++){
            cout << output[i];
            cout << block;
            Sleep(170);
            cout << "\b";
            cout << " ";
            Sleep(170);
            cout << "\b";
           
        }
    }

void cursoroff(){
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}

int main() {
    
    setupWindowSize();
    
    fontsize50();   
    
    cursoroff();
     //Play sound for the start of the program
    PlaySound(TEXT("C://Users//jonat//Workspaces//Functions//FlashingCursorEffect//matrix.wav"),NULL, SND_FILENAME| SND_ASYNC);
    
    system("COLOR 2");
    
    string output="Wake Up Neo";
    
    string output2="The Matrix has you...";
    
    string output3="Follow the white rabbit.";
    
    string output4="Knock, knock, Neo.";
    
    flashcursor(output);
    
    Sleep(5000);
    
    system("CLS");
    
    flashcursor(output2);
    
    Sleep(5000);
    
    system("CLS");
    
    flashcursor(output3);
    
    Sleep(5000);
    
    system("CLS");
    
    cout << output4;
    
    Sleep(5000);
	
    return 0;
}
