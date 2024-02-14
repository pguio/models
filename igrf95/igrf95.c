
#include <stdio.h>
#include <math.h>
#include <mex.h>

typedef float real;

void initize_();
void feldcof_(real * year, real * dimo);
void feldg_(real * glat, real * glong, real * height,
            real * bn, real * be, real * bd, real * b);
void shellg_(real *glat, real *glong, real *height,
             real *dimo, real *xl, int *icode, real *bab1);
void findb0_(real *zero5 , real * bdel, int *val, real * beq, real *rro);

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{

	real glat;
	real glong;
	real *height;
	real year;
	real dimo, *b, *bn, *be, *bd;
	real *dip, *dec;
	real *xl, bab1, *bequ, b0, bdel, zero5=.05, beq, rro;
	int val;
	int *icode;

	double umr, *ptr, *ptrb;
	int i, j, nheight;

#if 0
	umr=atan(1.)*4./180.;
#endif
	umr=M_PI/180.;

	initize_();

	if ( nrhs != 4 ) {
		mexErrMsgTxt(" igrf95 : requires 4 input arguments.");
	}

	glat=(real)*mxGetPr(prhs[0]); /* geodetic lat */
	glong=(real)*mxGetPr(prhs[1]); /* geodetic long */

	if (mxGetM(prhs[2])!=1 && mxGetN(prhs[2])!=1) {
		mexErrMsgTxt("  igrf95 : HEIGHT cannot be a matrix");
	}
	nheight=mxGetM(prhs[2])*mxGetN(prhs[2]);
	height=(real *)mxCalloc(nheight, sizeof(real) ); /* height */
	for (i=0, ptr=mxGetPr(prhs[2]); i<nheight; i++) height[i]=(real)ptr[i];

	b=(real *)mxCalloc(nheight, sizeof(real) );
	be=(real *)mxCalloc(nheight, sizeof(real) );
	bn=(real *)mxCalloc(nheight, sizeof(real) );
	bd=(real *)mxCalloc(nheight, sizeof(real) );
	dip=(real *)mxCalloc(nheight, sizeof(real) );
	dec=(real *)mxCalloc(nheight, sizeof(real) );
	xl=(real *)mxCalloc(nheight, sizeof(real) );
	bequ=(real *)mxCalloc(nheight, sizeof(real) );
	icode=(int *)mxCalloc(nheight, sizeof(int) );

	year=(real)*mxGetPr(prhs[3]); /* decimal year */

#if 1
	printf("glat= %+3.1f glong= %+3.1f year=%4.1f\n",glat,glong,year);
#endif

	feldcof_(&year, &dimo);

	for (i=0;i<nheight;i++) {
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

	plhs[0]=mxCreateDoubleMatrix(nheight,1,mxREAL);
	plhs[1]=mxCreateDoubleMatrix(nheight,9,mxREAL);
	plhs[2]=mxCreateDoubleMatrix(1,1,mxREAL);

	for (i=0, ptr=mxGetPr(plhs[0]), ptrb=mxGetPr(plhs[1]) ;i<nheight;i++) {
		ptr[i]=height[i];
		ptrb[i+0*nheight]=(double)b[i];
		ptrb[i+1*nheight]=(double)be[i];
		ptrb[i+2*nheight]=(double)bn[i];
		ptrb[i+3*nheight]=(double)bd[i];
		ptrb[i+4*nheight]=(double)dip[i];
		ptrb[i+5*nheight]=(double)dec[i];
		ptrb[i+6*nheight]=(double)xl[i];
		ptrb[i+7*nheight]=(double)bequ[i];
		ptrb[i+8*nheight]=(double)icode[i];
	}

	*mxGetPr(plhs[2])=dimo;

#if 0
	printf("%.4f %.4f \n", dimo, b0);
	for (i=0; i<nheight; i++)
		printf("%.2f %.4f %.4f %.4f %.4f %.4f %.2f %.2f %.2f %d\n",
		       height[i], bequ[i], bn[i], be[i], bd[i], b[i],
		       dip[i], dec[i], xl[i], icode[i]);
#endif

	mxFree(height);
	mxFree(b);
	mxFree(be);
	mxFree(bn);
	mxFree(bd);
	mxFree(dip);
	mxFree(dec);
	mxFree(xl);
	mxFree(bequ);
	mxFree(icode);


}
