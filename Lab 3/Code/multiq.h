#include "que.h"

/*  Structure definitions   */
struct multiq{
    int priority;
    struct queue q;
};

struct task{
    int tid; //task id
    int priority;
};

/*  Function Definitions    */

/*  function: createMQ()
    @param:
        int num
    @desc:
        dynamically allocate 
        multiq array of size 
        num.
    @return:
        multiq array
*/
struct multiq *createMQ(struct multiq *mq, int num);

/*  function: addMQ()
    @param:
        multiq mq
        task t
    @desc:
        add task t according to the 
        priority p in multiq.
    @return:
        the modified multiq
*/
struct multiq* addMQ(struct multiq* mq, struct task t);

/*  function: nextMQ()
    @param:
        multiq mq
        size of array
    @desc:
        returns the front of non-
        empty highest priority 
        queue.
    @return:
        the task
*/
struct task nextMQ(struct multiq *mq, int highest_priority);

/*  function: delNextMQ()
    @param:
        multiq mq
        size of array
    @desc:
        deletes the front task in
        the highest priority queue.
    @return:
        the modified multiq
*/
struct multiq *delNextMQ(struct multiq *mq, int highest_priority);

/*  function: isEmptyMQ()
    @param:
        multiq mq
        size of array
    @desc:
        checks if all queues in the
        multiq is empty are not.
    @return:
        1: true
        0: false
*/
int isEmptyMQ(struct multiq* mq, int size);

/*  function: sizeMQ()
    @param:
        multiq mq
        size of array
    @desc:
        returns the total number of
        items in the multiq.
    @return:
        int size
*/
int sizeMQ(struct multiq *mq, int size_of_arr);

/*  function: sizeMQbyPriority()
    @param:
        multiq mq
        int priority
    @desc:
        returns the number of item
        in a queue of priority p.
    @return:
        int size
*/
int sizeMQbyPriority(struct multiq* mq, int priority);

/*  function: getQueueFromMQ()
    @param:
        multiq mq
        int priority
    @desc:
        returns the queue with 
        given priority
    @return:
        struct queue
*/
struct queue getQueueFromMQ(struct multiq* mq, int priority);

/*  function: print()
    @param:
        multiq mq
        int size_of_arr
    @desc:
        print the entire multiq
    @return:
        none
*/
void print(struct multiq *mq, int size);