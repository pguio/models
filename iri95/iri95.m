% [heights outf oarr]=iri95(jf,jmag,alati,along,iyear,mmdd,dhour,heights,oarr)
%
% International Reference Ionosphere (IRI) 1995
%
% input:  jmag=0/1      geodetic/geomagnetic latitude and longitude
%         alati,along   latitude north and longitude east in degrees
%         iyear         year as yyyy
%         mmdd (-ddd)   date (or day of year as a negative number)
%         dhour         local time (or universal time + 25) in decimal hours
%         heights       a vector of heights (km)
%         jf(1:20)      true/false flags for several options
%          jf(1)=1[0]    electron density is [not] calculated
%          jf(2)=1[0]    temperatures are [not] calculated
%          jf(3)=1[0]    ion composition is [not] calculated
%          jf(4)=1[0]    b0 from table [from gulyeava 1987]
%          jf(5)=1[0]    f2 peak from ccir [from ursi]
%          jf(6)=1[0]    ion comp. standard [danilov-yaichnikov-1985]
%          jf(7)=1[0]    stand. iri topside [iri-79]
%          jf(8)=1[0]    nmf2 peak model [input values]
%          jf(9)=1[0]    hmf2 peak model [input values]
%          jf(10)=1[0]   te model [te-ne model with ne input]
%          jf(11)=1[0]   ne standard [lay-functions version]
%          jf(12)=1[0]   message are written to unit=6 [=12]
%          jf(13)=1[0]   foF1 from model[foF1 or NmF1 - user input]
%          jf(14)=1[0]   hmF1 from model[hmF1 - user input]
%          jf(15)=1[0]   foE  from model[foE or NmE - user input]
%          jf(16)=1[0]   hmE  from model[hmE - user input]
%          jf(17)=1[0]   Rz12 from file[Rz12 - user input]
%          jf(18)=1[0]   simple ut<->lt[using ut_lt subroutine]
%          jf(19)        free
%          jf(20)        free
%      ---------------------------------------------------------------------
%
%  Depending on the jf() settings additional INPUT parameters may be required:
%
%          Setting              INPUT parameter
%       ------------------------------------------------------
%       jf(8)=.false.      OARR(1)=user input for foF2/MHz or NmF2/m-3
%       jf(9)=.false.      OARR(2)=user input for hmF2/km or M(3000)F2
%       jf(10)=.false.     OARR(15),OARR(16),OARR(17)=user input for 
%                            Ne(300km),Ne(400km),Ne(600km)/m-3; use 
%                            OARR()=-1 if one of these values is not
%                            available.
%       jf(13)=.false.     OARR(3)=user input for foF1/MHz or NmF1/m-3 
%       jf(14)=.false.     OARR(4)=user input for hmF1/km
%       jf(15)=.false.     OARR(5)=user input for foE/MHz or NmE/m-3 
%       jf(16)=.false.     OARR(6)=user input for hmE/km
%       jf(17)=.flase.     OARR(33)=user input for Rz12
%  jf(1:11)=1 generates the standard iri-90 parameters.
%  if you set jf(8)=0, than you have to provide the f2 peak
%  nmf2/m-3 or fof2/mhz in oarr(1). similarly, if you set jf(9)=0,
%  than you have to provide the f2 peak height hmf2/km in
%  oarr(2). if you set jf(10)=0, then you have to provide the
%  electron density in m-3 at 300km and/or 400km and/or 600km in
%  oarr(3), oarr(4), and oarr(5). if you want to use this option at
%  only one of the three altitudes, than set the densities at the
%  other two to zero.
%  output:  outf(1:11,1:length(heights))  iri profiles of heights 
%              outf(:,1)  electron density/m-3
%              outf(:,2)  neutral temperature/k
%              outf(:,3)  ion temperature/k
%              outf(:,4)  electron temperature/k
%              outf(:,5)  percentage of o+ ions in %
%              outf(:,6)  percentage of h+ ions in %
%              outf(:,7)  percentage of he+ ions in %
%              outf(:,8)  percentage of o2+ ions in %
%              outf(:,9)  percentage of no+ ions in %
%                 and, if jf(6)=.false.:
%              outf(:,10)  percentage of cluster ions in %
%              outf(:,11)  percentage of n+ ions in %
%            oarr(1:35)   additional output parameters
% oarr(1) = nmf2/m-3            oarr(2) = hmf2/km
% oarr(3) = nmf1/m-3            oarr(4) = hmf1/km
% oarr(5) = nme/m-3             oarr(6) = hme/km
% oarr(7) = nmd/m-3             oarr(8) = hmd/km
% oarr(9) = hhalf/km            oarr(10) = b0/km
% oarr(11) =valley-base/m-3     oarr(12) = valley-top/km
% oarr(13) = te-peak/k          oarr(14) = te-peak height/km
% oarr(15) = te-mod(300km)      oarr(16) = te-mod(400km)/k
% oarr(17) = te-mod(600km)      oarr(18) = te-mod(1400km)/k
% oarr(19) = te-mod(3000km)     oarr(20) = te(120km)=tn=ti/k
% oarr(21) = ti-mod(430km)      oarr(22) = x/km, where te=ti
% oarr(23) = sol zenith ang/deg oarr(24) = sun declination/deg
% oarr(25) = dip/deg            oarr(26) = dip latitude/deg
% oarr(27) = modified dip lat.  oarr(28) = dela
% oarr(29) = sunrise/dec. hours oarr(30) = sunset/dec. hours
% oarr(31) = iseason (1=spring) oarr(32) = nseason (1=northern spring)
%*****************************************************************
%*** the altitude limits are:  lower (day/night)  upper        ***
%***     electron density         60/80 km       1000 km       ***
%***     temperatures              120 km        3000 km       ***
%***     ion densities             100 km        1000 km       ***
%*****************************************************************
%*********            internally                    **************
%*********       all angles are in degree           **************
%*********       all densities are in m-3           **************
%*********       all altitudes are in km            **************
%*********     all temperatures are in kelvin       **************
%*********     all times are in decimal hours       **************
%*****************************************************************

