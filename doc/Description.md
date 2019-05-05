# Description du projet

Au lancement du programme, notre environnement est initialisé, la liste des voisins est vide, ainsi que la liste des voisins potentiels, on n'a pas de message reçu, ni de message dont on attend un acquittement, ni de message à envoyer, notre id est tiré au hasard et notre socket est construite grâce à la fonction build_socket.

``` c
typedef struct      s_env{
    uint64_t id;
    int      socket;
    t_list * li_neighbours;
    t_list * li_potential_neighbours;
    t_list * li_messages;
    t_list * li_acquit;
    t_list * li_buffer_tlv_ip;
}                   t_env;
```

On ajoute Juliusz à la liste des voisins potentiels.
Le terminal est modifié grâce à ncurses, il est séparé en deux parties, une pour afficher ce qu'on reçoit et une autre pour taper un message sans être dérangé par des messages entrant.
On peut également lancer le programme avec l'option --no-ncurses qui lance le programme directement dans le terminal sans le modifier.
Ensuite la fonction core_loop est appelé, il s'agit de la partie qui fait tourner la boucle principale. Elle attend de faire une action avec select, qui bloque jusqu'à recevoir un message sur le chat, recevoir un message de l'utilisateur ou la fin du timeout. Elle redirige ensuite vers les fonctions adapté [cf Phase0](Phase0_Analyse.md).

Pour quitter le programme il suffit de taper QUIT dans le terminal.
