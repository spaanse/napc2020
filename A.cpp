#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N; cin>>N;
    int nm[20100];
    queue<int> order;
    for(int m=1; m<=2*N; m++){
	nm[m] = -1;
	order.push((m-1)%N+1);
    }
    
    int ind = 1;
    for(int n=0; n<2*N-1; n++){
	int a, b; cin>>a;
	if(nm[a] != -1)
	    cout << nm[a] << endl;
	else {
	    nm[a] = order.front();
	    cout << order.front() << endl;
	    order.pop();
	}
	cin>>b;
	if(nm[b]!=-1)
	    cout << nm[b] << endl;
	else {
	    if(order.front() == nm[a]){
		order.push(order.front());
		order.pop();
	    }
	    nm[b] = order.front();
	    order.pop();
	    cout << nm[b] << endl;
	}
    }
}
