
#include <stdio.h>
#include <math.h>
#include <mex.h>

typedef float real;

void gtd6_(int *iday, real *ut, real *alt, real *glat, real *glong, real *lst,
           real *f107a, real *f107, real *ap, int *mass, real *d, real*t);
void meter6_(int *mks);
void tselec_(real *sw);

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{

	int iday;
	real ut;
	real *alt;
	real glat;
	real glong;
	real lst;
	real f107a;
	real f107;
	real ap[7];
	int mass=48;
	real d[8], t[2];
	int mks;
	real sw[25];

	int i, j, nalt;
	double *ptr, *ptrt;


	if ( nrhs != 10 ) {
		mexErrMsgTxt(" msise90 : requires 10 input arguments.");
	}

	iday=(int)*mxGetPr(prhs[0]); /*  year and day (yyddd) */
	ut=(real)*mxGetPr(prhs[1]); /* ut (sec) */

	if (mxGetM(prhs[2])!=1 && mxGetN(prhs[2])!=1) {
		mexErrMsgTxt("  msise90 : ALT cannot be a matrix");
	}
	nalt=mxGetM(prhs[2])*mxGetN(prhs[2]);
	alt=(real *)mxCalloc(nalt, sizeof(real) ); /* alt */
	for (i=0, ptr=(double *)mxGetPr(prhs[2]); i<nalt; i++)
		alt[i]=(real)ptr[i];

	glat=(real)*mxGetPr(prhs[3]); /* geodetic lat */
	glong=(real)*mxGetPr(prhs[4]); /* geodetic long */
	lst=(real)*mxGetPr(prhs[5]); /* local apparent solar time (hours) */

	f107a=(real)*mxGetPr(prhs[6]); /* 3 months average flux at 10.7 cm */
	f107=(real)*mxGetPr(prhs[7]); /* daily flux at 10.7 cm */

	ap[0]=(real)*mxGetPr(prhs[8]); /* magnetic index */
	for (i=1;i<7;i++) ap[i]=0.;

	mass=(int)*mxGetPr(prhs[9]); /* mass number mass 0 temperature, mass 48 for all */

#if 1
	printf("iday=%3.d ut=%4.f glat=%+4.1f glong=%+4.1f lst=%4.1f\n",
	       iday, ut, glat, glong, lst);
	printf("f107a=%4.1f f107=%4.1f ap=%.1f mass=%d\n",f107a, f107, ap[0], mass);
#endif

	for (i=0; i<25; i++) sw[i]=1.; /* default setting */

	tselec_(sw);

	mks=1;
	meter6_(&mks); /* set mks */

	plhs[0] = mxCreateDoubleMatrix(nalt,1, mxREAL); /* create alts array */
	for (i=0, ptr=mxGetPr(plhs[0]); i<nalt; i++) ptr[i]=(double)alt[i];

	plhs[1] = mxCreateDoubleMatrix(nalt,8, mxREAL); /* create density array */

	plhs[2] = mxCreateDoubleMatrix(nalt,2, mxREAL); /* create temperature array */

	for (i=0, ptr=mxGetPr(plhs[1]), ptrt=mxGetPr(plhs[2]); i<nalt; i++) {
		gtd6_(&iday, &ut, alt+i, &glat, &glong, &lst, &f107a, &f107, ap, &mass, d, t);
		for (j=0; j<8; j++) ptr[i+j*nalt]=d[j];
		for (j=0; j<2; j++) ptrt[i+j*nalt]=t[j];
	}

#if 0
	for (i=0, ptr=mxGetPr(plhs[1]), ptrt=mxGetPr(plhs[2]); i<nalt; i++) {
		printf("%.0f %.2e %.2e  %.2e %.2e %.2e %.2e %.2e %.2e %.2e %.2e\n",
		       alt[i], d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7], t[0], t[2]);
	}
#endif


	mxFree(alt);

}
