#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gt>

double Get_value();

void Coordinates_input (const int n, double *arr_x, double *arr_y) //ввод координат
{
  if (!arr_x) {printf("Pointer 'x' is Null\n"); return;}
  if (!arr_y) {printf("Pointer 'y' is Null\n"); return;}

  for (int i = 0; i < n; i++)
  {
      double value_x, value_y;
      value_x = Get_value();
      value_y = Get_value();

      arr_x[i] = value_x;
      arr_y[i] = value_y;
   }
}

void Polygon_square(const int n, const double *arr_x, const double *arr_y, double *square) //получает на вход два массива координат и выдаёт площадь
{
    double s = arr_x[n - 1] * arr_y[0] - arr_x[0] * arr_y[n - 1];

    for (int i=0; i<n-1; i++)
    {
        s = s + arr_x[i] * arr_y[i + 1] - arr_x[i + 1] * arr_y[i];
    }
    s = fabs(s / 2);
    *square = s;
}

void Polygon_calculator ()
{
    int n=0;
    while (n<3)
    {
        n = (int)Get_value();
        if (n<3) printf("the number of vertices must be more than 3\n");
    }

    double *arr_x = (double*)calloc(n, sizeof(double));
    double *arr_y = (double*)calloc(n, sizeof(double));
    Coordinates_input(n, arr_x, arr_y);

    double square = 0;
    double *ptr_square = &square;

    Polygon_square(n, arr_x, arr_y, ptr_square);
    printf("%g", *ptr_square);

    free(arr_x);
    free(arr_y);
}

double Get_value ()
{
    char str[10];
    char *ptr;
    double value;

    do 
    {
        scanf("%9s", str);
        value = strtod(str, &ptr);
        if (*ptr != '\0') printf("please, input number\n");
    }
    while (*ptr != '\0');
    return value;
}

int main()
{
    Polygon_calculator();
    return 0;
}
