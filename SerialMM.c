#include<stdio.h>

double* pAMatrix; // First argument of matrix multiplication
double* pBMatrix; // Second argument of matrix multiplication
double* pCMatrix; // Result matrix
int Size; // Size of matrices

// Function for memory allocation and initialization of matrix elements
void ProcessInitialization (double* &pAMatrix, double* &pBMatrix, double* &pCMatrix, int &Size) { // Setting the size of matrices
	printf("\nEnter the size of matrices: ");
	scanf("%d", &Size);
	printf("\nChosen matrices size = %d \n", Size);
	// Setting the size of matrices
	
	do {
		printf("\nEnter size of matrices: ");
		scanf("%d", &Size);
		printf("\nChose n matrices' size = %d", Size); if (Size <= 0)
		printf("\nSize of objects must be greater than 0!\n");
	}
	while (Size <= 0);
	
	// Memory allocation
	pAMatrix = new double [Size*Size];
	pBMatrix = new double [Size*Size];
	pCMatrix = new double [Size*Size];
	
	// Initialization of matrix elements
	DummyDataInitialization(pAMatrix, pBMatrix, Size);
	for (int i=0; i<Size*Size; i++) {
		pCMatrix[i] = 0;
	}
}	

// Function for simple initialization of matrix elements
void DummyDataInitialization(double* pAMatrix, double* pBMatrix, int Size){
	int i, j; // Loop variables
	for (i=0; i<Size; i++) {
		for (j=0; j<Size; j++) {
			pAMatrix[i*Size+j] = 1;
			pBMatrix[i*Size+j] = 1;
		}
	}
}


// Function for computational process termination
void ProcessTermination (double* pAMatrix, double* pBMatrix, double* pCMatrix) {
	delete [] pAMatrix;
	delete [] pBMatrix;
	delete [] pCMatrix;
}

// Function for matrix multiplication
void SerialResultCalculation(double* pAMatrix, double* pBMatrix, double* pCMatrix, int Size) {
	int i, j, k; // Loop variables
	for (i=0; i<Size; i++) {
		for (j=0; j<Size; j++) {
			for (k=0; k<Size; k++) {
				pCMatrix[i*Size+j] += pAMatrix[i*Size+k]*pBMatrix[k*Size+j];
			}
		}
	}
}

void printMatrix(double* pMatrix, int size, int size)
{
    int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++) {
			printf("%lf ", pMatrix[i*size+j]);
		}
		printf("\r\n");			
	}
} 

void main() {
	double* pAMatrix; // First argument of matrix multiplication
	double* pBMatrix; // Second argument of matrix multiplication
	double* pCMatrix; // Result matrix
	int Size; // Size of matrices
	
	time_t start, finish;
	double duration;
	printf ("Serial matrix multiplication program\n");
	
	// Memory allocation and initialization of matrix elements
	ProcessInitialization(pAMatrix, pBMatrix, pCMatrix, Size);
	
	// Matrix output
	printf ("Initial A Matrix \n");
	PrintMatrix(pAMatrix, Size, Size);
	printf("Initial B Matrix \n");
	PrintMatrix(pBMatrix, Size, Size);
	
	// Matrix multiplication
	SerialResultCalculation(pAMatrix, pBMatrix, pCMatrix, Size);
	
	// Printing the result matrix
	printf ("\n Result Matrix: \n");
	PrintMatrix(pCMatrix, Size, Size);
	
	// Computational process termination
	ProcessTermination(pAMatrix, pBMatrix, pCMatrix);
	getch();
}
