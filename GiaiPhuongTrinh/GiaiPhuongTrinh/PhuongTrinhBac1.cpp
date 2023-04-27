// ax+b=0
//
int GiaiPTBac1(double a, double b, double* x)
{
	if (a == 0) {
		if (b == 0) return 0; // vo so nghiem
		else return -1; // vo nghiem
	}
	else {
		*x = -b / a;
		return 1;
	}
}