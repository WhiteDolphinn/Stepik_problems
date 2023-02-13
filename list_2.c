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

void list_init(struct Node* list)
{
    list = NULL;
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
    struct Node* list_new = (struct Node*)calloc(1, sizeof(struct Node));
    list_new->data = d;

    list_insert_before(list, list_new);
    return list_new;
}

Data list_pop_front(struct Node* list)
{
    struct Node* list_2 = list->next;
    Data d = list_2->data;

    list_remove(list_2);
    free(list_2);

    return d;
}

Data list_pop_back(struct Node* list)
{
    struct Node* list_2 = list->prev;
    Data d = list_2->data;

    list_remove(list_2);
    free(list_2);

    return d;
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
    while(list != NULL)
    {
        struct Node* old_list = list;
        list = list->next;
        free(old_list);
    }
}

void list_print (struct Node* list)
{
    struct Node* list_1 = list;
    for(int i = 0; i != 0 && list != list_1; list = list->next)
    {
        printf("%d ", list->data);
        i++;
    }

    printf("\n");
}


int list_is_empty (struct Node * list)
{
    return list == NULL;
}
