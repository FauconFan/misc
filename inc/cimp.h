#ifndef CIMP_H
#define	CIMP_H

#define	_POSIX_SOURCE

// Standards includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

// SDL includes
#include <SDL.h>

// Cimp includes
#include "typedefs.h"
#include "env.h"
#include "utils.h"
#include "parser.h"
#include "commands.h"

#define	CIMP_PROMPT "cimp>> "

int initialize_readline(void);
void cimp_exe(t_parser_out * cmd);

#endif // ifndef CIMP_H
