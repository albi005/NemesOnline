// 100/100

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

int NOPE() {
	cout << -1 << ln;
	return 0;
}

int main()
{
	// INIT
	fast_cin();

	int departureCount, cleanupTime;
	cin >> departureCount >> cleanupTime;
	
	vector<int> departures(departureCount);
	forn(i, departureCount) {
		cin >> departures[i];
	}

	int arrivalCount, maxHoverTime;
	cin >> arrivalCount >> maxHoverTime;
	
	vector<int> arrivals(arrivalCount);
	forn(i, arrivalCount) {
		cin >> arrivals[i];
	}
	
	int lookAhead = maxHoverTime / cleanupTime + 1;

	// SOLVE
	int waitSum = 0, departureIndex = 0, arrivalIndex = 0, currentTime = 0;
	while (arrivalIndex < arrivalCount && departureIndex < departureCount) {
		int nextArrivalStart = arrivals[arrivalIndex];
		int nextArrivalEnd = nextArrivalStart + maxHoverTime;
		int nextDeparture = departures[departureIndex];

		bool nextMustBeArrival = nextArrivalEnd <= max(currentTime, nextDeparture) + cleanupTime;
		bool nextIsArrival = nextMustBeArrival || nextArrivalStart < nextDeparture;
		if (!nextMustBeArrival) {
			bool wouldBeLate = false;
			int wouldBeTime = currentTime + cleanupTime;
			forn(i, lookAhead) {
				int wouldBeNextArrivalIndex = arrivalIndex + i;
				if (wouldBeNextArrivalIndex >= arrivalCount) break;
				if (arrivals[wouldBeNextArrivalIndex] + maxHoverTime < wouldBeTime) {
					wouldBeLate = true;
					break;
				}
				wouldBeTime += cleanupTime;
			}
			if (wouldBeLate)
				nextIsArrival = true;
		}

		if (nextIsArrival) {
			if (currentTime > nextArrivalStart) {
				if (currentTime > nextArrivalEnd)
					return NOPE();
				waitSum += currentTime - nextArrivalStart;
			}
			else
				currentTime = nextArrivalStart;
			arrivalIndex++;
		} else {
			if (currentTime > nextDeparture)
				waitSum += currentTime - nextDeparture;
			else
				currentTime = nextDeparture;
			departureIndex++;
		}			
		currentTime += cleanupTime;
	}

	while (arrivalIndex < arrivalCount) {
		int nextArrivalStart = arrivals[arrivalIndex];
		int nextArrivalEnd = nextArrivalStart + maxHoverTime;
		if (currentTime > nextArrivalStart) {
			if (currentTime > nextArrivalEnd)
				return NOPE();
			waitSum += currentTime - nextArrivalStart;
		}
		else
			currentTime = nextArrivalStart;
		arrivalIndex++;			
	}

	while (departureIndex < departureCount) {
		int nextDeparture = departures[departureIndex];
		if (currentTime > nextDeparture)
			waitSum += currentTime - nextDeparture;
		else
			currentTime = nextDeparture;
		departureIndex++;
	}
	
	cout << waitSum << ln;
	
	// ඞ
	return 0;
}