#include "common.h"
/*************************************************************/
void initialize(queue& q)
{
	q.clear();
	q.push_back(CTask(98, 23)); //Process ID=0
	q.push_back(CTask(20, 84));  //Process ID=1
	q.push_back(CTask(26, 82));  //Process ID=2
	q.push_back(CTask(17, 32));  //Process ID=3
	q.push_back(CTask(41, 59));  //Process ID=4
	q.push_back(CTask(90, 88));  //Process ID=5
	q.push_back(CTask(61, 57));  //Process ID=6
	q.push_back(CTask(41, 2));  //Process ID=7
	q.push_back(CTask(64, 45));  //Process ID=8
	q.push_back(CTask(84, 86));  //Process ID=9
}
/*************************************************************/
void initialize_TestCase(Gantt& q)
{
	q.clear();
	q.push_back(CPUBurst(3, 24));
	q.push_back(CPUBurst(7, 2));
	q.push_back(CPUBurst(3, 8));
	q.push_back(CPUBurst(4, 13));
	q.push_back(CPUBurst(8, 45));
	q.push_back(CPUBurst(0, 23));
	q.push_back(CPUBurst(4, 46));
	q.push_back(CPUBurst(6, 57));
	q.push_back(CPUBurst(2, 82));
	q.push_back(CPUBurst(1, 84));
	q.push_back(CPUBurst(9, 86));
	q.push_back(CPUBurst(5, 88));
}
/*************************************************************/
int main(int argc, char* argv[])
{
	queue q;
	Gantt running_chart, test_case;
	initialize(q);
	initialize_TestCase(test_case);
	cout << "Preemptive SJF CPU scheduler!\n\n";
	SRTF(q, running_chart);
	if (running_chart == test_case) cout << "Correct!" << endl;
	else cout << "Incorrect!" << endl;
	return 0;
}
/*************************************************************/




