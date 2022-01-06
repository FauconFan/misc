%ifndef SYS_H
%define SYS_H

%define STDOUT				1

%ifidn __OUTPUT_FORMAT__, macho64

%define SYS_MACHO(nb)		0x2000000 | nb
%define SYS_READ			SYS_MACHO(3)
%define SYS_WRITE			SYS_MACHO(4)

%else

%define SYS_READ 0
%define SYS_WRITE 1

%endif

%endif
