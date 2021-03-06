#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main(int argc, char *argv[]) //first is size of matrix, second is number of threads
{
    int thread = atoi(argv[2]);
    omp_set_num_threads(thread); //just setting #of thread nothing else

    int size = atoi(argv[1]);
    //scanf("%d", size);
    int len = 0;
    int i, j, k, total = 0;
    int *ptr, *ptr1, *ptr2, **A, **B, **C;

    len = sizeof(int *) * size + sizeof(int) * size * size;
    A = (int **)malloc(len);
    B = (int **)malloc(len);
    C = (int **)malloc(len);
    ptr = (int *)(A + size);
    ptr1 = (int *)(B + size);
    ptr2 = (int *)(C + size);

    for (k = 0; k < size; k++)
    {
        A[k] = (ptr + size * k);
        B[k] = (ptr1 + size * k);
        C[k] = (ptr2 + size * k);
    } //set up pointer for 2D matrix

//    srand(time(0));
//    clock_t start, stop;
//    float set_up, mult;
//    start = clock();
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            A[i][j] = rand(); // used % 10 to check
            B[i][j] = rand(); // % 10
        }
    } //----set up random number for multiplication aboce
 //   stop = clock();
 //   set_up = (float)(stop - start) / CLOCKS_PER_SEC;

   // start = clock();
#pragma omp parallel shared(A,B,C) private(i,j,k,total)
{
//	int thread_count = omp_get_num_threads();
//   int my_rank = omp_get_thread_num();
 //   printf("Hello from thread %d of %d threads\n", my_rank, thread_count);
#pragma omp for schedule(dynamic)
for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            for (k = 0; k < size; k++)
            {
                total = total + A[i][k] * B[k][j];
            }
            C[i][j] = total;
            total = 0;
        }
    } //------matrix multiplication and placed in matrix C
}
//    stop = clock();
//    mult = (float)(stop - start) / CLOCKS_PER_SEC;
//    printf("%f,%f\n", set_up, mult);

    // for (i = 0; i < size; i++)
    // {
    //     for (j = 0; j < size; j++)
    //     {
    //         printf("%d ", C[i][j]);
    //     }
    //     printf("\n");
    // } //used for checking validity

    free(A);
    free(B);
}

// for (i = 0; i < size; i++)
// {
//     for (j = 0; j < size; j++)
//     {
//         printf("%d ", A[i][j]);
//     }
//     printf("\n");
// }
// for (i = 0; i < size; i++)
// {
//     for (j = 0; j < size; j++)
//     {
//         printf("%d ", B[i][j]);
//     }
//     printf("\n");
// }
//     for (i = 0; i < size; i++)
// {
//     for (j = 0; j < size; j++)
//     {
//         printf("%d ", C[i][j]);
//     }
//     printf("\n");
// }
