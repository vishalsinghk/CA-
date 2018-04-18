#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int help=1;
pthread_mutex_t lock;
int n=1;


void *teacher()
{
	
	pthread_mutex_lock(&lock);
	int a,b;
	b=n;
	b--;
	a=help;
	a--;
	help=a;
	printf("\n\nStudent awake the teacher from sleep\n ");
	printf("\nStudent demand help from teacher");
   //     printf("\nTeacher Helping a student");
	a++;
	help=a;
	b++;
	n=b;
	pthread_mutex_unlock(&lock);
	
}


int main()
{
	pthread_mutex_init(&lock,NULL);
	int num_t,i;
	pthread_t *th;

	printf("\n\nTeacher is sleeping\n");
	printf("SLEEPINGGGGGGGGGGGGGGGG");
	printf("\n\nEnter the number of Student ..\n");
	scanf("%d",&num_t);
	
	if(num_t <= 0)
	{
		printf("\n Number of student is not less than 1\n");
		return 0;
	}
	else if(num_t >4)
	{
		printf("\n Only allow 4 and less than 4 student waiting outside student is=%d",num_t-4);
//		printf("\n After 4 student can wait for turn outside room");

		th=(pthread_t *)malloc(num_t * sizeof(pthread_t));

		for(i=0;i<num_t;i++)
		{

		pthread_create(&th[i],NULL,teacher,NULL);

		sleep(6);
		if(n==1)
		{
 printf("\nTeacher Helping a student number=%d",i+1);		
	printf("\nTeacher is sleeping   After helping the student \n\n");
		}

		sleep(3);
		}

		for(i=0;i<4;i++)
		{
		pthread_join(th[i],NULL);
		}

	}
	else
	{
	th=(pthread_t *)malloc(num_t * sizeof(pthread_t));

	for(i=0;i<num_t;i++)
	{

		pthread_create(&th[i],NULL,teacher,NULL);

		sleep(6);
		if(n==1)
		{
 printf("\nTeacher Helping a student number=%d",i+1);
			printf("\nTeacher is  Sleeping   After helping the student\n\n");
		}
		
		sleep(3);
		

	}



	for(i=0;i<num_t;i++)
	{
		pthread_join(th[i],NULL);

	}


	}

		
}
