#include "../library/libstatic.h"
#include <stdio.h>
#include "project.h"



int Compare_matrix (int **matrix1, int **matrix2, int mm, int nn)
{
    for (int i=0; i<mm; i++)
    {
        for (int j = 0; j < nn; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
            {
                return -1;
            }
        }
    }
    return 0;
}

int Check_inital_data (int **matrix1, int **matrix2, int mm, int nn)
{
    if (Compare_matrix(matrix1, matrix2, mm, nn)==0)
    {
        return 0;
    }
    else
    {
        printf("%s\n", "Fill error. Matrices are not equal");
        return -1;
    }
}