typedef struct LinkedList{
    struct NODE* start;
    struct NODE* last;
    int linked_size;
    void (*append) (struct LinkedList* list,long data);
    void (*put_first) (struct LinkedList* list, long data);
    void (*put) (struct LinkedList* list,  int point, long data);
    long (*get) (struct LinkedList* list, int point);
    void (*remove_first) (struct LinkedList* list);
    void (*remove_last) (struct LinkedList* list);
    void (*remove) (struct LinkedList* list, int point);
    int (*size) (struct LinkedList* list);
    void (*clear) (struct LinkedList* lsit);
}LinkedList;
void _Linkedlist_init_(LinkedList* list);
void _Linkedlist_free_(LinkedList* list);
