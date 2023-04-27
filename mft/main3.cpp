#include "common.h"

vector<MemSlot> gTable;
/*************************************************************/
void Initialize(ProcessQueue& q, RequestQueue& r)
{
    gTable.clear();
    //Memory initialization
    gTable.push_back(MemSlot(0, 256));
    gTable.push_back(MemSlot(256, 512));
    gTable.push_back(MemSlot(256 + 512, 512));
    gTable.push_back(MemSlot(256 + 512 + 512, 128));
    gTable.push_back(MemSlot(256 + 512 + 512 + 128, 32));
    gTable.push_back(MemSlot(256 + 512 + 512 + 128 + 32, 128));

    //Request initialization
    q.push_back(Process(4, 60));
    q.push_back(Process(2, 145));
    q.push_back(Process(1, 212));
    q.push_back(Process(3, 97));


    //Memory reference
    r.push_back(Refer(2, 87));
    r.push_back(Refer(1, 95));
    r.push_back(Refer(4, 20));
    r.push_back(Refer(3, 254));
    r.push_back(Refer(3, 59));
}
/*************************************************************/
void InitializeProcessTestCase(const ProcessQueue inpq, ProcessQueue& pq)
{
    pq = inpq;
    pq[0]._slotID = 3;
    pq[1]._slotID = 0;
    pq[2]._slotID = 1;
    pq[3]._slotID = 5;
}
/*************************************************************/
void InitializeRefTestCase(const RequestQueue inrq, RequestQueue& aq)
{
    aq = inrq;
    aq[0]._address = 87;
    aq[1]._address = 351;
    aq[2]._address = 1300;
    aq[3]._address = -1;
    aq[4]._address = 1499;
}
/*************************************************************/
void InitializeMemTestCase(SlotState& tcs)
{
    tcs.push_back(MemState(0, OCCUPIED, 2, 111));
    tcs.push_back(MemState(1, OCCUPIED, 1, 300));
    tcs.push_back(MemState(2, FREE, -1, 0));
    tcs.push_back(MemState(3, OCCUPIED, 4, 68));
    tcs.push_back(MemState(4, FREE, -1, 0));
    tcs.push_back(MemState(5, OCCUPIED, 3, 31));
}
/*************************************************************/
int main(int argc, char* argv[])
{
	ProcessQueue q, opq, tcpq; // output_process_q and testcase_pq
	RequestQueue r, aoq, tcaq;
	SlotState sq, tcsq;

	cout << "MFT memory management demonstration\n\n";
	Initialize(q, r);
	InitializeProcessTestCase(q, tcpq);
	MFTAllocate(q, opq);
	if (tcpq == opq) cout << "Process test case is correct" << endl;
	else cout << "Process test case is incorrect" << endl;

	cout << "\nMemory state\n";
	InitializeMemTestCase(tcsq);
	viewMemState(sq);
	if (sq == tcsq) cout << "Memory test case is correct" << endl;
	else cout << "Memory test case is incorrect" << endl;

	MemoryReference(r, aoq);
	InitializeRefTestCase(r, tcaq);
	if (tcaq == aoq) cout << "Reference test case is correct" << endl;
	else cout << "Reference test case is incorrect" << endl;
	return 0;
}