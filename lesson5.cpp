#include <iostream>
using namespace std;

// Functions
// If you don't wanna return anything, use "void" as datatype, void is the absence of datatype

string menu(){
    string text = "\nOption:\n1. Welcome\n2. Sign out";
    string option = "";

    cout << text << endl;

    cout << "\nOption: ";
    cin >> option;

    return option;
    
}

string welcome(string name){
    string s = "\nWelcome " + name;
    return s;
}

string bye(string name){
    string s = "\nSee you " + name;
    return s;
}

int main(){

    bool end = false;

    while (end == false){
        string option = menu();

        if (option == "1"){
            cout << "\nEnter your name: " << endl;
            string name = "";
            cin >> name;

            cout << welcome(name) << endl;
        }

        else if (option == "2"){
            cout << "\nEnter your name: " << endl;
            string name = "";
            cin >> name;

            cout << bye(name) << endl;
            end = true;
        }
    }
}