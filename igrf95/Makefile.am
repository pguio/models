
datadir=$(prefix)/mex/data

data_DATA = data/*.dat 

AM_FFLAGS = @FFLAGS@ -DDATAPATH="'$(datadir)/'"

mexdir=$(prefix)/mex
mex_HEADERS = igrf95.m igrf95test.m
mex_SCRIPTS = igrf95.$(MEXEXT)

check_PROGRAMS = bilcal test

bilcal_SOURCES = bilcal.f igrf_sub.fpp
test_SOURCES = test.c shellig.fpp

igrf95.$(MEXEXT): igrf95.c igrf_sub.o


SUFFIXES = .$(MEXEXT) .fpp

.c.$(MEXEXT):
	$(MEX) $(MEXFLAGS) $^ $(MEXLDADD)

.fpp.o:
	$(F77COMPILE) -c -o $@ `test -f '$<' || echo '$(srcdir)/'`$<

clean-local:
	-rm -rf *.$(MEXEXT)

