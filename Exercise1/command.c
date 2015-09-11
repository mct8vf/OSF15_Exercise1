#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "command.h"

#define MAX_CMD_COUNT 50
#define MAX_CMD_LEN 25

	//TODO 4
	//TODO FUNCTION COMMENT
	/*
 * PURPOSE: To parse or split up some input(commands) and store the individual commands into an array
 * INPUTS:	char* input which is to be parsed, Commands_t** cmd where the commands are to be stored
 * RETURN:	'true' of operation compeleted without issue, false if otherwise
 **/
bool parse_user_input (const char* input, Commands_t** cmd) {
	
	//TODO ERROR CHECK INCOMING PARAMETERS
	if((!input)||(!cmd))
		return false;
	char *string = strdup(input);
	
	*cmd = calloc (1,sizeof(Commands_t));
	(*cmd)->cmds = calloc(MAX_CMD_COUNT,sizeof(char*));

	unsigned int i = 0;
	char *token;
	token = strtok(string, " \n");
	for (; token != NULL && i < MAX_CMD_COUNT; ++i) {
		(*cmd)->cmds[i] = calloc(MAX_CMD_LEN,sizeof(char));
		if (!(*cmd)->cmds[i]) {
			perror("Allocation Error\n");
			return false;
		}	
		strncpy((*cmd)->cmds[i],token, strlen(token) + 1);
		(*cmd)->num_cmds++;
		token = strtok(NULL, " \n");
	}
	free(string);
	return true;
}

	//TODO FUNCTION COMMENT
	/*
 * PURPOSE: Free the list of commands
 * INPUTS:	Commands_t** cmd containing the commands to be deleted
 * RETURN:	None
 **/
void destroy_commands(Commands_t** cmd) {

	//TODO ERROR CHECK INCOMING PARAMETERS
	if(!cmd)
	{
		printf("Error: NULL\n");
	}
	else{
		
		for (int i = 0; i < (*cmd)->num_cmds; ++i) {
			free((*cmd)->cmds[i]);
		}
		free((*cmd)->cmds);
		free((*cmd));
		*cmd = NULL;
	}
}

