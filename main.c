#include <stdio.h>
#include "LinkedList.h"
#include "Stack.h"

int main(){
    LinkedList list;
    _Linkedlist_init_(&list);
    Stack* stack;
    
    stack = malloc(sizeof(Stack));
    _stack_init_(stack);
    stack->push(stack, 1);
    stack->push(stack, 3);
    list.append(&list, (long)stack);
    
    stack = malloc(sizeof(Stack));
    _stack_init_(stack);
    stack->push(stack,5);
    stack->push(stack, 10);
    list.append(&list, (long)stack);
    
    stack = malloc(sizeof(Stack));
    _stack_init_(stack);
    stack->push(stack, 2);
    stack->push(stack, 4);
    list.append(&list,(long)stack);
    
    stack = (Stack*)(list.get(&list, 0));
    printf("%d ", stack->pop(stack));
    printf("%d\n", stack->pop(stack));
    _stack_free_(stack);
    free(stack);
    
    stack = (Stack*)(list.get(&list, 2));
    printf("%d ", stack->pop(stack));
    printf("%d\n", stack->pop(stack));
    _stack_free_(stack);
    free(stack);
    
    stack = (Stack*)(list.get(&list, 1));
    printf("%d ", stack->pop(stack));
    printf("%d\n", stack->pop(stack));
    _stack_free_(stack);
    free(stack);

    _Linkedlist_free_(&list);
    
    return 0;
}
