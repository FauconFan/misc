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

On admet que le Else se rattache au dernier If croisé (hors Begin End)  

## To Do List

 - [ ] Créer le flex
 - [ ] Créer le Parser
 - [ ] Gestion des variables

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
| operator | "+" \| "-" \| "/" \| "*" |
| identificateur | [a-z][a-zA-Z]* |
| program | {instructions-next} |
| instructions-next | {instruction} ; {instructions-next} \| &#x3b5; |
| instruction | ##Exec Instruction <br> DrawCircle ( {expr} , {expr} , {expr} , {couleur} ) <br> FillCircle ( {expr} , {expr} , {expr} , {couleur} ) <br> DrawRect ( {expr} , {expr} , {expr} , {expr} , {couleur} ) <br> FillRect ( {expr} , {expr} , {expr} , {expr} , {couleur} ) <br> ##Control Instruction <br> Begin {instructions-next} End <br> If {expr} Then {instruction } Else {instruction} <br> If {expr} Then {instruction} <br> While {expr} Do {instruction} Done <br> ##Imp Instruction <br> Const {identificateur} = {expr} <br> Var {identificateur} = {expr} <br> {identificateur} = {expr} |
| expr | {nombre} \| ( {expr} {operator} {expr} ) \| {identificateur} |

## Auteurs / Contributeurs
- Pierre Gimalac
- Joseph Priou
