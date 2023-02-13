typedef int Data;

struct Node {
    Data val;
    struct Node * next;
};

struct Node* list_create();
void list_push(struct Node ** plist, Data x);
Data list_pop(struct Node ** plist);
Data list_get(struct Node * list);
void list_print(struct Node * list);
int list_size(struct Node * list);
void list_clear(struct Node ** plist);

struct Node* list_create()
{
    return NULL;
}

void list_push(struct Node** plist, Data x)
{
    struct Node* list = (struct Node*)calloc(1, sizeof(struct Node));
    list->val = x;
    list->next = *plist;
    *plist = list;
}

Data list_pop(struct Node** plist)
{
    Data value = (*plist)->val;
    struct Node* old_list = *plist;
    *plist = (*plist)->next;
    free(old_list);
    return value;
}

Data list_get(struct Node* list)
{
    return list->val;
}

void list_print(struct Node* list)
{
    for( ; list != NULL; list = list->next)
        printf("%d ", list->val);

    printf("\n");
}

int list_size(struct Node* list)
{
    int i = 0;
    for( ; list != NULL; list = list->next)
        i++;

    return i;
}

void list_clear(struct Node ** plist)
{
    while(*plist != NULL)
    {
        struct Node* new_list = (*plist)->next;
        free(*plist);
        *plist = new_list;
    }
}

int list_is_empty (struct Node * list)
{
    return list == NULL;
}
