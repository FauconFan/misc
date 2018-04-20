# ADS4_Project - GraphTXT [![Build Status](https://travis-ci.com/FauconFan/ADS4_Project.svg?token=2sRmqJj9p4TAy8ScMWxd&branch=master)](https://travis-ci.com/FauconFan/ADS4_Project)

Le but de ce projet est de créer un parser/lexer d'un langage donnée.  
La grammaire est spécifié dans ce fichier.  
Le projet est codé en Java.  
On utiliser jflex en tant que dépendance.  
Le code est écrit en Anglais.  
On accepte les fichiers en extension 'gtxt'.  

Pour gérer la portée des variables, on utilise la structure suivante :  
```
HashMap <Integer, HashMap<String, AccessData> >

public class AccessData
{
	private final boolean is_cst;
	private int value;

	public AccessData(boolean is_cst, int value)
	{
		this.is_cst = is_cst;
		this.value  = value;
	}

	...
}
```
où la première clé est le niveau de profondeur (le niveau de profondeur commence à 0, s'incrémente avec Begin et se décrémente avec End)  

On admet que le Else se rattache au dernier If croisé (hors Begin End) (Dangling Else Problem)

Gestion de la portée des variables :
 - Si une variable est définie dans un bloc de profondeur d, si on essaie d'accéder à cette varible dans un bloc de profondeur inférieure à d, on a une erreur sémantique
 - Une variable ne peut pas étre redéfinie dans le même bloc, mais elle peut être redéfinie dans un bloc plus profond, elle reprend son ancienne valeur quand on quitte ce sous-bloc
 - Une constante ne peut être modifiée

On fait une interprétation en plusieurs étapes :
 1. Analyse lexicale (jflex)
 2. Analyse syntaxique (création de l'AST)
 3. Analyse sémantique (gestion de la portée de variables)
 4. Evaluation de l'AST (éxécution)

## To Do List

 - [x] Créer le flex
 - [x] Créer le Parser
 - [x] Créer l'arbre de syntaxe abstraite (AST)
 - [x] Gestion des variables Analyse sémantique
 - [x] Evaluation

## Bonus

 - [x] Faire une boucle While
 - [x] Faire une boucle For (peut être améliorée)
 - [x] Faire des Elif
 - [x] Faire des Exceptions avec le numéro de la ligne et de la colonne
 - [x] Intégration Continue - Travis
 - [x] Création de fonctions systèmes:
 	- Exit

## Idées - Bonus

 - Créer des variables Booléenne, String, Couleurs
 - Faire une évaluation booléenne
 - Faire une vidéo
 - Pouvoir définir des fonctions
 - Pouvoir définir des structures
 - Faire une interprétation dynamique des erreurs (afficher toutes les erreurs et pas juste la première erreur croisée)

## Grammaire Lexicale

| Identifier | Content |
| ---------- | ------- |
| nombre | [0-9]+ |
| hex | [0-9A-F] |
| couleur | #{hex}{hex}{hex}{hex}{hex}{hex} |
| operator | "+" <br> "-" <br> "/" <br> "*" |
| identificateur | [a-z][a-zA-Z_]* |
| <i><b>program</b></i> | <i><b>{instructions-next}</i></b> |
| <i><b>instructions-next</i></b> | <i><b>{instruction}</i></b> ; <i><b>{instructions-next}</i></b> <br> &#x3b5; |
| <i><b>instruction</i></b> | <i>## Exec Instruction</i> <br> DrawCircle ( <i><b>{expr}</i></b> , <i><b>{expr}</i></b> , <i><b>{expr}</i></b> , {couleur} ) <br> FillCircle ( <i><b>{expr}</i></b> , <i><b>{expr}</i></b> , <i><b>{expr}</i></b> , {couleur} ) <br> DrawRect ( <i><b>{expr}</i></b> , <i><b>{expr}</i></b> , <i><b>{expr}</i></b> , <i><b>{expr}</i></b> , {couleur} ) <br> FillRect ( <i><b>{expr}</i></b> , <i><b>{expr}</i></b> , <i><b>{expr}</i></b> , <i><b>{expr}</i></b> , {couleur} ) <br> <i>## System Instruction</i> <br> Exit ( <i><b>{expr}</i></b> ) <br> <i>## Control Instruction</i> <br> Begin <i><b>{instructions-next}</i></b> End <br> If <i><b>{expr}</i></b> Then <i><b>{instrument}</i></b> <i><b>{if_follow}</i></b> <br> While <i><b>{expr}</i></b> Do <i><b>{instruction}</i></b> <br>For ( <i><b>{instruction}</i></b> ; <i><b> {expr} </i></b> ; <i><b>{instruction}</i></b> ) Then <i><b>{instruction}</i></b> <br> <i>## Imp Instruction</i> <br> Const {identificateur} = <i><b>{expr}</i></b> <br> Var {identificateur} = <i><b>{expr}</i></b> <br> {identificateur} = <i><b>{expr}</i></b> |
| <i><b>if_follow </i></b>| Elif <i><b>{expr}</i></b> Then <i><b>{instruction}</i></b> <i><b>{if_follow}</i></b> <br> Else <i><b>{instruction}</i></b> <br> &#x3b5; |
| <i><b>expr</i></b> | {nombre} <br> ( <i><b>{expr}</i></b> {operator} <i><b>{expr}</i></b> ) <br> {identificateur} |

## Auteurs / Contributeurs
- Pierre Gimalac
- Joseph Priou
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
