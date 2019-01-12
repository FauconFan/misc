
#include "atpt.h"

void	print_header(void)
{
	time_t	t;
	size_t	len[3];
	char	*date;

	ioctl(1, TIOCGWINSZ, &g_atpt->ws);
	t = time(NULL);
	date = ctime(&t);
	len[0] = strlen(date);
	len[1] = strlen(g_atpt->file);
	len[2] = strlen(PREFIX_HEADER_FILE);
	if (len[0] + len[1] + len[2] + 10 > g_atpt->ws.ws_col)
	{
		printf("%*s", g_atpt->ws.ws_col, date);
		printf("%s%s\n", PREFIX_HEADER_FILE, g_atpt->file);
	}
	else
		printf("%s%s%*s",
			PREFIX_HEADER_FILE,
			g_atpt->file,
			(int)(g_atpt->ws.ws_col - len[1] - len[2]),
			date);
	printf("%s%s\n", PREFIX_HEADER_CMD, g_atpt->cmd);
	printf("\n");
}
