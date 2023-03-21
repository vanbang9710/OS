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
//#include<queue>
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
#define taskname "resourcerequest"
//#define cout cerr

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
template<typename T>
ostream& operator<<(ostream& os, const std::pair<T, int>& array)
{
	//...code
	os << "[";
	for (int i = 0; i < array.second; ++i) {
		os << array.first[i] << ", ";
	}
	os << "]";
	return os;
}

bool Smaller(int a[], int b[], int n) {
	for (int i = 0; i < n; ++i) {
		if (a[i] > b[i]) return false;
	}
	return true;
}

void Modify(int a[], int b[], int n, int multiplier) {
	for (int i = 0; i < n; ++i) {
		a[i] += b[i] * multiplier;
	}
}

bool Banker(SystemInfo& info) {
	int Work[NTT_RESOURCE_N];
	copy(info.Available, info.Available + NTT_RESOURCE_N, Work);
	//cout << make_pair(Work, NTT_RESOURCE_N) << '\n';
	vector<bool> Finish(NTT_PROCESS_M, false);
	int finish_cnt = 0;
	while (finish_cnt < NTT_PROCESS_M) {
		int i;
		for (i = 0; i < NTT_PROCESS_M; ++i) {
			if (!Finish[i] && Smaller(info.Need[i], Work, NTT_RESOURCE_N)) {
				Modify(Work, info.Allocation[i], NTT_RESOURCE_N, 1);
				Finish[i] = true;
				++finish_cnt;
				break;
			}
		}
		if (i == NTT_PROCESS_M) {
			return false;
		}
	}
	return true;
}

void ResourceRequest(SystemInfo& info, queue& result) {
	for (int i = 0; i < NTT_PROCESS_M; ++i) {
		//cout << i << '\n';
		if (!Smaller(info.Request[i], info.Need[i], NTT_RESOURCE_N)) {
			result.push_back(RequestResp(i, -2));
			continue;
		}
		if (!Smaller(info.Request[i], info.Available, NTT_RESOURCE_N)) {
			result.push_back(RequestResp(i, -3));
			continue;
		}
		Modify(info.Available, info.Request[i], NTT_RESOURCE_N, -1);
		Modify(info.Allocation[i], info.Request[i], NTT_RESOURCE_N, 1);
		Modify(info.Need[i], info.Request[i], NTT_RESOURCE_N, -1);
		if (Banker(info)) {
			result.push_back(RequestResp(i, 0));
		}
		else {
			result.push_back(RequestResp(i, -1));
			Modify(info.Available, info.Request[i], NTT_RESOURCE_N, 1);
			Modify(info.Allocation[i], info.Request[i], NTT_RESOURCE_N, -1);
			Modify(info.Need[i], info.Request[i], NTT_RESOURCE_N, 1);
		}
	}
}