
/*
**  Step Bonus : tmilon & jpriou
**  Sudoku Solver
*/

:- use_module(library(clpfd)).

%%% SOLVING %%%
sudoku(Rows) :-
        length(Rows, 9),
        maplist(same_length(Rows), Rows),
        append(Rows, Vs), Vs ins 1..9,
        maplist(all_distinct, Rows),
        transpose(Rows, Columns),
        maplist(all_distinct, Columns),
        Rows = [As,Bs,Cs,Ds,Es,Fs,Gs,Hs,Is],
        squares(As, Bs, Cs),
        squares(Ds, Es, Fs),
        squares(Gs, Hs, Is).

squares([], [], []).
squares([N1,N2,N3|Ns1], [N4,N5,N6|Ns2], [N7,N8,N9|Ns3]) :-
        all_distinct([N1,N2,N3,N4,N5,N6,N7,N8,N9]),
        squares(Ns1, Ns2, Ns3).

%%% PRINTING STUFF

print_digit(D, D):-
    ansi_format([bold, fg(green)], '~w', [D]).
print_digit(D, _):-
    ansi_format([bold, fg(blue)], '~w', [D]).

print_single([Hori|[]], [Hcpy|_]):-
    write(','),
    print_digit(Hori, Hcpy).
print_single([Hori|Tori], [Hcpy|Tcpy]):-
    write(','),
    print_digit(Hori, Hcpy),
    print_single(Tori, Tcpy).

print_row([]).
print_row([Hori|Tori], [Hcpy|Tcpy]):-
    write('['),
    print_digit(Hori, Hcpy),
    print_single(Tori, Tcpy),
    write(']'),
    nl.

print([], _).
print([Hori|Tori], [Hcpy|Tcpy]) :-
  print_row(Hori, Hcpy),
  print(Tori, Tcpy).

domain(0).

build_associated_row([], []).
build_associated_row([Hori|Tcpy], [_|Tori]):-
    domain(Hori),
    build_associated_row(Tcpy, Tori).
build_associated_row([Hori|Tcpy], [Hori|Tori]):-
    build_associated_row(Tcpy, Tori).

build_associated([], []).
build_associated([Hcpy|Tcpy], [Hori|Tori]):-
    build_associated_row(Hcpy, Hori),
    build_associated(Tcpy, Tori).

t1():-
    test1(X),
    sudoku(X),
    test1(Y),
    build_associated(Y, X),
    print(X, Y).

t2():-
    test2(X),
    sudoku(X),
    test2(Y),
    build_associated(Y, X),
    print(X, Y).

t3():-
    test3(X),
    sudoku(X),
    test3(Y),
    build_associated(Y, X),
    print(X, Y).

main() :-
    t1,
    nl,
    t2,
    nl,
    t3, !.


test1([
        [_,_,_,_,_,_,_,_,_],
        [_,_,_,_,_,3,_,8,5],
        [_,_,1,_,2,_,_,_,_],
        [_,_,_,5,_,7,_,_,_],
        [_,_,4,_,_,_,1,_,_],
        [_,9,_,_,_,_,_,_,_],
        [5,_,_,_,_,_,_,7,3],
        [_,_,2,_,1,_,_,_,_],
        [_,_,_,_,4,_,_,_,9]
    ]).

test2([
        [_,_,_,1,5,_,_,7,_],
        [1,_,6,_,_,_,8,2,_],
        [3,_,_,8,6,_,_,4,_],
        [9,_,_,4,_,_,5,6,7],
        [_,_,4,7,_,8,3,_,_],
        [7,3,2,_,_,6,_,_,4],
        [_,4,_,_,8,1,_,_,9],
        [_,1,7,_,_,_,2,_,8],
        [_,5,_,_,3,7,_,_,_]
    ]).

test3([
        [_,6,_,1,_,4,_,5,_],
        [_,_,8,3,_,5,6,_,_],
        [2,_,_,_,_,_,_,_,1],
        [8,_,_,4,_,7,_,_,6],
        [_,_,6,_,_,_,3,_,_],
        [7,_,_,9,_,1,_,_,4],
        [5,_,_,_,_,_,_,_,2],
        [_,_,7,2,_,6,9,_,_],
        [_,4,_,5,_,8,_,7,_]
    ]).
