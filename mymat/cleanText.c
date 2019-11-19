
#include "cleanText.h"

/*
*	Recursive function, Receives input from the user and during operation:
*	1. Clears white characters from input
*	2. Sets the input according to a neat format 
*	<opcode> <operand>,<operand>,<operand>...
*/

int CleanText (char *buffer, int i)
{
	char tempc; /* Saving temporary character */
	int flag = 0; /* Flag to mark first word in command */


	/* Checks whether this is the beginning of the command */
	if (i==0)
	{
		while ( ( (tempc=getchar()) == ' ') || (tempc == '\t') || (tempc == '\n') );
		flag = 1;
	}
	else
	{
		while ( ( (tempc=getchar()) == ' ') || (tempc == '\t') );
		flag = 0;
	}
	
	
	/*  String finishes if: Line break character / Input end character / The bumper is full     */
	if ( (tempc == '\n') || ( i==(MAX_CHAR_CMD-1) || (tempc == '\0')) || (tempc == EOF))
	{
		*(buffer+i) = '\0';

		if(tempc == EOF)	/*End input!*/
			return -1;
	
		return 0;
	}
	
	*(buffer+i) = tempc;
	i++;

	if ( (tempc == ',') && (flag!=1) )
	{
		*(buffer+i) = '\t';
		i++;
	}


	/* Retrieves a string of characters for buffer */
	while ( (i<(MAX_CHAR_CMD-1)) && ( (tempc=getchar()) != ' ') && (tempc != '\t') && (tempc != '\n') && (tempc != '\0') )
	{
		*(buffer+i) = tempc;
		i++;

		if ( tempc == ',') /*&& (flag!=1) )*/
		{
			*(buffer+i) = '\t';
			i++;
		}
		
	}
	
	/*  String finishes if: Line break character / Input end character / The bumper is full     */
	if ( (tempc == '\n') || ( i==(MAX_CHAR_CMD-1) || (tempc == '\0')) || (tempc == EOF) )
	{
		*(buffer+i) = '\0';

		if(tempc == EOF) 	/*End input!*/
			return -1;
			
		return 0;
	}
	
	/* End word */
	/*if ( (tempc == ',') && (flag!=1) )*/

	if ( *(buffer+i-1) != '\t') 
	{
		*(buffer+i) = '\t';
		i++;
	}

	/* ecursive reading, continue reading command line */
	return CleanText(buffer,i);
}



/*
*Reset the buffer before use
*/
void clearbuffer (char *buffer)
{
	int i;
	for (i=0;i<MAX_CHAR_CMD;i++)
	{
		*(buffer+i)=0;
	}
}




