CFLAGS_LANGUAGE=-std=c99 -pedantic -D_POSIX_C_SOURCE \
		-D_SVID_SOURCE
CFLAGS_WARNS=-Wall -Wextra -Werror
CFLAGS_INCLUDES=-Iinclude -I$(LIBXML_INCLUDES) -I$(LIBUDIS_INCLUDES)

AM_CFLAGS=	-ggdb -fPIC -O2 $(CFLAGS_LANGUAGE) \
		$(CFLAGS_WARNS) \
		$(CFLAGS_INCLUDES)

lib_LTLIBRARIES=libpenetra.la

libpenetra_la_SOURCES =  penetra.c \
			coff.c \
			optional.c \
			nt.c \
			dos.c


libpenetra_la_LDFLAGS = -version-info 1:0:0
libpenetra_la_LIBADD=-L$(LIBXML_LIBPATH) -L$(LIBUDIS_LIBPATH) -lxml2 -ludis86

library_includedir=$(includedir)/penetra
library_include_HEADERS	=	include/penetra/penetra.h \
				include/penetra/types.h \
				include/penetra/error.h \
				include/penetra/defines.h \
				include/penetra/optional.h \
				include/penetra/nt.h \
				include/penetra/dos.h \
				include/penetra/coff.h
