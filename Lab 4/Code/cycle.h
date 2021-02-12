#include "linkedlist.h"
#include "stdio.h"

/*  function: createCycle()
    @param:
        linkedList
    @return:
        the node value
    @desc:
        Randomly choose if list is going to be
        linear or cyclic and properly make 'em
*/
int createCycle(struct linkedList *ls, FILE* f);

/*  function: testCyclic()
    @param:
        linkedList
    @return:
        0 - linear
        1 - cyclic
    @desc:
        test the list for cyclic nature. For dummy 
        implementation try to return always linear
*/
int testCyclic(struct linkedList *ls);

/*  function: makeCircularList()
    @param:
        linkedList
        total_mem
        file
        status
    @return:
        none
    @desc:
        check the cyclicity of list and make it a
        circular list.
*/
void makeCircularList(struct linkedList *ls, int status, unsigned long int *total_mem, FILE* f);