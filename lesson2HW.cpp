#include <iostream>
#include <string>
using namespace std;

int main(){
    string text = "";
    getline(cin, text);

    int l = text.length();
    int lastIndex = l-1;
    int count = 0;

    for (int i = lastIndex; i>=0; i--){
        cout << text[i] << endl;

        if (text[i] != ' '){
            count++;
        }
        else{
            break;
        }
    }

    cout << count << endl;
}

