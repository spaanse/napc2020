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

int main() {
	int numSet;
	cin >> numSet;
	vi cardFace(2*numSet,-1);
	vi used(numSet,0);
	for (int turn = 0; turn < 2*numSet-1; turn++) {
		int a,b;
		cin >> a; a--;
		if (cardFace[a] == -1) {		
			for (int i = 0; i < numSet; i++) {
				if (used[i] == 0) {
					cardFace[a] = i;
					used[i]++;
					break;
				}
			}
		}
		if (cardFace[a] == -1) {		
			for (int i = 0; i < numSet; i++) {
				if (used[i] == 1) {
					cardFace[a] = i;
					used[i]++;
					break;
				}
			}
		}
		cout << cardFace[a]+1 << endl << flush;
		cin >> b; b--;
		if (cardFace[b] == -1) {
			for (int i = 0; i < numSet; i++) {
				if (i != cardFace[a] and used[i] == 1) {
					cardFace[b] = i;
					used[i]++;
					break;
				}
			}
		}
		if (cardFace[b] == -1) {
			for (int i = 0; i < numSet; i++) {
				if (i != cardFace[a] and used[i] == 0) {
					cardFace[b] = i;
					used[i]++;
					break;
				}
			}
		}
		if (cardFace[b] == -1) {
			cardFace[b] = cardFace[a];
			used[cardFace[b]]++;
		}
		cout << cardFace[b]+1 << endl << flush;
	}
	return 0;
}