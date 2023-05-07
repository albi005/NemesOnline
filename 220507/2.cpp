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


class Interval {
public:
    int start = 0;
    int end = 0;
    Interval() {};
    Interval(int, int) {};
};

int main()
{
    fast_cin();

    unordered_map<int, Interval> cache;
    int count = 0;

    int jelentkezok, days;
    cin >> jelentkezok >> days;

    for (int i = 0; i < jelentkezok; i++) {
        Interval current;
        cin >> current.start >> current.end;

        Interval interval;
		
        if (cache.count(current.start - 1) == 1) {
			interval = cache[current.start - 1];
			interval.end = current.end;
            cache.erase(current.start - 1);
        }
        else {
			interval = current;
            count++;
        }
		cache[interval.start] = interval;

        if (cache.count(current.end + 1) == 1) {
			interval.end = cache[current.end + 1].end;
            cache.erase(current.end + 1);
			if (interval.end != interval.start)
                count--;
        }
        cache[interval.end] = interval;
        cout << count << ln;
    }

    return 0;
}