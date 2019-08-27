
/*
**  Step Bonus : tmilon & jpriou
**  Implementation of problem 2 of the Project Euler:
**	https://projecteuler.net/problem=2
*/

fibonacci:-
	fibonacci(1, 2, 0), !.
fibonacci(X, _, Sum):-
	X > 4000000,
	write(Sum).
fibonacci(X, Y, Sum):-
	0 is mod(X, 2),
	NewSum is Sum+X,
	Next is X+Y,
	fibonacci(Y, Next, NewSum).
fibonacci(X, Y, Sum):-
	Next is X+Y,
	fibonacci(Y, Next, Sum).
