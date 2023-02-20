#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 15
#define POISON 0xDED32DED
//#define MASK (QUEUE_SIZE - 1)

struct queue{
    int* data;
    unsigned int head;
    unsigned int tail;
    bool block_push;
    bool block_pop;
};

void queue_init(struct queue* queue);
void queue_delete(struct queue* queue);
void queue_push(struct queue* queue, int i);
int queue_pop(struct queue* queue);
void queue_check(FILE* file, struct queue* queue, const char* filename, const char* function_name, int line);
int queue_is_empty(struct queue* queue);
void queue_print(struct queue* queue);

int main()
{
    struct queue q1;
    queue_init(&q1);
    struct queue q2;
    queue_init(&q2);

    for(int i = 0; i < 5; i++)
    {
        int buf = 0;
        scanf("%d", &buf);
        queue_push(&q1, buf);
        //queue_print(&q1);
    }

    for(int i = 0; i < 5; i++)
    {
        int buf = 0;
        scanf("%d", &buf);
        queue_push(&q2, buf);
        //queue_print(&q2);
    }

    queue_print(&q1);
    queue_print(&q2);

    for(int i = 0; i < 1000; i++)
    {
        int val1 = queue_pop(&q1);
        int val2 = queue_pop(&q2);
        printf("val1 = %d\tval2 = %d\n", val1, val2);

        if(val1 < val2)
        {
            if(val1 == 0 && val2 == 9)
            {
                queue_push(&q1, val1);
                queue_push(&q1, val2);
            }
            else
            {
                queue_push(&q2, val1);
                queue_push(&q2, val2);
            }
            queue_print(&q1);
            queue_print(&q2);
            printf("\n\n\n");
        }
        else
        {
            if(val1 == 9 && val2 == 0)
            {
                queue_push(&q2, val1);
                queue_push(&q2, val2);
            }
            else
            {
                queue_push(&q1, val1);
                queue_push(&q1, val2);
            }
            queue_print(&q1);
            queue_print(&q2);
            printf("\n\n\n");
        }

        if(queue_is_empty(&q1))
        {
            queue_delete(&q1);
            queue_delete(&q2);
            printf("second %d\n", i+1);
            return 0;
        }

        if(queue_is_empty(&q2))
        {
            queue_delete(&q1);
            queue_delete(&q2);
            printf("first %d\n", i+1);
            return 0;
        }
    }

    queue_delete(&q1);
    queue_delete(&q2);
    printf("botva\n");
    return 0;
}

void queue_init(struct queue* queue)
{
    queue->head = 0;
    queue->tail = 0;
    queue->block_push = false;
    queue->block_pop = true;
    queue->data = (int*)calloc(QUEUE_SIZE, sizeof(int));

    for(int i = 0; i < QUEUE_SIZE; i++)
        queue->data[i] = POISON;
}

void queue_delete(struct queue* queue)
{
    queue->head = POISON;
    queue->tail = POISON;
    free(queue->data);
}

void queue_push(struct queue* queue, int i)
{
        queue->data[queue->tail++] = i;
        if(queue->tail == QUEUE_SIZE)
            queue->tail = 0;
}

int queue_pop(struct queue* queue)
{
        int i = queue->data[queue->head++];
        queue->data[queue->head - 1] = POISON;
        if(queue->head == QUEUE_SIZE)
            queue->head = 0;
    return i;
}

int queue_is_empty(struct queue* queue)
{
    return queue->head == queue->tail;
}

void queue_print(struct queue* queue)
{
    for(int i = 0; i < QUEUE_SIZE; i++)
    {
        if(queue->data[i] != (int)POISON)
            printf("%d ", queue->data[i]);
        else
            printf("-'- ");
    }
    printf("\n");
}
