
#include <stdio.h>
#include <math.h>
#include <mex.h>

typedef float real;

void gws5_(int *iyd, real *sec, real *alt, real *glat, real *glong,
           real *stl, real *f107a, real*f107, real *ap, real *w);

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	int iyd;
	real sec, stl;
	real *alt, glat, glong;
	real f107a, f107;
	real ap[2];
	real w[2];
	real *ptr;
	double *dptr;
	int i, j, nalt;

	if ( nrhs != 9 ) {
		mexErrMsgTxt(" gws5 : requires 9 input arguments.");
	}

	/************************************************************************
	 *
	 *  iyd   YEAR AND DAY AS YYDDD
	 *  sec   UT(SEC)  (Not important in lower atmosphere)
	 *  alt   ALTITUDE(KM)
	 *  glat  GEODETIC LATITUDE(DEG)
	 *  glong GEODETIC LONGITUDE(DEG)
	 *  stl   LOCAL APPARENT SOLAR TIME(HRS)
	 *  f107  3 MONTH AVERAGE OF F10.7 FLUX (Use 150 in lower atmos.)
	 *  f107a DAILY F10.7 FLUX FOR PREVIOUS DAY (")
	 *  ap[2] Two element array with
	 *        ap[0] = MAGNETIC INDEX(DAILY) (use 4 in lower atmos.)
	 *        ap[1]=CURRENT 3HR ap INDEX (used only when SW(9)=-1.)
	 *
	 ************************************************************************/

	iyd=(int)*mxGetPr(prhs[0]);
	sec=(real)*mxGetPr(prhs[1]);
	alt=(real *)mxGetPr(prhs[2]);
	glat=(real)*mxGetPr(prhs[3]);
	glong=(real)*mxGetPr(prhs[4]);
	stl=(real)*mxGetPr(prhs[5]);
	f107=(real)*mxGetPr(prhs[7]);
	f107a=(real)*mxGetPr(prhs[6]);
	dptr=mxGetPr(prhs[8]);
	ap[0]=(real)dptr[0];
	ap[1]=(real)dptr[1];

	if (mxGetN(prhs[2]) != 1 && mxGetM(prhs[2]) != 1) {
		mexErrMsgTxt(" hmw93 : ALT cannot be a matrix.");
	}
	/* # of heights to calculate */
	nalt=mxGetM(prhs[2])*mxGetN(prhs[2]);

	alt=(real *)mxCalloc(nalt, sizeof(real));
	for (i=0, dptr=mxGetPr(prhs[2]); i<nalt; i++) alt[i]=(real)dptr[i];

	plhs[0] = mxCreateDoubleMatrix(nalt,1, mxREAL); /* create heighs array */
	for (i=0, dptr=mxGetPr(plhs[0]); i<nalt; i++) dptr[i]=(double)alt[i];

	plhs[1] = mxCreateDoubleMatrix(nalt, 2, mxREAL); /* create Wind array */

#if 1
	printf("iyd=%4.d sec=%6.f ", iyd, sec);
	printf("glat=%+3.f glong=%+3.f stl=%3.f ", glat, glong, stl);
	printf("f107a=%3.0f f107=%3.0f ap=%2.0f, %2.0f\n",
	       f107a, f107, ap[0], ap[1]);
#endif
	for (i=0, dptr=mxGetPr(plhs[1]); i<nalt; i++) {
		gws5_(&iyd, &sec, alt+i, &glat, &glong, &stl, &f107a, &f107, ap, w);
		for (j=0; j<2; j++) {
			dptr[i+j*nalt]=(double)w[j];
		}
#if 0
		printf("alt=%4.f w=%+10.5f, %+10.5f\n", alt[i], w[0], w[1]);
#endif
	}
	mxFree(alt);
}


