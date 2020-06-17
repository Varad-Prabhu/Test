//Matrix multiplication

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function prototype
void initializeArray(int **,int,int);
void displayArray(const int **,int,int);
void matrixMultiplication(int **,const int **,const int **,int,int,int);

//Function Definition
void initializeArray(int **a,int m,int n)
{
    int i,j;
    srand(time(NULL));
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            *(*(a+i)+j)=rand()%10;
        }
    }
}

void displayArray(const int **a,int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",*(*(a+i)+j));
        }
        printf("\n");
    }
}


void matrixMultiplication(int **dest,const int **a,const int **b,int m1,int n1,int n2)
{
    int i,j,k;
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {
            *(*(dest+i)+j)=0;
            for(k=0;k<n1;k++)
                *(*(dest+i)+j)=*(*(dest+i)+j)+ *(*(a+i)+k)**(*(b+k)+j);
        }
    }

}


int main()
{
    int **matrix1,**matrix2,m1,n1,m2,n2;
    int i;
    printf("\nEnter the order (m1,n1) of matrix 1: ");
    scanf("%d%d",&m1,&n1);
    if(m1>0 && n1>0)
    {
        matrix1=(int **)malloc(sizeof(int *)*m1);
        for(i=0;i<m1;i++)
            *(matrix1+i)=(int *)malloc(sizeof(int)*n1);
        initializeArray(matrix1,m1,n1);
        printf("\nMatrix 1 with randomly initialized values: \n");
        displayArray(matrix1,m1,n1);
    }
    else
        printf("\nInvalid matrix 1 order.");
    printf("\nEnter the order (m2,n2) of matrix 2: ");
    scanf("%d%d",&m2,&n2);
    if(m2>0 && n2>0)
    {
        matrix2=(int **)malloc(sizeof(int *)*m2);
        for(i=0;i<m2;i++)
            *(matrix2+i)=(int *)malloc(sizeof(int)*n2);
        initializeArray(matrix2,m2,n2);
        printf("\nMatrix 2 with randomly initialized values: \n");
        displayArray(matrix2,m2,n2);
    }
    else
        printf("\nInvalid matrix 2 order.");
    if(m1>0 && n2>0 && n1==m2)
    {
	int **matrix3;
        printf("\nMatrix 1 and Matrix 2 multiplication possible.");
        matrix3=(int **)malloc(sizeof(int *)*m1);
        for(i=0;i<m1;i++)
            *(matrix3+i)=(int *)malloc(sizeof(int)*n2);
        matrixMultiplication(matrix3,matrix1,matrix2,m1,n1,n2);
        printf("\nMultiplication of matrix 1 and matrix 2 is: \n");
        displayArray(matrix3,m1,n2);
    }
    else
    {
        printf("\nMatrix 1 and Matrix 2 multiplication not possible. As the number of columns of matrix 1 is not equal to number of rows of matrix 2.");
    }
    return 0;
}

