#include <iostream>

using namespace std;

int main(){
    int N; cin>>N;
    int nm[20100];
    int order[20100];
    for(int m=1; m<=2*N; m++){
	nm[m] = -1;
	order[m] = (m-1)%N+1;
    }
    
    int ind = 1;
    for(int n=0; n<2*N-1; n++){
	int a, b; cin>>a;
	if(nm[a] != -1)
	    cout << nm[a] << endl;
	else {
	    nm[a] = order[ind];
	    cout << order[ind++] << endl;
	}
	cin>>b;
	if(nm[b]!=-1)
	    cout << nm[b] << endl;
	else {
	    nm[b] = order[ind];
	    cout << order[ind++] << endl;
	}
    }
}
