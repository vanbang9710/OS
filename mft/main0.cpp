#include "common.h"

vector<MemSlot> gTable;

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