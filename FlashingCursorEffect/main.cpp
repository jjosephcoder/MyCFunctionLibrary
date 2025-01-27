#include <iostream>
#include <windows.h> //Library needed for Sleep method
#include <vector>

using namespace std;
///Function Prototypes
void flashcursor(string &output);

void flashcursor(string &output){
    unsigned char block = 254;
    
    for(size_t i=0; i<output.size(); i++){
            cout << output[i];
            cout << block;
            Sleep(250);
            cout << "\b";
            cout << " ";
            Sleep(250);
            cout << "\b";
           
        }
    }



int main() {
    string output={};
  	cout << "Please enter a string" << endl;
    getline(cin,output);
    flashcursor(output);
	return 0;
}
