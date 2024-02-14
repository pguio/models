
mexdir=$(prefix)/mex
mex_HEADERS = msise90.m msise90test.m
mex_SCRIPTS = msise90.$(MEXEXT)

check_PROGRAMS = test_driver

test_driver_SOURCES = test_driver.f gtd6.f

msise90.$(MEXEXT): msise90.c gtd6.o

SUFFIXES = .$(MEXEXT)

.c.$(MEXEXT):
	$(MEX) $(MEXFLAGS) $^ $(MEXLDADD)

clean-local:
	-rm -rf *.$(MEXEXT)

