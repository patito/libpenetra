SUBDIRS = hosts

TESTS = main_test

check_PROGRAMS = main_test

bin_PROGRAMS = main_test

AM_CFLAGS = 	-Wall -Werror -ggdb \
		-I../src/include

LDADD=-L../src/.libs -lpenetra -lcunit

main_test_SOURCES = 	penetra_test.c \
			main_test.c
AUTOMAKE_OPTIONS=serial-tests
