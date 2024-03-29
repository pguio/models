=========================================================================
National Space Science Data Center      Data set  MG-14G         Aug 1995 
=========================================================================

NAME:        International Geomagnetic Reference Field (1995)

SOURCE:	     R.A. Langel, NASA, GSFC, Code 921, Greenbelt, MD 20771
             langel@geomag.gsfc.nasa.gov
	     C. Barton, Australian Geological Survey Organization,
	     GPO Box 378, Canberra, ACT, 2601, Australia
	     cbarton@agso.gov.au

NSSDC CONTACT: D. Bilitza, GSFC/NSSDC code 633/Raytheon, Greenbelt,
             MD 20771, Fax. (301) 286-1771
	     Internet:	BILITZA@NSSDCA.GSFC.NASA.GOV

CONTENT:     17 files					      *.*   blocks
	     FORTRAN source code:  
             (1) main program				 BILCAL.FOR   21
             (2) subroutines, functions                 SHELLIG.FOR   84
	     geomagnetic field model coefficients:
             (3) definitive coefficients for 1945	 DGRF45.DAT    4
             (4) definitive coefficients for 1950	 DGRF50.DAT    4
             (5) definitive coefficients for 1955	 DGRF55.DAT    4
             (6) definitive coefficients for 1960	 DGRF60.DAT    4
             (7) definitive coefficients for 1965	 DGRF65.DAT    4
             (8) definitive coefficients for 1970	 DGRF70.DAT    4
             (9) definitive coefficients for 1975	 DGRF75.DAT    4
            (10) definitive coefficients for 1980	 DGRF80.DAT    4
            (11) definitive coefficients for 1985	 DGRF85.DAT    4
            (12) definitive coefficients for 1990	 DGRF90.DAT    4
            (13) 	    coefficients for 1995	 IGRF95.DAT    4
            (14) extrapol. coefficients for 1995-2000    IGRF95S.DAT    3
             demonstration programs:
	    (15) BILCAL user manual with examples        BILCAL.LOG   28
            (16) this file                             AAREADME.DOC
	    (17) IGRF subroutine			igrf_sub.for

BRIEF DESCRIPTION:

The International Geomagnetic Reference Field (IGRF) model is the 
empirical representation of the Earth's magnetic field recommended for 
scientific use by the International Association of Geomagnetism and 
Aeronomy (IAGA). The IGRF model represents the main (core) field without 
external sources. They employ the usual spherical harmonics expansion
of the scalar potential in geocentric coordinates. The IGRF model
coefficients are based on all available data sources including geomagnetic 
measurements from observatories, ships, aircrafts and satellites. 

The IGRF-95 model consists of coefficient sets for the epochs 1945 to 1995
in steps of 5 years and the first time derivatives of the coefficients for 
the time period 1995 to 2000. During the 5-year intervals between consecutive 
models, linear interpolation is recommended. The IGRF coefficients for 1945, 
1950, .. 1985, 1990 are definitive coefficient sets, meaning that no further 
revisions are anticipated. 

In combination with the IGRF coefficient sets different subroutines have 
been used to determine the components of the magnetic field vector and the 
L-value at a given location. The NSSDC version uses the subroutines FELDG 
(magnetic field vector) and SHELLG (L shell) developed by G. Kluge at the 
European Space Operations Center (ESOC). His use of inverse cartesian co-
ordinates simplifies the computation. The IGRF subroutines were developed 
by A. Zunde of the U.S. Geological Survey (USGS). 

The program BILCAL produces tables of the geomagnetic field strength, vector 
components (B-abs., B-north, B-east, B-down, declination, inclination), 
equatorial/minimum field strength (B0), dipole moment, and L-value  in  
latitude, longitude (geodetic), altitude, or year (decimal). The 
IGRF/FELDG/SHELLG software package is available from NSSDC on tape, or on 
floppy disk for use on IBM compatible Personal Computers.


REFERENCES:

Peddie, N. W., International Geomagnetic Reference Field: the third
   generation, J. Geomagn. Geoelectr. 34, 309-326, 1982.

Kluge, G., Direct computation of the magnetic shell parameter,
   Computer Phys. Communications 3, 31-35, 1972.

International Geomagnetic Reference Field Revision 1987, J. Geomag.
   Geoelectr. 39, 773-779, 1987   and    EOS Trans. 69, 559, 1988

Langel, R. A., D. R. Barraclough, D. J. Kerridge, V. P. Golovkov,
   T. J. Sabaka, and R. H. Estes, Definitive IGRF models for 1945,
   1950, 1955, and 1960, J. Geomag. Geoelectr. 40, 645-702, 1988

Langel, R. A., International Geomagnetic Reference Field, 1991 
   Revision, J. Geomag. Geoelectr. 43, 1007-1012, 1991

Barton, C.E., Revision of International Geomagnetic Reference Field
   Released, EOS Trans. 77, #16, April 16, 1996.

Barton, C.E., International Geomagnetic Reference Field: The Seventh
   Generation, J. Geom. Geoelectr. 49, 123-148, 1997.

=========================================================================
National Space Science Data Center      Data set  MG-14G         Aug 1995 
=========================================================================
