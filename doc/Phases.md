# Phases

Il y a 4 phases dans le développement de ce projet.

- Phase de mise en place.
- Phase de réflexion de structure de données
- Phase d'implémentation des algorithmes de communication.
- Phase de finalisation.

## Phase de mise en place

Cette phase sert à commencer le projet et est subdivisé en 3 sous phases :

- Écriture d'un protocole de communication UDP serveur/client sur chaque instance du programme.
- Interface utilisateur interaction avec l'utilisateur.
- Logger verbosity / filelog etc...

### Communication

Il faut une implémentation serveur en mode non bloquant, et une implémentation client pour envoyer des données bruts.

### Interface utilisateur

L'interface utilisateur devra permettre 2 choses : la lecture d'une entrée en mode non-bloquant et l'affichage d'un message (idéalement sur la ligne du dessus).

Il faut aussi qu'on puisse taper une "commande" à l'aide de slash '/', par exemple '/help' ou '/list'. Ce qui permet au programme (et non aux reste du réseau) pour avoir des informations supplémentaires. L'idée est que l'on puisse accéder aux données du programmes sur demande et non en regardant les logs...

Il faut que la structure qui gère les commandes soit dynamique, i.e. on doit pouvoir rajouter une commande très facilement.

Pour l'affichage du message, il faut qu'on puisse afficher les messages venant d'ailleurs mais également les messages venant du programme (à l'aide des commandes).

Chaque affichage est précédé de l'heure actuelle, format "[HH:MM:SS] | " suivi du message potentiellement d'un marqueur pour indiquer si il s'agit du programme ou d'un message provenant du réseau. Peut-être avec des codes couleurs également.

### Logger

Il faut avoir un fichier qui gère les logs au format printf, avec une gestion du degré de verbosity au lancement.

Les logs seront reportés à 2 endroits différents : dans le terminal et dans un fichier.

Les logs ne sont reportés dans le terminal que si le degré de verbosity au lancement du programme est assez haut.

Si un message est d'importance 2, et que le degré est 3 actuelle, alors le message est affiché. De même si le degré actuelle est de 1, alors le message n'est pas affichée. Si l'importance et le degré sont les mêmes, alors le message est affiché.

Par défaut le degré de verbosity est de 0, et aucun message n'est d'importance 0, en particulier l'importance d'un message est strictement positif.

Les logs sont toujours reportés dans un fichier .logs gitignoré dans le dossier actuelle. Au début du lancement du programme, le programme indique le chemin vers le fichier de log actuel. Dans ce fichier est conservé la date (jour + date), le degré d'importance du message et le message lui-même le tout sur une même ligne.

## Phase de réflexion de structure de données

Dans cette phase on réfléchit à quelles structures de données on doit adopter pour l'inondation, les protocoles de maintien de voisins en accord au sujet.

Il s'agit d'une phase de réflexion sans code.

On se met autour d'une table (avec une bière) et on discute structure de données à plusieurs niveaux, à savoir TODO

## Phase d'implémentation des algorithmes de communication

Ici, on implémente le protocole de communication imposé par le sujet, inondation maintien des voisins, déclaration recherche, etc... voir le sujet.

Ne pas oublier d'utiliser le logger pour tout... TOUT

## Phase de finalisation

Cette phase est là pour les détails. On doit finaliser le projet : documentation, commentaires, propreté de code, factorisation de code. Expliquer les choix bizarres...

## Après

T'y penses pas pour l'instant.