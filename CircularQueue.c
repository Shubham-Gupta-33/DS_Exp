#include<stdio.h>

int element , data , rear=-1 , front=-1;
int maxsize=8;
int queue[8];


void insert(int element)
{
    if((rear+1)%maxsize==front)
    {
        printf("Queue Is FULL");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=element;
    }
    else
    {
        rear=(rear+1)%maxsize;
        queue[rear]=element;    
    }
}

void delete()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue Is EMPTY");
    }
    else if(front==rear)
    {
        data=queue[front];
        front=rear=-1;
        printf("Deleted element is %d",data);
    }
    else
    {
        data=queue[front];
        front=(front+1)%maxsize;
        printf("Deleted element is %d",data);
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue Is EMPTY");
    }
    else
    {
        int i=front;
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%maxsize;
        }
        printf("%d \n",queue[rear]);
    }
}


int main()
{
    int k;

    do
    {
        printf("\n----Queue Menu---- ");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n Select Queue Operation:");
        scanf("%d", &k);

        switch(k)
        {
            case 1:
            printf("Enter element to insert: ");
            scanf("%d",&element);
            insert(element);
            break;

            case 2:
            delete();
            break;

            case 3:
            display();
            break;

            case 4:
            return 0;
            break;

            default:
            printf("Invalid Input");
            break;
        }
    } while(k != 4);
return 0;
}
