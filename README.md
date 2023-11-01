# openmp_cpu

For clang clang++ compiler
sudo apt install libomp-dev

For gcc g++ omp comes prebuild.

g++ omp1.cpp -fopenmp

1. omp1.cpp = openmp hello world
2. omp2.cpp = getting no of threads launched with each thread ids
3. omp3.cpp = launching a function with a specified no of threads.
4. omp4.cpp = barrier
    omp4_1.c = barrier deadlock example
5. omp5.cpp = handling critical section
6. omp6.cpp = pragma parallel for
7. omp7.cpp = private and shared variable
8. omp8.cpp = omp conditions
9. omp9.cpp = omp sections //ppt from here
10. omp10.cpp = mutex lock
11. imp11.cpp = reduction example //this may also avoid false sharing problem 
12. omp12.cpp, omp12_1.cpp, omp12_2.cpp = pragma parallel for2. False sharing problem example.
13  omp13.cpp = omp barrier and master example
14. omp14.cpp omp14_1.cpp = false sharing problem avoidance
15. omp15.cpp = single 
16. omp16.cpp = scheduling loops
17. omp17.cpp = tasks
    omp17_1.cpp=task depends
    omp17_2.cpp=taskloop
    omp17_3.cpp=taskgroup
    omp17_4.cpp=task vs sections syncronization demo
18. omp18.cpp = tasks 2
19. omp19.cpp = opem mp nested for loop, collapse
20. omp20.cpp = openmp ordered construct
21. omp21.cpp = openmp atomic 
