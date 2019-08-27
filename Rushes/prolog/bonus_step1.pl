
/*
**	Step 1 : tmilon & jpriou
**	Rude Famille
*/

/*
**	We define 4 facts:
**		- isWoman_(name).
**		- isMan_(name).
**		- isChild_(child, parent_masc, parent2_fem)
**		- isRelationShip_(parent1_masc, parent2_fem)
**	
**	Fact isWoman_ and isMan_ are incompatible...
**	
*/

:- use_module(library(clpfd)).

:- discontiguous isMan_/1.
:- discontiguous isWoman_/1.
:- discontiguous isRelationShip_/2.
:- discontiguous isChild_/3.

isMan_(marc).
isMan_(jean).
isMan_(jules).
isMan_(leon).
isMan_(jacques).
isMan_(luc).
isMan_(loic).
isMan_(gerard).
isMan_(paul).
isMan_(herve).

isWoman_(anne).
isWoman_(lisa).
isWoman_(betty).
isWoman_(sylvie).
isWoman_(eve).
isWoman_(valerie).
isWoman_(julie).

isRelationShip_(marc, anne).
isRelationShip_(jules, lisa).
isRelationShip_(luc, betty).
isRelationShip_(leon, sylvie).
isRelationShip_(loic, eve).
isRelationShip_(paul, julie).

isChild_(jean, marc, anne).
isChild_(jules, marc, anne).
isChild_(leon, marc, anne).
isChild_(jacques, jules, lisa).
isChild_(lisa, luc, betty).
isChild_(loic, luc, betty).
isChild_(gerard, luc, betty).
isChild_(paul, loic, eve).
isChild_(valerie, loic, eve).
isChild_(herve, leon, sylvie).
isChild_(julie, leon, sylvie).

femme(X) :-
	isWoman_(X).

homme(X) :-
	isMan_(X).

enfant_de(X, Y) :- isChild_(X, _, Y).
enfant_de(X, Y) :- isChild_(X, Y, _).

en_relation(X, Y) :- isRelationShip_(X, Y).
en_relation(X, Y) :- isRelationShip_(Y, X).

mari_de(X, Y) :-
	isMan_(X),
	isRelationShip_(X, Y).

femme_de(X, Y) :-
	isWoman_(X),
	isRelationShip_(Y, X).

beaupere_de(X, Y) :-
	isMan_(X),
	enfant_de(Z, X),
	en_relation(Z, Y).

bellemere_de(X, Y) :-
	isWoman_(X),
	enfant_de(Z, X),
	en_relation(Z, Y).

ancetre_de(X, Y) :-
	enfant_de(Y, X).

ancetre_de(X, Y) :-
	enfant_de(Z, X),
	ancetre_de(Z, Y).

%%% BONUS %%%

isWoman_(romane).
isWoman_(cindy).
isWoman_(philippa).
isMan_(roger).

isRelationShip_(jacques, romane).

isChild_(cindy, jacques, romane).
isChild_(philippa, jacques, romane).
isChild_(roger, jacques, romane).

frere_ou_soeur(X, Y) :-
	X \== Y,
	enfant_de(X, M),
	enfant_de(Y, M).

cousin_de(X, Y) :-
	enfant_de(X, X1),
	enfant_de(Y, Y1),
	enfant_de(X1, M),
	enfant_de(Y1, M),
	homme(M),
	X \== Y,
	not(frere_ou_soeur(X, Y)).

getParents(Name, List):-
	findall(X, enfant_de(Name, X), List).

getChilds(Name, List):-
	findall(X, enfant_de(X, Name), List).

getSiblings(Name, List):-
	findall(X, frere_ou_soeur(X, Name), List).

getCousins(Name, List):-
	findall(X, cousin_de(X, Name), List).