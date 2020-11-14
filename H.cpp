#include <iostream>

using namespace std;

int main(){
    int dp[110][110][5050];
    
    dp[1][0][1] = dp[1][0][0] = 1;

    for(int tr_size=2; tr_size<=100; tr_size++){
	for(int side=0; last_side<=100; last_side++){
	    for(int n_strong = 0; n_strong <= 5050; n_strong++){
		dp[tr_size][side][n_strong] = 0;
	    

		if(side<=n_strong && tr_size > 1)
		    dp[tr_size][side][n_strong] += dp[tr_size-1][side+1][n_strong-side];

		if(side>0)
		    dp[tr_size][side][n_strong] += dp[tr_size][side-1][n_strong];
		
	    }
	}
    }
}
