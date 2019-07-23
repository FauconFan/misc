
section .data
fmt:
	.string		db "%3$csection .data%3$cfmt:%3$c%2$c.string%2$c%2$cdb %4$c%1$s%4$c, 0%3$cfile:%3$c%2$c.string%2$c%2$cdb __FILE__, 0%3$cname_file_fmt:%3$c%2$c.string%2$c%2$cdb %4$cSully_%%d.s%4$c, 0%3$cobj_file_fmt:%3$c%2$c.string%2$c%2$cdb %4$cSully_%%d.o%4$c, 0%3$cexe_file_fmt:%3$c%2$c.string%2$c%2$cdb %4$c./Sully_%%d%4$c, 0%3$ccmd_fmt:%3$c%2$c.string%2$c%2$cdb %4$c/Users/jpriou/.brew/bin/nasm -f macho64 --prefix _ %%1$s -o %%2$s && /usr/bin/ld -macosx_version_min 10.8 -lSystem %%2$s -o %%3$s%4$c, 0%3$c%3$csection .text%3$c%2$cglobal main%3$c%2$cextern dprintf%3$c%2$cextern sprintf%3$c%2$cextern system%3$c%2$cextern strchr%3$c%3$cmain:%3$c%2$c%2$cpush%2$crbp%3$c%2$c%2$cmov%2$c%2$crbp, rsp%3$c%2$c%2$csub%2$c%2$crsp, 0x800%3$c%2$c%2$cand%2$c%2$crsp, -16%3$c%3$c%2$c%2$cmov%2$c%2$cdword [rsp + 0x0], %5$d%3$c%3$c%2$c%2$ccmp%2$c%2$cdword [rsp + 0x0], 0%3$c%2$c%2$cje%2$c%2$c.gend%3$c%3$c%2$c%2$clea%2$c%2$crdi, [rel file.string]%3$c%2$c%2$cxor%2$c%2$crsi, rsi%3$c%2$c%2$cmov%2$c%2$crsi, '_'%3$c%2$c%2$ccall%2$cstrchr%3$c%3$c%2$c%2$ccmp%2$c%2$crax, 0%3$c%2$c%2$cje%2$c%2$c.prepare_buffer%3$c%2$c%2$cdec%2$c%2$cdword [rsp + 0x0]%3$c%3$c%2$c.prepare_buffer:%3$c%3$c%2$c%2$cmov%2$c%2$crdi, rsp%3$c%2$c%2$cadd%2$c%2$crdi, 0x500%3$c%2$c%2$clea%2$c%2$crsi, [rel name_file_fmt.string]%3$c%2$c%2$cmov%2$c%2$crdx, [rsp + 0x0]%3$c%2$c%2$ccall%2$csprintf%3$c%2$c%2$ctest%2$ceax, 0x80000000%3$c%2$c%2$cjne%2$c%2$c.bend%3$c%3$c%2$c%2$cmov%2$c%2$crdi, rsp%3$c%2$c%2$cadd%2$c%2$crdi, 0x600%3$c%2$c%2$clea%2$c%2$crsi, [rel obj_file_fmt.string]%3$c%2$c%2$cmov%2$c%2$crdx, [rsp + 0x0]%3$c%2$c%2$ccall%2$csprintf%3$c%2$c%2$ctest%2$ceax, 0x80000000%3$c%2$c%2$cjne%2$c%2$c.bend%3$c%3$c%2$c%2$cmov%2$c%2$crdi, rsp%3$c%2$c%2$cadd%2$c%2$crdi, 0x700%3$c%2$c%2$clea%2$c%2$crsi, [rel exe_file_fmt.string]%3$c%2$c%2$cmov%2$c%2$crdx, [rsp + 0x0]%3$c%2$c%2$ccall%2$csprintf%3$c%2$c%2$ctest%2$ceax, 0x80000000%3$c%2$c%2$cjne%2$c%2$c.bend%3$c%3$c%2$c%2$cmov%2$c%2$crdi, rsp%3$c%2$c%2$cadd%2$c%2$crdi, 0x100%3$c%2$c%2$clea%2$c%2$crsi, [rel cmd_fmt.string]%3$c%2$c%2$cmov%2$c%2$crdx, rsp%3$c%2$c%2$cadd%2$c%2$crdx, 0x500%3$c%2$c%2$cmov%2$c%2$crcx, rsp%3$c%2$c%2$cadd%2$c%2$crcx, 0x600%3$c%2$c%2$cmov%2$c%2$cr8, rsp%3$c%2$c%2$cadd%2$c%2$cr8, 0x700%3$c%2$c%2$ccall%2$csprintf%3$c%2$c%2$ctest%2$ceax, 0x80000000%3$c%2$c%2$cjne%2$c%2$c.bend%3$c%2$c%3$c%2$c.write_to_file:%3$c%3$c%2$c%2$cmov%2$c%2$crax, 0x2000005%3$c%2$c%2$cmov%2$c%2$crdi, rsp%3$c%2$c%2$cadd%2$c%2$crdi, 0x500%3$c%2$c%2$cmov%2$c%2$crsi, 0x601%3$c%2$c%2$cmov%2$c%2$crdx, 0664o%3$c%2$c%2$csyscall%3$c%2$c%2$cjc%2$c%2$c.bend%3$c%2$c%2$cmov%2$c%2$c[rsp + 0x4], eax%3$c%3$c%2$c%2$cmov%2$c%2$crdi, [rsp + 0x4]%3$c%2$c%2$clea%2$c%2$crsi, [rel fmt.string]%3$c%2$c%2$clea%2$c%2$crdx, [rel fmt.string]%3$c%2$c%2$cmov%2$c%2$crcx, 9%3$c%2$c%2$cmov%2$c%2$cr8, 10%3$c%2$c%2$cmov%2$c%2$cr9, 34%3$c%2$c%2$ccall%2$cdprintf%3$c%2$c%2$ctest%2$ceax, 0x80000000%3$c%2$c%2$cjne%2$c%2$c.bend%3$c%3$c%2$c%2$cmov%2$c%2$crax, 0x2000006%3$c%2$c%2$cmov%2$c%2$crdi, [rsp + 0x4]%3$c%2$c%2$csyscall%3$c%2$c%2$cjc%2$c%2$c.bend%3$c%2$c%3$c%2$c.compile:%3$c%3$c%2$c%2$cmov%2$c%2$crdi, rsp%3$c%2$c%2$cadd%2$c%2$crdi, 0x100%3$c%2$c%2$ccall%2$csystem%3$c%2$c%2$ccmp%2$c%2$ceax, 0%3$c%2$c%2$cjne%2$c%2$c.bend%3$c%3$c%2$c.run:%3$c%2$c%2$ccmp%2$c%2$cdword [rsp + 0x0], 0%3$c%2$c%2$cje%2$c%2$c.gend%3$c%3$c%2$c%2$cmov%2$c%2$crdi, rsp%3$c%2$c%2$cadd%2$c%2$crdi, 0x700%3$c%2$c%2$ccall%2$csystem%3$c%2$c%2$ccmp%2$c%2$ceax, 0%3$c%2$c%2$cjne%2$c%2$c.bend%3$c%3$c%2$c%2$cjmp%2$c%2$c.gend%3$c%3$c%2$c.bend:%3$c%2$c%2$cmov%2$c%2$crax, 1%3$c%2$c%2$cjmp%2$c%2$c.end%3$c%2$c.gend:%3$c%2$c%2$cmov%2$c%2$crax, 0%3$c%2$c.end:%3$c%2$c%2$cmov%2$c%2$crsp, rbp%3$c%2$c%2$cpop%2$c%2$crbp%3$c%2$c%2$cret%3$c", 0
file:
	.string		db __FILE__, 0
name_file_fmt:
	.string		db "Sully_%d.s", 0
obj_file_fmt:
	.string		db "Sully_%d.o", 0
exe_file_fmt:
	.string		db "./Sully_%d", 0
cmd_fmt:
	.string		db "/Users/jpriou/.brew/bin/nasm -f macho64 --prefix _ %1$s -o %2$s && /usr/bin/ld -macosx_version_min 10.8 -lSystem %2$s -o %3$s", 0

section .text
	global main
	extern dprintf
	extern sprintf
	extern system
	extern strchr

main:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 0x800
		and		rsp, -16

		mov		dword [rsp + 0x0], 5

		cmp		dword [rsp + 0x0], 0
		je		.gend

		lea		rdi, [rel file.string]
		xor		rsi, rsi
		mov		rsi, '_'
		call	strchr

		cmp		rax, 0
		je		.prepare_buffer
		dec		dword [rsp + 0x0]

	.prepare_buffer:

		mov		rdi, rsp
		add		rdi, 0x500
		lea		rsi, [rel name_file_fmt.string]
		mov		rdx, [rsp + 0x0]
		call	sprintf
		test	eax, 0x80000000
		jne		.bend

		mov		rdi, rsp
		add		rdi, 0x600
		lea		rsi, [rel obj_file_fmt.string]
		mov		rdx, [rsp + 0x0]
		call	sprintf
		test	eax, 0x80000000
		jne		.bend

		mov		rdi, rsp
		add		rdi, 0x700
		lea		rsi, [rel exe_file_fmt.string]
		mov		rdx, [rsp + 0x0]
		call	sprintf
		test	eax, 0x80000000
		jne		.bend

		mov		rdi, rsp
		add		rdi, 0x100
		lea		rsi, [rel cmd_fmt.string]
		mov		rdx, rsp
		add		rdx, 0x500
		mov		rcx, rsp
		add		rcx, 0x600
		mov		r8, rsp
		add		r8, 0x700
		call	sprintf
		test	eax, 0x80000000
		jne		.bend
	
	.write_to_file:

		mov		rax, 0x2000005
		mov		rdi, rsp
		add		rdi, 0x500
		mov		rsi, 0x601
		mov		rdx, 0664o
		syscall
		jc		.bend
		mov		[rsp + 0x4], eax

		mov		rdi, [rsp + 0x4]
		lea		rsi, [rel fmt.string]
		lea		rdx, [rel fmt.string]
		mov		rcx, 9
		mov		r8, 10
		mov		r9, 34
		call	dprintf
		test	eax, 0x80000000
		jne		.bend

		mov		rax, 0x2000006
		mov		rdi, [rsp + 0x4]
		syscall
		jc		.bend
	
	.compile:

		mov		rdi, rsp
		add		rdi, 0x100
		call	system
		cmp		eax, 0
		jne		.bend

	.run:
		cmp		dword [rsp + 0x0], 0
		je		.gend

		mov		rdi, rsp
		add		rdi, 0x700
		call	system
		cmp		eax, 0
		jne		.bend

		jmp		.gend

	.bend:
		mov		rax, 1
		jmp		.end
	.gend:
		mov		rax, 0
	.end:
		mov		rsp, rbp
		pop		rbp
		ret
