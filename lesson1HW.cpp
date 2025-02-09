#include <iostream>

using namespace std;

// 1. output to the user, asking for their name, age, and favorite color.
// 2. store their data in 3 variables, CHALLENGE: use one variable.
// 3. output their data using the following string:
// " (name) is (age) years old and their favorite color is (favorite color) "

int main(){
    string info = "";
    string info2 = "";

    cout << "Input your name" << endl;
    cin >> info;
    info = info + " is ";
    cout << "Input your age" << endl;
    cin >> info2;
    info = info + info2 + " years old and their favorite color is ";
    info2 = "";
    cout << "Input your favorite color" << endl;
    cin >> info2;
    info = info + info2;
    cout << info << endl;

}