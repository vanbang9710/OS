#ifndef COMMON_H
#define COMMON_H
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
/*********************************/
#ifdef linux
#include <inttypes.h>
//typedef uint64_t_t  uint64_t;
#endif // linux

 
class CLocation {
public:
	int _extent;
	int _block;	
	int _offset;
	
	CLocation() {
		_extent = -1;
		_block = -1;
		_offset = -1;		
	}
	CLocation(int e, int b, int o) {
		_extent = e;
		_block = b;		
		_offset = o;		
	}
	bool operator==(const CLocation& rhs) const
	{
		return _block == rhs._block && _offset == rhs._offset
			&& _extent == rhs._extent;			
	}
};

typedef vector<uint64_t> queue;
typedef vector<CLocation> loc_queue;

/*
INPUT: + the reference position queue: refs,
	   + the block size: block_size
	   + the file size: file_size
	   + the pointer size: pointer_size
OUTPUT: the location queue: wt corresponding to the input queue
	where each item in the queue will have the following values:
	+ valid reference: calculate the corresponding block and offset
	+ invalid referecnce: block_size=-1; offset=-1;

*/
void ExtentA(queue refs, int block_size, int extent_size, uint64_t file_size, loc_queue& wt);
#endif
