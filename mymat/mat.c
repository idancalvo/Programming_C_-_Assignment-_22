
#include "mat.h"
#define operand_2 4



/*  execution command read_Mat  */
void readMat (int mat0,double *arrVal)
{
    	int m;
	int n;
	int k=operand_2;
	for (n=0;n<size;n++)
	{
		for (m=0;m<size;m++)
		{
			*pointerval(mat0,n,m) =*(arrVal+k);
			k++;
		}
	}
}

/*  execution command print_Mat */
void printMat (int i)
{
	int m;
	int n;
	printf("%s:\n",name(i));
	for (n=0;n<size;n++)
	{
		for (m=0;m<size;m++)
		{
			printf ("\t%7.2f",*pointerval(i,n,m));
		}
		printf ("\n");
	}
	printf ("\n");	
}

/*  execution command add_Mat  */
void addMat (int mat1,int mat2,int mat3)
{
	
	int m;
	int n;
	for (n=0;n<size;n++)
	{
		for (m=0;m<size;m++)
		{
			*pointerval(cal_MAT,n,m) = *pointerval(mat1,n,m) + *pointerval(mat2,n,m);
		}
	}
	copyMatrix (mat3,cal_MAT);
}

/*  execution command sub_Mat  */
void subMat (int mat1,int mat2,int mat3)
{
	int m;
	int n;
	for (n=0;n<size;n++)
	{
		for (m=0;m<size;m++)
		{
			*pointerval(cal_MAT,n,m) = *pointerval(mat1,n,m) - *pointerval(mat2,n,m);
		}
	}
	copyMatrix (mat3,cal_MAT);
}

/*  execution command mul_Mat  */
void mulMat (int mat1,int mat2,int mat3)
{
	int m;
	int n;
	int i;
	double sum=0;
	for (n=0;n<size;n++)
	{
		for (m=0;m<size;m++)
		{
			for (i=0;i<size;i++)
			{
				sum += (*pointerval(mat1,n,i)) * (*pointerval(mat2,i,m));
			}
			*pointerval(cal_MAT,n,m) = sum;
			sum=0;
		}
	}
	copyMatrix (mat3,cal_MAT);
    
}


/*  execution command mul_Scalar  */
void mulScalar (int mat1,double scalar,int mat3)
{
	int m;
	int n;
	for (n=0;n<size;n++)
	{
		for (m=0;m<size;m++)
		{
			*pointerval(cal_MAT,n,m) = *pointerval(mat1,n,m) * scalar ;
		}
	}
	copyMatrix (mat3,cal_MAT);
}


/*  execution command trans_Mat  */
void transMat (int mat1,int mat2)
{
	int m;
	int n;
	for (n=0;n<size;n++)
	{
		for (m=0;m<size;m++)
		{
			*pointerval(cal_MAT,n,m) = *pointerval(mat1,m,n);
		}
	}
	copyMatrix (mat2,cal_MAT);
}

/*input index of matrix and return name of matrix*/
char* name (int i)
{
	char* matname [] = {"cal_MAT","MAT_A","MAT_B","MAT_C","MAT_D","MAT_E","MAT_F"};

	return matname[i];
}


/*Returns a pointer to the Value, matrix number i,row n, column m*/
double *pointerval (int i,int n,int m)
{
	return *(*(matrixTabel+i)+n)+m;
}



/*Prints all matrixs*/
void printMatrixs ()
{
	int i;
	for (i=1;i<num_of_matrix;i++)
	{	
		printMat(i);	
		printf ("-----------------------------\n");
	}	
}

/*Initializes a matrix to 0 and copies to others*/
void setMatrix () 
{
	int m;
	int n;
	for (n=0;n<size;n++)
	{
		for (m=0;m<size;m++)
		{
 			*pointerval(0,n,m)=0;
 		}
 	}
	clearMatrix();
}

/*copy 0 matrix to all */
void clearMatrix ()
{
	int i;
	for (i=1;i<num_of_matrix;i++)
	{
		copyMatrix(i,cal_MAT);
	}
}

/*copy matrix: matrix2 -> matrix1*/
void copyMatrix (int matrix1,int matrix2)
{
	int m;
	int n;
	for (n=0;n<size;n++)
	{
		for (m=0;m<size;m++)
		{
			*pointerval(matrix1,n,m) = *pointerval(matrix2,n,m);
		}
	}
}


