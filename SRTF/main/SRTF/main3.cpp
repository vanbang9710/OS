#include "common.h"
//Testcase1:
/*************************************************************/
void initialize(queue& q)
{
	q.clear();
	q.push_back(CTask(0, 61)); //Process ID=0
	q.push_back(CTask(5, 72));  //Process ID=1
	q.push_back(CTask(10, 23));  //Process ID=2
	q.push_back(CTask(2, 16));  //Process ID=3
	q.push_back(CTask(6, 10));  //Process ID=4
}
/*************************************************************/
void initialize_TestCase(Gantt& q)
{
	q.clear();
	q.push_back(CPUBurst(0, 2));
	q.push_back(CPUBurst(3, 4));
	q.push_back(CPUBurst(4, 10));
	q.push_back(CPUBurst(3, 12));
	q.push_back(CPUBurst(2, 23));
	q.push_back(CPUBurst(0, 59));
	q.push_back(CPUBurst(1, 72));
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




