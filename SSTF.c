#include<stdio.h>
#include<stdlib.h>
int main()
{
    int head, RQ[100],n,i,j,count=0,THM=0;
    printf("Enter no of request");
    scanf("%d",&n);
    printf("Enter sequence of request");
    for(i=0;i<n;i++)
    {
        scanf("%d",&RQ[i]);
    }
    printf("Enter head position");
    scanf("%d",&head);

    while(count!=n)
    {
        int min=100,d,index;

        for(i=0;i<n;i++)
        {
            d=abs(RQ[i]-head);
            if(min>d)
            {
                min=d;
                index=i;
            }
        }
        THM =THM+min;
        head=RQ[index];
        RQ[index]=1000;
        count++;
    }
    printf("Total head movement %d",THM);
    return 0;
}