
iday=172;
ut=29000;
alt=[100:100:1000]';
glat=60.;
glong=-70;
lst=16;
f107a=150;
f107=150;
ap=4;
mass=48;

[alt,d,t]=msise90(iday,ut,alt,glat,glong,lst,f107a,f107,ap,mass);


semilogx(d(:,[1:5 7:8]), alt)
xlabel('density [m-3]');
ylabel('alt [km]')
legend('[He]','[O]','[N2]','[O2]','[Ar]','[H]','[N]');

plot(t, alt)
xlabel('temperature [K]');
ylabel('alt [km]')
legend('T-exo','T')


fprintf(1,'\n');
fprintf(1,'%s%s\n',' Alt    [He]     [O]    [N2]    [O2]    [Ar]', ...
  '     [H]     [N] T-exo     T');
for i=1:length(alt),

  fprintf(1, ...
	'%4.f %5.1e %5.1e %5.1e %5.1e %5.1e %5.1e %5.1e %5.f %5.f\n',...
   alt(i), d(i,[1:5 7:8]), t(i,:) );

end

