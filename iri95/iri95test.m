function iri95test

heis=[100:100:1000]';
jmag=0;
lat=45.1;
long=293.1;
lat=69.586; % eiscat tromsø
long=19.227; % eiscat tromsø
iyear=1994;
mmdd=1015;
mmdd=110.;
dhour=12.5;
dhour=12.;
jf=ones(20,1); jf([5:6 12 19:20])=0;
oarr=0;
run(jf,jmag,lat,long,iyear,mmdd,dhour,heis,oarr);


heis=[100:20:300]';
jmag=0;
lat=45.1;
long=293.1;
iyear=1994;
mmdd=1015;
dhour=12.5;
jf=ones(20,1); jf([5:6 12 19:20])=0; 
oarr=0;
run(jf,jmag,lat,long,iyear,mmdd,dhour,heis,oarr);

heis=[100:20:300]';
jmag=0;
lat=45.1;
long=293.1;
iyear=1994;
mmdd=1015;
dhour=12.5;
jf=ones(20,1); jf([2 12])=0;
oarr=0;
run(jf,jmag,lat,long,iyear,mmdd,dhour,heis,oarr);

heis=[100:20:300]';
jmag=0;
lat=45.1;
long=293.1;
iyear=1994;
mmdd=1015;
dhour=12.5;
jf=ones(20,1); jf([6 10 12])=0;
oarr(4)=4;
run(jf,jmag,lat,long,iyear,mmdd,dhour,heis,oarr);


function run(jf,jmag,lat,long,iyear,mmdd,dhour,heis,oarr);

clear iri95
[heis,outf,oarr]=iri95(jf,jmag,lat,long,iyear,mmdd,dhour,heis,oarr);

for i=2:4,
	outf(find(outf(:,i)<0),i)=-1;
end

subplot(121),
semilogx([outf(:,1) (outf(:,1)*ones(1,5)).*outf(:,5:9)/100], heis)
xlabel('density [m-3]')
ylabel('height [km]');
legend('Ne','[O+]','[H+]','[He+]','[O2+]','[NO+]');

subplot(122),
plot(outf(:,2:4), heis)
xlabel('temp [K]')
ylabel('height [km]');
legend('Tn','Ti','Te');


fprintf(1,'\n');
fprintf(1,'%s%s\n',' Alt       Ne    Tn    Ti    Te', ...
	'  [O+]  [H+] [He+] [O2+] [NO+]');

for i=1:length(heis),
  fprintf(1,'%4.0f %8.2e %5.f %5.f %5.0f %5.f %5.f %5.f %5.f %5.0f\n', ...
	  heis(i), outf(i,1:9) );
end
fprintf(1,'lat/long : %+3.1f/%+3.1f\n', lat,long);
fprintf(1,'dip %3.1f\n', oarr(25) );
fprintf(1,'sza %+3.1f sde %+3.1f\n', oarr(23:24));
pause

