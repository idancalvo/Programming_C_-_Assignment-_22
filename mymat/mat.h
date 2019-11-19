
/*	Header Files	*/
#include <stdio.h>



/*	Constants	*/
#define size 4 		/*size of MATRIX*/
#define num_of_matrix 7	/*6 nurmal matrix + 1 calculation matrix*/
#define cal_MAT 0	/*index of the matrix helped calculate*/


typedef double mat [size][size];




/*	Retains all matrices:
* 	0-calculation matrix, 1-MAT_A, 2-MAT_B, 3-MAT_C, 4-MAT_D, 5-MAT_E, 6-MAT_F
*/
mat matrixTabel [num_of_matrix];  





/*	FUNCTION PROTOTYPE	*/
void readMat (int mat0,double *arrVal);
void printMat (int i);
void addMat (int mat1,int mat2,int mat3);
void subMat (int mat1,int mat2,int mat3);
void mulMat (int mat1,int mat2,int mat3);
void mulScalar (int mat1,double scalar,int mat3);
void transMat (int mat1,int mat2);

double *pointerval (int i,int n,int m);
void printMatrixs ();
void setMatrix ();
void clearMatrix ();
void copyMatrix (int matrix1,int matrix2);
char* name (int i);








