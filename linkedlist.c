#include<stdio.h>
#include<stdlib.h>
void Createlist(int n);
void insertAtFirst(int data);
void Display();
void insertAtLast();
void insertAtAnyLoc();
void deletionAtFirst();
void deletionAtLast();
void deletionAtAnyLoc();
typedef struct node
{
    int info;
    struct node*next;
}node;
node*start=NULL;

int main()
{int n,data,item;
    printf("enter the no. nodes\n");
    scanf("%d",&n);
    Createlist(n);
    printf("data in the list :\n");
    Display();
    printf("enter the data to be inserted at first\n");
    scanf("%d",&data);
    insertAtFirst(data);
    printf("enter the data to be inserted at last\n");
    scanf("%d",&item);
    insertAtLast(item);
    printf("enter the item to be inserted at any location\n");
    scanf("%d",&item);
    insertAtAnyLoc(item);
    Display();
    deletionAtFirst();
    deletionAtLast();
    Display();
    deletionAtAnyLoc();

    printf("New Data in the list\n");
    Display(); 
}
void Createlist(int n)
{int data,i;
      struct node *Newnode,*temp;
    start=(node*)malloc(sizeof(struct node));
    if(start==NULL)
    {
        printf(" unable to allocate memory\n");
    }
    else
    {
        printf("enter the data\n");
        scanf("%d",&data);
        start->info=data;
        start->next=NULL;
        temp=start;
    }
    for(i=1;i<n;i++)
    {
       Newnode=(struct node*)malloc(sizeof(struct node));
       if(Newnode==NULL)
       {
        printf("unable to allocate memory\n");
       }
       else{
        printf("enter the data\n");
        scanf("%d",&data);
        Newnode->info=data;
        Newnode->next=NULL;
        temp->next=Newnode;
        temp=temp->next;
       }
    }    
}
void insertAtFirst(int data)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("unable to allocate memory\n");
    
    }
    else
    {
        ptr->info=data;
        ptr->next=start;
        start=ptr;

    }
}
void Display()
{
    struct node*temp;
    if(start==NULL)
    {
        printf("list is empty\n");

    }
    else{
          temp=start;
          while(temp!=NULL)
          {
            printf("%d\n",temp->info);
            temp=temp->next;
          }
    }
}
void insertAtLast(int item)
{
  struct node *ptr,*temp;
  ptr=(node*)malloc(sizeof(node));
  if(ptr==NULL)
  {
    printf("unable to alloctae memory");
  }
  else{
    ptr->info=item;
    temp=start;
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
      temp->next=ptr;
      ptr->next=NULL;

  }
}
void insertAtAnyLoc(int item)
{
    int loc;
  struct node *ptr,*temp;
   ptr=(node*)malloc(sizeof(node));
   if(ptr==NULL)
   {
    printf("unable to alocate memory\n");
   }
   else
   {
    temp=start;
    ptr->info=item;
    printf("enter the index at which u want to insert\n");
    scanf("%d",&loc);
    int i=1;
    while(i<loc)
    {
        temp=temp->next;
        i++;
        }
        ptr->next=temp->next;
        temp->next=ptr;
   }

}   
void deletionAtFirst() 
{
  struct node *ptr;
  ptr=(node*)malloc(sizeof(node));
  if(ptr==NULL)
  {
    printf("list is empty\n");
  }
  else{
    ptr=start;
    start=start->next;
    free(ptr);
  }
}
void deletionAtLast()
{
  struct node *ptr,*temp;
  ptr=(node*)malloc(sizeof(node));
  if(ptr==NULL)
  {
    printf("list is empty\n");
  }
  else{
 temp=start;
 
 while(temp->next!=NULL)
 {
   ptr=temp;
   temp=temp->next;
 }  
 ptr->next=NULL;
  }
}
void deletionAtAnyLoc()
{
   struct node *ptr,*temp;
   ptr=(node*)malloc(sizeof(node));
   if(ptr==NULL)
   {
    printf("unable to allocate memory\n");
   }
   else{
    temp=start;
    int loc,i=0;
    printf("enter the index to which u wanna delete\n");
    scanf("%d",&loc);
    while(i<loc-1)
    {
      ptr=temp;
      temp=temp->next;
      i++;
    }
   ptr->next=temp->next;
   temp->next=ptr;
   }
}