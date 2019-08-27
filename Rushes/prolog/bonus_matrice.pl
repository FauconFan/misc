
/*
**	Step bonus : tmilon & jpriou
**	Matrix Utils
**	getIdentity(Size).
**	getEmptyMat(N, M, Mat).
**	isMatrix(Mat).
**	getNbRow(Mat, N).
**	getNbCol(Mat, M).
**	Transpose(X, Y).
**	Multiply(X, Y, Z).
*/

getIdentity__(_, []).
getIdentity__(0, [H|T]):-
	H = 1,
	getIdentity__(-1, T).
getIdentity__(N, [H|T]):-
	H = 0,
	N1 is N - 1,
	getIdentity__(N1, T).

getIdentity_(_, [], _).
getIdentity_(Index, [H|T], Size):-
	length(H, Size),
	getIdentity__(Index, H),
	I1 is Index + 1,
	getIdentity_(I1, T, Size).

getIdentity(IntSize, Mat):-
	length(Mat, IntSize),
	getIdentity_(0, Mat, IntSize).

getEmptyMat_(M, [H|T]):-
	length(H, M),
	getEmptyMat_(M, T).
getEmptyMat_(_, []).

getEmptyMat(0, 0, []).
getEmptyMat(N, M, Mat):-
	length(Mat, N),
	getEmptyMat_(M, Mat).

isMatrix_([], _).
isMatrix_([H|T], SizeFirst):-
	length(H, N),
	N = SizeFirst,
	isMatrix_(T, SizeFirst).

isMatrix([]).
isMatrix([H|T]):-
	length(H, N),
	append([H], T, Cpy),
	isMatrix_(Cpy, N).

getNbRow([], 0).
getNbRow(Mat, N):-
	isMatrix(Mat),
	length(Mat, N).

getNbCol([], 0).
getNbCol([H|T], M):-
	append([H], T, Mat),
	isMatrix(Mat),
	length(H, M).

transpose_([], [], []).
transpose_([[X|Xs]|Ys], [X|R], [Xs|Z]) :-
	transpose_(Ys, R, Z).

transpose([[]|_], []).
transpose(M, [X|T]) :-
	transpose_(M, X, M1), 
    transpose(M1, T).

multiply___(X,T,M,M+X*T).

multiply__([X|Xs],[T|Ts],M) :-
    foldl(multiply___,Xs,Ts,X*T,M).

multiply_(T,X,M) :-
    maplist(multiply__(X),T,M).

multiply(X, Y, Res):-
	getNbCol(X, N),
	getNbRow(Y, N),
	transpose(Y, Y1),
	maplist(multiply_(Y1), X, Tmp),
	maplist(maplist(is), Res, Tmp).

mat1([[4, 7], [2, 6]]).
mat2([[1, 2], [3, 4]]).
mat3([[1, 2, 3], [4, 5, 6], [7, 8, 9]]).
mat4([[1], [1], [1]]).
