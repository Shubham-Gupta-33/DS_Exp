#include<stdio.h>
int maxsize=100;
int top=-1,x,n;
int stack[100];

void push(int x)
{
    if(top==maxsize-1)
    {
        printf("Stack is Full");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}


int pop()
{
    if(top==-1)
    {
        printf("Stack is Empty");
    }
    else
    {
        x=stack[top];
        top--;
        return x;
    }
}


int peek()
{
    if(top==-1)
    {
        printf("Stack Is Empty");
    }
    else
    {
        return stack[top];
    }
}


void display()
{
    if(top==-1)
    {
        printf("stack is Empty");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("| %d |\n",stack[i]);
            printf("|____|\n");
        }
    }

}


int main()
{
int stack[100];
    do
    {
        printf("\n----- STACK MENU -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch(n)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                x = pop();
                if(top != -1)
                    printf("Popped Element = %d\n", x);
                break;

            case 3:
                x = peek();
                if(top != -1)
                    printf("Top Element = %d\n", x);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(n != 5);
    return 0;
}