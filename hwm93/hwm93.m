%  [ALT,W]=hwm93(IYD,SEC,ALT,GLAT,GLONG,STL,F107A,F107,AP)
%
%		Horizontal wind model HWM93 covering all altitude regions
%   A. E. HEDIN  (1/25/93) (4/9/93)
%   Calling argument list made similar to GTS5 subroutine for
%   MSIS-86 density model and GWS4 for thermospheric winds.
%        IYD - YEAR AND DAY AS YYDDD
%        SEC - UT(SEC)  (Not important in lower atmosphere)
%        ALT(:) - ALTITUDE(KM)
%        GLAT - GEODETIC LATITUDE(DEG)
%        GLONG - GEODETIC LONGITUDE(DEG)
%        STL - LOCAL APPARENT SOLAR TIME(HRS)
%        F107A - 3 MONTH AVERAGE OF F10.7 FLUX (Use 150 in lower atmos.)
%        F107 - DAILY F10.7 FLUX FOR PREVIOUS DAY ( " )
%        AP - Two element array with
%             AP(1) = MAGNETIC INDEX(DAILY) (use 4 in lower atmos.)
%             AP(2)=CURRENT 3HR ap INDEX (used only when SW(9)=-1.)
%        W(:,1) = MERIDIONAL (m/sec + Northward)
%        W(:,2) = ZONAL (m/sec + Eastward)


