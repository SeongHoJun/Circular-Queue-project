#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;

typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}Queue;

void init_queue(Queue* q)
{
    q->front = q->rear = 0;
}

int is_full(Queue* q)
{
    return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int is_empty(Queue* q)
{
    return (q->front == q->rear);
}

void queue_print(Queue* q)
{
    printf("Queue(front = %d rear = %d): ", q->front, q->rear);
    if (!is_empty(q))
    {
        int i = q->front;
        do
        {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%3d", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

void enqueue(Queue* q, int item)
{
    if (is_full(q))
    {
        fprintf(stderr, "Queue is Full! ");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(Queue* q)
{
    if (is_empty(q))
    {
        fprintf(stderr, "Queue is empty.");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(Queue* q)
{
    if (is_empty(q))
    {
        fprintf(stderr, "Queue is empty.");
    }
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void)
{
    Queue q;
    int element;
    int num;

    init_queue(&q);
    while (1)
    {
        printf("\n===== Menu =====\n");
        printf("1. Input data and Enqueue\n");
        printf("2. Dequeue and Print data\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Select number:");
        scanf_s("%d", &num);

        if (num == 1)
        {
            printf("Input the data: ");
            scanf_s("%d", &element);
            enqueue(&q, element);
            queue_print(&q);
            if (is_full(&q))
                fprintf(stderr, "Queue is Full!\n ");
        }

        if (num == 2)
        {
            printf("Dequeue: ");
            scanf_s("%d", &element);
            while (!is_empty(&q))
            {
                element = dequeue(&q);
                queue_print(&q);
            }
            if (is_empty(&q))
                fprintf(stderr, "Queue is empty.\n ");
        }

        if (num == 3)
            queue_print(&q);
        if (num == 4)
        {
            printf("Exit the program\n");
            return 0;
        }
    }
}