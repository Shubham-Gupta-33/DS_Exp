#include<stdio.h>

void main()
{
    int n,i,x,count=0,firstposition=-1,arr[10];


    printf("Enter The Number Of Element (max=10) : ");
    scanf("%d",&n);

    printf("Enter %d elements :\n",n);
    for( i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter Number To Find :");
    scanf("%d",&x);

    for( i=0;i<n;i++)
    {
        if(arr[i] == x)
        {
            count++;
            
            if(firstposition==-1)
            {
                firstposition=i;
            }

        }
 }
    printf("Number Of Occurences Of %d : %d\n",x,count);
    if(firstposition !=-1)
    {
        printf("First Occurence is at index : %d\n",firstposition);
    }
    else
    {
        printf("%d not Found in te array.\n",x);
    }
}