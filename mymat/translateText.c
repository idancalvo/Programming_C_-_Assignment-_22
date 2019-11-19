
#include "translateText.h"


/*
*Translates and encodes the command
*/
void textTransform (char *buffer)
{
	char tempchar1,tempchar2;
	int index=opcode;
	char *p_start, *p_next, *p_end;
	p_next = p_start = buffer;
	

	command[E_O_F]=CleanText (buffer,0); /* Receives, Clean and set input command */
	printf("your input: \"%s\"\n",buffer);

	if ((int)command[E_O_F]==-1)	/* Detects end input without 'stop' command */
	{
		return;
	}

	
	
	p_end = strchr(buffer,'\0'); /* Marks end of command line */
	
	tempchar1=*(p_end-1);
	tempchar2=*(p_end-2);
	
	
	/*Checks whether there is a comma at the end of input*/
	if ((tempchar1==',')||(((tempchar1==' ')||(tempchar1=='\t'))&&(tempchar2==','))) 
		addError(E_meny_text);
		
		
	
	if ( (tempchar1==' ') || (tempchar1=='\t') )
	{
		*(p_end-1) =',';
	}
	else
	{/*Command Order (adds a comma after each word)*/
		*(p_end) =',';
		*(p_end+1)='\0';
		p_end=p_end+1;			
	}


	/*Encoding word after word*/
	while ( (*p_next) != (*p_end) && index < MAX_VAL_CMD )
	{
												
		p_start = p_next;
		p_next = strchr(p_start,'\t');	/*Looking for the end of a word*/
									
		if (p_next==NULL)
		{
			p_next=p_end;
		}
		p_next++;
		strtok(p_start,"\t");		/* Split words */
		
		if (index==opcode)		/*Diagnoses the first word as an op-code*/
		{
			command[opcode] = opCodeCase(p_start);
			index++;
		}
		else 
		{			
			checkerComma(p_start); /*Checks if there is too much comma*/
			
			/*Encoding value 2-16, Routing to the correct function*/
		   	switch ((int)(command[opcode]))
			{
				case read_mat:
					set_read_mat(p_start,&index);
				   	break;

				case print_mat:
				   	set_print_mat(p_start,&index);
					break;
					
				case add_mat:
				case sub_mat:
				case mul_mat:
					set_add_mat(p_start,&index);
					break;
					
				case mul_scalar:
					set_mul_scalar(p_start,&index);
					break;

				case trans_mat:
					set_trans_mat(p_start,&index);
					break;

				case stop:
					set_stop(p_start,&index);
					break;
							
				default: 
					addError(E_opcod_name);	
			}
		}
	}
	Missing(index);
}


/* reset Command */
void clearCommand ()
{
	int i;
	for (i=0;i<MAX_VAL_CMD;i++)
	{
		command[i]=0;
	}
}


/*Encodes a matrix name to a number*/
int matrixCase (char *tempCmd)
{
	if (!strcmp(tempCmd,"MAT_A,"))
		return MAT_A;
	if (!strcmp(tempCmd,"MAT_B,"))
		return MAT_B;
	if (!strcmp(tempCmd,"MAT_C,"))
		return MAT_C;
	if (!strcmp(tempCmd,"MAT_D,"))
		return MAT_D;
	if (!strcmp(tempCmd,"MAT_E,"))
		return MAT_E;
	if (!strcmp(tempCmd,"MAT_F,"))
		return MAT_F;
		
	if( *(tempCmd+strlen(tempCmd)-1)!=',' )
	{
		addError(E_non_comma);
	}	
				
	addError(E_matrix_name);	
	return 0;
}		
	
	
/*Encodes a op-Code name to a number*/
int opCodeCase (char *tempCmd)
{
	if (!strcmp(tempCmd,"read_mat"))
		return read_mat;
	if (!strcmp(tempCmd,"print_mat"))
		return print_mat;
	if (!strcmp(tempCmd,"add_mat"))
		return add_mat;
	if (!strcmp(tempCmd,"sub_mat"))
		return sub_mat;
	if (!strcmp(tempCmd,"mul_mat"))
		return mul_mat;
	if (!strcmp(tempCmd,"mul_scalar"))
		return mul_scalar;
	if (!strcmp(tempCmd,"trans_mat"))
		return trans_mat;
	if (!strcmp(tempCmd,"stop,"))
		return stop;
	if (!strcmp(tempCmd,"stop"))
		return stop;
		
	if ( *(tempCmd+strlen(tempCmd)-1)==',' )
	{
		addError(illegal_comma);	
	}		
	else
	{
		addError(E_opcod_name);					
	}	
	return 0;
}


/*Encodes a string (number) to value (number)*/
double readscalar(char *p_char)
{
	double ans1 = 0;
	double ans2 = 0;
	int sign = 1;
	int point = 0;
	
	if (*p_char=='-') /* Positive or negative value	*/
	{
	sign=-1;
	p_char++;
	}
	
	while (*p_char!='\0')
	{
		if (!(isdigit(*p_char)) ) /* If the character is not a number */
		{
			if (*p_char=='.' && point==0) /*Sorts values before and after the point*/
			{
				point=1;	
			}	
			else
			{	
				if (*p_char!=',') /*Mapping invalid value error*/
				{
					if (*p_char==' ' || *p_char=='\t')
					{
						addError(E_non_comma);
					}
					else
					{
						addError(E_not_scalar);
					}
				}	
				break;	
			}
		}
		else
		{
			if(point==0)	/*values before point*/
			{
				ans1 = (ans1*10) + (*p_char-'0');
			}
			else 	/*values after point*/
			{
				ans2 = (ans2*10) +(*p_char-'0');
				point=point*10;
			}
		}
		p_char++;	
	}
	if(point!=0)
	{
		ans2=(ans2/(point));
	}
	
	return ((ans1+ans2)*sign);
}




/* Encodes command read_mat  */
void set_read_mat(char *p_start,int *index)
{

	if (*index==operand_1)
	{
		command[*index] = matrixCase (p_start);
	}
	else
	{
		command[*index] = readscalar (p_start);
	}
	*index=*index+1;
}


/* Encodes command print_mat  */
void set_print_mat(char *p_start,int *index)
{
	if (*index==operand_1)
	{
		command[*index] = matrixCase (p_start);
	}
	else
	{
		addError(E_meny_text);
	}
	*index=*index+1;
}




/* Encodes command add_mat  */
void set_add_mat(char *p_start,int *index)
{

	if (*index>=operand_1 && *index<=operand_3)
	{
		command[*index] = matrixCase (p_start);
	}
	else 
	{
		addError(E_meny_text);
	}
	*index=*index+1;
}




/* Encodes command mul_scalar  */
void set_mul_scalar(char *p_start,int *index)
{
	if (*index==operand_1 || *index==operand_3)
	{
		command[*index] = matrixCase (p_start);
	}
	else 
	{
		if (*index==operand_2)
		{
			command[*index]= readscalar(p_start);
		}
		else
		{
		addError(E_meny_text);
		}
	}
	*index=*index+1;
}




/* Encodes command trans_mat  */
void set_trans_mat(char *p_start,int *index)
{
	if (*index==operand_1 || *index==operand_2)
	{
		command[*index] = matrixCase (p_start);
	}
	else 
	{
		addError(E_meny_text);
	}
	*index=*index+1;
}



/* Encodes command set_stop  */
void set_stop(char *p_start,int *index)
{
	addError(E_meny_text);
	*index=*index+1;
}



/*Mapping command errors*/
void addError (int error)
{
	((int)(command[errors])==E_ALL_GOOD) ? command[errors] = error : 0 ;
}


/*Checks if there is too much comma*/
void checkerComma (char *tempchar)
{
	if (*tempchar==',')
	{
		addError(E_meny_comma);	
	}
}



void Missing(int index)
{
	switch ((int)(command[opcode]))
	{
		case read_mat:
		case trans_mat:
			if (index<operand_3) 
 				addError(E_missing_parmeter);		
		   	break;
		case print_mat:
		   	if (index<operand_2) 
				addError(E_missing_parmeter);
			break;
		case add_mat:
		case sub_mat:
		case mul_mat:
		case mul_scalar:
			if (index<operand_3+1)
				addError(E_missing_parmeter);
			break;
		case stop:
			break;	
	}

}



