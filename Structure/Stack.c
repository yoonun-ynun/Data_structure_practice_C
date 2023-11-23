#include "Stack.h"
#include <stdlib.h>
#include <string.h>

void stack_resize(Stack* st){           //배열 크기를 동적으로 관리
    if(st->pointer == 0){
        st->arr = calloc(10, sizeof(int));
        memset(st->arr, 0, sizeof(int)*10);
        st->arr_size = 10;
        return;
    }
    
    if(st->arr_size == st->pointer){
        int* temparr = st->arr;
        st->arr = calloc(st->arr_size*2, sizeof(int));
        memcpy(st->arr, temparr, sizeof(int)*st->arr_size);
        free(temparr);
        st->arr_size*=2;
        return;
    }
    
    if(st->pointer < st->arr_size/2 && st->arr_size/2 >= 10){
        int* temparr = st->arr;
        st->arr = calloc(st->arr_size/2, sizeof(int));
        memcpy(st->arr, temparr, sizeof(int)*(st->arr_size/2));
        free(temparr);
        st->arr_size/=2;
        return;
    }
}

int stack_push(Stack* st,int item){
    stack_resize(st);
    st->arr[st->pointer++] = item;
    
    return item;
}

int stack_pop(Stack* st){
    if(st->pointer == 0){
        return -1;
    }
    return st->arr[--st->pointer];
}

int stack_peek(Stack* st){
    if(st->pointer == 0){
        return -1;
    }
    return st->arr[st->pointer-1];
}

int stack_size(Stack* st){
    return st->pointer;
}

void stack_clear(Stack* st){
    st->pointer = 0;
    stack_resize(st);
}

int stack_isEmpty(Stack* st){
    if(st->pointer == 0)
        return 1;
    else
        return 0;
}

void _stack_free_(Stack* st){       //동적할당된 배열 메모리 반환
    free(st->arr);
}

void _stack_init_(Stack* st){       //생성자
    st->pointer = 0;
    st->arr_size = 0;
    st->push = stack_push;
    st->resize = stack_resize;
    st->pop = stack_pop;
    st->peek = stack_peek;
    st->size = stack_size;
    st->isEmpty = stack_isEmpty;
    st->clear = stack_clear;
}
