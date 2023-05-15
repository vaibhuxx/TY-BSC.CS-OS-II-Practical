#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_PROCESSES 50
int Allocation[100][10],Max[100][10],Need[100][10],Available[10],Total[10]={0,0,0};
int no_of_resources,no_of_processes;
static int finish[MAX_PROCESSES];
int finishAll()
{
   int i;
       for(i=0;i<no_of_processes;i++)
         if(finish[i]==0)
              return 0;
         return 1;
}
int safe()
{
   int i,j,flag=1;
    int tAllocation[100][10],tNeed[100][10],tAval[10];
     for (i=0;i< no_of_resources;i++)
         tAval[i]=Available[i];
     for(i=0;i<no_of_processes;i++)
{
        finish[i]=0;
            for(j=0;j<no_of_processes;j++)
           {
            tAllocation[i][j]=Allocation[i][j];
            tNeed[i][j]=Need[i][j];
           }
}
printf("\n\nSafe Sequence :");
while(!finishAll())
{
   flag=1;
    for(i=0;i<no_of_processes;i++)
       {
       if(finish[i]==1)
             continue;
     for(j=0;j<no_of_resources;j++)
      if(tNeed[i][j]>tAval[j])
      break;
     if (j==no_of_resources)
      {
        finish[i]=1;
      printf("P%d",i);
      flag=0;
              for(j=0;j<no_of_resources;j++)
            {
                 tAval[j]-=tNeed[i][j];
                 tAllocation[i][j]+=tNeed[i][j];
                 tNeed[i][j]=0;
             }
            for(j=0;j<no_of_resources;j++)
             {
               tAval[j]+=tAllocation[i][j];
               tAllocation[i][j]=0;
             }
       }
}
if(flag==1)return 0;
}
return 1;
}
void request()
{
  int i,j,p,Req[10];
     printf("\n\nRequest from which process ?");
     scanf("%d",&i);
      if(i>no_of_processes || i<0)
          {
            printf("\nError:Invalid Process ID,Process %d does not exist.",i);
            return;
          }
        printf("\nEnter Request :");
         for(j=0;j<no_of_resources;j++)
            scanf("%d",&Req[j]);
       for(j=0;j<no_of_resources;j++)
        if(Req[j]>Need[i][j])
         break;
   if(j<no_of_resources) printf("\nError : Invalid Request");
   else
 {
    printf("\nRequest is Valid ");
   for(j=0;j<no_of_resources;j++)
     if (Req[j]>Available[j])
     break;
          if(j<no_of_resources)
         printf("\nWAIT: Not Enough resources available with system");
          else
          {
       printf("\nRequired resources are  available.");
         for(j=0;j<no_of_resources;j++)
        {
           Available[j]-=Req[j];
           Allocation[i][j]+=Req[j];
           Need[i][j]-=Req[j];
        }
       if (safe())
        printf("\nSystem will remain in safe state.\nRequest granted");
       else
         {
printf("\nSystem does not remain in safe state,");
printf("\nRequest NOT granted.");
   for(j=0;j<no_of_resources;j++)
 {
     Available[j]+=Req[j];
     Allocation[i][j]-=Req[j];
     Need[i][j]+=Req[j];

}
}
}
}
}
int FindNeed()
{
  int i,j,resourceCount;
  char resource='A';
      printf("\nNeed Table\n-----------------------");
      printf("\nProcess");
     for(resourceCount=1;resourceCount<=no_of_resources;resourceCount++)
            printf("\t%c",resource++);
        for(i=0;i<no_of_processes;i++)
          {
              printf("\n\nP%d:   \t",i);
               for(j=0;j<no_of_resources;j++)
                   {
                     Need[i][j]=Max[i][j]-Allocation[i][j];
                     printf("%d\t",Need[i][j]);
                   }
          } 
}
int AcceptAllocationTable()
{
   int i,j,resourceCount;
  char resource='A';
     printf("\nEnter instances of Resources ALlocation to each process:");
    printf("\n\nAllocation\n------------------");
    printf("\nProcess");
      for(resourceCount=1;resourceCount<=no_of_resources;resourceCount++)
        printf("\t%c",resource++);
         for(i=0;i<no_of_processes;i++)
         {
              printf("\nP%d:\t",i);
               for(j=0;j<no_of_resources;j++)
              {
                scanf("%d",&Allocation[i][j]);
                Total[j]+=Allocation[i][j];
              }
          }
}
int AcceptMaxTable()
{
  int i,j,resourceCount;
 char resource='A';
            printf("\n\nEnter max resource requirements for each process:");
            printf("\n\nMAX\n---------------");
            printf("\nProcess");
       for(resourceCount=1;resourceCount<=no_of_resources;resourceCount++)
        printf("\t%c",resource++);
         for(i=0;i<no_of_processes;i++)
        {
           printf("\nP%d:\t",i);
             for(j=0;j<no_of_resources;j++)
             {
              scanf("%d",&Max[i][j]);
             }
        }
}
int main()
{
    int i,j,choice=1,resourceCount;
  char resource='A';
      printf("\nhow many types of Resources");
    scanf("%d",&no_of_resources);
      printf("\nhow many types of processes?");
      scanf("%d",&no_of_processes);
    
      AcceptAllocationTable();
    printf("\nEnter Available resources with system:");
        printf("\n\nAVAILABLE\n--------------");
        printf("ResType");
      for(resourceCount=1;resourceCount<=no_of_resources;resourceCount++)
                   printf("\t%c",resource++);
                printf("\n\t");
                   for(j=0;j<no_of_resources;j++)
                     {
                  scanf("%d",&Available[j]);
                  Total[j]+=Available[j];
                     }
              resource='A';
               printf("\nTotal system Resource are:");
               printf("\n\nTotal\n---------------\n");
               printf("\nTotal" );
              for(resourceCount=1;resourceCount<=no_of_resources;resourceCount++)
               printf("\t%c",resource++);
               printf("\n");
                 for(j=0;j<no_of_resources;j++)
                printf("\t%d",Total[j]);
              AcceptMaxTable();
        FindNeed();
         if(safe())
               {
                  printf("\n\nstatus: System is in Safe state");
                 do
                 {
                   request();
                   printf("\n\nAny More request?(yes=1/no=0):");
                   scanf("%d",&choice);
                  }while(choice == 1);
              }
          else
           printf("\nStatus:System is Not in safe state");
}

