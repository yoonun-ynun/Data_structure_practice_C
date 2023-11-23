#include <stdlib.h>
#include <string.h>
typedef struct stack{
    int pointer;
    int* arr;
    int arr_size;
    void (*resize) (struct stack* st);
    int (*push) (struct stack* st, int item);
    int (*pop) (struct stack* st);
    int (*peek) (struct stack* st);
    int (*size) (struct stack* st);
    int (*isEmpty) (struct stack* st);
    void (*clear) (struct stack* st);
}Stack;

void _stack_free_(Stack* st);
void _stack_init_(Stack* st);
