#include "common.h"
/*************************************************************/
void initialize(queue& q)
{
	q.clear();
	q.push_back(CTask(0, 24)); //Process ID=0
	q.push_back(CTask(4, 7));  //Process ID=1
	q.push_back(CTask(7, 3));  //Process ID=2
}
/*************************************************************/
void initialize_TestCase(Gantt& q)
{
	q.clear();
	q.push_back(CPUBurst(0, 4));
	q.push_back(CPUBurst(1, 3));
	q.push_back(CPUBurst(2, 3));
	q.push_back(CPUBurst(1, 4));
	q.push_back(CPUBurst(0, 20));
}
/*************************************************************/
int main(int argc, char* argv[])
{
	queue q;
	Gantt running_chart,test_case;
	initialize(q);
	initialize_TestCase(test_case);
	cout << "Preemptive SJF CPU scheduler!\n\n";
	SRTF(q,running_chart);
	if(running_chart==test_case) cout << "Correct!" <<endl;
	else cout << "Incorrect!" <<endl;
	return 0;
}
/*************************************************************/




