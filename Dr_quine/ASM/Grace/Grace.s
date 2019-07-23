
%define	FMT_STRING	"%3$c%%define%2$cFMT_STRING%2$c%4$c%1$s%4$c%3$c%3$c%%macro%2$cHEADER_ASM%2$c0%3$c%3$csection .data%3$cfmt:%3$c%2$c.string%2$cdb%2$cFMT_STRING, 0%3$ckid:%3$c%2$c.string db%2$c%4$cGrace_kid.s%4$c, 0%3$c%3$csection .text%3$c%2$cglobal main%3$c%2$cextern dprintf%3$c%3$c%%endmacro%3$c%3$c%%macro FT 0%3$cmain:%3$c%2$c%2$cpush%2$crbp%3$c%2$c%2$cmov%2$c%2$crbp, rsp%3$c%2$c%2$csub%2$c%2$crsp, 16%3$c%2$c%2$cand%2$c%2$crsp, -16%3$c%3$c%2$c%2$cmov%2$c%2$crax, 0x2000005%3$c%2$c%2$clea%2$c%2$crdi, [rel kid.string]%3$c%2$c%2$cmov%2$c%2$crsi, 0x601%3$c%2$c%2$cmov%2$c%2$crdx, 0644o%3$c%2$c%2$csyscall%3$c%2$c%2$cjc%2$c%2$c.bend%3$c%3$c%2$c%2$cmov%2$c%2$c[rsp + 0], rax%3$c%3$c%2$c%2$cmov%2$c%2$crdi, [rsp + 0]%3$c%2$c%2$clea%2$c%2$crsi, [rel fmt.string]%3$c%2$c%2$clea%2$c%2$crdx, [rel fmt.string]%3$c%2$c%2$cmov%2$c%2$crcx, 9%3$c%2$c%2$cmov%2$c%2$cr8, 10%3$c%2$c%2$cmov%2$c%2$cr9, 34%3$c%2$c%2$ccall%2$cdprintf%3$c%2$c%2$ccmp%2$c%2$ceax , -1%3$c%2$c%2$cje%2$c%2$c.bend%3$c%3$c%2$c%2$cmov%2$c%2$crax, 0x2000006%3$c%2$c%2$cmov%2$c%2$crdi, [rsp + 0]%3$c%2$c%2$csyscall%3$c%2$c%2$cjc%2$c%2$c.bend%3$c%3$c%2$c%2$cmov%2$c%2$crax, 0%3$c%2$c%2$cjmp%2$c%2$c.end%3$c%3$c%2$c.bend:%3$c%2$c%2$cmov%2$c%2$crax, 1%3$c%2$c%3$c%2$c.end:%3$c%2$c%2$cmov%2$c%2$crsp, rbp%3$c%2$c%2$cpop%2$c%2$crbp%3$c%2$c%2$cret%3$c%%endmacro%3$c%3$cHEADER_ASM%3$cFT%3$c"

%macro	HEADER_ASM	0

section .data
fmt:
	.string	db	FMT_STRING, 0
kid:
	.string db	"Grace_kid.s", 0

section .text
	global main
	extern dprintf

%endmacro

%macro FT 0
main:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 16
		and		rsp, -16

		mov		rax, 0x2000005
		lea		rdi, [rel kid.string]
		mov		rsi, 0x601
		mov		rdx, 0644o
		syscall
		jc		.bend

		mov		[rsp + 0], rax

		mov		rdi, [rsp + 0]
		lea		rsi, [rel fmt.string]
		lea		rdx, [rel fmt.string]
		mov		rcx, 9
		mov		r8, 10
		mov		r9, 34
		call	dprintf
		cmp		eax , -1
		je		.bend

		mov		rax, 0x2000006
		mov		rdi, [rsp + 0]
		syscall
		jc		.bend

		mov		rax, 0
		jmp		.end

	.bend:
		mov		rax, 1
	
	.end:
		mov		rsp, rbp
		pop		rbp
		ret
%endmacro

HEADER_ASM
FT
