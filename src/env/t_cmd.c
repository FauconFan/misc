#include "cimp.h"

t_cmd * cmd_alloc() {
	t_cmd * cmd;

	if ((cmd = malloc(sizeof(t_cmd))) == NULL) {
		return (NULL);
	}
	memset(cmd, 0, sizeof(t_cmd));
	return (cmd);
}

void cmd_free(t_cmd * cmd) {
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->name)
		free(cmd->name);
	free(cmd);
}
