
/*	Header Files	*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
#include "cleanText.h"


/*	Constants	*/
#define MAX_VAL_CMD 20		/* Maximum value per line command */
double command[MAX_VAL_CMD]; /* 0-errors, 1- EOF , 2-op_code, (3-19) operands (matrix or Values) */



/*	FUNCTION PROTOTYPE	*/
void textTransform (char *buffer);
void clearCommand ();
int matrixCase (char *tempCmd);
int opCodeCase (char *tempCmd);
double readscalar(char *p_char);
void set_read_mat(char *p_start,int *index);
void set_print_mat(char *p_start,int *index);
void set_add_mat(char *p_start,int *index);
void set_mul_scalar(char *p_start,int *index);
void set_trans_mat(char *p_start,int *index);
void set_stop(char *p_start,int *index);
void addError (int error);
void checkerComma (char *buffer);
void Missing(int index);








