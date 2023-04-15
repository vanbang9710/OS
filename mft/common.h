#ifndef COMMON_H
#define COMMON_H
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////
// Memory reference OR logical address request
class Refer {
public:
	int _id; // process id
	int _offset; // logical address
	int _address; // physical address
	Refer(int i, int o) {
		_id = i;
		_offset = o;
		_address = -1;
	}
	bool operator==(const Refer& rhs) const
	{
		return _id == rhs._id
			&& _offset == rhs._offset
			&& _address == rhs._address;
	}
};
typedef vector<Refer> RequestQueue;

//////////////////////////////////////////////////////////////////////////
class Process {
public:
	int _id;
	int _size; // limit
	int _slotID; // slot id in RAM

	Process(int i, int s) {
		_id = i;
		_size = s;
		_slotID = -1;
	}
	Process(int i, int s, int slot) {
		_id = i;
		_size = s;
		_slotID = slot;
	}
	bool operator==(const Process& rhs) const
	{
		return _id == rhs._id
			&& _size == rhs._size
			&& _slotID == rhs._slotID;
	}
};

typedef vector<Process> ProcessQueue;
//////////////////////////////////////////////////////////////////////////

enum { FREE, OCCUPIED };

// RAM
class MemSlot {
public:

	int _size; // limit
	int _status; // FREE or OCCUPIED
	int _progsize; // process' limit
	int _progid; // process' id
	int _start; // base

	MemSlot(int st, int s) {
		_size = s;
		_status = FREE;
		_start = st;
		_progsize = 0;
		_progid = -1;
	}

	MemSlot(int s) {
		_size = s;
		_status = FREE;
		_progsize = 0;
		_progid = -1;
		_start = -1;
	}
};

class MemState {
public:
	int _slotID; // slot id in RAM
	int _status; // FREE or not
	int _programID; // process id
	int _internalFrag; // amount of fragmentation in bits

	MemState(int sid, int status, int progid, int fragment) {
		_slotID = sid;
		_status = status;
		_programID = progid;
		_internalFrag = fragment;
	}

	bool operator==(const MemState& rhs) const
	{
		return _slotID == rhs._slotID
			&& _status == rhs._status
			&& _programID == rhs._programID
			&& _internalFrag == rhs._internalFrag;
	}
};
typedef vector<MemState> SlotState;
extern vector<MemSlot> gTable;
/*************************************************************/

/*
Function viewMemState(SlotState &q))
INPUT: None
OUTPUT: SlotState &q containing the status of all slots in the memory ordered by the slotID. Each slot
_status=
	 + FREE if the slot is not allocated
	 + OCCUPIED if the slot is allocated
_programID=
	 + -1 if the slot is FREE
	 + programID of the allocated process if the slot is occupied
_internalFrag= the actual fragment of the slot. If the slot is FREE the fragment is 0
*/
void viewMemState(SlotState& q);
/*
Function MFTAllocate
INPUT: ProcessQueue &q the process queue needs to be allocated
OUTPUT: ProcessQueue & allocatedq - the vector maps process to the slot
Use bestfit allocation algorithm to find the slot for each process in order of the input queue
*/
void MFTAllocate(const ProcessQueue& q, ProcessQueue& allocatedq);
/*
Function
INPUT: the reference queue where each item is a Cref
OUTPUT: the address queue where each item is corresponding address to the input queue
 + -2 if the process is not available in the memory
 + -1 if the reference is invalid
 + actual physical address (in bytes), otherwise
*/
void MemoryReference(const RequestQueue& q, RequestQueue& a);
#endif