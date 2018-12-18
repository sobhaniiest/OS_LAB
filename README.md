# OS_LAB

Assignment – 1                        
1. Create a child from parent process. Child will compute the factorial of a given number and the parent checks if it is a prime number. 
2. Find out the maximum number of processes that can be created. 
3. Prove that context switch occurs when two process run infinitely.

Assignment – 2 
1. Write a shell program which implements, takes 
i) Name of a binary and executes it from current directory 
ii) Name and path of the binary and executes. 
iii) History feature. 
iv) Pipe 
2. Demonstrate how a zombie is created. Demonstrate how zombie creation can be prevented in four different ways.

Assignment – 3
1. Find out the context switch time and the time quantum on your system, programmatically. 
2. Compare the average time for creation of threads with that of processes. 
3. From the main threads, create a thread and detach it and show that it cannot be killed by other threads. 
4. Investigate if you can bind two threads to two different cores of your processor and them in parallel. 
5. Show that opened files are shared between thread and see whether the file pointer is also shared. 
6. Design a scenario to show that the exit status of a thread can be reaped. 
7. Illustrate the scenario of master thread and worker threads where each worker reads two lines from common file, 
displays them on the terminal and exits. 

Assignment – 4
1. Create a process P1, In P1, create a shared memory SM1, Similarly in process P2, create a shared memory SM2. 
P1 writes on SM1 and P2 reads from SM1. P2 writes on SM2 and P1 reads from SM2. Thus, user of P1 can communicate with the user of P2,
like in a messenger program.
2. Implement the solution of the Bounded Buffer Producer Consumer problem using Semaphores.
3. Provide the solution for the Dining Philosopher’s problem using semaphores.
4. Implement the solution of Reader’s priority Readers-Writers problem.

Assignment – 5
1. Create two shared libraries, A.so and B.so. 
A.so contain the implementation of factorial and B.so contains the implementation of palindrome. 
Show that these libraries can be simultaneously used 5 processes. 
Also, show that in each process, the address of the shared libraries in their logical address space is same (use gdb). 

Assignment – 6

1. Implement talk daemon for duplex communication between two processes using pipe.
