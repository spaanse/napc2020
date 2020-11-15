#include <iostream>
#include <map>

using namespace std;

int main(){
    int N; cin>>N;
    
    map<string, int> rank;

    for(int n=0; n<N; n++){
	string s; cin>>s;
	rank[s] = n;
    }
    
    string fav = "suspicious";
    int maxinc = 0;

    for(int n=0; n<N; n++){
	string s; cin>>s;
	
	int delta = rank[s]-n;
	if(delta>maxinc){
	    maxinc = delta;
	    fav = s;
	}
    }
    cout << fav << endl;
    return 0;
}
