/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Get the input from the terminal and returns it.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
#include "input.h"

char *get_chars_from_term(shell_t *shell, int fd)
{
	char *input = malloc(sizeof(char) * 1);
	int i = 0;
	int c = 0;

	if (input == NULL)
		return (NULL);
	input[i] = '\0';
	while (read(fd, &c, sizeof(int)) && c != EOT && c != '\n') {
		check_match_direct(input, c, &i, shell);
		i = cursor_moves(input, c, &i, shell->binding);
		// Check history
		// Check tabulation
		input = regular_char(input, c, &i, fd);
		c = 0;
	}
	return (c != EOT ? input : NULL);
}
