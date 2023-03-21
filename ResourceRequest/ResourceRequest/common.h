#ifndef COMMON_H
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//////////////////////////////////////////////////////////////////////////
#define NTT_RESOURCE_N 3
#define NTT_PROCESS_M 5
class SystemInfo {
public:
	int	Need[NTT_PROCESS_M][NTT_RESOURCE_N];
	int Available[NTT_RESOURCE_N];
	int Allocation[NTT_PROCESS_M][NTT_RESOURCE_N];
	int Request[NTT_PROCESS_M][NTT_RESOURCE_N];
};

class RequestResp {
public:
	int _processID;
	int _status;
	/*
	  status=
	  0: the request can be granted
	  -1: the request may cause a deadlock if it is granted
	  -2: the request has caused an error since it asks more than its need
	  -3: the request has to wait since its request is not satisfied at the moment
	*/
	RequestResp(int p, int s) {
		_processID = p;
		_status = s;
	}
public:
	bool operator==(const RequestResp& rhs) const
	{
		return _processID == rhs._processID
			&& _status == rhs._status;
	}
};

typedef vector<RequestResp> queue;
/*
INPUT: SystemInfo info contains the current information
OUTPUT: result the vector of results with the same process order as the input - the SystemInfo
*/
void ResourceRequest(SystemInfo& info, queue& result);
#endif