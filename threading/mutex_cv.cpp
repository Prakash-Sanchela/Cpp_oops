/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <pthread.h>

using namespace std;

pthread_mutex_t mt1;
pthread_cond_t cv;
int data = 0;

	void* printEven(void *p1)
	{
	    while(data < 40)
	    {
	        pthread_mutex_lock(&mt1);
	        if (data %2 == 0) {
	            printf("Tid %ld even %d \n", pthread_self(),data++);
	        }
	        pthread_mutex_unlock(&mt1);
	    }
	    pthread_exit(0);
	}
	
	void* printOdd(void *p2)
	{
	    while(data < 40)
	    {
	        pthread_mutex_lock(&mt1);
	        if (data %2 != 0) {
	            printf("Tid %ld odd %d \n", pthread_self(), data++);   
	        }
	        pthread_mutex_unlock(&mt1);
	    }
	    pthread_exit(0);
	}

int main()
{
     // threading
	    pthread_t id1, id2, id3, id4;
	    
	    pthread_create(&id1, NULL, &printEven, NULL);
	    pthread_create(&id2, NULL, &printOdd, NULL);
	    
	    pthread_create(&id3, NULL, &printEven, NULL);
	    pthread_create(&id4, NULL, &printOdd, NULL);
	    //sleep(3);
	    
	    pthread_join(id1, NULL);
	    pthread_join(id2, NULL);
	    pthread_join(id3, NULL);
	    pthread_join(id4, NULL);

        pthread_mutex_destroy(&mt1);
	    pthread_cond_destroy(&cv);

    cout<<"Hello World";

    return 0;
}





/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <pthread.h>

using namespace std;

pthread_mutex_t mt1;
pthread_cond_t cv;
int data = 0;

	void* printEven(void *p1)
	{
	    while(data < 40)
	    {
	        pthread_mutex_lock(&mt1);
	        /*while (data%2 != 0)
	        {
	            //thread_cond_wait(&cv, &mt1);
	        }*/
	        if (data %2 == 0) {
	            printf("%d ", data++);
	        }
	        else
	        {
	            //pthread_cond_signal(&cv);
	            pthread_mutex_unlock(&mt1);
	        }
	    }
	    pthread_exit(0);
	}
	
	void* printOdd(void *p2)
	{
	    while(data < 40)
	    {
	        pthread_mutex_lock(&mt1);
	        /*while (data % 2 != 1)
	        {
	            //pthread_cond_wait(&cv, &mt1);
	        }*/
	        if (data %2 != 0) {
	            printf("%d ", data++);   
	        }
	        else {
	        //pthread_cond_signal(&cv);
	        pthread_mutex_unlock(&mt1);
	        }
	    }
	    pthread_exit(0);
	}

int main()
{
     // threading
	    pthread_t id1, id2;
	    
	    pthread_create(&id1, NULL, &printEven, NULL);
	    pthread_create(&id2, NULL, &printOdd, NULL);
	    //sleep(3);
	    
	    pthread_join(id1, NULL);
	    pthread_join(id2, NULL);

        pthread_mutex_destroy(&mt1);
	    pthread_cond_destroy(&cv);

    cout<<"Hello World";

    return 0;
}
