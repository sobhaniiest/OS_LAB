#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

FILE *fp;

void *thread1(void *vargp)
{
    char str[100];
    char c;
    pthread_t t = pthread_self();
    sprintf(str,"1st Thread ID = %ld \n",(long int)t);
    write(1,str,strlen(str));
    c = fgetc(fp);
    while(!feof(fp)) 
    {
        sprintf(str,"#%c",c); 
        write(1,str,strlen(str));
        c = fgetc(fp);
    }
    return NULL;
}

void *thread2(void *vargp)
{
    char str[100];
    char c;
    pthread_t t = pthread_self();
    sprintf(str,"2nd Thread ID = %ld \n",(long int)t);
    write(1,str,strlen(str));
    c = fgetc(fp);
    while(!feof(fp)) 
    {
        sprintf(str,"@%c",c); 
        write(1,str,strlen(str));
        c = fgetc(fp);
    }
    return NULL;
}

int main()
{
    fp = fopen("test.txt", "r");
    pthread_t tid1,tid2;
    void *tret;
    if(pthread_create(&tid1, NULL, thread1, NULL))
        printf("Error in creating thread1!\n");
    if(pthread_create(&tid2, NULL, thread2, NULL))
        printf("Error in creating thread2!\n");  
    if(pthread_join(tid1,&tret))
        printf("Error in joining thread1!\n");  
    if(pthread_join(tid2,&tret))
        printf("Error in joining thread2!\n");
 
    exit(0);
}