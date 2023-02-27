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

    //tree_print(tree);
    //tree_print_leaves(tree);

    unsigned int high = 1;
    tree_high(tree, &high);
    printf("%u ", high);

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
    static unsigned int high = 1;
    static unsigned int max_high = 1;
    if(tree->left == NULL && tree->right == NULL)
        return high;



}
