# Phases d'analyse de la phase 0
Il s'agit de la phase ou on a été réveillé par un message entrant.

### Si on connaît le sender :
On analyse le message :
- on ignore les Pad1 et PadN
- si c'est un hello (court ou long) on modifie la date du dernier hello reçu
- si c'est un hello long on modifie la date du dernier hello long reçu
- si c'est un neighbour on ajoute un neighbour potentiel à notre liste des voisins potentiels
- si c'est un data, on renvoie un acquittement, on affiche le message, on l'envoie à nos voisins et on ajoute le message à la liste des messages dont on attend un acquittement par voisins
- si c'est un ack, on enlève de la liste le message dont on attendait l'acquittement.
- si c'est un GoAway, on le supprime de la liste des voisins et on le met dans les voisins potentiels, on supprime également tous les messages dont on attendait un acquittement de sa part.
- si c'est un warning, on affiche le message

### Si on ne connaît pas le sender :
On analyse le message :
- si c'est un hello court, on regarde le nombre de voisins qu'on a, si on en a pas assez on lui renvoie un hello_long et on l'ajoute à notre liste de voisins
- si c'est un hello long, on l'ajoute à notre liste de voisins
- on ignore tout le reste  
