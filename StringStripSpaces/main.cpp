#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;


//////Function Prototype////
void stripspace();

void stripspace(){
    // Creating a string containing multiple whitespaces.
   
    string str{};
    cout << "Please enter a string: ";
    getline(cin, str);

    cout<< "String before removing whitespaces:" << str << endl << endl;

    // Using the erase, remove_if, and ::isspace functions.
    str.erase(remove_if(str.begin(),str.end(), ::isspace),str.end());
    
    cout << "String after removing the white spaces" << str << endl;
    

    system("PAUSE");    
}

using namespace std;

int main(){
    
    stripspace();
 
   return 0;
}