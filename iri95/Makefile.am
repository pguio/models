
datadir=$(prefix)/mex/data

igrf=$(datadir)/ig_rz.dat

data_DATA = data/*.asc data/ig_rz.dat

AM_FFLAGS = @FFLAGS@ -DDATAPATH="'$(datadir)'" -DIGRF="'$(igrf)'"

mexdir=$(prefix)/mex
mex_HEADERS = iri95.m iri95test.m
mex_SCRIPTS = iri95.$(MEXEXT)

check_PROGRAMS = iri_test iris13_test irit13_test test

iri_test_SOURCES = iri_test.f iris13.fpp irif13.fpp irit13.f cira86.f
iris13_test_SOURCES = iris13_test.f iris13.fpp irif13.fpp irit13.f cira86.f
irit13_test_SOURCES = iris13_test.f iris13.fpp irif13.fpp irit13.f cira86.f
test_SOURCES = test.c iris13.fpp irif13.fpp irit13.f cira86.f

iri95.$(MEXEXT): iri95.c iris13.o irif13.o irit13.o cira86.o

SUFFIXES = .$(MEXEXT) .fpp

.c.$(MEXEXT):
	$(MEX) $(MEXFLAGS) $^ $(MEXLDADD)

.fpp.o:
	$(F77COMPILE) -c -o $@ `test -f '$<' || echo '$(srcdir)/'`$<

clean-local:
	-rm -rf *.$(MEXEXT)

