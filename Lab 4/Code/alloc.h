/*  function: myalloc()
    @param:
        size of the array to be allocated.
        total heap memory
    @return:
        returns the starting address of array
        or null.
    @desc:
        create a dynamic array and i+1 as value
*/
void *myalloc(int size, unsigned long int *total_mem);

/*  function: myfree()
    @param:
        the pointer to array
        total heap memory
        memory to be deducted
    @return:
        none
    @desc:
        free the memory taken by array.
*/
void myfree(void *ptr, unsigned long int *total_mem, unsigned long int mem);