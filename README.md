# 42 Expert System

The goal of this project is to an expert system for proposition calculus.

You have a list of axioms (a list of facts that is true), a list of rules (of kind: A => B + C), and a list of queries (a list of facts that you want to know).
The program detects if there is any inconsistency, during the solving task.

The algorithm is pretty stupid, and for a exponential problem, we don't use any heuristic, and we test everything.

The following symbols are defined, in order of decreasing priority:
 - ( and ) which are fairly obvious. Example : A + (B | C) => D
 - ! which means NOT. Example : !B
 - \+ which means AND. Example : A + B
 - | which means OR. Example : A | B
 - ˆ which means XOR. Example : A ˆ B
 - => which means "implies". Example : A + B => C
 - <=> which means "if and only if". Example : A + B <=> C

Exemple input :
```
(A + B) | C => E

=AB
?E
```

Exemple output :
```
Env:
Rules
(((A + B) | C) => E)
Table of truth
E : Undefined
C : Undefined
B : True
A : True

Step 1:
Depth 0:
From this formula : (((A + B) | C) => E)
We know:
	E is True
Step 2:
Depth 0:
We cannot deduce anything from the sets of rules...
So we are doing a dijunction on the variable C
Step 3:
Depth 1:
+ We suppose that C is True
Step 4:
Depth 1:
+ We suppose that C is False
Step 5:
Depth 1:
+ We take common values in both environments
==== FINAL ====
E : True
```

A step is just the moment when the program is doing something interesting, like deducing something or making a dijunction on a variable. There are a lot of substeps that are not displayed like verifying if a rule is consistent, or useful with the current table of truth.

## How to...

### Use the program

```
usage: python3 main.py [-i] [-v [-v...]] file
```

### Test program

```
make test_deduction
```

### Get the full subject

See the subject.pdf

# Authors

 - Gregory Monnier (gmonnier [at] student.42.fr)
 - Joseph Priou (jpriou [at] student.42.fr)
