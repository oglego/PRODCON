#ifndef _BUFFER_H_DEFINED_
#define _BUFFER_H_DEFINED_

typedef int buffer_item;

#define BUFFER_SIZE 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex initializer
sem_t empty;                                       // semaphore
sem_t full;                                        // semaphore

void buffer_insert_item(buffer_item item); // Function Prototype
void buffer_remove_item(buffer_item item); // Function Prototype
#endif                                     // _BUFFER_H_DEFINED_
