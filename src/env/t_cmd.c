#include "cimp.h"

t_cmd * cmd_alloc() {
	t_cmd * cmd;

	if ((cmd = malloc(sizeof(t_cmd))) == NULL) {
		return (NULL);
	}
	cmd->cmd     = NULL;
	cmd->name    = NULL;
	cmd->num     = 0;
	cmd->rect.x  = -1;
	cmd->rect.y  = -1;
	cmd->rect.w  = -1;
	cmd->rect.h  = -1;
	cmd->point.x = -1;
	cmd->point.y = -1;
	memset(cmd->color, 0, sizeof(cmd->color));
	return (cmd);
}

void cmd_free(t_cmd * cmd) {
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->name)
		free(cmd->name);
	free(cmd);
}
