/*
*****************************************************************************************************

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

*/

#include <stdio.h>     /* Input/output */
#include <stdlib.h>    /* required for rand() */
#include <pthread.h>   /* required for threads/mutex */
#include <unistd.h>    /* required for sleep() */
#include <semaphore.h> /* required for semaphore */
#include "buffer.h"    /* Include buffer.h header file */

buffer_item buffer[BUFFER_SIZE] = {-1, -1, -1, -1, -1}; /* Initialize a buffer to be of size BUFFER_SIZE - defined in header - set default values to -1 */
int buffer_cap = 0;                                     /* Variable that will keep track of how many buffers are occupied */
void *producer(void *param);                            /* Prototype for the producer model */
void *consumer(void *param);                            /* Prototype for the consumer model */
int input = 0;                                          /* Input variable in order to keep track of items that are input into our buffer */
int output = 0;                                         /* Output variable in order to keep track of items that are taken out of our buffer */
void display_buffers();                                 /* Helper function to iterate and print what is in the buffer */
int buffer_capacity();                                  /* Helper function that will keep track of how many buffers are occupied */
int simulation_flag = 1;                                /* Set the simulation flag to be initialized to true - used for running the simulation*/
void primality_check(int num);                          /* Function to see if a given number is prime */
static char *snapshot;                                  /* Static char variable so that we can pass what the user inputs to our below functions */
int num_produced = 0;                                   /* Keep track of the number of items that are produced */
int num_consumed = 0;                                   /* Keep track of the number of items that are consumed */
int num_times_full_buff = 0;                            /* Keep track of the number of times that the buffer becomes full */
int num_times_empty_buff = 0;                           /* Keep track of the number of times that the buffer is empty */

int main(int argc, char *argv[])
{
    /* Declare variables for what the user inputs
    1) (simulation_time) - Length of time the main thread is to sleep before terminating
    2) (max_sleep) - Max length of time the producer and consumer threads will sleep before producing or consuming an item
    3) (producers) - Number of Producer Threads
    4) (consumers) - Number of Consumer Threads
    5) (snapshot) - A "y" or "n" to output individual buffer snapshots
    */

    int simulation_time = atoi(argv[1]);
    int max_sleep = atoi(argv[2]);
    int producers = atoi(argv[3]);
    int consumers = atoi(argv[4]);
    snapshot = (argv[5]);

    /* Create threads based off of what the user inputs above
    for the number of producer threads and consumer threads */
    pthread_t producer_threads[producers];
    pthread_t consumer_threads[consumers];

    /* Initialize the mutex and sempahores */
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    /* Display starting message */
    printf("Starting Threads...");
    /* Call buffer_capacity and show the number of buffers occupied */
    int bc = buffer_capacity();
    printf("\n(buffers occupied: %d)", bc);
    /* Display the buffers and the values that are contained in them */
    display_buffers();

    /* create the threads based off of the number of producers input above;
    argv[2] is passed to the producer function in order to utilize the value
    of max_sleep variable that the user passes above */
    for (int i = 0; i < producers; i++)
    {
        pthread_create(&producer_threads[i], NULL, producer, argv[2]);
    }
    /* create the threads based off of the number of consumers input above;
    argv[2] is passed to the consumer function in order to utilize the value
    of max_sleep variable that the user passes above */
    for (int i = 0; i < consumers; i++)
    {
        pthread_create(&consumer_threads[i], NULL, consumer, argv[2]);
    }

    // Make the main threads sleep for the length of time input by the user */
    sleep(simulation_time);
    // Set simulation flag to false; simulation is over */
    simulation_flag = 0;

    /* wait for the producer threads to terminate */
    for (int i = 0; i < producers; i++)
    {
        pthread_join(producer_threads[i], NULL);
    }
    /* wait for the consumer threads to terminate */
    for (int i = 0; i < consumers; i++)
    {
        pthread_join(consumer_threads[i], NULL);
    }

    /* cleanup and destroy the mutex that we created along with the semaphores for empty and full */
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    /* Display the statistics of the simulation */
    printf("  \nPRODUCER / CONSUMER SIMULATION COMPLETE  \n");
    printf("===========================================\n");
    printf("Simulation Time: %26d\n", simulation_time);
    printf("Maximum Thread Sleep Time: %16d\n", max_sleep);
    printf("Number of Producer Threads: %15d\n", producers);
    printf("Number of Consumer Threads: %15d\n", consumers);
    printf("Size of Buffer: %27d\n\n", BUFFER_SIZE);
    printf("Total Number of Items Produced: %11d\n", num_produced);
    printf("Total Number of Items Consumed: %11d\n\n", num_consumed);
    printf("Number of Items Remaining in Buffer: %6d\n", buffer_cap);
    printf("Number Of Times Buffer Was Full: %10d\n", num_times_full_buff);
    printf("Number of Times Buffer Was Empty: %9d\n\n\n", num_times_empty_buff);
}

/*
***********************************************************************************************
Display Buffers Function

This function is a simple helper function which will iterate through our
buffer and display the contents of it.

Return Value
--------------
None - void function does not return a value; it just displays what is in the buffer

Value Parameters
-------------
None - This function does not take any parameters; it just displays what is in the buffer

***********************************************************************************************
*/

void display_buffers()
{
    printf("\nbuffers: ");
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        printf("%d ", buffer[i]);
    }
}

/*
***********************************************************************************************
Buffer Capacity Function

This function is a simple helper function which will calculate the capacity of the buffer.

The function will iterate through our buffer and count the number of spots which show the
value of -1 which indicates that this spot in our buffer is empty.  Once we have this count
we subtract the value from the size of our buffer in order to calculate how many spots
are taken in the buffer.

Return Value
--------------
Int - Return the number of taken spots in the buffer

Value Parameters
-------------
None - This function does not take any parameters

***********************************************************************************************
*/

int buffer_capacity()
{
    buffer_cap = 0;
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        if (buffer[i] == -1)
            buffer_cap += 1;
    }
    buffer_cap = BUFFER_SIZE - buffer_cap;
    return buffer_cap;
}

/*
***********************************************************************************************
Buffer Insert Item Function

This function is declared in our header file.  The function will accept a buffer item as input
and will then insert the item into our buffer.  We utilize our "input" global variable defined
above so that we can input the given buffer_item into the correct spot of our circular array.

Return Value
--------------
None - This function is a void function and will not return any value; it will insert an item
into our buffer

Value Parameters
-------------
item - buffer_item - This function will accept a buffer_item as input

***********************************************************************************************
*/

void buffer_insert_item(buffer_item item)
{
    buffer[input] = item;
}

/*
***********************************************************************************************
Buffer Remove Item Function

This function is declared in our header file.  This function will remove an item from our
buffer by searching for the item that is given in the parameter in our buffer; if the value
is found in our buffer then that value is set to -1 in order to show that the item has
been removed from the buffer.

Return Value
--------------
None - This function is a void function and will not return any value; it will remove a given
item from our buffer

Value Parameters
-------------
item - buffer_item - This function will accept a buffer_item as input

***********************************************************************************************
*/

void buffer_remove_item(buffer_item item)
{
    for (int i = 0; i < BUFFER_SIZE; i++)
        if (buffer[i] == item)
            buffer[i] = -1;
}

/*
***********************************************************************************************
Primality Check Function

This function will accept an integer as input and will then check to see if the number is
a prime number.

We first initialize a "prime flag" (int prime) to 0 in order to flag whether or not a number
is prime.

The function will iterate through numbers which are greater than 2 and less than the given
number to see if the number is divisible by any of the numbers between 2 and itself; if the
input number is divisible by one of these numbers then we set the prime flag to 1 indicating
that no the number is not a prime number.

If none of the numbers divide the input number then it is a prime number and * * * PRIME * * *
is printed out.

Return Value
--------------
None - This function is a void function and will not return any value; it will just display
* * * PRIME * * * if the input number is a prime number.

Value Parameters
-------------
num - int - This function accepts an integer as input

***********************************************************************************************
*/

void primality_check(int num)
{
    int prime = 0;
    if (num > 1)
    {
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
                prime = 1;
        }

        if (prime == 0)
            printf("* * * PRIME * * *");
    }
}

/*
***********************************************************************************************
Producer Function

This function will simulate our Producer in our Producer/Consumer Model.

The producer function will first create a buffer item, then declare a max_sleep time based
off of the parameter that is based to it.  Then for the entirety of the simulation time it will
sleep for a random number of seconds based off of the max sleep time that is passed to it.  After
the producer has "slept" it will generate a random number.  Once this random number is calculated
the producer will utilize a semaphore and mutex in order to lock the buffer so that a consumer
cannot update the buffer while it is trying to insert the random number that it has produced.

After this happens the producer inserts the random number into the buffer and variables are
updated and might be displayed based off of whether or not the user wants to see snapshots
of the activity for each iteration.  Once the item has been inserted by the producer the "input"
variable is updated in order to keep track of where the producer is at in our buffer; after this is
done then the producer will "unlock" the mutex and then by using the semaphore will "signal" the
consumer that they are done with the buffer.


Return Value
--------------
None - This function is a void function and will not return any value

Pointer Parameters
-------------
 param - void pointer - This function will, in this case, accept the max_sleep variable
 as input from the user

***********************************************************************************************
*/

void *producer(void *param)
{
    buffer_item r;
    int max_sleep = atoi(param);
    while (simulation_flag)
    {
        /* sleep for a random period of time */
        /* the random period of time will be between 1 and the value of max_sleep defined above that the user inputs*/
        srand(time(NULL));                // Needed in order to reset random value so that it is not the same each time
        int t = rand() % (max_sleep) + 1; // Use t for "time" and compute the number of seconds the producer must "sleep"
        sleep(t);
        /* generate a random number between 1 and 100*/
        r = rand() % (100) + 1;
        /* After a value is produced in the producer model the following needs to be done:
        wait(empty)
        wait(mutex)
        add next produced to buffer
        signal(mutex)
        signal(full) */
        sem_wait(&empty);           // wait
        pthread_mutex_lock(&mutex); // lock
        buffer_insert_item(r);      // insert the random number generated into the buffer
        num_produced += 1;          // increment our count of how many numbers are produced by the producer

        //  Display Producer x writes r - notate buffers occupied, and display the buffers values
        //  this is based on whether or not the user wants to see this information for each "snapshot"
        // pthread_self is utilized in order to show the id of the current thread
        if (*snapshot == 'y')
            printf("\nProducer %lu writes %d", pthread_self(), buffer[input]); // show thread id and what value the producer produced
        int bc = buffer_capacity();
        if (*snapshot == 'y')
            printf("\n(buffers occupied: %d)", bc); // show the number of buffers that are occupied
        if (*snapshot == 'y')
            display_buffers(); // display the buffers and their contents
        // Display dashes under the slots of the buffers and show W under the location of where the producer is writing to
        if (*snapshot == 'y')
            printf("\n         -- -- -- -- --");
        if (input == 0 && *snapshot == 'y')
            printf("\n         W");
        if (input == 1 && *snapshot == 'y')
            printf("\n             W");
        if (input == 2 && *snapshot == 'y')
            printf("\n                W");
        if (input == 3 && *snapshot == 'y')
            printf("\n                   W");
        if (input == 4 && *snapshot == 'y')
            printf("\n                      W");
        if (bc == 5 && *snapshot == 'y')
            printf("\nAll buffers full.  Producer %lu waits.\n", pthread_self()); // show that the producer is waiting if the buffer is full of items
        if (bc == 5)
            num_times_full_buff += 1; // keep track of the number of times that the buffer is full

        // Below syntax based off of in = (in + 1) % BUFFER_SIZE found in chapter 3
        input = (input + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex); // unlock so that the consumer can consume what is in the buffer
        sem_post(&full);              // signal the consumer that the producer is no longer updating the buffer
    }
}

/*
***********************************************************************************************
Consumer Function

This function will simulate our Consumer in our Producer/Consumer Model.

The function will first set a variable to be the value of max_sleep time which is based off
of the value that is passed to the function that the user has input above.  The function will
then do the following based off of how long the simulation time is.  The consumer
will sleep for a random period of time based off of the max sleep time that is passed to it.
After the consumer has "slept" it will utilize a mutex and semaphore in order to "lock" and
"signal" the producer that they are updating the buffer.  The consumer will then "consume"
what has been input into the buffer by removing the item from the buffer (in this case the
consumer is calling a function so that the items value is set to -1 to indicate that it has
been removed from the buffer) after the consumer has removed the item from the buffer then
it will display the "snapshot" values based on whether or not the user wants to see these
values.  After this is done, then the consumer will update the "output" variable in order to
keep track of where they are consuming at in the buffer; after this is done then the consumer
will then "unlock" and "signal" the producer that they are done with updating the buffer.

Return Value
--------------
None - This function is a void function and will not return any value

Pointer Parameters
-------------
 param - void pointer - This function will, in this case, accept the max_sleep variable
 as input from the user

***********************************************************************************************
*/

void *consumer(void *param)
{
    // set max sleep to be the value of what the user has input
    int max_sleep = atoi(param);
    // for the length of the simulation do what is in the while loop
    while (simulation_flag)
    {
        /* sleep for a random period of time */
        /* the random period of time will be between 1 and the value passed for max_sleep in seconds */
        srand(time(NULL));                // Needed in order to have reset random value
        int t = rand() % (max_sleep) + 1; // Use t for "time"
        sleep(t);
        /* After a value is produced in the producer model the following needs to be done by the consumer:
        wait(full)
        wait(mutex)
        remove an item from buffer to next consumed
        signal(mutex)
        signal(empty)
        consume the item in next consumed
        */
        sem_wait(&full);            // wait/signal producer
        pthread_mutex_lock(&mutex); // lock
        int value = buffer[output]; // set a value to be the value of what is in the buffer at the current position
        buffer_remove_item(value);  // remove this value from the buffer (consume it)
        num_consumed += 1;          // increment the count of how many numbers are consumed from the buffer

        // Display "snapshot" values based off of whether or not the user wants to see these values
        // utilize pthread_self in order to show the id of the thread
        if (*snapshot == 'y')
            printf("\nConsumer %lu reads %d ", pthread_self(), value); // show the thread id and the value that the consumer is consuming
        if (*snapshot == 'y')
            primality_check(value); // check whether or not the number consumed is prime, if it is display * * * PRIME * * *
        int bc = buffer_capacity();
        if (*snapshot == 'y')
            printf("\n(buffers occupied: %d)", bc); // show the number of buffers that are occupied
        if (*snapshot == 'y')
            display_buffers(); // display the buffers and their content

        // Display dashes under the slots of the buffers and show R under the location of where the consumer is reading from
        if (*snapshot == 'y')
            printf("\n         -- -- -- -- --");
        if (output == 0 && *snapshot == 'y')
            printf("\n         R");
        if (output == 1 && *snapshot == 'y')
            printf("\n             R");
        if (output == 2 && *snapshot == 'y')
            printf("\n                R");
        if (output == 3 && *snapshot == 'y')
            printf("\n                   R");
        if (output == 4 && *snapshot == 'y')
            printf("\n                      R");
        if (bc == 0 && *snapshot == 'y')
            printf("\nAll buffers empty.  Consumer %lu waits.\n", pthread_self()); // If the buffers are empty display it and the thread id of the waiting consumer
        if (bc == 0)
            num_times_empty_buff += 1; // keep track of the number of times that the buffer is empty

        // Below syntax is based off of out = (out + 1) % BUFFER_SIZE found in chapter 3 */
        output = (output + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex); // unlock the buffer for the producer
        sem_post(&empty);             // signal the producer that the consumer is no longer updating the buffer
    }
}
