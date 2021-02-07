#include <omp.h> 
  
#include <stdio.h> 
#include <stdlib.h> 
  
int main(int argc, char* argv[]) 
{ 
  
    // Creation of the parallel region
    #pragma omp parallel 
    { 
  
        printf("Hello Parallel World... from thread = %d\n", 
               omp_get_thread_num()); 
    } 
    // Ending of parallel region 
} 
