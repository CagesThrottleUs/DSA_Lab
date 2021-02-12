#include "alloc.h"
#include "stdio.h"

/* Structure definitions */
/* Structure: LinkedList node */

struct node{
    int element;
    struct node *next;
};

/* This counts the number of element in list and also
    has the pointer link to first node */
struct linkedList{
    struct node *head;
};

/*  function: insert()
    @param:
        linkeddList
        element
        total_mem
        file
    @return:
        none
    @desc:
        insert the element into list and update the required
*/
void insert(struct linkedList *ls, int ele, unsigned long int *total_mem);

/*  function: deleteFirst()
    @param:
        struct linkedList* ls
        total_mem
        file
    @desc:
        delete the first node in the list.
    @return:
        none
*/
void deleteFirst(struct linkedList *ls, unsigned long int *total_mem);

/*  function: length()
    @param:
        struct linkedList* ls
    @desc:
        calculates the length of the list
    @return:
        length
*/
unsigned int length(struct linkedList *ls);

/*  function: createList()
    @param:
        int N
        total_mem
        file
    @return:
        the linked list created
    @desc:
        Generate N random number and feed them to
        the list ls and return ls.
*/
struct linkedList *createList(int n, unsigned long int *total_mem, FILE* f);