
/*
**	Step 3 : tmilon & jpriou
**	La chèvre, le loup et le chou.
*/

change(right, left).
change(left, right).

% checks position of the man to see if it matches with at least one of the two
is_at_least_with(X, X, _).
is_at_least_with(X, _, X).

is_safe([Man,Wolf,Goat,Cabbage]) :-
	is_at_least_with(Man,Goat,Wolf), is_at_least_with(Man,Goat,Cabbage).

% the man is the only one able to row, he can move one of the three others or just move alone

move([X,X,Goat,Cabbage],wolf,[Y,Y,Goat,Cabbage]) :- change(X,Y).
move([X,Wolf,X,Cabbage],goat,[Y,Wolf,Y,Cabbage]) :- change(X,Y).
move([X,Wolf,Goat,X],cabbage,[Y,Wolf,Goat,Y]) :- change(X,Y).
move([X,Wolf,Goat,Cabbage],nothing,[Y,Wolf,Goat,Cabbage]) :- change(X,Y).

%if movement happened, highlight in blue
side(left, right, Letter):-
	ansi_format([bold, fg(yellow)], " |~~~~~~~~|~w~n", [Letter]).
side(right, left, Letter):-
	ansi_format([bold, fg(yellow)], "~w|~~~~~~~~|~n", [Letter]).
%else just print normally
side(left, _, Letter):-
	format(" |~~~~~~~~|~w~n", Letter).
side(right, _, Letter):-
	format("~w|~~~~~~~~|~n", Letter).

printAll([A, B, C, D], [NextA, NextB, NextC, NextD]):-
	side(A, NextA, 'M'),
	side(B, NextB, 'W'),
	side(C, NextC, 'G'),
	side(D, NextD, 'C').

% recursive until we find a position where everyone is on the other side
solution([right,right,right,right],_, _).
solution(Config, [FirstMove | OtherMoves], Val) :-
	move(Config, FirstMove, NextConfig),
	is_safe(NextConfig),
	NewVal is Val-1,
	solution(NextConfig, OtherMoves, NewVal),
	format("Deplacement ~w: ~w~n", [Val, FirstMove]),
	printAll(Config, NextConfig).

findsolutioncount(Val) :-
	length(X, Val),
	not(solution([left, left, left, left], X, Val)),
	NVal is Val+1,
	findsolutioncount(NVal).

main():-
	not(findsolutioncount(0)).
