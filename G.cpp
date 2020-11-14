#include <iostream>
#include <vector>

using namespace std;

#define vi vector<int>

vector<vi> g;

void dfs(int n, vi& v, vi& f, vi& s, bool gr){
    if(v[n])
	return;
    v[n] = true;
    if(gr)
	f.push_back(n);
    else
	s.push_back(n);

    for(int j:g[n])
	dfs(j, v, f, s, !gr);
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);
    int N, M; cin>>N>>M;
    g.assign(N+1, vi());
    for(int m=0; m<M; m++){
	int a, b; cin>>a>>b;
	g[a].push_back(b);
	g[b].push_back(a);
    }
    
    vi v(N+1, 0);
    vi firstgroup, secondgroup;
    
    for(int n=1; n<=N; n++){
	if(v[n]==0){
	    dfs(n, v, firstgroup, secondgroup, true);
	}
    }
    
    int tot = 0;

    vi group(N+1, 1);

    for(int j:secondgroup)
	group[j] = 2;

    if(firstgroup.size()%2==1 && secondgroup.size()%2==1){
	for(int i: firstgroup){
	    if(g[i].size()<secondgroup.size())
		tot = 1;
	}
    }
    tot += firstgroup.size()/2;
    tot += secondgroup.size()/2;

    cout << tot << endl;

    return 0;
}
