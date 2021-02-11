#include "multiq.h"
#include<stdlib.h>
#include<sys/time.h>
#include<stdio.h>
#include<string.h>
#define SIZE 10

int highest_priority = 0;
struct multiq *mq = NULL;

/*  function: loadData
    @param:
        FILE f
    @desc:
        read (tid, priority) pair
        from f and add them to 
        multiq
    @return:
        the generated multiq.
*/
struct multiq *loadData(FILE *f);

/*  function: testDel
    @param:
        int num
    @desc:
        performs num of 
        delNextMQ() operations.
    @return:
        the modified multiq.
*/
struct multiq* testDel(int num);

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Required number of inputs in command line not entered!\n");
        exit(1);
    }
    FILE* f = fopen(argv[1], "r");
    mq = loadData(f);
    printf("Enter the number of times delete operation to be used: ");
    int num;
    scanf("%d", &num);
    mq = testDel(num);
    fclose(f);
    free(mq);
    return 0;
}

/*  function: readVal()
    @param:
        char *haystack
        char needle
    @desc:
        to separate the <task_id, priority>
        pair and create a struct task obj.
    @return:
        struct task obj
*/
struct task readVal(const char *haystack, char needle){
    struct task temp;
    int len = strlen(haystack);
    // first 7 char are for tid
    char c[7] = "";
    strncat(c, haystack, 7);
    temp.tid = atoi(c);
    temp.priority = atoi(strchr(haystack, needle)+1);
    return temp;
}

void updateHighestPriority(){
    while(highest_priority > 0){
        int len = sizeMQbyPriority(mq, highest_priority);
        if(len == 0) highest_priority--;
        else break;
    }
}

struct multiq *loadData(FILE *f){
    time_t time1, time2;
    time1 = time(NULL);
    struct task temp;
    mq = (struct multiq *)malloc(SIZE * sizeof(struct multiq));
    mq = createMQ(mq, SIZE);
    highest_priority = SIZE;
    char s[15];
    while (fgets(s, 15, f)){
        printf("read: %s", s);
        temp = readVal(s, ',');
        mq = addMQ(mq, temp);
    }
    printf("\nThe queue now:\n");
    print(mq, SIZE);
    time2 = time(NULL);
    double diff_time = difftime(time2, time1);
    printf("Total Load Time: %lf\n", diff_time);
    updateHighestPriority();
    return mq;
}

struct multiq* testDel(int num){
    double sum=0;
    for(int i=0; i<num; i++){
        time_t t1, t2;
        t1 = time(NULL);
        printf("Highest Priority (prior deletion): %d\n", highest_priority);
        mq = delNextMQ(mq, highest_priority);
        updateHighestPriority();
        t2 = time(NULL);
        double diff = difftime(t2, t1);
        sum += diff;
        printf("Time for iteration [%d/%d]: %lf\n", i + 1, num, diff);
    }
    printf("The queue now:\n");
    print(mq, SIZE);
    printf("Average Time per iteration: %lf\n", sum / num);
}