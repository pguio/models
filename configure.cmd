#!/bin/sh

case `hostname` in

jazz5|jazz6)
#./configure MEXFLAGS="-O -I/usr/local/numerics/include" MEXLDADD="-lgfortran" CFLAGS=-I/usr/local/numerics/include LIBS="-L/usr/local/numerics/lib -lnag -lfitpack -lgfortran -lm" FFLAGS="-fPIC -std=legacy -fno-align-commons -freal-4-real-8 -O2 -funroll-loops -finline-functions -fstrict-aliasing" --prefix=$HOME/research/models
./configure MEXFLAGS="-O -I/usr/local/numerics/include" MEXLDADD="-lgfortran" CFLAGS=-I/usr/local/numerics/include LIBS="-L/usr/local/numerics/lib -lnag -lfitpack -lgfortran -lm" FFLAGS="-fPIC -std=legacy -O2 -funroll-loops -finline-functions -fstrict-aliasing -fdec-char-conversions" --prefix=$HOME/research/models
;;

jazz*)
./configure MEXFLAGS="-O -I/usr/local/numerics/include" MEXLDADD="-lgfortran" \
CFLAGS=-I/usr/local/numerics/include LIBS="-L/usr/local/numerics/lib -lnag -lfitpack -lgfortran -lm" \
--prefix=$HOME/research/models
;;

esac

