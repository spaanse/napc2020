#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N; cin>>N;
    int a[50];
    for(int n=0; n<N; n++)
	cin>>a[n];
    sort(a, a+N);

    double exp = 0.0;
    double p = 0.5;
    for(int n=N-1; n>=0; n--){
	exp += p*((double)a[n]);
	p *= 0.5;
    }
    printf("%.7f\n", exp);
    return 0;
}
