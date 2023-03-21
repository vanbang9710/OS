#include "common.h"
/*************************************************************/
void InitializeResourceRequest(SystemInfo &info)
{

	//Allocation
	info.Allocation[0][0]=0;
	info.Allocation[0][1]=1;
	info.Allocation[0][2]=0;
	
	info.Allocation[1][0]=3;
	info.Allocation[1][1]=0;
	info.Allocation[1][2]=2;
	
	info.Allocation[2][0]=3;
	info.Allocation[2][1]=0;
	info.Allocation[2][2]=2;
	
	info.Allocation[3][0]=2;
	info.Allocation[3][1]=1;
	info.Allocation[3][2]=1;

	info.Allocation[4][0]=0;
	info.Allocation[4][1]=0;
	info.Allocation[4][2]=2;

	
	//Need
	info.Need[0][0]=7;
	info.Need[0][1]=4;
	info.Need[0][2]=3;
	
	info.Need[1][0]=0;
	info.Need[1][1]=2;
	info.Need[1][2]=0;
	
	info.Need[2][0]=6;
	info.Need[2][1]=0;
	info.Need[2][2]=0;
	
	info.Need[3][0]=0;
	info.Need[3][1]=1;
	info.Need[3][2]=1;

	info.Need[4][0]=4;
	info.Need[4][1]=3;
	info.Need[4][2]=1;


	//Available
	info.Available[0]=2;
	info.Available[1]=3;
	info.Available[2]=0;

	//Request
	info.Request[0][0]=0;
	info.Request[0][1]=2;
	info.Request[0][2]=0;
	
	info.Request[1][0]=3;
	info.Request[1][1]=2;
	info.Request[1][2]=0;
	
	info.Request[2][0]=3;
	info.Request[2][1]=3;
	info.Request[2][2]=0;
	
	info.Request[3][0]=0;
	info.Request[3][1]=1;
	info.Request[3][2]=1;

	info.Request[4][0]=3;
	info.Request[4][1]=3;
	info.Request[4][2]=1;
}
/*************************************************************/
/*
	status=
	   0: the request can be granted
	  -1: the request may cause a deadlock if it is granted
	  -2: the request has caused an error since it asks more than its need
	  -3: the request has to wait since its request is not satisfied at the moment          
*/
void initialize_Test_result(queue &test_case){
	test_case.clear();
	test_case.push_back(RequestResp(0,-1));
	test_case.push_back(RequestResp(1,-2));
	test_case.push_back(RequestResp(2,-2));
	test_case.push_back(RequestResp(3,-3));
	test_case.push_back(RequestResp(4,-3));
}
/*************************************************************/
int main(int argc, char* argv[])
{
	SystemInfo info;
	queue test_case, result;
	cout << "Resource Request Simulation Program!\n";
	InitializeResourceRequest(info);
	initialize_Test_result( test_case);
	ResourceRequest(info,result);    
		if(result==test_case) cout << "Correct!\n";
	else cout << "Incorrect!\n";
	return 0;
}
/*************************************************************/

