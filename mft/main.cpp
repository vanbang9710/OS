#include "common.h"

vector<MemSlot> gTable;
/*************************************************************/
void Initialize(ProcessQueue &q,RequestQueue &r)
{
	gTable.clear();
	//Memory initialization
	gTable.push_back(MemSlot(0,512));
	gTable.push_back(MemSlot(512,128));
	gTable.push_back(MemSlot(512+128,256));
	gTable.push_back(MemSlot(512+128+256,9048));
	gTable.push_back(MemSlot(512+128+256+9048,256));
	gTable.push_back(MemSlot(512+128+256+9048+256,4096));

	//Request initialization
	q.push_back(Process(1,200));
	q.push_back(Process(2,1000));
	q.push_back(Process(3,256));

	//Memory reference
	r.push_back(Refer(1,30));
	r.push_back(Refer(2,904));
	r.push_back(Refer(2,1904));
	r.push_back(Refer(3,130));

}
/*************************************************************/
void InitializeProcessTestCase(const ProcessQueue inpq, ProcessQueue &pq)
{
	pq=inpq;
	pq[0]._slotID=2;
	pq[1]._slotID=5;
	pq[2]._slotID=4;
}
/*************************************************************/
void InitializeRefTestCase(const RequestQueue inrq, RequestQueue &aq)
{
	aq=inrq;
	aq[0]._address=670;
	aq[1]._address=11104;
	aq[2]._address=-1;
	aq[3]._address=10074;
}
/*************************************************************/
void InitializeMemTestCase(SlotState&tcs)
{
	tcs.push_back(MemState(0,FREE,-1,0));
	tcs.push_back(MemState(1,FREE,-1,0));
	tcs.push_back(MemState(2,OCCUPIED,1,56));
	tcs.push_back(MemState(3,FREE,-1,0));
	tcs.push_back(MemState(4,OCCUPIED,3,0));
	tcs.push_back(MemState(5,OCCUPIED,2,3096));
}
/*************************************************************/
int main(int argc,char *argv[])
{
	ProcessQueue q,opq,tcpq; // output_process_q and testcase_pq
	RequestQueue r,aoq,tcaq;
	SlotState sq,tcsq;
	
	cout << "MFT memory management demonstration\n\n";
	Initialize(q,r);
	InitializeProcessTestCase(q,tcpq);
	MFTAllocate(q,opq);
	if(tcpq==opq) cout << "Process test case is correct" <<endl;
	else cout << "Process test case is incorrect" <<endl;
	
	cout << "\nMemory state\n";
	InitializeMemTestCase(tcsq);
	viewMemState(sq);
	if(sq==tcsq) cout << "Memory test case is correct" <<endl;
	else cout << "Memory test case is incorrect" <<endl;
	
	MemoryReference(r,aoq);
	InitializeRefTestCase(r,tcaq);
	if(tcaq==aoq) cout << "Reference test case is correct" <<endl;
	else cout << "Reference test case is incorrect" <<endl;
	return 0;
}
/*************************************************************/

