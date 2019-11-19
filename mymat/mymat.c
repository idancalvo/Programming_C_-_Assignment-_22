
#include "mymat.h"
/*
*file:	
*	mymat: All the functions that are sorted between the modes
*	mat: Operations on matrices
*	cleanText: Initial process of cleaning input
*	translateText: Translation and encoding of input
*
*theory:
*	Receiving a single input line from the user while removing white characters.
*	Encoding to predefined code and entering an array that stores all information about the command.
*	Routing According to the data Of the array To execute the command and And error diagnosis.
 */


int main (void)
{ 
	char buffer [MAX_CHAR_CMD];			/* Used to temporarily store input characters */
	setMatrix ();					/* reset all matrices */
	printf("Hello,\n");
	
	while (!((int)(command[2])==8&&(int)(command[errors])==E_ALL_GOOD))	/* Continue until 'stop' command */
	{
		clearCommand ();			/* reset Command */
		clearbuffer (buffer);			/* reset buffer */
				
		OutputToUser (0);			/*Prints message*/
		textTransform(buffer);			/* Receives and translates command */
		
		if(command[E_O_F]==E_not_stop) 		/* Detects end input without 'stop' command */
		{
			command[errors]=E_not_stop;
			playrror ();			/* Prints an error message */
			break;
		}
		
		play();					/* Performs a user command */
		printf("-----------\n\n");
		
	}


	return 0;
}



/*
* 	Performs a user command, Routing to the correct function
*/
void play ()
{
	if((int)command[errors]==E_ALL_GOOD)
	{
		switch ((int)command[opcode])
		{
			case read_mat:
				readMat (command[operand_1],command);
				OutputToUser (1);
				break;

			case print_mat:
				printMat (command[operand_1]);
				OutputToUser (2);
				break;

			case add_mat:
				addMat (command[operand_1],command[operand_2],command[operand_3]);
				OutputToUser (3);
				break;

			case sub_mat:
				subMat (command[operand_1],command[operand_2],command[operand_3]);
				OutputToUser (4);
				break;

			case mul_mat:
				mulMat (command[operand_1],command[operand_2],command[operand_3]);
				OutputToUser (5);
				break;

			case mul_scalar:
				mulScalar (command[operand_1],command[operand_2],command[operand_3]);
				OutputToUser (6);
				break;

			case trans_mat:
				transMat (command[operand_1],command[operand_2]);
				OutputToUser (7);
				break;

			case stop:
				OutputToUser (8);
				break;
				
			default:
			printf(" ---SOS--- \n");
		}
	}
	else 
	{
		playrror();	
	
	}
}


/*
* 	Prints an error message, Routing to the correct function
*/
void playrror ()
{
	printf("You have an error, ");
	switch ((int)command[errors])
	{
		case E_opcod_name:
			printf("Undefined command name\n");
			break;
		case E_matrix_name:
			printf("Undefined matrix name\n");
			break;
		case E_meny_comma:
			printf("Multiple consecutive commas\n");
			break;
		case E_real_number:
			printf("Parameter not a real number\n");
			break;
		case E_meny_text:
			printf("Extraneous text after end of command\n");
			break;
		case E_missing_parmeter:
			printf("Missing parmeter\n");
			break;
		case E_not_scalar:
			printf("Parameter not a scalar\n");
			break;
		case illegal_comma:
			printf("illegal comma\n");
			break;
		case E_non_comma:
			printf("Missing comma\n");
			break;
		case E_not_stop:
			printf("You did not add a \'stop\' command\n");
			break;
			
			
		default:
		printf("The command was not received well\n");
	}
}


/*
* 	Prints message to user, Routing to the correct function
*/
void OutputToUser (int index)
{
	switch (index)
	{
		case 0:
			printf("Please enter a command\n");
			break;
		case 1:
			printf("Command: \"read_mat\" succeeded \n");
			break;
		case 2:
			printf("Command: \"print_mat\" succeeded \n");
			break;
		case 3:
			printf("Command: \"add_mat\" succeeded \n");
			break;
		case 4:
			printf("Command: \"sub_mat\" succeeded \n");
			break;
		case 5:
			printf("Command: \"mul_mat\" succeeded \n");
			break;
		case 6:
			printf("Command: \"mul_scalar\" succeeded \n");
			break;
		case 7:
			printf("Command: \"trans_mat\" succeeded \n");
			break;
		case 8:
			printf("Command: \"stop\" succeeded \n");
			break;
		case 9:
			printf(" \n");
			break;
		case 10:
			printf(" \n");
			break;
			
		default:
		printf("\n");
	}
}





