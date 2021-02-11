/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

int initialize_elements(JobList List){
    return inputJobs(List);
}

SeqList createlist(){
    SeqList sl;
    sl.head = nextfreeloc++;
    sl.size = 0;
    st[sl.head].next = -1;
    return (sl);
}

void printJob (Job j){
    printf ("[JOB ID = %d | Priority = %d | Arr time = %d | Arrival time = %d]\n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list){
    int i; int size;

    printf("\n Enter the Number of Jobs :");
    scanf("%d", &size);

    for (i=0;i<size;i++){
        printf("\nEnter job ID");
        scanf("%d",&list[i].id);
        printf("Enter Priority (from 0 - 2)");
        scanf("%d",&list[i].pri);
        printf("Execution Time");
        scanf("%d",&list[i].et);
        printf ("Arrival Time");
        scanf ("%d",&list[i].at);
    }
    return size;
}

SeqList insert(Job j , SeqList sl){
    if (st[sl.head].next == -1){
        //the list was empty
        sl.size++;
        st[sl.head].next = nextfreeloc++;
        st[sl.head].ele = j;
    }
    else{
        int currentStorageLoacation = sl.head;
        int nextStorageLocation = st[currentStorageLoacation].next;

        //compare with current ORDER compare(Job j1, Job j2)
        while( nextStorageLocation != -1){
            Job ele = st[currentStorageLoacation].ele;
            ORDER what = compare(j, ele);
            if(what == LESSER || what == EQUAL){
                sl.size++;
                st[currentStorageLoacation].ele = j;
                st[currentStorageLoacation].next = nextfreeloc++;
                int tempLocationStorage = nextStorageLocation;
                nextStorageLocation = st[currentStorageLoacation].next;
                st[nextStorageLocation].ele = ele;
                st[nextStorageLocation].next = tempLocationStorage;
                return (sl);
            }
            else{
                currentStorageLoacation = nextStorageLocation;
                nextStorageLocation = st[currentStorageLoacation].next;
            }
        }
        // LAST condition: Greatest comparison_factor was addded
        sl.size++;
        st[currentStorageLoacation].next = nextfreeloc++;
        nextStorageLocation = st[currentStorageLoacation].next;
        st[nextStorageLocation].ele = j;
        st[nextStorageLocation].next = -1; // here it indicates the end of list
        return sl;
    }
}
  
void insertelements (JobList list , int size, SeqList s[3]){
    for(int i=0; i<size; i++){ 
        Job j = list[i];
        if(j.pri == PRI_0) s[0] = insert(j, s[0]);
        else if (j.pri == PRI_1) s[1] = insert(j, s[1]);
        else s[2] = insert(j, s[2]);
    }
    //copy_sorted_ele(s, list);
}

void copy_sorted_ele(SeqList s[3] , JobList ele){
    // copy s[2] -> s[1] -> s[0] to ele using st
    int currentStorageLocation;
    int nextStorageLocation;
    int index = 0;
    for(int i=2; i>=0; i--){
        currentStorageLocation = s[i].head;
        nextStorageLocation = st[currentStorageLocation].next;
        while (nextStorageLocation != -1)
        {
            ele[index++] = st[currentStorageLocation].ele;
            currentStorageLocation = nextStorageLocation;
            nextStorageLocation = st[currentStorageLocation].next;
        }
        ele[index++] = st[currentStorageLocation].ele;
    }
}

void printSeqlist(SeqList sl){
    int currentStorageLocation = sl.head;
    int nextStorageLocation = st[currentStorageLocation].next;

    while( nextStorageLocation != -1 ){
        printJob(st[currentStorageLocation].ele);
        currentStorageLocation = nextStorageLocation;
        nextStorageLocation = st[currentStorageLocation].next;
    }
    printJob(st[currentStorageLocation].ele); // as the nextStorageLocation will be -1
}

void printJobList(JobList list, int size){
    for(int i=0; i<size; i++){
        printJob(list[i]);
    }
}

void sortJobList(JobList list, int size){
    SeqList seq[3];
    seq[0] = createlist();
    seq[1] = createlist();
    seq[2] = createlist();
    insertelements(list, size, seq);
    printlist(seq[0]);   
    printlist(seq[1]);
    printlist(seq[2]);
    copy_sorted_ele(seq , list); 
}
