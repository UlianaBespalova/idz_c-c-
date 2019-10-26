#include "../library/libstatic.h"
#include "../library/libdyn.h"
#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void Compare_results (int key_value)
{
    matrix = (int**)malloc(m* sizeof(int*));
    for (int i=0; i<m; i++) {matrix[i]=malloc(sizeof(int)*n);}
    Fill_matrix(matrix, key_value);

    int **new_matrix = (int**)malloc(m* sizeof(int*));
    for (int j=0; j<m; j++) new_matrix[j]=malloc(sizeof(int)*n);
    Fill_matrix(new_matrix, key_value);

    int res = Check_inital_data(matrix, new_matrix, m, n);

    if (res == 0) {
        time_t t1 = clock();
        Display_matrix_threads();
        time_t t2 = clock();
        double sec1 = (double) (t2 - t1) / CLOCKS_PER_SEC;

        t1 = clock();
        Display_matrix(new_matrix, m);
        t2 = clock();
        double sec2 = (double) (t2 - t1) / CLOCKS_PER_SEC;

        printf("\n%s\n", "-------- compare results -------");

        if (Compare_matrix(matrix, new_matrix, m, n) == 0) {
            printf("%s = %d  -  %s\n", "key value", key_value, "OK");
        } else {
            printf("%s\n", "Error. Matrices are not equal");
        }
        printf("%s = %d * %d\n", "matrix size", n, m);
        printf("%s = %f\n%s = %f\n", "Time 1 (naive algorithm)", sec1, "Time 2 (multithreaded algorithm)", sec2);

    }


    //clean memory
    for (int i=0; i<m; i++) free (matrix[i]);
    free (matrix);
    for (int i=0; i<m; i++) free (new_matrix[i]);
    free (new_matrix);
}



int main()
{
    long int J = sysconf (_SC_NPROCESSORS_CONF);
    if (J>0) thread_number = (int)J;



    Compare_results(0);
    sleep(4);
    Compare_results(5);


    return 0;
}