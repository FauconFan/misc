# Phase d'analyse de la phase 1

Il s'agit du moment ou on analyse ce qu'on doit faire.

## Première étape - Delete Old Pot Neighbours

On supprime les voisins trop vieux (après 5 essais de connexions).

## Deuxième étape - Connect new Neighbour

On compte le nombre de voisin qu'on a, si on en a pas assez, c'est à dire moins que NB_NEI_MAX (on supposera au début que NB_NEI_MAX = 8), on regarde dans notre liste de voisins potentiels à qui on peut envoyer un hello court. Si on a déjà envoyé un hello court à un voisin potentiel on attend avant de lui en renvoyer un.

## Troisième étape - Go Away old Neighbours

On parcourt notre liste de voisins pour voir si on doit envoyer des Go Away à des voisins trop vieux. On ajoute les TLV qu'on doit envoyer à notre liste li_buffer_tlv_ip. Et on supprime les voisins.

## Quatrième étape - Send Long Hellos

On parcourt notre liste de voisins pour voir si on doit envoyer un hello long. On ajoute les TLV qu'on doit envoyer à notre liste li_buffer_tlv_ip.

## Cinquième étape - Go Away Ack missing

On parcourt notre liste des voisins à acquitter, si c'est la 5ème fois que l'on envoie le message, on lui envoie un go away, et on l'efface de notre environnement (voisins, voisins potentiels, messages à acquitter).

## Sixième étape - Resend messages non acquitted

On parcourt notre liste de message non acquittés pour voir à qui on doit renvoyer un message. On ajoute les TLV qu'on doit envoyer à notre liste li_buffer_tlv_ip.

## Septième étape - Send random Neighbour TLV

On peut ajouter un TLV neighbour de manière aléatoire.

## Huitième étape - Delete old messages to free space

On supprime les messages trop vieux, on incrémente le temps si jamais il n'y a pas eu acquittement.

## Étape finale

On envoie les TLV qui sont dans li_buffer_tlv_ip, et on les supprime de la liste.
