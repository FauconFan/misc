# Phase d'analyse de la phase 1

Il s'agit du moment ou on analyse ce qu'on doit faire.

## Première étape

On compte le nombre de voisin qu'on a, si on en a pas assez, c'est à dire moins que NB_NEI_MAX (on supposera au début que NB_NEI_MAX = 8), on regarde dans notre liste de voisins potentiels à qui on peut envoyer un hello court. Si on a déjà envoyé un hello court à un voisin potentiel on attend avant de lui en renvoyer un.

## Deuxième étape

On parcourt notre liste de voisins pour voir si on doit envoyer des Go Away à des voisins trop vieux. On ajoute les TLV qu'on doit envoyer à notre liste li_buffer_tlv_ip. Et on supprime les voisins.

## Troisième étape

On parcourt notre liste de voisins pour voir si on doit envoyer un hello long. On ajoute les TLV qu'on doit envoyer à notre liste li_buffer_tlv_ip.

## Quatrième étape

On parcourt notre liste des voisins à acquitter, si c'est la 5ème fois que l'on envoie le message, on lui envoie un go away, et on l'efface de notre environnement (voisins, voisins potentiels, messages à acquitter).

## Cinquième étape

On parcourt notre liste de message non acquittés pour voir à qui on doit renvoyer un message. On ajoute les TLV qu'on doit envoyer à notre liste li_buffer_tlv_ip.

## Sixième étape

On peut ajouter un TLV neighbour de manière aléatoire.

## Septième étape

On envoie les TLV qui sont dans li_buffer_tlv_ip, et on les supprime de la liste.
