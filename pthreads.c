#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//thread function defined
void *ThreadFunction(void *arg){
    printf("Hello World from thread ID %lu!\n", pthread_self());
    //function is void so we return null
    return NULL;
}

//main function
int main(){
    //creating a new thread
    pthread_t thread;
    if(pthread_create(&thread, NULL, ThreadFunction, NULL)!=0){
        //error handling
        perror("pthread_create");
        return 1;
    }
    //main thread to say hello
    printf("Hello world from the main thread (thread ID %lu)!\n", pthread_self());

    //waiting for child process to finish
    pthread_join(thread, NULL);

    return 0;
}