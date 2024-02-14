
glat=45.1;
glong=293.1;
height=[100:100:1000];
year=1985.5;

[height, bi, dimo]=igrf95(glat,glong,height,year);

plot(bi(:,1:4),height)
xlabel('B [gauss]')
ylabel('alt [km]')
legend('|B|','B-east','B-north','B-down')


fprintf(1,'Dipol moment (gauss) = %.4f\n', dimo);

fprintf(1,'%s%s\n',' Alt   |B|   B-east  B-north   B-down',...
	' Dipole   Dec.  L-val     B-eq icode');
for i=1:length(height)

  fprintf(1, ...
	  '%4.f %5.2f %+8.4f %+8.4f %+8.4f %+6.2f %+6.2f %6.2f %8.4f %5.d\n', ...
		height(i), bi(i,:) );

end
