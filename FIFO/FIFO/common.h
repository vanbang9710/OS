#ifndef COMMON_H
#define COMMON_H
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
class PageRep {
public:
	char _pageNo;
	char _status;
	char _swapPage;
	PageRep(char p, char t, char s) {
		_pageNo = p;
		_status = t;
		_swapPage = s;
	}
public:
	bool operator==(const PageRep& rhs) const
	{
		return _pageNo == rhs._pageNo
			&& _status == rhs._status
			&& _swapPage == rhs._swapPage;
	}
};

typedef vector<PageRep> repqueue;

/*
INPUT: + the reference string refs,
	   + the number of frames nFrame

OUTPUT: the queue wt containing the processing action in corresponding to the input queue (in preserved order)
		Each item in the queue:
		_pageNo: is the input page number
		action is stated in _status and _swapPage
		hit:_status	 = 0 and _swapPage= -1;
		miss with no replacement:  _status	=1 and _swapPage=-1
		miss with replacement:  _status	=2 and _swapPage=swapped out pageNo

*/
void FIFO(string refs, int nFrame, repqueue& wt);
#endif