#ifdef __cplusplus
extern "C"
#endif

int m = 5000;
int n = 10000;
int **matrix;

int thread_number = 5;
struct Data;

void Fill_matrix (int **, int);

void Found_steps (struct Data*, int);

void *One_thread_display (void*);

void Display_matrix_threads ();
