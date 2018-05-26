/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** If condition management
*/

#include "script.h"

char *pass_all_lines(shell_t *shell, FILE *fd)
{
	char *line = NULL;
	size_t n = 0;

	while (!line || !strcmp(line, "endif") || !strcmp(line, "else")) {
		if (line) {
			free(line);
			line = NULL;
			n = 0;
		}
		if (getline(&line, &n, fd) == -1) {
			shell->script = false;
			fclose(fd);
			return (NULL);
		}
	}
	return (line);
}

static char *pass_condition(shell_t *shell, cond_t *cond_line, FILE *fd)
{
	char *line = NULL;
	size_t n = 0;

	if (cond_line->command) {
		if (getline(&line, &n, fd) == -1) {
			shell->script = false;
			fclose(fd);
			return (NULL);
		}
		return (line);
	}
	line = pass_all_lines(shell, fd);
	free_cond_line(cond_line);
	cond_line = init_conditional_line();
	return (line);
}

char *if_management(shell_t *shell, cond_t *cond_line, FILE *fd)
{
	int status = 0;
	char *line = NULL;
	size_t n = 0;

	if ((status = check_script_condition(shell, cond_line)) == FAILURE)
		return (NULL);
	if (status == SUCCESS) {
		if (cond_line->command)
			return (strdup(cond_line->command));
		if (getline(&line, &n, fd) == -1) {
			shell->script = false;
			fclose(fd);
			return (NULL);
		}
		return (line);
	} else
		return (line = pass_condition(shell, cond_line, fd));
}
