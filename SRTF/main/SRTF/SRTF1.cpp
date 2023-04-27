#include "common.h"
#include <climits>
#include <algorithm>
#define taskname "SRTF"
#pragma warning(disable : 4996)

void SRTF(const queue& _q, Gantt& running_chart) {
	if (fopen(taskname".out", "r")) {
		//freopen(taskname".out", "w", stdout);
	}
	queue q = _q;
	vector<int> id, p;
	for (int i = 0; i < q.size(); ++i) {
		id.push_back(i);
	}
	sort(id.begin(), id.end(), [&](const int& a, const int& b) {
		if (q[a]._appear != q[b]._appear) return q[a]._appear > q[b]._appear;
		return q[a]._duration > q[b]._duration;
		});
	vector<int> r = id;
	int time = 0;
	if (!r.empty()) {
		p.push_back(r.back());
		r.pop_back();
	}
	while (!p.empty() || 0 < r.size()) {
		int cnt = INT_MAX, i = -1;
		if (!p.empty()) {
			cnt = q[p.back()]._duration;
			i = -2;
		}
		for (int j = r.size() - 1; j >= 0; --j)
		{
			CTask tmp = q[r[j]];
			//if (tmp._appear >= time) {
			int time_ = max(tmp._appear - time, 0);
				if (cnt - (time_) > tmp._duration) {
					cnt = time_;
					i = j;
					break;
				}
			//}
		}
		if (!p.empty()) running_chart.push_back(CPUBurst(p.back(), cnt));
		time += cnt;
		if (i == -2) {
			q[p.back()]._duration = 0;
			p.pop_back();
		}
		else {
			if (!p.empty()) q[p.back()]._duration -= cnt;
		}
		for (int j = r.size() - 1; j >= 0; --j) {
			if (q[r.back()]._appear > time) break;
			p.push_back(r.back());
			r.pop_back();
		}
		sort(p.begin(), p.end(), [&](const int& a, const int& b) {
			return q[a]._duration > q[b]._duration;
			});
		for (auto& c : running_chart) {
			cout << c._process << ' ' << c._duration << ' ';
		}
		cout << '\n';
		for (auto &i : p) {
			CTask c = q[i];
			cout << i << ' ' << c._appear << ' ' << c._duration << ' ';
		}
		cout << '\n';
		for (auto& i : r) {
			CTask c = q[i];
			cout << i << ' ' << c._appear << ' ' << c._duration << ' ';
		}
		cout << '\n';
		cout << time << '\n';
		cout << '\n';
	}
}