
/*
**	Step 2 : tmilon & jpriou
**	Énigme d'Einstein
*/

persons(0, []) :- !.
persons(N, [(_Men,_Color,_Drink,_Smoke,_Animal)|T]) :- N1 is N-1, persons(N1,T).

person(1, [H|_], H) :- !.
person(N, [_|T], R) :- N1 is N-1, person(N1, T, R).

/*
**	q1 :- L’Anglais vit dans la maison rouge.
**	q2 :- Le Suédois a des chiens.
**	q3 :- Le Danois boit du thé.
**	q4 :- La maison verte est à gauche de la maison blanche.
**	q5 :- Le propriétaire de la maison verte boit du café.
**	q6 :- La personne qui fume des Pall Mall a des oiseaux.
**	q7 :- Le propriétaire de la maison jaune fume des Dunhill.
**	q8 :- La personne qui vit dans la maison du centre boit du lait.
**	q9 :- Le Norvégien habite dans la première maison.
**	q10 :- L’homme qui fume des Blend vit à côté de celui qui a des chats.
**	q11 :- L’homme qui a un cheval est le voisin de celui qui fume des Dunhill.
**	q12 :- Le propriétaire qui fume des Blue Master boit de la bière.
**	q13 :- L’Allemand fume des prince.
**	q14 :- Le Norvégien vit juste à côté de la maison bleue.
**	q15 :- L’homme qui fume des Blend a un voisin qui boit de l’eau.
**
*/

q1([(british,red,_, _, _)|_]).
q1([_|T]) :- q1(T).

q2([(sweden,_,_,_,dog)|_]).
q2([_|T]) :- q2(T).

q3([(danish,_,tea,_,_)|_]).
q3([_|T]) :- q3(T).

q4([(_,green,_,_,_),(_,white,_,_,_)|_]).
q4([_|T]) :- q4(T).

q5([(_,green,coffee,_,_)|_]).
q5([_|T]) :- q5(T).

q6([(_,_,_,pallmall,bird)|_]).
q6([_|T]) :- q6(T).

q7([(_,yellow,_,dunhill,_)|_]).
q7([_|T]) :- q7(T).

q8(Persons) :- person(3, Persons, (_,_,milk,_,_)).

q9(Persons) :- person(1, Persons, (norwegian,_,_,_,_)).

q10([(_,_,_,blend,_),(_,_,_,_,cat)|_]).
q10([(_,_,_,_,cat),(_,_,_,blend,_)|_]).
q10([_|T]) :- q10(T).

q11([(_,_,_,dunhill,_),(_,_,_,_,horse)|_]).
q11([(_,_,_,_,horse),(_,_,_,dunhill,_)|_]).
q11([_|T]) :- q11(T).

q12([(_,_,beer,bluemaster,_)|_]).
q12([_|T]) :- q12(T).

q13([(german,_,_,prince,_)|_]).
q13([_|T]) :- q13(T).

q14([(norwegian,_,_,_,_),(_,blue,_,_,_)|_]).
q14([(_,blue,_,_,_),(norwegian,_,_,_,_)|_]).
q14([_|T]) :- q14(T).

q15([(_,_,_,blend,_),(_,_,water,_,_)|_]).
q15([(_,_,water,_,_),(_,_,_,blend,_)|_]).
q15([_|T]) :- q15(T).

question([(_,_,_,_,fish)|_]).
question([_|T]) :- question(T).

solution(Persons) :-
  persons(5, Persons),
  q1(Persons),
  q2(Persons),
  q3(Persons),
  q4(Persons),
  q5(Persons),
  q6(Persons),
  q7(Persons),
  q8(Persons),
  q9(Persons),
  q10(Persons),
  q11(Persons),
  q12(Persons),
  q13(Persons),
  q14(Persons),
  q15(Persons),
  question(Persons).


display_men_for_fish(Men, fish) :-
	ansi_format([bold, bg(green)], '~w', [Men]).
display_men_for_fish(Men, _) :-
	ansi_format([bold, fg(green)], '~w', [Men]).

display_animal_for_fish(fish) :-
	ansi_format([bold, bg(blue)], '~w', [fish]).
display_animal_for_fish(Animal) :-
	ansi_format([bold, fg(blue)], '~w', [Animal]).

display([]).
display([(Men, Color, Drink, Smoke, Animal) | NEXT]) :-
	write('The '),
	display_men_for_fish(Men, Animal),
	write(' guy lives in the '),
	ansi_format([bold, fg(red)], '~w', [Color]),
	write(' house with his '),
	display_animal_for_fish(Animal),
	write('. He drinks '),
	ansi_format([bold, fg(magenta)], '~w', [Drink]),
	write(' and smokes '),
	ansi_format([bold, fg(cyan)], '~w', [Smoke]),
	write('.'),
	write('\n'),
	display(NEXT).

main() :-
	solution(X),
	display(X), !.
