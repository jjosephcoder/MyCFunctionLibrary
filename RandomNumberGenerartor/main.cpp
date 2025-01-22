#include <iostream>
#include <algorithm> //library for the shuffle number method
#include <random> 
#include <vector>
#include <windows.h> //Library for using Windows System Colours and Font Size Of Terminal screen
#include <cwchar> //Library for changing the font type and size in the output console


using namespace std;
//////Function Prototype///////
int randomnumber(int low, int high, int &num);
void windowfont();
///////////////////////////////

//////////////////////////////////////
///////randomnumber function def/////
////////////////////////////////////

int randomnumber(int low, int high, int &num){
    
                //create a vector of int type and assign the number of elements to be equal to the value of high - 
                //low +1 so we dont use 0    
                vector<int> nums(high-low +1);
  
                //n C++, iota() is a library function used to fill a range of elements with 
                //increasing values starting from the given initial value.
                iota(nums.begin(),nums.end(),low);    
   
                //std::random_device is a uniformly-distributed 
                //integer random number generator that produces non-deterministic random numbers, and we assign the random
                //numbers to the rd variable which is overwritten with the next random number each time the for loop
                //iterates
                random_device rd;
    
                //It randomly rearrange elements in range [first, last). The function swaps 
                //the value of each element with some other randomly picked element. Shuffling the elements of the vector
                //each iteration removes the likelyhood that the same numbers are picked againby the random funciton.
                shuffle(nums.begin(),nums.end(),rd);
                
                //cout << "Random Number Is: " << nums[0] <<endl;
                num = nums[0];
                return num;
        }

////WindowFont funciton declaration//////
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
    
    int num{};
    //Just pass in your start and end numbers for random number generation
    randomnumber(1,59,num);
    cout << "Your Random Number Passed Back By Reference Is:-";
	cout << num << "\n\n";
    
    //Just pass in your start and end numbers for random number generation
    randomnumber(1,10,num);
    cout << "Your Random Number Passed Back By Reference Is:-";
    cout << num << "\n\n";
    
    //Get the user to enter the start and end numbers for the randomnumber fucntion
    //call
    int low{};
    int high{};
    cout << "Please Enter The Start Number: ";
    cin >>low;
    cout << "\n\n";
    cout << "Please Enter The End Number: ";
    cin >>high;
    
    //Execute the randomnumber function passing in the variables low and high as
    //parameters
    randomnumber(low,high,num);
    cout << "Your Random Number Passed Back By Reference Is:-";
    cout << num << "\n\n";
    
    system("PAUSE");
	return 0;
}
