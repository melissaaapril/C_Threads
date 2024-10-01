#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//creating global variable
#define NUM_THREADS 5

//thread function defined
void *ThreadFunction(void *arg){
    int thread_num = *(int*)arg;
    //making switch case for multiple threads
    // i couldve done an if else but i wanted to try switch case
    switch(thread_num){
        case 1:
        printf("I like the song Love is banned by Gemini (thread ID %lu)!\n");
        break;
        case 2:
        printf("I like the song When Sunday Comes Around by Marlon Funaki (thread ID %lu)!\n");
        break;
        case 3:
        printf("I like the song Mist by ateez (thread ID %lu)!\n");
        break;
        case 4:
        printf("I like playing guitar (thread ID %lu)!\n");
        break;
        case 5:
        printf("I like reading books (thread ID %lu)!\n");
        break;
    }
    //printf("I like the game Dress to Impress on Roblox %d! (ID%lu)\n", thread_num, pthread_self());
    //function is void so we return null
    return NULL;
}

//main function
int main(){
    //creating a new thread
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    //iterater 
    int i;

    //making the threads to pass along
    for (i = 0; i < NUM_THREADS; i++){
        //passing another thread nunm
        thread_args[i] = i + 1;
        if(pthread_create(&threads[i], NULL, ThreadFunction, &thread_args[i]) != 0){
            //error handling
            perror("pthread_create");
            return 1;
        }
    }
    //main thread to say hello
    printf("My name is Melissa!! (thread ID %lu)!\n", pthread_self());

    //waiting for child processes to finish
    for (i = 0; i<NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("All threads finished\n");
    return 0;
}