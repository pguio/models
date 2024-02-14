%      [height,bi,dimo]=igrf95(glat,glong,height,year)
%
%      International Geomagnetic Reference Field (1995)
%
%     input:
%        glat - geodetic latitude(deg)
%        glong - geodetic longitude(deg)
%        height - vector height (km)
%        year - decimal year
%     output:
%        bi(:,1) - magnitude of B (gauss)
%        bi(:,2) - B-east (gauss)
%        bi(:,3) - B-north (gauss)
%        bi(:,4) - B-down (gauss)
%        bi(:,5) - Dipole (deg)
%        bi(:,6) - Declination (deg)
%        bi(:,7) - L-value
%        bi(:,8) - B0 field strength at the magnetic equator
%        bi(:,9) - icode
%                        = 1 L and B0  corrected
%                        = 2 wrong
%                        = 3 approx.
%        dimo -  Dipol moment (gauss)
%
