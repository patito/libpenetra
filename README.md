libpenetra
==========

The libpenetra was created with the goal of studying the windows binary format
known as Portable Executable (PE). With libpenetra you can access all info
about PE binaries.

Dependencies
============

The libpenetra has some dependencies.

	* libxml2-dev
	* libcunit1-dev (optional)

If your distro is based on Debian:

	$ sudo apt-get install libxml2-dev libcunit1-dev

Otherwise:

	* http://cunit.sourceforge.net/
	* https://git.gnome.org/browse/libxml2/

Building and Installing
=======================

Now that all dependencies were satisfied, we can build and install libpenetra. First clone the project. 

	$ git clone https://github.com/patito/libpenetra.git
    $ ./autogen.sh
    $ ./configure
    $ make
    $ sudo make install

Documentation
=============

To generate the doxygen documentation you can execute the command below.

	$ cd doc
	$ doxygen Doxyfile

If you do not have doxygen, do this 1st bitch:

	$ sudo ap-get install doxygen 

If your distro is not based on Debian, you can see more info:

	* http://www.stack.nl/~dimitri/doxygen/download.html

:-)

Examples
==========

With libpenetra you can get any field of PE binary. See the Example below:

```c

/* This example show info about DOS Header.
 *
 */

#include <stdio.h>

#include <penetra/penetra.h>

int main (int argc, char**argv)
{	
	Penetra pen;
	PenetraDos dos;
	_i32 offset;
	_u16 signature;
	_u16 cblp;
	_u16 cp;
	_u16 crlc;
	_u16 cparhdr;
	_u16 minalloc;
	_u16 maxalloc;
	_u16 ss;
	_u16 sp;
	_u16 csum;
	_u16 ip;
	_u16 cs;
	_u16 lfarlc;
	_u16 ovno;
	_u16 oemid;
	_u16 oeminfo;

	if (argc < 2) {
		printf("Usage: %s <bin>\n", argv[0]);
		return 1;
	}

	penetra_init(&pen);
	penetra_open(&pen, argv[1]);

	if (PENETRA_SUCCESS != penetra_is_pe(&pen)) {
		printf("Not a PE file!\n");
		penetra_finish(&pen);
		return 1;
	}
	
	penetra_get_dos(&pen, &dos);

	penetra_dos_get_signature(&dos, &signature);
	printf("e_magic = %#x\n", signature);

	penetra_dos_get_cblp(&dos, &cblp);
	printf("e_cblp = %d\n", cblp);
	
	penetra_dos_get_cp(&dos, &cp);
	printf("e_cp = %d\n", cp);
	
	penetra_dos_get_crlc(&dos, &crlc);
	printf("e_crlc = %d\n", crlc);

	penetra_dos_get_cparhdr(&dos, &cparhdr);
	printf("e_cparhdr = %d\n", cparhdr);
	
	penetra_dos_get_minalloc(&dos, &minalloc);
	printf("e_minalloc = %d\n", minalloc);

	penetra_dos_get_maxalloc(&dos, &maxalloc);
	printf("e_maxalloc = %d\n", maxalloc);

	penetra_dos_get_ss(&dos, &ss);
	printf("e_ss = %d\n", ss);

	penetra_dos_get_sp(&dos, &sp);
	printf("e_sp = %#x\n", sp);

	penetra_dos_get_csum(&dos, &csum);
	printf("e_csum = %d\n", csum);

	penetra_dos_get_ip(&dos, &ip);
	printf("e_ip = %d\n", ip);

	penetra_dos_get_cs(&dos, &cs);
	printf("e_cs = %d\n", cs);

	penetra_dos_get_lfarlc(&dos, &lfarlc);
	printf("e_lfarlc = %#x\n", lfarlc);
	
	penetra_dos_get_ovno(&dos, &ovno);
	printf("e_ovno = %d\n", ovno);

	penetra_dos_get_oemid(&dos, &oemid);
	printf("e_oemid = %d\n", oemid);
	
	penetra_dos_get_oeminfo(&dos, &oeminfo);
	printf("e_oeminfo = %d\n", oeminfo);

	penetra_dos_get_lfanew(&dos, &offset);
	printf("e_lfanew = %#x\n", offset);

	penetra_finish(&pen);

	return 0;
}

```
