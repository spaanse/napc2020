#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <assert.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef int64_t ll;

struct point{
	long long x, y, i;
	void rotright() {
		int _x = x, _y = y;
		y = _x+_y;
		x = _x-_y;
	}
	bool operator<(point o) {
		return tie(y,x) < tie(o.y, o.x);
	}
};


int main() {
	int numShaft;
	cin >> numShaft;
	vector<point> coord(numShaft);
	for (int i = 0; i < numShaft; i++) {
		coord[i].i = i;
		cin >> coord[i].x >> coord[i].y;
	}



	vector<vector<ll> > dp(numShaft, vector<ll>(numShaft,0)), dp_ccw(numShaft, vector<ll>(numShaft,0));
	for (int i = 0; i < numShaft; i++) {
		dp[i][i] = 1;
		dp_ccw[i][i] = 1;
	}

	vector<point> temp = coord;
	for (int rep = 0; rep < 8; rep++) {
		sort(temp.begin(), temp.end());
		for (int j = 0; j < numShaft; j++) {
			ll sum = 0;
			int start = 0;
			for (int i = 0; i <= numShaft; i++) {
				if (i == numShaft or temp[i].y != temp[start].y) {
					for (int k = i-1; k >= start; k--) {
						sum -= dp[j][temp[k].i];
						dp[j][temp[k].i] = sum;
					}
					assert(sum == 0);
					start = i;
				}
				if (i != numShaft)
					sum += dp[j][temp[i].i];
			}
		}
		for (int i = 0; i < numShaft; i++) {
			temp[i].rotright();
		}
	}

	ll ans = 0;
	for (int i = 0; i < numShaft; i++) {
		ans += dp[i][i];
	}
	cout << ans << endl;

	return 0;
}