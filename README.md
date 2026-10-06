#include<stdio.h>
#define MAX 4
int queue[MAX];
int front=-1,rear=-1;

void insert(){
  int value;
  if(rear==MAX-1){
     printf("Queue Overflow\n");
     return;
     }
  printf("Enter a value:");
  scanf("%d",&value);
  if(front==-1)
    front=0;
  rear++;
  queue[rear]=value;
  printf("%d inserted into the queue:",value);
}
void delete(){
  if(front==-1){
    printf("Queue is empty\n");
    return;
    }
  printf("%d deleted from queue",queue[front]);
  front++;
}
void display(){
    int i;
   if(front==-1){
     printf("Queue is empty\n");
     return;
     }
   printf("Elements in queue are:");
   for(i=front;i<=rear;i++)
     printf("%d",queue[i]);
   printf("\n");
}
int main(){
  int choice;
  while(1){
     printf("---QUEUE MENU---\n");
     printf("1.Insert\n");
     printf("2.Delete\n");
     printf("3.Display\n");
     printf("4.Exit\n");

     printf("Enter your choice:");
     scanf("%d",&choice);

     switch(choice)
     {
        case 1:
            insert();
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exit\n");
            return 0;

        default:
           printf("Inavalid Choice");
    }
  }
}
