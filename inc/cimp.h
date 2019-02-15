#ifndef CIMP_H
#define	CIMP_H

#define	_POSIX_SOURCE

// Standards includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>

#include <string.h>

// SDL includes
#include <SDL.h>

// Cimp includes
#include "typedefs.h"
#include "env.h"
#include "utils.h"
#include "parser.h"

#define	CIMP_PROMPT "cimp>> "

char * cimp_readline(void);

#endif // ifndef CIMP_H
