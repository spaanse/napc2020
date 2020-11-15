#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main(){
    int R, C, K; cin>>R>>C>>K;
    string g[60];

    for(int r=0; r<R; r++){
	cin>>g[r];
    }
    // row, column, drow, dcolumn, next kangaroo
    priority_queue<tuple<int, int, int, int, int, int> > q;

    for(int r=0; r<R; r++){
	for(int c=0; c<C; c++){
	    if(g[r][c]=='0')
		q.push(tuple<int, int, int, int, int, int>(0, r, c, 0, 0, 1));
	}
    }
    
    int v[50][50][105][105][7];

    for(int a=0; a<50; a++)
	for(int b=0; b<50; b++)
	    for(int c=0; c<105; c++)
		for(int d=0; d<105; d++)
		    for(int e=0; e<7; e++)
			v[a][b][c][d][e] = -1;

    int mind = 1e9;
    while(!q.empty()){
	auto t = q.top(); q.pop();
	
	int d, r, c, dr, dc, nk;
	tie(d, r, c, dr, dc, nk) = t;

	if(v[r][c][dr+50][dc+50][nk] != -1)
	    continue;
	v[r][c][dr+50][dc+50][nk] = -d;
	if(g[r][c] == '0'+nk){
	    if(nk==K+1 && dr==0 && dc==0){
		mind = min(mind, -d);
		continue;
	    }
	    if(nk<K+1)
		nk++;
	}
	for(int ddc = -1; ddc<=1; ddc++){
	    for(int ddr = -1; ddr <= 1; ddr++){
		dc += ddc;
		dr += ddr;

		r += dr;
		c += dc;
		
		if(0<=r && r<R && 0<=c && c<C && g[r][c] != '#'){
		    q.push({d-1, r, c, dr, dc, nk});
		}

		r -= dr;
		c -= dc;

		dc -= ddc;
		dr -= ddr;
	    }
	}
    }
    if(mind>1e8)
	cout << "impossible" << endl;
    else
	cout << mind << endl;
    return 0;
}
