# Phases d'analyse de la phase 0

Il s'agit de la phase ou on a été réveillé par le réseau, un message tapé par l'utilisateur ou un timeout.

## Réveillé par le réseaux

### Si on connaît le sender

On analyse le message :

- on ignore les Pad1 et PadN
- si c'est un hello (court ou long) on modifie la date du dernier hello reçu
- si c'est un hello long on modifie la date du dernier hello long reçu
- si c'est un neighbour on ajoute un neighbour potentiel à notre liste des voisins potentiels, si il n'y est pas déjà, et si on est pas déjà voisin avec lui.
- si c'est un data, on met un acquittement dans li_buffer_tlv_ip, on affiche le message si c'est la première fois, on l'ajoute à li_buffer_tlv_ip par voisins hormis le voisin qui nous l'a envoyé et à la liste des messages dont on attend un acquittement par voisins
- si c'est un ack, on enlève de la liste le message dont on attendait l'acquittement.
- si c'est un GoAway, on le supprime de la liste des voisins et on le met dans les voisins potentiels, on supprime également tous les messages dont on attendait un acquittement de sa part.
- si c'est un warning, on affiche le message.

### Si on ne connaît pas le sender

On analyse le message :

- si c'est un hello court, on regarde le nombre de voisins qu'on a, si on en a pas assez on lui renvoie un hello_long sinon on l'ajoute à la liste des voisins potentiels
- si c'est un hello long, on l'ajoute à notre liste de voisins, le supprime des voisins potentiels s'il y était et on lui renvoie un hello long pour la bidirectionnalité.
- on ignore tout le reste.  

## Réveillé par un message de l'utilisateur

Construit le message, on l'ajoute à la liste li_buffer_tlv_ip par voisins et à la liste des messages dont on attend un acquittement par voisins.

## Réveillé par un timeout

Passage à la [phase 1](Phase1_Analyse.md) directement.
