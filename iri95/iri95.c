
#include <stdio.h>
#include <math.h>
#include <mex.h>

typedef float real;

void iris13_(int *jf, int *jmag, real *alati, real *along, int *iyyyy,
             int *mmdd, real *dhour, real *heibeg, real *heiend, real *heistp,
             real *outf, real *oarr);

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	int jmag;
	int jf[20];
	real alati, along;
	int iyyyy;
	int mmdd;
	real dhour;
	real heibeg, heiend, heistp=1.;
	real outf[11*100];
	real oarr[38];
	int i, j, n;
	real *heis;
	int nheis;
	double *ptr;

	if ( nrhs != 9 ) mexErrMsgTxt(" iri13 : requires 9 input arguments.");

	if (mxGetN(prhs[0]) != 1 && mxGetM(prhs[0]) != 1)
		mexErrMsgTxt(" iri13 : JF cannot be a matrix.");

	n=mxGetM(prhs[0])*mxGetN(prhs[0]);
	if (n!=20) mexErrMsgTxt(" iri13 : JF has length 20.");
	for (i=0, ptr=mxGetPr(prhs[0]); i<n; i++) jf[i]=(int)ptr[i];

	jmag=(int)*mxGetPr(prhs[1]); /* geodetic (geomagnetic) latitude and longitude */
	alati=(real)*mxGetPr(prhs[2]); /* latitude north */
	along=(real)*mxGetPr(prhs[3]); /* longitude east */

	iyyyy=(int)*mxGetPr(prhs[4]);  /* iyyyy */
	mmdd=(int)*mxGetPr(prhs[5]); /* date (>0), day of year (<0) */
	dhour=(real)*mxGetPr(prhs[6]); /* local time (>0), universal time+25 (<0) */

#if 1
	printf("jmag=%d alati=%.1f along=%.1f iyyyy=%4.d mmdd=%4.d dhour=%4.2f\n",
			jmag, alati, along, iyyyy, mmdd, dhour);
#endif

	if (mxGetN(prhs[7]) != 1 && mxGetM(prhs[7]) != 1)
		mexErrMsgTxt(" iri13 : HEIS cannot be a matrix.");

	nheis=mxGetM(prhs[7])*mxGetN(prhs[7]); /* # of heights to calculate */
	heis=(real *)mxCalloc(nheis, sizeof(real));
	for (i=0, ptr=mxGetPr(prhs[7]); i<nheis; i++) heis[i]=(real)ptr[i];

	if (mxGetN(prhs[8]) != 1 && mxGetM(prhs[8]) != 1)
		mexErrMsgTxt(" iri13 : OARR cannot be a matrix.");

	for (i=0, ptr=mxGetPr(prhs[8]); i<mxGetN(prhs[8])*mxGetM(prhs[8]); i++)
		oarr[i]=(real)ptr[i];

	/* Output */
	plhs[0] = mxCreateDoubleMatrix(nheis,1, mxREAL); /* create height array */
	for (i=0, ptr=mxGetPr(plhs[0]); i<nheis; i++) ptr[i]=(double)heis[i];
	plhs[1] = mxCreateDoubleMatrix(nheis, 11, mxREAL); /* create outf array */
	plhs[2] = mxCreateDoubleMatrix(1, 38, mxREAL); /* create oarr array */

	for (i=0, ptr=mxGetPr(plhs[1]); i<nheis; i++) {

		heibeg=heis[i];
		heistp=1.;
		heiend=heibeg;
#if 0
		printf("heibeg %f heistp %f heiend %f\n", heibeg, heistp, heiend);
		for (j=0; j<20; j++) printf("%d ", jf[j]);
		printf("\n");
		printf("jmag %d\n", jmag);
		printf("alati %f\n", alati);
		printf("along %f\n", along);
		printf("iyyy %d\n", iyyyy);
		printf("mmdd %d\n", mmdd);
		printf("dhour %f\n", dhour);
#endif

		iris13_(jf, &jmag, &alati, &along, &iyyyy, &mmdd, &dhour,
		        &heibeg, &heiend, &heistp, outf, oarr);
#if 0
		printf("%4.0f %.2e %4.0f %4.0f %4.0f %2.0f %2.0f %2.0f %2.0f %2.0f\n",
		       heibeg, outf[0],outf[1], outf[2], outf[3], outf[4],
		       outf[5], outf[6],outf[7],outf[8]);
#endif

		for (j=0; j<11; j++) ptr[i+j*nheis]=(double)outf[j];
	}

	for (i=0, ptr=mxGetPr(plhs[2]); i<38; i++) ptr[i]=(double)oarr[i];

	mxFree(heis);

#if 0
	for (i=0;i<nheis;i++)
		printf("%.4e %.4e %.4e %.4e %.4e %.4e\n",
		       heis[i], outf[i*11],outf[i*11+1],
		       outf[i*11+2], outf[i*11+3], outf[i*11+4]);
	printf("\n");
	printf("nmf2/m-3 : %.4e hmf2/m-3 : %.4e\n", oarr[0], oarr[1]);
	printf("nmf1/m-3 : %.4e hmf1/m-3 : %.4e\n", oarr[2], oarr[3]);
	printf("nme/m-3  : %.4e hme/m-3  : %.4e\n", oarr[4], oarr[5]);
	printf("nmd/m-3  : %.4e hmd/m-3  : %.4e\n", oarr[6], oarr[7]);
	printf("hhalf/km : %.4e b0/km    : %.4e\n", oarr[8], oarr[9]);
	printf("valley-base/m-3 : %.4e valley-top/m-3  : %.4e\n",
	       oarr[10],oarr[11]);
	printf("te-peak/K : %.4e te-peak height/km\n", oarr[12], oarr[13]);
	printf("te-mod(300km)/K : %.4e te-mod(400km)/K : %.4e\n",oarr[14],oarr[15]);
	printf("te-mod(600km)/K : %.4e te-mod(1400km)/K : %.4e\n",
	       oarr[16],oarr[17]);
	printf("te-mod(3000km)/K : %.4e te(120km)=tn=ti : %.4e\n",
	       oarr[18],oarr[19]);
	printf("ti-mod(430km)/K : %.4e x/km where te=ti : %.4e\n",
	       oarr[20],oarr[21]);
	printf("sol zenith ang/deg : %.4e sun decl/deg : %.4e\n",oarr[22],oarr[23]);
	printf("dip/deg : %.4e dip latitude/deg : %.4e\n", oarr[24], oarr[25]);
	printf("modified dip lat./deg : %.4e dela : %.4e\n", oarr[26], oarr[27]);
	printf("sunrise/dec.hours : %.4e sunset/dec.hours : %.4e\n",
	       oarr[28],oarr[29]);
	printf("iseason (1=spring) : %.4e nseason (1=northern spring) : %.4e\n",
	       oarr[30], oarr[31]);
#endif

}
