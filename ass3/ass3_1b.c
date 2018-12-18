#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <string.h>
#include <linux/unistd.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>


int main()

{
    double quantum;
    cpu_set_t set;
    struct sched_param prio_param;
    int prio_max;

    CPU_ZERO( &set );
    CPU_SET( 0, &set );
    memset(&prio_param,0,sizeof(struct sched_param));

    struct timespec tp;

    sched_setaffinity( getpid(), sizeof( cpu_set_t ), &set );
    prio_max = sched_get_priority_max(SCHED_RR);
    prio_param.sched_priority = prio_max;
    sched_setscheduler(getpid(),SCHED_RR,&prio_param);


    sched_rr_get_interval( 0,&tp);

    quantum = (tp.tv_sec*1000000000+tp.tv_nsec)/1000;
    printf("Time Quantum = %lf us\n",quantum);

}
