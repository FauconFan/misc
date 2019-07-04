%ifndef SYS_H
%define SYS_H

%define SYS_MACHO(nb)		0x2000000 | nb
%define SYS_WRITE			SYS_MACHO(4)
%define STDOUT				1

%endif
