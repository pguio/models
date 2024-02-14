
#include <stdio.h>
#include <math.h>

typedef float real;

void initize_();
void feldcof_(real * year, real * dimo);
void feldg_(real * glat, real * glong, real * height,
            real * bn, real * be, real * bd, real * b);
void shellg_(real *glat, real *glong, real *height,
             real *dimo, real *xl, int *icode, real *bab1);
void findb0_(real *zero5 , real * bdel, int *val, real * beq, real *rro);

//umr=atan(1.)*4./180.;

int main()
{

	real glat=45.1;
	real glong=293.1;
	real height[10]={100.,200.,300.,400.,500.,600.,700.,800.,900.,1000.};
	real year=1985.5;
	real dimo, b[10], bn[10],be[10],bd[10];
	real dip[10], dec[10], l[10], c[10];
	real xl[10], bab1, bequ[10], b0, bdel, zero5=.05, beq, rro;
	int val;
	int icode[10];

	double umr;
	int i, j;

	umr=M_PI/180.;

	initize_();

	feldcof_(&year, &dimo);

	for (i=0;i<10;i++) {
		feldg_(&glat, &glong, height+i, bn+i, be+i, bd+i, b+i);
		shellg_(&glat, &glong, height+i, &dimo, xl+i, icode+i, &b0);
		dip[i]=asin((double)bd[i]/b[i])/umr;
		dec[i]=asin((double)be[i]/sqrt((double)be[i]*be[i]+bn[i]*bn[i]))/umr;
		bequ[i]=dimo/(xl[i]*xl[i]*xl[i]);
		if (icode[i]==1) {
			bdel=1e-3;
			findb0_(&zero5, &bdel, &val, &beq, &rro);
			if (val) bequ[i]=beq;
		}
	}

	printf("%.4f %.4f \n", dimo, b0);
	for (i=0; i<10; i++)
		printf("%4.0f %8.5f %8.5f %8.5f %8.5f %8.5f %8.5f %8.5f %8.5f %d\n",
		       height[i], bequ[i], bn[i], be[i], bd[i], b[i],
		       dip[i], dec[i], xl[i], icode[i]);


	return 0;
}
