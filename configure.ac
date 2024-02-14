# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.71])
AC_INIT([models],[1.0],[patrick.guio@gmail.com])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_SRCDIR([hwm93/hwm93.c])
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE
AM_MAINTAINER_MODE


dnl Checks for programs.
AC_PROG_CC
AC_PROG_F77
AC_PROG_F77_C_O
AC_PROG_CPP
AC_PROG_INSTALL

dnl Matlab mex stuff
AC_PROG_MEX

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([
	Makefile 
	hwm93/Makefile
	igrf95/Makefile
	iri95/Makefile
	msise90/Makefile
	])

AC_OUTPUT

