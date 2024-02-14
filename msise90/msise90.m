%      [alt,d,t]=msise90(iyd,sec,alt,glat,glong,stl,f107a,f107,ap,mass,d,t)
%
%        Neutral Atmosphere Empirical Model from the Surface to Lower
%          Exosphere  msise90 (jgr, 96, 1159-1172, 1991)
%
%     input:
%        iyd - year and day as yyyyddd or ddd (day of year from 1 to 365)
%        sec - ut(sec)
%        alt - vector altitude(km)
%        glat - geodetic latitude(deg)
%        glong - geodetic longitude(deg)
%        stl - local apparent solar time(hrs)
%        f107a - 3 month average of f10.7 flux
%        f107 - daily f10.7 flux for previous day
%        ap - magnetic index(daily)
%        mass - mass number (only density for selected gas is
%                 calculated.  mass 0 is temperature.  mass 48 for all.
%     note:  ut, local time, and longitude are used independently in the
%            model and are not of equal importance for every situation.
%            for the most physically realistic calculation these three
%            variables should be consistent (stl=sec/3600+glong/15).
%            f107, f107a, and ap effects are not large below 80 km
%            and these can be set to 150., 150., and 4. respectively.
%     output:
%        d(:,1) - he number density(m-3)
%        d(:,2) - o number density(m-3)
%        d(:,3) - n2 number density(m-3)
%        d(:,4) - o2 number density(m-3)
%        d(:,5) - ar number density(m-3)
%        d(:,6) - total mass density(kg/m3)
%        d(:,7) - h number density(m-3)
%        d(:,8) - n number density(m-3)
%        t(:,1) - exospheric temperature
%        t(:,2) - temperature at alt
%      o, h, and n set to zero below 72.5 km
%      exospheric temperature set to average for altitudes below 120 km.
%*****************************************************************
%*********       all angles are in degree           **************
%*********       all densities are in m-3           **************
%*********       all altitudes are in km            **************
%*********     all temperatures are in kelvin       **************
%*********     all times are in decimal hours       **************
%*****************************************************************

