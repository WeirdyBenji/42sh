/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Init all the paths inside the shell
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "mylib.h"

static char *init_alias_home(char **env)
{
	char *home = my_get_env(env, "HOME");
	char *path = my_strcpy(NULL, "/.alias42");
	char *alias = NULL;
	int i = 0;

	if (home == NULL)
		home = my_strcpy(NULL, ".\0");
	alias = malloc(sizeof(char) * (strlen(path) + strlen(home) + 1));
	if (alias == NULL)
		return (NULL);
	for (int a = 0; home[a]; a++) {
		alias[i] = home[a];
		i++;
	}
	for (int a = 0; path[a]; a++) {
		alias[i] = path[a];
		i++;
	}
	alias[i] = '\0';
	return (alias);
}

static char *init_history_home(char **env)
{
	char *home = my_get_env(env, "HOME");
	char *path = my_strcpy(NULL, "/.history42");
	char *history = NULL;
	int i = 0;

	if (home == NULL)
		home = my_strcpy(NULL, ".\0");
	history = malloc(sizeof(char) * (strlen(path) + strlen(home) + 1));
	if (history == NULL)
		return (NULL);
	for (int a = 0; home[a]; a++) {
		history[i] = home[a];
		i++;
	}
	for (int a = 0; path[a]; a++) {
		history[i] = path[a];
		i++;
	}
	history[i] = '\0';
	return (history);
}

char **init_paths(char **env)
{
	char **paths = malloc(sizeof(char *) * 3);

	paths[0] = init_alias_home(env);
	paths[1] = init_history_home(env);
	paths[2] = NULL;
	return (paths);
}