#include "irc_udp.h"

static int		loop(char **buff_prog)
{
	char	*tmp;
	char	*buff;
	int		ret;

	buff = 0;
	ret = 0;
	if (strchr(*buff_prog, '\n') == 0)
		buff = strnew(2);
	while (strchr(*buff_prog, '\n') == 0)
	{
		bzero(buff, 2);
		if ((ret = read(0, buff, 1)) == -1)
			break ;
		if (ret == 0)
			break ;
		buff[ret] = '\0';
		tmp = strjoin(*buff_prog, buff);
		free(*buff_prog);
		*buff_prog = tmp;
		if (strlen(buff) < 1)
			break ;
	}
	if (buff != 0)
		free(buff);
	return ((ret == -1) ? -1 : 0);
}

static int		gnl_stdin(char **line)
{
	size_t len;

	if (line == 0 || read(0, 0, 0) < 0 || (*line = malloc(1)) == NULL)
		return (-1);
	*line[0] = 0;
	if (loop(line) == -1)
		return (0);
	len = strlen(*line);
	if (len > 0 && (*line)[len - 1] == '\n')
		(*line)[len - 1] = '\0';
	return (1);
}

char            *ui_read_pseudo(void) {
    char    *line;

    if (gnl_stdin(&line) <= 0) {
        if (line != NULL)
            free(line);
        return (NULL);
    }
    return (line);
}