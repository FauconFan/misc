# ft_nm_otool

This project was done for the ft_nm_otool pedagogic project in the 42 school. The purpose of this project is to understand how a a binary file is strucured. So, we have to list symbols in a binary (nm) et the text section (otool -t).

The project will only compile in a MacOSX environment because it use the mach-o header. It also works only on Mach-O file (64, 32 bit big/little endian), on universal binaries (32 bit big/little endian) and on archives.

You can also use my test.makefile on a MacOSX environment to see if things still works.
