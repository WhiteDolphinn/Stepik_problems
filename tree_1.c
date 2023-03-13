#include <stdio.h>
#include <stdlib.h>
typedef int Data;

struct Node{
    Data val;
    struct Node * left;
    struct Node * right;
};

struct Node* tree_add(struct Node* tree, Data x);
void tree_print(struct Node* tree);
void tree_destroy(struct Node * tree);
void tree_print_leaves(struct Node* tree);
unsigned int tree_high(struct Node* tree);
char is_balanced(struct Node* tree);
void print_in_high(struct Node* tree, unsigned int high);
void print_in_width(struct Node* tree);

int main()
{
    struct Node* tree = NULL;

   // int data[10000] = {0};
    //int i = 0;

    /*scanf("%d ", data);

    while(data[i] != 0)
    {
        scanf("%d", &data[i]);
        i++;
    }

    for(int j = 0; j < i; j++)
        tree_add(tree, data[i]);*/
    int buf = 0;
    scanf("%d", &buf);

    while(buf != 0)
    {
        tree = tree_add(tree, buf);
        scanf("%d", &buf);
    }

    //int high = 0;
    //scanf("%d", &high);

    //tree_print(tree);
    //tree_print_leaves(tree);

    /*unsigned int high = tree_high(tree);
    printf("%u\n", high);*/

    /*if(is_balanced(tree))
        printf("YES\n");
    else
        printf("NO\n");*/

    //print_in_high(tree, high);
    print_in_width(tree);

    tree_destroy(tree);
}

struct Node* tree_add(struct Node* tree, Data x)
{
    if(tree == NULL)
    {
        struct Node* new_node = (struct Node*)calloc(1, sizeof(struct Node));

        new_node->val = x;
        new_node->right = NULL;
        new_node->left = NULL;
        return new_node;
    }

    if(x > tree->val)
        tree->right = tree_add(tree->right, x);
    if(x < tree->val)
        tree->left = tree_add(tree->left, x);

    return tree;
}

void tree_print(struct Node * tree)
{
    if (tree == NULL)
        return;

    tree_print(tree->left);
    printf("%d ", tree->val);
    tree_print(tree->right);
}

void tree_destroy(struct Node * tree)
{
    if(tree == NULL)
        return;

    tree_destroy(tree->left);
    tree_destroy(tree->right);
    free(tree);
}

void tree_print_leaves(struct Node* tree)
{
    if(tree == NULL)
        return;

    tree_print_leaves(tree->left);

    if(tree->left == NULL && tree->right == NULL)
        printf("%d ", tree->val);

    tree_print_leaves(tree->right);
}

unsigned int tree_high(struct Node* tree)
{
    if (tree == NULL)
        return 0;

    unsigned int high_left = tree_high(tree->left);
    unsigned int high_right = tree_high(tree->right);

    if(high_left >= high_right)
        return high_left + 1;
    else
        return high_right + 1;
}

char is_balanced(struct Node* tree)
{
    if (tree == NULL)
        return 0;

    unsigned int high_left = tree_high(tree->left);
    unsigned int high_right = tree_high(tree->right);

    if(high_left >= high_right && high_left - high_right > 1)
        return 0;

    if(high_right >= high_left && high_right - high_left > 1)
        return 0;

    if(high_left >= high_right)
        return high_left + 1;
    else
        return high_right + 1;
}


void print_in_high(struct Node* tree, unsigned int high)
{
    if(tree == NULL)
        return;

    if(high == 0)
    {
        printf("%d ", tree->val);
        return;
    }

    print_in_high(tree->left, high-1);
    print_in_high(tree->right, high-1);
}

void print_in_width(struct Node* tree)
{
    unsigned int high = tree_high(tree);
    for(unsigned int i = 0; i < high; i++)
        print_in_high(tree, i);
}
