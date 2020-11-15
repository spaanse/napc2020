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
	void rotleft() {
		int _x = x, _y = y;
		x = _x+_y;
		y = _y-_x;
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



	vector<vector<ll> > dp_clw(numShaft, vector<ll>(numShaft,0)), dp_ccw(numShaft, vector<ll>(numShaft,0));
	for (int i = 0; i < numShaft; i++) {
		dp_clw[i][i] = 1;
		dp_ccw[i][i] = 1;
	}

	vector<point> temp = coord;
	for (int rep = 0; rep < 4; rep++) {
		sort(temp.begin(), temp.end());
		for (int j = 0; j < numShaft; j++) {
			ll sum = 0;
			int start = 0;
			for (int i = 0; i <= numShaft; i++) {
				if (i == numShaft or temp[i].y != temp[start].y) {
					for (int k = i-1; k >= start; k--) {
						sum -= dp_clw[j][temp[k].i];
						dp_clw[j][temp[k].i] = sum;
					}
					assert(sum == 0);
					start = i;
				}
				if (i != numShaft)
					sum += dp_clw[j][temp[i].i];
			}
		}
		for (int i = 0; i < numShaft; i++) {
			temp[i].rotright();
		}
	}

	for (int rep = 0; rep < 4; rep++) {
		for (int i = 0; i < numShaft; i++) {
			temp[i].rotleft();
		}
		sort(temp.begin(), temp.end());
		for (int j = 0; j < numShaft; j++) {
			ll sum = 0;
			int start = 0;
			for (int i = 0; i <= numShaft; i++) {
				if (i == numShaft or temp[i].y != temp[start].y) {
					for (int k = i-1; k >= start; k--) {
						sum -= dp_ccw[j][temp[k].i];
						dp_ccw[j][temp[k].i] = sum;
					}
					start = i;
				}
				if (i != numShaft) 
					sum += dp_ccw[j][temp[i].i];
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < numShaft; i++) {
		for (int j = 0; j < numShaft; j++) {
			ans += dp_clw[i][j] * dp_ccw[i][j];
		}
	}
	cout << ans << endl;

	return 0;
}