
/*
**  Step Bonus : tmilon & jpriou
**  Implementation of problem 1 of the Project Euler:
**	https://projecteuler.net/problem=1
*/

list(1000, []).
list(N, [H|T]):-
	H = N,
	N1 is N + 1,
	list(N1, T).

incremente_(0, _, H, N, M):-
	M is N + H.
incremente_(_, 0, H, N, M):-
	M is N + H.
incremente_(_, _, _, N, M):-
	M is N.

incremente([], M):-
	write(M).
incremente([H|T], N):-
	R1 is mod(H, 3),
	R2 is mod(H, 5),
	incremente_(R1, R2, H, N, M),
	incremente(T, M).

main():-
	list(0, List),
	incremente(List, 0), !.
