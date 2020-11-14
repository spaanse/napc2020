#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
 

int main(){
    bool possible = true;
    int n;
    cin >> n;
    vector<string> arr;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    for(int j = 0; j<arr[0].length(); j++){
        if(arr[0][j] == '9'){
            arr[0][j] = '6';
        }
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<arr[i].length(); j++){
            if(arr[i][j] == '6'){
                arr[i][j] = '9';
            }
        }
        if(stoll(arr[i]) < stoll(arr[i -1])){
            possible = false;
        } else {
            for(int j=0; j<arr[i].length(); j++){
                if(arr[i][j] == '9'){
                    arr[i][j] = '6';
                    if(stoll(arr[i]) < stoll(arr[i-1])){
                        arr[i][j] = '9';
                    }
                }
            }
        }
    }
    if(possible){
        cout << "possible" << endl;
        for(int i = 0; i<n; i++){
            cout << arr[i] << endl;
        }
    }
    else {
        cout << "impossible" << endl;
    }
}