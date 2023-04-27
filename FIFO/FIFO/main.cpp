#include "common.h"
/*************************************************************/
void initializeTestCase(repqueue &tc)
{
	tc.push_back(PageRep('1',1,-1));
	tc.push_back(PageRep('2',1,-1));
	tc.push_back(PageRep('3',1,-1));
	tc.push_back(PageRep('4',1,-1));
	tc.push_back(PageRep('1',0,-1));
	tc.push_back(PageRep('2',0,-1));
	tc.push_back(PageRep('5',2,'1'));
	tc.push_back(PageRep('1',2,'2'));
	tc.push_back(PageRep('2',2,'3'));
	tc.push_back(PageRep('3',2,'4'));
	tc.push_back(PageRep('4',2,'5'));
	tc.push_back(PageRep('5',2,'1'));
}
/*************************************************************/

int main(int argc, char* argv[])
{
	repqueue wt,tc;
	string refstr=string("123412512345");

	printf("FIFO Page replacement!\n");	
	initializeTestCase(tc);
	FIFO(refstr,4,wt);

	if(tc==wt)cout << "Correct" <<endl;
	else  cout << "Incorrect" <<endl;

	return 0;
	
}
/*************************************************************/
