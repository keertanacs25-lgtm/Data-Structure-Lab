
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertBeginning(struct Node **head, int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(struct Node **head, int value)
{
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertMiddle(struct Node **head, int value, int position) {
    struct Node *newNode, *temp;
    int i;
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1)
    {
        insertBeginning(head, value);
        return;
    }
    temp = *head;
    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void createList(struct Node **head, int n) {
    struct Node *newNode, *temp;
    int i, value;
    for (i = 1; i <= n; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }
        newNode->data = value;
        newNode->next = NULL;
        if (*head == NULL)
        {
            *head = newNode;
        }
        else
        {
            temp = *head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

int main() {
    struct Node *head = NULL;
    int n,choice, value, position;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("Invalid number of nodes!\n");
        return 1;
    }
    createList(&head, n);
    printf("\nOriginal linked list:\n");
    display(head);
    printf("\n1.Insert at Beginning\n2.Insert at Position\n3.Insert at End\n4.Display\n5.Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &value);
                insertBeginning(&head, value);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertMiddle(&head, value, position);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;

            case 4:
                printf("Linked list:");
                display(head);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
