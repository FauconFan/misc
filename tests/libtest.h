#ifndef LIBTEST_H
#define	LIBTEST_H

#include <check.h>
#include "cimp.h"
TCase *modif_test();
TCase *window_test();
TCase *parsing_test();

t_bool compareSurfaces(SDL_Surface * surf1, SDL_Surface * surf2);

#endif
