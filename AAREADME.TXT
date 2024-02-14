Directory Title:	Models Distribution and Staging Directory
Last Updated:		19-MAY-1998
Principal Contact:	Dieter Bilitza, bilitza@nssdca.gsfc.nasa.gov
				Telephone: (301) 286-0190
			    	FAX: (301) 286-1771
Magnetic Field Contact:  Natasha Papitashvili, natasha@nssdca.gsfc.nasa.gov
				Telephone: (301) 286-3451
Organization:		National Space Science Data Center, Code 633
			NASA/Goddard Space Flight Center, Greenbelt, MD 20771
Computer System:	NSSDC Computing Facility

Access procedure:	The files can be retrieved by anonymous ftp. On-the-
fly compression can be used to compress the file(s) before transmitting them. 
To use this option one has to enter the following command at the ftp prompt:
> get filename.gz (e.g. iris13.for.gz)
This will work with the extension '.Z' as well. The tar option can be
used to retrieve a whole subdirectory:
> get subdir.tar      or   > get subdir.tar.gz   for additional compression.
To unzip and untar these files you have to use the following commands:
> gunzip subdir.tar.gz      and then     > tar -xf subdir.tar 

Brief Description: 	The purpose of this directory is to allow users access 
to NSSDC's holding of solar-terrestrial models. Currently posted models and 
their subdirectories are:

/ionospheric/
	/iri/ International Reference Ionosphere (IRI) 1990 and 1995 models
	/chiu/ Chiu Ionospheric Model 1975
	/photoelectron_code/ Richards's photoelectron model PESIMP 1992 
	/convection_Efield/Heppner-Maynard-Rich model
	/auroral_oval/Holzworth&Meng parameterization of Feldstein Ovals
/atmospheric/
	/cira/ COSPAR International Reference Atmosphere 1986 (binary & ASCII)
	/msis/ Mass Spectrometer Incoherent Scatter atmos. mod. 1986 and 1990E
	/hwm93/ Horizontal Wind Model 1993
	/h_exos/ Hodges's exospheric H model, 1994
	/met/ MSFC Engineering Thermosphere Model, 1988
/magnetospheric/
	/geo_cgm/ Coordinate conversion: Geographic <-> Corrected Geomagnetic 
	/igrf/ International Geomagnetic Reference Field 1945-1995, Version 1995
	/gsfc/ GSFC 12/83 and 11/87 geomagnetic field model 
	/mgst/ Magsat (6/80) and (4/81) geomagnetic field models 
    	/tsyganenko87/ Tsyganenko mag. field model incl. ext. sources, 1987
	/tsyganneko/ Tsyganenko 1989c and 1996 models, Geopack
	/jensen_cain/ Jensen & Cain 1962 magnetic field model 
/radiation_belt/
	/radbelt/ AE-8/AP-8 Radiation Belt models, 1990
	/shieldose/ Selzer, Space-shielding radiation dose computation, 1980
	/sofip/ SOFIP program for orbit integrated fluxes, 1980
	/radmodls/ Vampola's computation of orbit integrated fluxes, 1994
/solar/
    	/euv/
		/euvac/ Richards's solar EUV flux model, 1995
		/ae-euv/ EUV74113, Hintegger's AE-based solar EUV ref. spectra 
	 	/tobiska/ Solar EUV Flux model, Tobiska, 1994
	/protons/
		/solpro/ Solar Proton Fluences model, 1975 
/planets/
	/venus/
		/pv-atmos/ Venus Ref. Atmosphere, 1983 (Pioneer Venus Orbiter) 
		/pv-ionos/ Venus Ref. Ionosphere, 1984 (Pioneer Venus Orbiter) 

The subdirectories contain all source code, coefficients, and text files 
necessary to successfully use these models. The international standard models 
IRI, MSIS, IGRF, and also RADBELT, TSYGANENKO and GEO_CGM can be accessed and 
run on  the WorldWideWeb at
http://nssdc.gsfc.nasa.gov/space/model/models_home.html

UPDATE HISTORY:

02/15/94: Al Hedin's horizontal wind model was updated to 1993 version. 
03/04/94: Selzer's 1980 SHIELDOSE code (2 files) is now on line.
10/14/94: Hinteregger's EUV reference spectra online.
10/24/94: Richards's photoelectron code for aeronomical computation
03/10/95: AP8MAX/MIN instead of AP8MAC/MIC in RADBELT
03/28/95: IRI MS-DOS executable available in directory IRI_PC
06/07/95: GEO_CGM (geo -> geom corr) updated
07/12/95: Richards's EUVAC model for solar EUV flux online
07/13/95: Hodges's exospheric hydrogen model online
07/13/95: MSFC engineering thermosphere models online
08/08/95: IGRF model updated to year 2000.
11/29/95: IGRF95 coefficient set corrected.
12/23/95: Newest version of IRI in directory IRI
01/31/96: New version of GEO__CGM
05/30/96: PV ionospheric and atmospheric models online
09/10/97: GUZIK version added to SOFIP directory
02/23/99: Heppner-Maynard-Rich convection Electric Field model added
02/26/99: Holzworth-Meng Parameterization of Feldstein Auroral Ovals added
