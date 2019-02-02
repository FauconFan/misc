
#ifndef CIMP_H
# define CIMP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

# include <string.h>

# include <SDL.h>

# define CIMP_PROMPT	"cimp>> "

char			*cimp_readline(void);

#endif
