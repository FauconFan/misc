# PR6_IRC_UDP

Nous avons implémenté un chat en pair à pair en UDP, qui fonctionne grâce à un système de voisins et un protocole d’inondation. Vous pouvez trouver le sujet précis du projet au sein de notre projet git.

Auteurs:

- Raphaëlle Gauchée
- Joseph Priou

Vous pouvez trouver le sujet de notre projet ainsi qu'un compte rendu à la racine de notre projet.

## Manuel

``` sh
Help:
./irc_udp --no-ncurses --with-logs --no-juliusz-init --no-port --port NUM_PORT 

    --no-ncurses : launch the application in raw mode
    --with-logs : launch the application with logs on the screen
    --no-juliusz-init : launch the application without juliusz connexion
    --no-port : launch the application with no port specified
    --port NUM_PORT : launch the application with port NUM_PORT specified

If some contradicory informations are given, the last one is kept
```
