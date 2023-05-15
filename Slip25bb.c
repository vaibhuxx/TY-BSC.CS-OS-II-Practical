
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200

typedef struct dir
{
 char fname[20];
 int start;
 struct dir *next;
}NODE;

NODE *first,*last;

int n,fb,bit[MAX];

void init()
{
 int i;

 printf("Enter total no.of disk blocks:");
 scanf("%d",&n);

 fb = n;

 for(i=0;i<10;i++)
 {
  int k = rand()%n;
  if(bit[k]!=-2)
  {
   bit[k]=-2;
   fb--;
  }
 }
}

void show_bitvector()
{
 int i;
 for(i=0;i<n;i++)
  printf("%d ",bit[i]);
 printf("\n");
}

void show_dir()
{
 NODE *p;
 int i;

 printf("File\tChain\n");
 
 p = first;
 while(p!=NULL)
 {
  printf("%s\t",p->fname);
  i = p->start;
  while(i!=-1)
  {
   printf("%d->",i);
   i=bit[i];
  }
  printf("NULL\n");
 
  p=p->next;
 }
}

void create()
{
 NODE *p;
 char fname[20];
 int i,j,nob;

 printf("Enter file name:");
 scanf("%s",fname);

 printf("Enter no.of blocks:");
 scanf("%d",&nob);

 if(nob>fb)
 {
  printf("Failed to create file %s\n",fname);
  return;
 }

 for(i=0;i<n;i++)
 {
  if(bit[i]==0) break;
 }

 p = (NODE*)malloc(sizeof(NODE));
 strcpy(p->fname,fname);
 p->start=i;
 p->next=NULL;

 if(first==NULL)
  first=p;
 else
  last->next=p;

 last=p;

 fb-=nob;

 j=i+1;
 nob--;

 while(nob>0)
 {
  if(bit[j]==0)
  {
   bit[i]=j;
   i=j;
   nob--;
  }
  j++;
 }

 bit[i]=-1;
 printf("File %s created successully.\n",fname);
}

void delete()
{
 char fname[20];
 NODE *p,*q;
 int nob=0,i,j;

 printf("Enter file name to be deleted:");
 scanf("%s",fname);

 p = q = first;
 while(p!=NULL)
 {
  if(strcmp(p->fname,fname)==0)
   break;

  q=p;
  p=p->next;
 }

 if(p==NULL)
 {
  printf("File %s not found.\n",fname);
  return;
 }

 i = p->start;
 while(i!=-1)
 {
  nob++;
  j = i;
  i = bit[i];
  bit[j] = 0;
 }

 fb+=nob;
 
 if(p==first)
  first=first->next;
 else if(p==last)
 {
  last=q;
  last->next=NULL;
 }
 else
  q->next = p->next;

 free(p);
 
 printf("File %s deleted successfully.\n",fname);
}
void recursivePart(int pages[]){
    int st, len, k, c, j;
    printf("Enter the index of the starting block and its length: ");
    scanf("%d%d", &st, &len);
    k = len;
    if (pages[st] == 0){
        for (j = st; j < (st + k); j++){
            if (pages[j] == 0){
                pages[j] = 1;
                printf("%d------>%d\n", j, pages[j]);
            }
            else {
                printf("The block %d is already allocated \n", j);
                k++;
            }
        }
    }
    else
        printf("The block %d is already allocated \n", st);
    printf("Do you want to enter more files? \n");
    printf("Enter 1 for Yes, Enter 0 for No: ");
    scanf("%d", &c);
    if (c==1)
        recursivePart(pages);

}


int main()
{
 int ch;



     int pages[50], p, a;
    for (int i = 0; i < 50; i++)
        pages[i] = 0;
    printf("Enter the number of blocks already allocated: ");
    scanf("%d", &p);
    printf("Enter the blocks already allocated: ");
    for (int i = 0; i < p; i++){
        scanf("%d", &a);
        pages[a] = 1;
    }
    recursivePart(pages);
 init();

 while(1)
 {
  printf("1.Show bit vector\n");
  printf("2.Create new file\n");
  printf("3.Show directory\n");
  printf("4.Delete file\n");
  printf("5.Exit\n");
  printf("Enter your choice (1-5):");
  scanf("%d",&ch);

  switch(ch)
  {
  case 1:
   show_bitvector();
   break;
  case 2:
   create();
   break;
  case 3:
   show_dir();
   break;
  case 4:
   delete();
   break;
  case 5:
   exit(0);
  }
 }

 return 0;
}





