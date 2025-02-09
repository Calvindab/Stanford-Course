#include <iostream>
using namespace std;

int main(){
    // Creating varaible, printing, concatenation, and input

    int x = 1;
    char nicko = 'W';
    string quote = "Good luck with Sharon, Nicko";
    float hehe = 10.5;
    bool yes = true;

    cout << x << endl;
    cout << nicko << endl;
    cout << quote << endl;
    cout << hehe << endl;
    cout << yes << endl;

    cout << quote << " " << nicko << endl;
    // This << means the code is telling console to output (cout) a varaible, <<
    // cout means console output

    // Input

    // You coudl also do **string something;**, but doing this mean that you're assigning the variable to nothing, which is why it's always better to add a default string
    // So it's better to do **string something = "";**
    string something = "";

    cout << "input something" << endl;
    cin >> something;

    cout << "Your name is:" << something << endl;
    // Notice how this time, the operator becomes >>, it's meaning that the code is telling the computer to throw the usere input into something
    // cin means console input
}