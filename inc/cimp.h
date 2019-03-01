#ifndef CIMP_H
#define	CIMP_H

#define	_POSIX_SOURCE

// Standards includes
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <string.h>

// SDL includes
#include <SDL.h>

// Typedef includes, needs to come first
#include "typedefs.h"

// Cimp includes
#include "commands.h"
#include "env.h"
#include "parser.h"
#include "utils.h"

#define	CIMP_PROMPT "cimp>> "

int initialize_readline(void);
int cimp_exe(t_parser_out * cmd);

#endif // ifndef CIMP_H
