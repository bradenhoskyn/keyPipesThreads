/***************************************************************

 ***************************************************************/

#include "general.h"

int main(void)
{
	pthread_t thread1, thread2, thread3;
	int pipe1[2];//pipe for child 1 and child 2 to share
	int pipe2[2];//pipe for child 2 and child 3 to share
	int status;//for wait()

	if(pipe(pipe1)<0)
	{
		fprintf(stderr, "Error opening pipe #1\n\n");
		exit(100);
	}

	//pipe one array
	int arrayOne[2];
	arrayOne[0] = 0;
	arrayOne[1] = pipe1[1];

	pthread_create(&thread1, NULL, child1, (void *) arrayOne); //create pthread and call child 1 process


	if(pipe(pipe2)<0)
	{ 
		fprintf(stderr, "Error opening pipe #2\n\n");
		exit(100);
	}

	//pipe2 array
	int arrayTwo[2];
	arrayTwo[0] = pipe1[0];
	arrayTwo[1] = pipe2[1];

	pthread_create(&thread2, NULL, child2, (void *) arrayTwo); //create pthread and call child 1 process



	//pipe3 array
	int arrayThree[2];
	arrayThree[0] = pipe2[0];
	arrayThree[1] = 1;

	pthread_create(&thread3, NULL, child3, (void *) arrayThree); //create pthread and call child 1 process


	/*wait for all three children in whatever order they complete*/
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	return(0);
}
