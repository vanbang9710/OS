#include "common.h"
/******************************************************/
void initializeQueue(queue& q)
{
    q.push_back(1<<14);
    q.push_back(1024);
    q.push_back(4096);
    q.push_back(4*1024*1024);    
    q.push_back(12 * 1024 * 1024);    
    q.push_back(4294967296);
    q.push_back(4899210751);
    q.push_back(5368709476);
    q.push_back(1299210251);
}
/******************************************************/

void initializeTestCase(loc_queue& tc)
{
    tc.push_back(CLocation(0,4,0));
    tc.push_back(CLocation(0,0,1024));
    tc.push_back(CLocation(0, 1, 0));
    tc.push_back(CLocation(10, 24,0));
    tc.push_back(CLocation(30, 72,0));    
    tc.push_back(CLocation(10485,76,0));
    tc.push_back(CLocation(11960,96,1535));
    tc.push_back(CLocation(-1,-1,-1));
    tc.push_back(CLocation(3171,90,11));
}
/******************************************************/
int main()
{
    queue inq;
    loc_queue outq,tc;
    int block_size, extent_size = 100;
    uint64_t file_size;

    block_size = 1 << 12; //4KB
    file_size = 5268709476;//bytes
    initializeQueue(inq);
    std::cout << "Extent based disk allocation!\n";
    ExtentA(inq,block_size, extent_size,file_size,outq);
    initializeTestCase(tc);
    if (tc == outq)cout << "Correct!" << endl;
    else cout << "Incorrect!" << endl;
}
/******************************************************/
