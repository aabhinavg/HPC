**HPC With C++** <p>
- C++ uses [OpenMp](https://www.openmp.org/) (API) that support multi-platform shared memory multiprocessing programming on most platform including HPC.
- We are going to get information about how parallel programming is achieved in C++.
</pr>

**First Hello Parallel World Using Openmp** </br>
  - **Step 1**.
    - Include Header file for openMp along with standard header file <b>#include <omp.h></b>
  - **Step 2** 
    - ***Specify the parallel region where you want to make Shared Resouce Which Can Be Accesed Parallel***
      - <b> pragma omp parallel </b> is a keyword used to make region parallel.(i.e Resources or chunks of code inside this region are shared among thread)
            The pragma omp parallel fork additional threads to carry out the work enclosed in the parallel. The original thread will be denoted as the 
            master thread with <b> thread ID 0 </b>. Code for creating a parallel region would be,
            <pre>
                  #pragma omp parallel
                  {
                    //Code for the parallel region.
                  }
             </pre>     
                  
      - Here we want to make <b>Hello Parallel World </b> string as a parallel region to be shared between the thread </br> 
        Therefore;
            <pre>
                  #pragma opm parallel
                  {
                      printf("Hello Parallel World ... from thread =%d\n",<b>omp_get_thread_number()</b>);
                  }
            </pre>
      - Here omp_get_thread_number() is a API to know it about in detail [click here](https://www.openmp.org/spec-html/5.0/openmpsu113.html).
      
  - **Step 3**  
    - ***Specify The Number of Thread Going To Acess The Shared Memory Region***</br>  
      - Here we can use external variable to set the number of thread to access the shared recourse created in above Step 2.
        <pre>
              <b> export OMP_NUM_THREADS=5 </b>
        </pre>
  <p><u><strong>Internal Mechanism of Thread</strong></u><br />
  <a href="https://media.geeksforgeeks.org/wp-content/uploads/20190420123429/Parallel-Region1.png"><img src="https://media.geeksforgeeks.org/wp-content/uploads/20190420123429/Parallel-Region1.png" alt="Shared Memory region between 5 threads" width="610" height="350" class="aligncenter size-full wp-image-1015627" /></a></p>
  <p>As per the above figure, Once the compiler encounters the shared regions code, the master thread(<em> <b>thread which has thread id 0 </b></em>) will fork into the specified number of threads. Here it will get forked into 5 threads because we will initialise the number of threads to be executed as 5, using the command <code><b>export OMP_NUM_THREADS=5</b></code>. Entire code within the parallel region will be executed by all threads concurrently. <b>Once the parallel region ended, all threads will get merged into the master thread.</b></p>
  </li>
  <li><strong>Compile and Run or Build</strong>:<br />
  <b>Build:</b></p>
  <pre>gcc -o parallel_world -fopenmp hello.c</pre>
  <p><b>Execute:</b></p>
<pre>./parallel_world</pre>
</li>
</ol>
