// #include<stdio.h>

/* Structure definitions */ 
/* Structure: LinkedList node */

struct node{
    int element;
    struct node* next;
};

/* This counts the number of element in list and also
    has the pointer link to first node */
struct linkedList{
    int count;
    struct node* first;
};

/*  function: insertFirst
    @param:
        struct linkedList* head
        int ele
    @desc:
        Insert a given element to the beginning of list
*/
void insertFirst(struct linkedList* head, int ele);

/*  function: deleteFirst
    @param:
        struct linkedList* head
    @desc:
        deletes the first of element of list
    @return:
        return the pointer to deleted element.
*/
struct node* deleteFirst(struct linkedList* head);

/*  function: printList
    @param:
        struct linkedList* head
    @desc:
        prints all elements in list
*/
void printList(struct linkedList* head);

/*  function: search
    @param:
        struct linkedList* head
        int ele
    @desc:
        searches for a given element in a linked list.
    @return:
        1 if found else 0
*/
int search(struct linkedList* head, int ele);

/*  function: delete
    @param:
        struct linkedList* head
        int ele
    @desc:
        delete the first node in the list with ele.
    @return:
        return the deleted node or send error back
*/
struct node* deleteEle(struct linkedList* head, int ele); // delete is a keyword in C++ so was getting error
