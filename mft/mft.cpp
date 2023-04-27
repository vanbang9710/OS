/*Nguyen Van Bang 20020002*/
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
#define taskname "mft"
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

void viewMemState(SlotState& q) {
	q.clear();
	for (int j = 0; j < gTable.size(); ++j) {
		auto& slot = gTable[j];
		q.push_back(MemState(j, slot._status, slot._progid, slot._status == FREE ? 0 : slot._size - slot._progsize));
	}
}

void MFTAllocate(const ProcessQueue& q, ProcessQueue& allocatedq) {
	allocatedq = q;
	for (int i = 0; i < allocatedq.size(); ++i) {
		auto& p = allocatedq[i];
		int size = INT_MAX, id = -1;
		for (int j = 0; j < gTable.size(); ++j) {
			auto& slot = gTable[j];
			if (slot._status == FREE) {
				if (slot._size >= p._size && slot._size < size) {
					size = slot._size;
					id = j;
				}
			}
		}
		if (id != -1) {
			p._slotID = id;
			gTable[id]._status = OCCUPIED;
			gTable[id]._progsize = p._size;
			gTable[id]._progid = p._id;
		}
	}
}
void MemoryReference(const RequestQueue& q, RequestQueue& a) {
	a = q;
	for (int i = 0; i < a.size(); ++i) {
		auto& r = a[i];
		r._address = -2;
		for (int j = 0; j < gTable.size(); ++j) {
			auto& slot = gTable[j];
			if (slot._progid == r._id) {

				if (r._offset < 0 || r._offset >= slot._progsize) {
					r._address = -1;
				}
				else {
					r._address = slot._start + r._offset;
				}
				break;
			}
		}
	}
}