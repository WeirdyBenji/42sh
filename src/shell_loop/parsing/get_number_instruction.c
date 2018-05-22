/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Get the number of instruction in the user input.
*/

#include <stdlib.h>
#include "instruction.h"

static unsigned int seek_next_separator(char *user_input, int *i)
{
	while (user_input[*i] && (user_input[*i] == INSTRUCTION_SEPARATOR
	|| user_input[*i] == ' ' || user_input[*i] == OR_INSTRUCTION_SEPARATOR
	|| user_input[*i] == AND_INSTRUCTION_SEPARATOR)) {
		(*i)++;
	}
	if (user_input[*i] == '\0')
		return (0);
	return (1);
}

unsigned int get_number_instruction(char *user_input)
{
	unsigned int instruction = 1;

	for (int i = 0; user_input[i]; i++) {
		if (INSTRUCTION_SEPARATOR_ALL(user_input, i)) {
			instruction += seek_next_separator(user_input, &i);
		}
	}
	return (instruction);
}
