#include <iostream>
using namespace std;

// Loops

int main(){

    // Example of while loop
    int num = 0;

    while (num != 1000){
        cout << num << endl;
        if (num == 621){
            cout << "Oh that's my birthday btw" << endl;
        }

        num = num + 1;
    }

    // Example of for loop
    for (int i=0; i<100; i++){ // Or you could increment by 2 by doing i=i+2, logically speaking you could also do i=i+1 isntead of i++, but it's a convention to use i++
        cout << i << endl;
    }
}
