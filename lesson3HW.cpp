#include <iostream>
using namespace std;

// - Create a calculator program that takes three user inputs
// - 2 integers,  and an operation to perform on the 2 integers.

// - Define functions to perform the following operations:
// 1. add
// 2. subtract
// 3. multiply
// 4. divide

int calculate(int num1, char sign, int num2){
    int ans = 0;

    if (sign == '+'){
        ans = num1+num2;
    }

    else if (sign == '-'){
        ans = num1-num2;
    }

    else if (sign == '*'){
        ans = num1*num2;
    }

    return ans;
}

float divide(float num1, float num2){
    if (num2 == 0){
        cout << "Error, division by 0 is not possible" << endl;
    }

    return num1/num2;
}

int main(){
    int num1;
    int num2;
    char sign;

    cout << "Enter a number: ";
    cin >> num1;
    cout << endl;

    cout << "Enter an operator: ";
    cin >> sign;
    cout << endl;

    cout << "Enter the final number: ";
    cin >> num2;
    cout << endl;

    if (sign == '/'){
        cout << "\n" << divide(static_cast<float>(num1), static_cast<float>(num2)) << endl;
    }
    else{
        cout << "\n" << calculate(num1, sign, num2) << endl;
    }


}