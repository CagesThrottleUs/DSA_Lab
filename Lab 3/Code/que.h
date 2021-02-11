/*  Structure definitions   */
/*  Defines a node  */
struct node{
    int element;
    struct node* next;
};

/*  Defines the queue   */
struct queue{
    struct node* front;
    struct node* rear;
};

/*  Function declaration    */

/*  function: newQ()
    @return: 
        returns an empty queue
*/
struct queue newQ();

/*  function: isEmptyQ()
    @param:
        struct queue
    @return:
        1: if q is empty
        0: elsewhere
*/
int isEmptyQ(struct queue q);

/*  function: delQ()
    @param:
        struct queue
    @desc:
        Deletes the element in 
        front of queue.
    @return:
        the modified queue
*/
struct queue delQ(struct queue q);

/*  function: front()
    @param:
        struct queue
    @desc:
        returns the element of first
    @return:
        int ele
*/
int front(struct queue q);

/*  function: addQ()
    @param:
        struct queue
        int ele
    @desc:
        add ele to the end of queue
        and return the modified que
    @return:
        the modified queue
*/
struct queue addQ(struct queue q, int ele);

/*  function: lengthQ()
    @param:
        struct queue
    @desc:
        returns the length of queue
    @return:
        int len
*/
int lengthQ(struct queue q);

/*  function: printQ()
    @param:
        struct queue
    @desc:
        prints the queue
    @return:
        none
*/
void printQ(struct queue q);