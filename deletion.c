#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
   struct Node *next;

};
struct Node *head=NULL;
void createNode(int value)
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    struct Node *temp=head;

    newNode->data=value;
    newNode->next=NULL;

    if(head==NULL)
    {
        head=newNode;
        return;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
}
void deleteFirst()
{
    struct Node *temp;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp=head;
    head=head->next;
    free(temp);

    printf("%d is deleted\n",temp->data);
}
void deleteElement(int value)
{
    struct Node *temp=head,*prev=NULL;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(head->data==value){
        head=head->next;
        free(temp);
        printf("%d deleted",temp->data);
        return;
    }
    while(temp!=NULL&&temp->data!=value){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Element not found\n");
        return;
    }
    prev->next=temp->next;
    free(temp);
    printf("%d is deleted\n",temp->data);

}
void deleteLast()
{
    struct Node *temp=head,*prev=NULL;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("Last node is deleted");
        return;
    }
    while(temp!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    printf("Last node is deleted");


}
void display()
{
    struct Node *temp=head;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Linked List:");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice,value,pos,n;

    printf("Enter number of nodes to create:");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        createNode(value);
    }
    do
    {
        printf("1.Delete at First\n");
        printf("2.Delete specified element\n");
        printf("3.Delete at Last\n");
        printf("4.Display\n");

        printf("Enter choice:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                deleteFirst();
                break;
            case 2:
                printf("Enter element to delete:");
                scanf("%d",&value);
                deleteElement(value);
                break;

            case 3:
                deleteLast();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exit\n");
                break;

        }
    }while(choice!=5);
    return 0;
}





