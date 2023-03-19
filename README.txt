Author: Aaron Ogle
Project: Project 4 - Producer/Consumer

*****************************************************************************************************

COMPILING INSTRUCTIONS:

To compile the program, the following commands must be called:

cc osproj3.c -o osproj3 -lpthread

after successfully compiling, the user must input

./osproj3 <> <> <> <> <>

where the 5 inputs are:

1) length of time the main thread should sleep
2) Max length of time the producer and consumer threads will sleep
3) Number of producer threads
4) Number of consumer threads
5) A "y" or "n" (stands for yes/no) to output the buffer snapshots for each item produced/consumed

*****************************************************************************************************

EXAMPLE INPUT/OUTPUT:

aogle@DESKTOP-0EPMK2E:~/CSC660/Projects/Project4$ cc osproj3.c -o osproj3 -lpthread
aogle@DESKTOP-0EPMK2E:~/CSC660/Projects/Project4$ ./osproj3 10 3 2 2 yes
Starting Threads...
(buffers occupied: 0)
buffers: -1 -1 -1 -1 -1
Producer 140221328197376 writes 81
(buffers occupied: 1)
buffers: 81 -1 -1 -1 -1
         -- -- -- -- --
         W
Producer 140221319743232 writes 23
(buffers occupied: 2)
buffers: 81 23 -1 -1 -1
         -- -- -- -- --
             W
Consumer 140221311289088 reads 81
(buffers occupied: 1)
buffers: -1 23 -1 -1 -1
         -- -- -- -- --
         R
Consumer 140221302834944 reads 23 * * * PRIME * * *
(buffers occupied: 0)
buffers: -1 -1 -1 -1 -1
         -- -- -- -- --
             R
All buffers empty.  Consumer 140221302834944 waits.

Producer 140221319743232 writes 71
(buffers occupied: 1)
buffers: -1 -1 71 -1 -1
         -- -- -- -- --
                W
Producer 140221328197376 writes 35
(buffers occupied: 2)
buffers: -1 -1 71 35 -1
         -- -- -- -- --
                   W
Consumer 140221311289088 reads 71 * * * PRIME * * *
(buffers occupied: 1)
buffers: -1 -1 -1 35 -1
         -- -- -- -- --
                R
Consumer 140221302834944 reads 35
(buffers occupied: 0)
buffers: -1 -1 -1 -1 -1
         -- -- -- -- --
                   R
All buffers empty.  Consumer 140221302834944 waits.

Producer 140221319743232 writes 38
(buffers occupied: 1)
buffers: -1 -1 -1 -1 38
         -- -- -- -- --
                      W
Producer 140221328197376 writes 54
(buffers occupied: 2)
buffers: 54 -1 -1 -1 38
         -- -- -- -- --
         W
Consumer 140221302834944 reads 38
(buffers occupied: 1)
buffers: 54 -1 -1 -1 -1
         -- -- -- -- --
                      R
Consumer 140221311289088 reads 54
(buffers occupied: 0)
buffers: -1 -1 -1 -1 -1
         -- -- -- -- --
         R
All buffers empty.  Consumer 140221311289088 waits.

Producer 140221319743232 writes 41
(buffers occupied: 1)
buffers: -1 41 -1 -1 -1
         -- -- -- -- --
             W
Consumer 140221311289088 reads 41 * * * PRIME * * *
(buffers occupied: 0)
buffers: -1 -1 -1 -1 -1
         -- -- -- -- --
             R
All buffers empty.  Consumer 140221311289088 waits.

Producer 140221328197376 writes 88
(buffers occupied: 1)
buffers: -1 -1 88 -1 -1
         -- -- -- -- --
                W
Consumer 140221302834944 reads 88
(buffers occupied: 0)
buffers: -1 -1 -1 -1 -1
         -- -- -- -- --
                R
All buffers empty.  Consumer 140221302834944 waits.

Producer 140221319743232 writes 88
(buffers occupied: 1)
buffers: -1 -1 -1 88 -1
         -- -- -- -- --
                   W
Producer 140221328197376 writes 22
(buffers occupied: 2)
buffers: -1 -1 -1 88 22
         -- -- -- -- --
                      W
Consumer 140221302834944 reads 88
(buffers occupied: 1)
buffers: -1 -1 -1 -1 22
         -- -- -- -- --
                   R
Consumer 140221311289088 reads 22
(buffers occupied: 0)
buffers: -1 -1 -1 -1 -1
         -- -- -- -- --
                      R
All buffers empty.  Consumer 140221311289088 waits.

Producer 140221319743232 writes 22
(buffers occupied: 1)
buffers: 22 -1 -1 -1 -1
         -- -- -- -- --
         W
Consumer 140221302834944 reads 22
(buffers occupied: 0)
buffers: -1 -1 -1 -1 -1
         -- -- -- -- --
         R
All buffers empty.  Consumer 140221302834944 waits.

Producer 140221328197376 writes 51
(buffers occupied: 1)
buffers: -1 51 -1 -1 -1
         -- -- -- -- --
             W
Consumer 140221311289088 reads 51
(buffers occupied: 0)
buffers: -1 -1 -1 -1 -1
         -- -- -- -- --
             R
All buffers empty.  Consumer 140221311289088 waits.

PRODUCER / CONSUMER SIMULATION COMPLETE
===========================================
Simulation Time:                         10
Maximum Thread Sleep Time:                3
Number of Producer Threads:               2
Number of Consumer Threads:               2
Size of Buffer:                           5

Total Number of Items Produced:          12
Total Number of Items Consumed:          12

Number of Items Remaining in Buffer:      0
Number Of Times Buffer Was Full:          0
Number of Times Buffer Was Empty:         8

*****************************************************************************************************

DESCRIPTION:

This program will implement a simulation of the Producer/Consumer problem in order to explore
process synchronization.  The program will utilize a circular array so that a producer may
input a random number that they generate and a consumer will then "consume" this number by
removing it from the array.  If the number is prime, the consumer will call out * * * PRIME * * *.

To make sure that a producer is not inputting a number into the array at the same time a consumer
is trying to remove an item from the array the program will utilize semaphores and mutexes so that
only the producer or consumer will be able to update the array at a given time.  To explore the process
of synchronization more, the producer will sleep for a random period of time and will then attempt to
insert an item into the array if there is room for it.  The consumer will also sleep for a random
period of time and will then try to remove an item from the array if there are items in the array
to be removed.  If the array (buffer) is full then the producer will call out that it is full and
if the array (buffer) is empty then the consumer will call out that it is empty.

The program will depend on user input, which is defined above, and the program will also output
statistics about the simulation after the simulation is completed.

To implement this program the use of threads are constructed for each the producer and consumer;
once these are created then the main function will sleep for the duration of the simulation, and
once the simulation is over then the threads will be joined/terminated with the other ones and the
statistics will be displayed.

*****************************************************************************************************
