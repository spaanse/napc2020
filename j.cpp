#include <iostream>

using namespace std;

int main(){
    long long no_of_jars;
    long long capacity;
    cin >> no_of_jars >> capacity;
    
    if((no_of_jars % capacity) == 0){
        cout << (no_of_jars / capacity) << endl;
    }
    else{
        long long boxes = no_of_jars / capacity + 1;
        long long minimum_in_box = no_of_jars / boxes;
        cout << minimum_in_box << endl;
    }
}