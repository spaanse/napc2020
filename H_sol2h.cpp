#include <iostream>

using namespace std;

int main(){
    cout << "int ans[] = {";
    for(int n=0; n<=100; n++){
	for(int m=0; m<=n*(n+1)/2; m++){
	    int a; cin>>a;
	    if(m||n)
		cout << ",";
	    cout << a;
	}
    }
    cout << "}" << endl;
    
    return 0;
}
