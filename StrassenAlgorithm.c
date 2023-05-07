#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void strassen(int,int **,int **,int **);
void multiply(int,int **,int **,int **);
void add(int,int **,int **,int **);
void sub(int,int **,int **,int **);
main()
{
    int a,b,c,d,n,**A,**B,**C,max;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(b == c)
    {
        max = a;
        if(max < b)
        {
            max = b;
        }
        if(max < d)
        {
            max = d;
        }
        if(max & max - 1)                                   //確認矩陣大小 484 2的n次方
        {
            int shift = ceil(log2(max));                    //取以2為底的log上階
            max = pow(2,shift);                             //得最接近的2的乘冪
        }
        A = (int **)calloc(max,sizeof(int *));
        B = (int **)calloc(max,sizeof(int *));
        C = (int **)calloc(max,sizeof(int *));
        for(int i = 0 ; i < max ; i++)
        {
            A[i] = (int *)calloc(max,sizeof(int));
            B[i] = (int *)calloc(max,sizeof(int));
            C[i] = (int *)calloc(max,sizeof(int));
        }
        for(int i = 0 ; i < a ; i++)
        {
            for(int j = 0 ; j < b ; j++)
            {
                scanf("%d",(*(A + i) + j));
            }
        }
        for(int i = 0 ; i < c ; i++)
        {
            for(int j = 0 ; j < d ; j++)
            {
                scanf("%d",(*(B + i) + j));
            }
        }
        strassen(max,A,B,C);
        for(int i = 0 ; i < a ; i++)
        {
            for(int j = 0 ; j < d ; j++)
            {
                printf("%d ",C[i][j]);
            }
            puts("");
        }
        free(A);
        free(B);
        free(C);
    }
}
void strassen(int n,int **A,int **B,int **C)
{
    if(n <= 2)
    {
        multiply(n,A,B,C);
    }
    else
    {
        int size = n / 2;
        int **A11,**A12,**A21,**A22,**B11,**B12,**B21,**B22,**M1,**M2,**M3,**M4,**M5,**M6,**M7,**temp1,**temp2,**C11,**C12,**C21,**C22;
        A11 = (int **)malloc(size * sizeof(int *));
        A12 = (int **)malloc(size * sizeof(int *));
        A21 = (int **)malloc(size * sizeof(int *));
        A22 = (int **)malloc(size * sizeof(int *));
        B11 = (int **)malloc(size * sizeof(int *));
        B12 = (int **)malloc(size * sizeof(int *));
        B21 = (int **)malloc(size * sizeof(int *));
        B22 = (int **)malloc(size * sizeof(int *));
        M1 = (int **)malloc(size * sizeof(int *));
        M2 = (int **)malloc(size * sizeof(int *));
        M3 = (int **)malloc(size * sizeof(int *));
        M4 = (int **)malloc(size * sizeof(int *));
        M5 = (int **)malloc(size * sizeof(int *));
        M6 = (int **)malloc(size * sizeof(int *));
        M7 = (int **)malloc(size * sizeof(int *));
        temp1 = (int **)malloc(size * sizeof(int *));
        temp2 = (int **)malloc(size * sizeof(int *));
        C11 = (int **)malloc(size * sizeof(int *));
        C12 = (int **)malloc(size * sizeof(int *));
        C21 = (int **)malloc(size * sizeof(int *));
        C22 = (int **)malloc(size * sizeof(int *));
        for(int i = 0 ; i < size ; i++)
        {
            A11[i] = (int *)malloc(sizeof(int) * size);
            A12[i] = (int *)malloc(sizeof(int) * size);
            A21[i] = (int *)malloc(sizeof(int) * size);
            A22[i] = (int *)malloc(sizeof(int) * size);
            B11[i] = (int *)malloc(sizeof(int) * size);
            B12[i] = (int *)malloc(sizeof(int) * size);
            B21[i] = (int *)malloc(sizeof(int) * size);
            B22[i] = (int *)malloc(sizeof(int) * size);
            M1[i] = (int *)malloc(sizeof(int) * size);
            M2[i] = (int *)malloc(sizeof(int) * size);
            M3[i] = (int *)malloc(sizeof(int) * size);
            M4[i] = (int *)malloc(sizeof(int) * size);
            M5[i] = (int *)malloc(sizeof(int) * size);
            M6[i] = (int *)malloc(sizeof(int) * size);
            M7[i] = (int *)malloc(sizeof(int) * size);
            temp1[i] = (int *)malloc(sizeof(int) * size);
            temp2[i] = (int *)malloc(sizeof(int) * size);
            C11[i] = (int *)malloc(sizeof(int) * size);
            C12[i] = (int *)malloc(sizeof(int) * size);
            C21[i] = (int *)malloc(sizeof(int) * size);
            C22[i] = (int *)malloc(sizeof(int) * size);
        }
        for(int i = 0 ; i < size ; i++)
        {
            for(int j = 0 ; j < size ; j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + size];
                A21[i][j] = A[i + size][j];
                A22[i][j] = A[i + size][j + size];                   
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + size];
                B21[i][j] = B[i + size][j];
                B22[i][j] = B[i + size][j + size];
            }
        }
        add(size,A11,A22,temp1);        //A11+A22
        add(size,B11,B22,temp2);        //B11+B22
        strassen(size,temp1,temp2,M1);
        add(size,A21,A22,temp1);        //A21+A22
        strassen(size,temp1,B11,M2);
        sub(size,B12,B22,temp1);        //B12-B22
        strassen(size,A11,temp1,M3);
        sub(size,B21,B11,temp1);        //B21-B11
        strassen(size,A22,temp1,M4);
        add(size,A11,A12,temp1);        //A11+A12
        strassen(size,temp1,B22,M5);
        sub(size,A21,A11,temp1);        //A21-A11
        add(size,B11,B12,temp2);        //B11+B12
        strassen(size,temp1,temp2,M6);
        sub(size,A12,A22,temp1);        //A12-A22
        add(size,B21,B22,temp2);        //B21+B22
        strassen(size,temp1,temp2,M7);
        add(size,M1,M4,temp1);          //M1+M4
        sub(size,temp1,M5,temp2);       //M1+M4-M5
        add(size,temp2,M7,C11);         //C11
        add(size,M3,M5,C12);            //C12
        add(size,M2,M4,C21);            //C21
        add(size,M1,M3,temp1);          //M1+M3
        sub(size,temp1,M2,temp2);       //M1+M3-M2
        add(size,temp2,M6,C22);         //C22
        free(A11);
        free(A12);
        free(A21);
        free(A22);
        free(B11);
        free(B12);
        free(B21);
        free(B22);
        free(temp1);
        free(temp2);
        free(M1);
        free(M2);
        free(M3);
        free(M4);
        free(M5);
        free(M6);
        free(M7);
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(j >= 0 && j < size && i >= 0 && i < size)
                {
                    C[i][j] = C11[i][j];
                }
                if(j >= size && j < n && i >= 0 && i < size)
                {
                    C[i][j] = C12[i][j - size];
                }
                if(j >= 0 && j < size && i >= size && i < n)
                {
                    C[i][j] = C21[i - size][j];
                }
                if(j >= size && j < n && i >= size && i < n)
                {
                    int a = i - size,b = j - size;
                    C[i][j] = C22[i - size][j - size];
                }
            }
        }
        free(C11);
        free(C12);
        free(C21);
        free(C22);
    }
}
void multiply(int n,int **A,int **B,int **C)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            C[i][j] = 0;
            for(int k = 0 ; k < n ; k++)
            {
                C[i][j] += A[i][k] * B[k][j]; 
            }
        }
    }
}
void add(int n,int **A,int **B,int **C)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void sub(int n,int **A,int **B,int **C)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}