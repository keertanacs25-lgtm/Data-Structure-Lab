#include <stdio.h>
#include <stdlib.h>

#define MAX 3
int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int item;
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter an element: ");
    scanf("%d", &item);

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = item;
    printf("Element inserted\n");
}

void deleteElement() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Element deleted: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue empty\n");
        return;
    }
    printf("Elements in Queue: ");

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n---Queue Menu---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
