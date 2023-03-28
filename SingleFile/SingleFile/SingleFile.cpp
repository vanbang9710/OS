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
#define taskname "Test"
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

inline bool exist(const string name) {
    ifstream f(name.c_str());
    return f.good();
}

void read(istream& fp) {
    while (!fp.eof()) {
        // string line;
        // getline(fp, line);
        // cout << line << endl;
        int x;
        fp >> x;
        cout << x;
    }
}

int main()
{
    ifstream fp;
    string fName = taskname".inp";
    istream& in = exist(fName)
        ? [&]() -> istream& {
        fp.open(fName);
        if (!fp) abort();
        return fp;
    }()
        : cin;

    read(in);

    if (fp.is_open()) {
        fp.close();
    }
    return 0;
    format
}