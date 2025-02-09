#include <iostream>
using namespace std;

class Rock{
    public:
        void doNothing(){
            cout << "..." << endl;
        }
};

void fullUsername(string firstName){
    string fullName = firstName + ' ' + "Morales";

    cout << fullName << endl;
}

int main(){
    string aVaraible = "Nicko";

    fullUsername(aVaraible);

    Rock rock1;

    rock1.doNothing();
}