# Phase 3 Hippocampe

La phase 3 désigne une phase transitoire entre le travail de la phase 2 et la fin de la partie obligatoire du projet.

Il suffit juste de faire fonctionner le multi fenêtre.

```
#define NB_SCREENS	4

typedef struct      s_cimp
{
	t_cimp_screen   screen[NB_SCREENS];
	int             running;
    int             focus;
	t_cimp_select * select;
	t_cimp_event *  event;
	SDL_Surface *   copy_buffer;
}                   t_cimp;
```

Valeur par défaut de focus : -1

Le focus est changé automatiquement sur un appel de open. Sur un appel explicit de fonction sur une image ou sur un clic d'une fenêtre.

Si on close une fenêtre dont c'est le focus. Le focus devient -1.

Si une commande nécessite le focus et le focus vaut -1. La commande échoue.

## Modification parser

Pouvoir expliciter la sélection de focus au sein de n'importe quelle commande qui en nécessite.

## Modication commandes actuelles

Il faut adapter toutes les commandes pour qu'elles s'adaptent à ce nouveau fonctionnement.

## Ajout de la commande focus

La commande focus permet de modifier le focus actuel du programme.
