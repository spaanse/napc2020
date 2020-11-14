#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
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

int main() {
	int height, numStrong;
	cin >> height >> numStrong;
	int numPeople = height*(height+1)/2;
	
	vector<vector<Mod> > dp(height+1, vector<Mod>(numPeople,0));
	for (int i = 0; i < height; i++) {
		dp[i][0] = 1;
	}
	dp[1][1] = 1;

	for (int l = 2; l < height; l++) {
		for (int f = 1; f < l*(l+1)/2; f++) {
			dp[l][f] = 0;
			// hier moet nog meer
		}
	}


	return 0;
}