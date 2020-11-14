#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef int64_t ll;

struct Mod {
	ll mod = 1000000007, val = 0;
	Mod() {}
	Mod(const ll& newVal) { val = newVal % mod; if (val < 0) { val += mod; } }
	Mod(const ll& newVal, const ll& newMod) { mod = newMod; val = newVal % mod; if (val < 0) { val += mod; } }
	Mod(const Mod& other) { val = other.val; mod = other.mod; }
	Mod& operator=(const ll& newVal) { val = newVal % mod; if (val < 0) { val += mod; } return *this; }
	Mod& operator=(const Mod& other) { val = other.val; mod = other.mod; return *this; }
	Mod& operator*=(const Mod& other) { val = (val * other.val) % mod; return *this; }
	Mod& operator+=(const Mod& other) { val += other.val; if (val >= mod) { val -= mod; } return *this; }
	Mod& operator-=(const Mod& other) { val -= other.val; if (val < 0)   { val += mod; } return *this; }
	Mod& operator/=(const Mod& other) { val = (val * pow(other, mod - 2) .val) % mod; return *this; }
	Mod& operator++() { val++; if (val >= mod) { val -= mod; } return *this; }
	Mod& operator--() { val--; if (val < 0)   { val += mod; } return *this; }
	bool operator==(const Mod& other) const { return val == other.val; }
	bool operator< (const Mod& other) const { return val < other.val; }
	bool operator> (const Mod& other) const { return val > other.val; }
	bool operator!=(const Mod& other) const { return val != other.val; }
	bool operator<=(const Mod& other) const { return val <= other.val; }
	bool operator>=(const Mod& other) const { return val >= other.val; }
	explicit operator ll() const { return val; }
	explicit operator bool() const { return val?true:false; }
	friend Mod operator+(Mod lhs, const Mod& rhs) { lhs += rhs; return lhs; }
	friend Mod operator-(Mod lhs, const Mod& rhs) { lhs -= rhs; return lhs; }
	friend Mod operator*(Mod lhs, const Mod& rhs) { lhs *= rhs; return lhs; }
	friend Mod operator/(Mod lhs, const Mod& rhs) { lhs /= rhs; return lhs; }
	friend Mod operator+(const ll &lhs, const Mod &rhs) { return Mod(lhs, rhs.mod) + rhs; }
	friend Mod operator-(const ll &lhs, const Mod &rhs) { return Mod(lhs, rhs.mod) - rhs; }
	friend Mod operator*(const ll &lhs, const Mod &rhs) { return Mod(lhs, rhs.mod) * rhs; }
	friend Mod operator/(const ll &lhs, const Mod &rhs) { return Mod(lhs, rhs.mod) / rhs; }
	friend bool operator==(const ll &lhs, const Mod &rhs) { return lhs == rhs.val; }
	friend bool operator!=(const ll &lhs, const Mod &rhs) { return lhs != rhs.val; }
	friend bool operator< (const ll &lhs, const Mod &rhs) { return lhs < rhs.val; }
	friend bool operator> (const ll &lhs, const Mod &rhs) { return lhs > rhs.val; }
	friend bool operator<=(const ll &lhs, const Mod &rhs) { return lhs <= rhs.val; }
	friend bool operator>=(const ll &lhs, const Mod &rhs) { return lhs >= rhs.val; }
	friend Mod pow(Mod base, ll exp) {
		Mod ans = {1, base.mod}; do{ if (exp & 1) { ans *= base; } base *= base; } while (exp >>= 1); return ans;
	}
	friend ostream& operator<<(ostream& os, const Mod& obj) { return (os << obj.val); }
	friend istream& operator>>(istream& is, Mod& obj) { ll newVal; is >> newVal; obj = newVal; return is; }
};

typedef vector<Mod> vm;
typedef vector<vm> vvm;
typedef vector<vvm> vvvm;

int main() {
	int height, numStrong;
	cin >> height >> numStrong;
	int numPeople = height*(height+1)/2, numFlexible=numPeople-numStrong;
	
	vvvm dp(101, vvm(101,vm(5051,0)));

	dp[0][0][0] = 1;

	for (int p=0; p <= numPeople; p++) {
		for (int w = 1; w <= height; w++) {
			for (int h = 0; h <= w; h++) {
				if (h > 0) dp[w][h][p] = dp[w][h-1][p];
				if (h < w  and h <= p) dp[w][h][p] += dp[w-1][h][p-h];
				if (h >= w and h <= p) dp[w][h][p] += dp[w-1][w-1][p-h];
			}
		}
	}

	cout << dp[height][height][numFlexible] << endl;

	return 0;
}