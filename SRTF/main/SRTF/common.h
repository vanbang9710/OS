#ifndef COMMON_H
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class CTask{
public:
	int _appear;
	int _duration;
	CTask(int a,int d){
		_appear=a;
		_duration=d;
	}
};
class CPUBurst{
public:
	int _process;
	int _duration;
	CPUBurst(int p,int d){
		_process=p;
		_duration=d;
	}
public:
	bool operator==(const CPUBurst& rhs) const
	{ 
		return _process==rhs._process 			 
			 && _duration==rhs._duration; 
	}
    
};
typedef vector<CTask> queue;
typedef vector<CPUBurst> Gantt;
/*
INPUT: the queue q is the queue with process appeared time and duration (running time). With the sample in the test case	
OUTPUT: the queue gantt_chart containing running order of all the input processes (see the test case)
*/
void SRTF(const queue& q, Gantt & running_chart);
#endif