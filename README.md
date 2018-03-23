# ADS4_Project - GraphTXT
Le but de ce projet est de créer un parser/lexer d'un langage donnée.  
La grammaire est spécifié dans ce fichier.  
Le projet est codé en Java.  
On utiliser jflex en tant que dépendance.  
Le code est écrit en Anglais.  
On accepte les fichiers en extension 'gtxt'.  

Pour gérer la portée des variables, on utiliser la structure suivante :  
```
HashMap <Integer, HashMap<String, Integer>>
```
où la première clé est le niveau de profondeur (le niveau de profondeur commence à 0, s'incrémente avec Begin et se décrémente avec End)  

On admet que le Else se rattache au dernier If croisé (hors Begin End) (Dangling Else Problem)

Gestion de la portée des variables :
 - Si une variable est défini dans un bloc de profondeur d, si on essaie d'accéder à cette varible dans un bloc de profondeur inférieur, on a une erreur sémantique
 - Une variable ne peut pas étre redéfini dans le même bloc, mais elle peut être redéfini dans un bloc plus profond, elle reprend son ancienne valeur quand on quitte ce sous-bloc
 - Une constante ne peut être modifié

On fait une interprétation en plusieurs étapes :
 1. Analyse lexical (jflex)
 2. Analyse syntaxique (création de l'AST)
 3. Analyse sémantique (gestion de la portée de variables)
 4. Evaluation de l'AST (éxécution)

## To Do List

 - [x] Créer le flex
 - [x] Créer le Parser
 - [x] Créer l'arbre de syntaxe abstraite (AST)
 - [x] Gestion des variables Analyse sémantique
 - [x] Evaluation

## Idées

 - [ ] Faire une évaluation booléenne
 - [ ] Faire une vidéo
 - [ ] Savoir si un fichier est correctement parsé pour de l'intégration continue (Travis CI)
 - [ ] Pouvoir définir des fonctions
 - [ ] Pouvoir définir des structures

## Grammaire Lexicale

| Identifier | Content |
| ---------- | ------- |
| nombre | [0-9]+ |
| hex | [0-9A-F] |
| couleur | #{hex}{hex}{hex}{hex}{hex}{hex} |
| operator | "+" <br> "-" <br> "/" <br> "*" |
| identificateur | [a-z][a-zA-Z_]* |
| program | {instructions-next} |
| instructions-next | {instruction} ; {instructions-next} <br> &#x3b5; |
| instruction | <b>## Exec Instruction</b> <br> DrawCircle ( {expr} , {expr} , {expr} , {couleur} ) <br> FillCircle ( {expr} , {expr} , {expr} , {couleur} ) <br> DrawRect ( {expr} , {expr} , {expr} , {expr} , {couleur} ) <br> FillRect ( {expr} , {expr} , {expr} , {expr} , {couleur} ) <br> <b>## Control Instruction</b> <br> Begin {instructions-next} End <br> If {expr} Then {instrument} {if_follow} <br> While {expr} Do {instruction} Done <br> <b>## Imp Instruction</b> <br> Const {identificateur} = {expr} <br> Var {identificateur} = {expr} <br> {identificateur} = {expr} |
| if_follow | Elif {expr} Then {instruction} {if_follow} <br> Else {instruction} <br> &#x3b5; |
| expr | {nombre} <br> ( {expr} {operator} {expr} ) <br> {identificateur} |

## Auteurs / Contributeurs
- Pierre Gimalac
- Joseph Priou
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
