#include <iostream>

using namespace std;


int main(){
    int N, s; cin>>N>>s;
    int ind = 0;
    for(int n=0; n<=N; n++){
	for(int m=0; (m<s && n==N) || m<=n*(n+1)/2; m++, ind++){}
    }
    cout << ind << endl;
    cout << ans[ind] << endl;
    return 0;
}