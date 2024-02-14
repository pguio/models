

iday=[172, 81, 172, 81, 182];
ut=[29000., 29000., 75000., 29000.];
alt=[0:10:400];
xlat=[60., 0., 60., 45., 0, 45., 45., -45., 45., 45.];
xlong=[-70., 0., -70., 0, 90., 90., 0, -90., -90.];
xlst=[16.,4.,16.,0.,6.,9.,12.,0,0];
f107a=[150., 70., 150., 150., 150.];
f107=[150, 180, 150, 150];
ap=[4, 40, 4, 40 ,4];

for i=1:4,

	[alt,w]=hwm93(iday(i),ut(i),alt,xlat(i),xlong(i),xlst(i),f107a(i),f107(i),ap);
	plot(w,alt);
	xlabel('Wind speed [m/s]');
	ylabel('Altitude [km]');
	legend('meridional','zonal');
	pause

end

