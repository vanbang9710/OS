#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
#include<cstring>
#include<iomanip>
#include<string>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<algorithm>
#include<functional>
#include<random>
#include<sstream>

#define y0 asdahsdlkahsdad
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define taskname "CONTEST"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        //freopen(taskname".out", "w", stdout);
    }

    int n, t, f, x;
    cin >> n >> t >> f >> x;
    n -= f;
    t = (t- 1) * 60;
    int diff = t - x * n;
    if (diff > 0) {
        cout << "YES\n" << diff;
    } else if (diff == 0) {
        cout << "EXACT!";
    } else {
        cout << "NO\n";
        cout << -diff << '\n' << n - t / x;
    }

    return 0;
}
