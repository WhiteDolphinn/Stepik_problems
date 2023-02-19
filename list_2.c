#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Data;
struct Node {
    struct Node * next;
    struct Node * prev;
    Data data;
};

void list_init(struct Node * list);

void list_insert(struct Node * list, struct Node * t);
void list_insert_before(struct Node * list, struct Node * t);
void list_remove(struct Node * t);

struct Node * list_push_front(struct Node * list, Data d);
struct Node * list_push_back(struct Node * list, Data d);

Data list_pop_front(struct Node * list);
Data list_pop_back(struct Node * list);
Data list_delete(struct Node * t);

void list_print (struct Node * list);
int list_is_empty(struct Node * list);

void list_clear(struct Node * list);
void list_print (struct Node * list);
int list_is_empty (struct Node * list);

void test_non_alloc(int n)
{
    struct Node * x = malloc(11*sizeof(struct Node));
    struct Node * a = x+10;

    list_init(a);
    assert(list_is_empty(a));
    if(n == 1)
        goto END;

    for(int i = 0; i < 10; i++) {
        x[i].data = i;
        list_insert(a, &x[i]);
    }
    list_print(a);              // 9 8 7 6 5 4 3 2 1 0
    assert(!list_is_empty(a));
    if(n == 2)
        goto END;

    list_remove(&x[5]);
    list_print(a);              // 9 8 7 6 4 3 2 1 0
    list_remove(&x[0]);
    list_print(a);              // 9 8 7 6 4 3 2 1
    list_remove(&x[9]);
    list_print(a);              // 8 7 6 4 3 2 1
    if(n == 3)
        goto END;

    list_insert_before(a, &x[0]);
    list_print(a);              // 8 7 6 4 3 2 1 0
    list_insert(a, &x[9]);
    list_print(a);              // 9 8 7 6 4 3 2 1 0
    list_insert(&x[6], &x[5]);
    list_print(a);              // 9 8 7 6 5 4 3 2 1 0
    if(n == 4)
        goto END;

    while(!list_is_empty(a))
        list_remove(a->next);
    if(n == 5)
        goto END;

END:
    free(x);
}

void test_alloc(int n)
{
    struct Node a0, b0;
    struct Node * a = &a0;
    struct Node * b = &b0;

    list_init(a);
    list_init(b);

    int i;
    for(i=0; i<10; i++)
        list_push_back(a, i);
    list_print(a);              // 0 1 2 3 4 5 6 7 8 9
    assert(list_is_empty(b));
    if (n == 6)
        goto END;

    for(i=0; i<10; i++)
        list_push_front(b, list_pop_back(a));
    list_print(b);              // 0 1 2 3 4 5 6 7 8 9
    assert(list_is_empty(a));
    if (n == 7)
        goto END;

    for(i=0; i<10; i++) {
        list_push_front(a, i);
        list_pop_front(b);
    }
    list_print(a);              // 9 8 7 6 5 4 3 2 1 0
    assert(list_is_empty(b));
    if (n == 8)
        goto END;

    for(i=0; i<10; i++)
        list_push_back(b, list_pop_front(a));
    list_print(b);              // 9 8 7 6 5 4 3 2 1 0
    assert(list_is_empty(a));
    if (n == 9)
        goto END;

END:
    list_clear(a);
    list_clear(b);
}

int main()
{
    int n = 1;
    test_alloc(n);
    return 0;
}

void list_init(struct Node* list)
{
    list->next = list;
    list->prev = list;
}

void list_insert(struct Node* list, struct Node* t)
{
    struct Node* list_2 = list->next;

    list->next = t;
    list_2->prev = t;
    t->prev = list;
    t->next = list_2;
}

void list_insert_before(struct Node* list, struct Node* t)
{
    struct Node* list_2 = list->prev;

    list->prev = t;
    list_2->next = t;
    t->next = list;
    t->prev = list_2;
}

void list_remove(struct Node* t)
{
    struct Node* list = t->prev;
    struct Node* list_2 = t->next;

    list->next = list_2;
    list_2->prev = list;
}

struct Node* list_push_front(struct Node* list, Data d)
{
    struct Node* list_new = (struct Node*)calloc(1, sizeof(struct Node));
    list_new->data = d;

    list_insert(list, list_new);
    return list_new;
}

struct Node* list_push_back(struct Node* list, Data d)
{
    return list_push_front(list->prev, d);
}

Data list_pop_front(struct Node* list)
{
    return list_delete(list->next);
}

Data list_pop_back(struct Node* list)
{
    return list_delete(list->prev);
}

Data list_delete(struct Node* t)
{
    Data d = t->data;

    list_remove(t);
    free(t);

    return d;
}

void list_clear(struct Node * list)
{
    while(!list_is_empty(list))
        list_pop_front(list);
}

void list_print (struct Node* list)
{
   /* struct Node* list_1 = list;
    for(int i = 0; i != 0 && list != list_1; list = list->next)
    {
        printf("%d ", list->data);
        i++;
    }

    printf("\n");*/
    for(struct Node* p = list->next; p != list; p = p->next)
        printf("%d ", p->data);
}


int list_is_empty (struct Node * list)
{
    return list->next == list;
}
