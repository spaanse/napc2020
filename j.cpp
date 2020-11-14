#include <iostream>

using namespace std;

int main(){
    long long no_of_jars;
    long long capacity;
    cin >> no_of_jars >> capacity;

    long long jars_in_boxes = no_of_jars % capacity;
    cout << jars_in_boxes;    
}