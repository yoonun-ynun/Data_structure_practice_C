#include "LinkedList.h"
#include <stdlib.h>

typedef struct NODE{
    long data;
    struct NODE* next;
    struct NODE* previous;
}NODE;


void append(LinkedList* list,long data){
    if(list->linked_size == 0){
        list->start = malloc(sizeof(LinkedList));
        list->last = list->start;
        list->last->data = data;
        list->linked_size++;
        return;
    }else{
        list->last->next = malloc(sizeof(LinkedList));
        list->last->next->previous = list->last;
        list->last = list->last->next;
        list->last->data = data;
        list->linked_size++;
    }
}

NODE* getnode(LinkedList* list, int point){
    if(point>=list->linked_size/2){
        point = (list->linked_size - 1) - point;
        NODE* pointer = list->last;
        int i;
        for(i = 0;i<point;i++)
            pointer = pointer->previous;
        return pointer;
    }else{
        NODE* pointer = list->start;
        int i;
        for(i = 0;i<point;i++)
            pointer = pointer->next;
        return pointer;
    }
}

long get(LinkedList* list, int point){
    return getnode(list, point)->data;
}

void put_first(LinkedList* list, long data){
    if(list->linked_size == 0){
        list->start = malloc(sizeof(LinkedList));
        list->last = list->start;
        list->last->data = data;
        list->linked_size++;
        return;
    }else{
        list->start->previous = malloc(sizeof(LinkedList));
        list->start->previous->next = list->start;
        list->start = list->start->previous;
        list->start->data = data;
        list->linked_size++;
        return;
    }
}

void put(LinkedList* list, int point, long data){
    if(point == list->linked_size){
        append(list, data);
        return;
    }else if(point == 0){
        put_first(list, data);
        return;
    }else{
        NODE* pointer = getnode(list, point);
        NODE* previous = pointer->previous;
        previous->next = malloc(sizeof(LinkedList));
        pointer->previous = previous->next;
        previous->next->next = pointer;
        previous->next->previous = previous;
        previous->next->data = data;
        list->linked_size++;
    }
}

void del_first(LinkedList* list){
    if(list->linked_size == 1){
        free(list->start);
        list->linked_size--;
        return;
    }else{
        list->start = list->start->next;
        free(list->start->previous);
        list->start->previous = NULL;
        list->linked_size--;
        return;
    }
}

void del_last(LinkedList* list){
    if(list->linked_size == 1){
        free(list->last);
        list->linked_size--;
        return;
    }else{
        list->last = list->last->previous;
        free(list->last->next);
        list->last->next = NULL;
        list->linked_size--;
        return;
    }
}

void delete(LinkedList* list, int point){
    if(point+1 == list->linked_size){
        del_last(list);
    }else if(point == 0){
        del_first(list);
    }else{
        NODE* remove = getnode(list, point);
        remove->previous->next = remove->next;
        remove->next->previous = remove->previous;
        free(remove);
        list->linked_size--;
    }
}

int getsize(LinkedList* list){
    return list->linked_size;
}

void Linkedlist_clear(LinkedList* list){
    int i, size = list->linked_size;
    for(i = 0;i<size;i++){
        del_last(list);
    }
    list->linked_size = 0;
}

void _Linkedlist_init_(LinkedList* list){
    list->linked_size = 0;
    list->append = append;
    list->get = get;
    list->put = put;
    list->remove = delete;
    list->size = getsize;
    list->put_first = put_first;
    list->remove_first = del_first;
    list->remove_last = del_last;
    list->clear = Linkedlist_clear;
}

void _Linkedlist_free_(LinkedList* list){
    Linkedlist_clear(list);
}
