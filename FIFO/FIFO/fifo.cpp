#include "common.h"
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
#include<fstream>

#define y0 asdahsdlkahsdad
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define taskname "TEST"
#define cout cerr

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

template < class T >
ostream& operator << (ostream& os, const vector<T>& v)
{
	os << "[";
	for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
		os << *ii << ", ";
	}
	os << "]";
	return os;
}

void FIFO(string refs, int nFrame, repqueue& wt) {
	queue<int> q;
	vector<bool> inQ(1000, 0);
	for (char c : refs) {
		if (inQ[c]) {
			wt.push_back(PageRep(c, 0, -1));
		}
		else {
			inQ[c] = 1;
			q.push(c);
			if (q.size() <= nFrame) {
				wt.push_back(PageRep(c, 1, -1));
			}
			else {
				wt.push_back(PageRep(c, 2, q.front()));
				inQ[q.front()] = 0;
				q.pop();
			}
		}
	}
}