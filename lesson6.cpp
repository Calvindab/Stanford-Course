#include <iostream>
using namespace std;

// Classes - Object Oriented Programming

class person{
    public:
        string name;
        string lastName;
        int height;
        int mass;

        void run(){
            cout << "This person is running" << endl;
        }

        void walk(){
            cout << "This person is walking" << endl;
        }

        void sleep(){
            cout << "This person is sleeping" << endl;
        }
};

int main(){
    person nicko;

    nicko.name = "Nicko";
    nicko.lastName = "Martinez";
    nicko.height = 179; // in CM
    nicko.mass = 75; // in KG

    cout << nicko.name << endl;
    cout << nicko.lastName << endl;
    cout << nicko.height << endl;
    cout << nicko.mass << endl;
}