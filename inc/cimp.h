#ifndef CIMP_H
#define	CIMP_H

#define	_POSIX_SOURCE

// Standards includes
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>

// SDL includes
#include <SDL.h>

// Typedef includes, needs to come first
#include "typedefs.h"

// Cimp includes
#include "env.h"
#include "parser.h"
#include "utils.h"
#include "commands.h"

#define	CIMP_PROMPT "cimp>> "

char * cimp_readline(void);

#endif // ifndef CIMP_H
