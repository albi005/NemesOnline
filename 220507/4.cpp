// 35/100

#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())


vector<bool> stringToBools(string s) {
	vector<bool> res(s.size());
	forn(i, s.size()) {
		res[i] = s[i] == 'Z';
	}
	return res;
}

int main()
{
	fast_cin();

	int cells, iterations;
	cin >> cells >> iterations;
	string start;
	cin >> start;

	vector<bool> state = stringToBools(start);

	int ruleCount;
	cin >> ruleCount;
	vector<vector<bool>> rules(ruleCount);
	forn(i, ruleCount) {
		string rule;
		cin >> rule;
		rules[i] = stringToBools(rule);
	}

	forn(amogus, iterations) {
		vector<bool> nextState(cells);
		for (int i = 2; i < cells - 2; i++) {
			for (int ruleIndex = 0; ruleIndex < ruleCount; ruleIndex++)
			{
				if (state[i - 2] == rules[ruleIndex][0]
					&& state[i - 1] == rules[ruleIndex][1]
					&& state[i] == rules[ruleIndex][2]
					&& state[i + 1] == rules[ruleIndex][3]
					&& state[i + 2] == rules[ruleIndex][4])
				{
					nextState[i] = true;
					break;
				}
				//dbg(ruleIndex);
			}
		}
		
		//// print state
		//forn(i, cells) {
		//	if (state[i]) {
		//		cout << "_";
		//	} else {
		//		cout << "F";
		//	}
		//}
		//cout << ln;
		

		state = nextState;
	}

	// print true count
	int trueCount = 0;
	forn(i, cells) {
		if (state[i]) {
			trueCount++;
		}
	}
	cout << trueCount << ln;

	return 0;
}