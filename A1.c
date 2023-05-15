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
		char resource1='A';
		for(resourceCount=1;resourceCount<=no_of_resources;resourceCount++)
		 printf("\t%c",resource++);
          for(i=0;i<no_of_processes;i++)
           {
             printf("\nP%d:\t",i);
               for(j=0;j<no_of_resources;j++)
               {
                scanf("%d",&Allocation[i][j]);
                 
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
}
