# Doc

Ce document présente la documentation finale de ce projet. C'est un idéal. Au fur et à mesure du développement nous compléterons ce document en le perfectionnant.

Ce document ne traite que de la partie obligatoire de ce projet.  

## Structure idéale

```
#define NB_SCREENS	4

typedef struct      s_cimp_select
{
	SDL_Rect        surface;
	int             id_screen;
}                   t_cimp_select;

typedef struct      s_cimp_screen
{
	SDL_Window      *window;
	SDL_Surface     *buff_screen;
	char            *original_name;
}                   t_cimp_screen;

typedef struct      s_cimp
{
	t_cimp_screen   screens[NB_SCREENS];
	t_cimp_select   *select;
	SDL_Surface     *copy_buffer;
}                   t_cimp;
```

NB_SCREENS correspond à la valeur maximale d' écrans qu'il est permit d'ouvrir simultanément.

Chaque image est représentée par un identifiant (son index dans le tableau).

La structure t_cimp_select stocke la zone sélectionnée ainsi que l'identifiant de l'écran.

La structure t_cimp_screen stocke toutes les informations nécessaires pour manipuler l'image. window est la structure renvoyée par SDL_CreateWindow, et buff_screen est une copie de ce qui est affiché à l'écran.

La structure t_cimp est la structure globale de notre projet. Elle est donc composée de NB_SCREENS screens, des informations concernant la sélection, et un buffer qui désigne la partie copié ou coupé.

## Ensemble des actions

Ici est listé l'ensemble des commandes que doit gérer notre programme.  
Au début se situe la liste complète puis une description plus détaillée.

Le caractère '?' signifie que l'argument est optionnel.  
La notation [...] désigne juste un argument.  
La notation [...|...] désigne un type d'agument ou un autre. (e.g.: [NAME|ID]).  

Pour simplifier la lecture, nous utiliseront les raccourcis suivants :
 - [RECT] <~> [X0] [Y0] [W] [H]
 - [COLOR] <~> [[R] [G] [B]|[RGB]]
 - [NAME] <~> [? [NAME|ID]]

RECT désigne 4 arguments.  
COLOR permet d'écrire une couleur sous la forme décimale ou héxadécimale. (e.g: 255 0 0 ou FF00000)
NAME permet de savoir de qu'elle image on parle.  
Si il y a plus d'une image, l'argument NAME est obligatoire.  
Si la commande est open, l'argument NAME est obligatoire et ne peut pas être un ID.  
En particulier si il n'y a qu'une seule image, NAME est un argument optionnelle.

```
cimp>> help
 - help
 - open [NAME]
 - close [NAME]
 - list
 - save [NAME] [?PATH]
 - update [NAME] [?PATH]
 - select [NAME] [RECT]
 - unselect
 - cut [? [NAME] [RECT]]
 - copy [? [NAME] [RECT]]
 - paste [NAME] [X0] [Y0]
 - sym_verti [NAME] [? [RECT]]
 - sym_hori [NAME] [? [RECT]]
 - rotate [NAME] [ANGLE]
 - crop_reduce [NAME] [? [COORD]]
 - crop_extend [NAME] [? [COORD]]
 - scale [NAME] [xN|[W] [H]]
 - fill [NAME] [? [RECT]] [COLOR]
 - color_replace [NAME] [? [RECT]] [COLOR] [COLOR] [MARGIN]
 - color_negative [NAME] [? [RECT]]
 - color_gray [NAME] [? [RECT]]
 - color_white_black [NAME] [? [RECT]] [? [MARGIN]]
 - ajust_light_contrast [NAME] [???]
```

Pour les commandes après la commande list, l'action ne s'applique que sur [NAME] (dans le cas où il y a plusieurs images).

### open

open permet d'ouvrir une nouvelle image si le nombre total de fenêtre déjà ouverte n'est pas atteint.

### close

close permet de fermer une image SANS SAUVEGARDER. Le nom est le nom original de la photo, et l'id est récupéré depuis la commande list.

### list

list permet de lister (lol) les différentes images ouvertes. list affichera un ensemble d'information cohérentes sous forme d'un tableau.

Exemple:
```
cimp>> list

NAME			ID		TAILLE		FILEPATH
fleur.img		1		640x480		/home/.../cimp/tests/fleur.img
```

### save

save permet de sauvegarder l'image NAME|ID dans le chemin PATH, si le chemin PATH n'est pas spécifié, on sauvegarde l'image avec le chemin initial (utilisé pour charger l'image).

### update

update permet de recharger une image depuis le chemin donné. Si le chemin donné n'est pas spécifié, on recharge l'image depuis son chemin originel.

### select

select définit la zone sélectionnée (un rectangle) par le point de coordonnée (X0, Y0) qui désigne le point le plus en bas à gauche de l'image, puis le rectangle est de taille W * H. Si le name (ou l'identifiant) n'est pas spécifié et qu'il y a plus qu'une image, produit une erreur.

### unselect

unselect efface les coordonnées de la zone en mémoire.

### cut/copy/paste

cut copie la zone sélectionnée (ou donnée en argument) et la garde en mémoire, et remplace la zone sélectionnée par du blanc.  
copy fait la même chose mais n'efface pas la zone sélectionnée.  
paste copie la zone en mémoire aux coordonnées spécifiées.

### sym_verti/symm_hori

Ces deux commandes appliquent une symétrie verticale ou horizontale sur la zone sélectionnée.

### rotate

rotate est une commande qui prend un angle en argument (multiple de 90) et qui tourne l'image de ANGLE degré dans le sens horaire.

### crop_reduce/crop_extend

Ces commandes correspondent à la modification de l'espace de travail.  
crop_reduce réduit l'image a l'aide d'un découpage rectangulaire.  
crop_extend agrandit l'espace de travail (avec des pixels blancs)

### scale

scale est une commande qui agrandit/réduit l'espace de travail ainsi que la taille de l'image.
Les arguments sont  soit un facteur multiplicatif (e.g: scale x1.2), soit une nouvelle taille.

### fill

fill est une commande qui remplit un rectangle (ou la zone sélectionnée par une couleur)

### color_replace

color_replace est une commande qui remplace une couleur par une autre dans une zone sélectionnée avec une marge de tolérance pour la couleur remplacée.

### color_negative

color_negative inverse toutes les composantes RGB de tous les pixels de la zone sélectionnée.

### color_gray

color_gray remplace tous les pixels de la zone sélectionnée par son équivalent en variation de gris

### color_white_black

color_white_black remplace toutes les couleurs de la zone sélectionnée par blanc ou noir en respectant la règle suivante:

Si margin n'est pas donnée, elle vaut 128.

Si le représentant en variation de gris du pixel traité est plus grand (ou égale) que le margin alors le nouveau pixel est de couleur noir sinon il est de couleur blanc.

### ajust_light_contrast

À voir, se renseigner sur l'ajustement de la lumière et du contraste.

## To see later

 - Gérer les actions partielles
 - Gérer les actions faites sur l'interface graphique
