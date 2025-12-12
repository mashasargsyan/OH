      
#include <stdio.h>
#include <pthread.h>

#define MAX 8         
#define MAX_THREAD 4    

int a[MAX] = {1,2,3,4,5,6,7,8};
int sum[MAX_THREAD] = {0};
int part = 0;

pthread_mutex_t lock;

void* sum_array(void* arg)
{	
	    pthread_mutex_lock(&lock);
	        int thread_part = part++;
		    pthread_mutex_unlock(&lock);

		        int start = thread_part * (MAX / MAX_THREAD);
			    int end = (thread_part + 1) * (MAX/MAX_THREAD);

			        if (thread_part == MAX_THREAD - 1)
					        end = MAX;

				    for (int i = start; i < end; i++)
					        {
							        sum[thread_part] += a[i];
								    }

				        return NULL;
}

int main()
{
	    pthread_t threads[MAX_THREAD];
	        pthread_mutex_init(&lock, NULL);


		    for (int i = 0; i < MAX_THREAD; i++) {
			            pthread_create(&threads[i], NULL, sum_array, NULL);
				        }

		        for (int i = 0; i < MAX_THREAD; i++) {
				        pthread_join(threads[i], NULL);
					    }

			    int total_sum = 0;
			        for (int i = 0; i < MAX_THREAD; i++) {
					        total_sum += sum[i];
						    }

				    printf("Total sum (threads)= %d\n", total_sum);

				        int total_sum1 = 0;

					    for (int i = 0; i < MAX; i++) {
						            total_sum1 += a[i];
							        }

					        printf("Total sum = %d\n", total_sum1);

						    return 0;
}
        

