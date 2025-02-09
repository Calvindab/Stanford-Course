#include <iostream>
#include <vector>
using namespace std;

// Vector, which is basically list and arrays, but it could only store one data type
// You have to #include <vector>

int main(){
    vector <string> names = {"Nicko", "Sharon", "Calvin"};

    // To find a length of the vector, you use vectorName.size()
    for (int i=0; i<names.size(); i++){
        cout << names[i] << endl;
    }

    // You could also use it for characters
    string name = "nicko";

    for (int i=0; i<name.length(); i++){
        cout << name[i] << endl;
    }

    // Vectors functions example

    vector <int> v1 = {1, 2, 3, 4};

    v1.front(); // First index
    v1.back(); // Last index
    v1.size(); // Length of index
    v1.push_back(9); // Add an element to the back of the vector, basically appending
    v1.capacity(); // The number of size it could hold, when a vector needs more space, it would double the size
                   // For example if the vector currently has 4 value, and you wanted to append another value, it would double the size, so the capacity would be 8
    v1.pop_back(); // Return the value of the last index of the vector
    v1.shrink_to_fit(); // Shrink the vector capacity so that it fits the number of element, for example if you keep removing an element, you would also shrink the eisze so it doesn't take up memory
    v1.insert(v1.begin(), 5); // 2 parameters, the index position where you want the element to be, and the value of that index
    v1.insert(v1.begin()+1, 5); // Make index position 1 value 5
    
}