#include <iostream>
using namespace std;

// Conditionals
int main(){
    int age;

    cout << "Enter your age" << endl;
    cin >> age;

    // (Conditions) {Code to be executed if condition is true}
    if (age >= 21){
        cout << "Your allowed into the bar" << endl;
    }
    else{
        cout << "Get out" << endl;
    }


    // If you used else if statement, you must ALWAYS include else statement otherwise there will be an error
    int x;
    int y;

    cout << "Enter x" << endl;
    cin >> x;

    cout << "Enter y" << endl;
    cin >> y;

    if (x==y){
        cout << "x is equal to y" << endl;
    }

    else if (x <= y){
        cout << "x is less than y" << endl;
    }

    else if (x >= y){
        cout << "x is greater than y" << endl;
    }

    else if (x != y){
        cout << "x is not equal to y" << endl;
    }

    else{
        cout << "Idk ask Calvin" << endl;
    }


    int a;
    
    cout << "a: ";
    cin >> a;

    // AND operator &&
    // OR operator ||
    if (a > 100 || x < 0){
        cout << "a is less than 0 or greater than 100";
    }

    // You cannot do 0 <= x <= 100, that's allowed in Python, but in C++ it's not allowed
    else if (0 <= a && a <= 100){
        cout << "a is between 0 and 100 inclusive";
    }
    

}