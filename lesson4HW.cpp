#include <iostream>
#include <vector>
using namespace std;

// Finding the longest word

int main(){
    string text = "";
    getline(cin, text);
    text = text + ' ';

    vector <int> wordLength = {};

    int lastIndex = text.length()-1;
    int count = 0;
    int max = 0;


    for (int i=0; i<=lastIndex; i++){
        if (text[i] != ' '){
            count++;
        }

        else if (text[i] == ' '){
            wordLength.push_back(count);
            count = 0;
        }
    }

    for (int i=0; i<=wordLength.size(); i++){
        if (wordLength[i] > max){
            max = wordLength[i];
        }
    }

    cout << max << endl;
}