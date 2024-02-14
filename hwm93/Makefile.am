
mexdir=$(prefix)/mex

mex_HEADERS = hwm93.m  hwm93test.m
mex_SCRIPTS = hwm93.$(MEXEXT)
check_PROGRAMS = driver

driver_SOURCES = driver.f

hwm93.$(MEXEXT): hwm93.c gws5.o


SUFFIXES = .$(MEXEXT) 

.c.$(MEXEXT):
	$(MEX) $(MEXFLAGS) $^ $(MEXLDADD)

clean-local:
	-rm -rf *.$(MEXEXT)

