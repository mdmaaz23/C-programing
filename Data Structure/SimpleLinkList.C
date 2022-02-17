#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* link;
};

struct node * Create(struct node* start);
void Display(struct node* start);
struct node * AddToStart(struct node* start,int info);
struct node * AddToEnd(struct node* start,int info);
struct node * AddAtPos(struct node* start,int info,int pos);
struct node * DeleteFromPos(struct node* start,int pos);
void Count(struct node* start);


struct node* Copy(struct node* start)
{
    if (start == NULL) 
    {
        return NULL;
    }
    else 
    {
        struct node* temp= (struct node*)malloc(sizeof(struct node));
        temp->info = start->info;
        temp->link = Copy(start->link);
        return temp;
    }
}

int main()
{
    int choice,item,info;
    struct node* start=NULL;
    struct node* dup =NULL;

    while(1){
        printf("--- Linked List ---\n1.Create linked list\n2.Display\n3.Add element at start\n4.Add element at end\n5.Add at a particular postion\n6.Delete a number from any particular index\n7.Count\n8.Copy\n9.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice){ 
        case 1:
            start=Create(start);
            break;
        case 2:
            Display(start);
            break;
        case 3:
            printf("Enter the number that you want to insert at starting : ");
            scanf("%d",&info);
            start=AddToStart(start,info);
            break;
        case 4:
            printf("Enter the number that you want to insert at end : ");
            scanf("%d",&info);
            start=AddToEnd(start,info);
            break;
        case 5:
            printf("Enter the position where you want to insert a number: ");
            scanf("%d",&item);
            printf("Enter the number that you want to insert : ");
            scanf("%d",&info);
            start=AddAtPos(start,info,item);
            break;
        case 6:
            printf("Enter the index from where you want to delete an element : ");
            scanf("%d",&item);
            start=DeleteFromPos(start,item);
            break;
        case 7:
            Count(start);
            break;    
        case 8:
            dup= Copy(start);
            printf("Copied list: ");
            Display(dup);
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("You have enter wrong choice try again \n"); 
            break;
        }
    }

    return 0;
}

struct node * Create(struct node* start)
{
    int n,info;
    start=NULL;
    printf("Enter the no. of elements you want to put in List : ");
    scanf("%d",&n);
    if(n==0)
    {
        printf("Created empty list\n\n");
        return start;
    }
    for(int i=0;i<n;i++)
    {
        printf("Enter the %d element : ",i+1);
        scanf("%d",&info);
        start=AddToEnd(start,info);
    }
    return start;

}

void Display(struct node* start)
{
    struct node *p=start;
    if(start==NULL){
        printf("List is Empty\n\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->link;
    }
    printf("\n\n");

}

//start is the first node of list
struct node * AddToStart(struct node* start,int info)
{   
    //thse 3 steps will create temp that will point to the node 
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->info=info;
    temp->link=start;     //update the link part of the node

    start=temp;           //already start node there will now point to the new temp node 
    return start;
}

struct node * AddToEnd(struct node* start,int info)
{   
    // assighing the address return by malloc to temp
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->info=info;         //update the info by some value 
    temp->link=NULL;         //update the link by null
    struct node *p=start;        //ptr p will point to start(start ptr)
    if(start ==NULL)
    {
        start=temp;
        return start;
    }
    while(p->link!=NULL)   //point to the 1st node of list which will not be NULL and go inside the loop until it finds null
    {
        p=p->link;
    }
    p->link=temp;          //update the link part i.e by the address of temp
    return start;

}

struct node * AddAtPos(struct node* start,int info,int pos)
{
    int i=1;
    struct node* p=start;
    if (pos==1)                            //check if list is empty and we have to add first 
    {
       start= AddToStart(start,info);
       return start;
    }
    for(p=start;p!=NULL && i<pos-1;i++)           //traverse the list and find the position where it is null and update the link part
    {
        p=p->link;
    }
    if(p==NULL)          //check if we are add at a given position i.e if we have 3 node & we are adding at 5 posiion then this loop will tell us we are putting wrong
    {
        printf("List has less than %d elements\n",pos);
    }
    else
    {
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->info=info;
        temp->link=p->link;
        p->link=temp;
    }
    printf("\n");
    return start;

}

struct node * DeleteFromPos(struct node* start,int pos)
{
        struct node *p=start;
        int i=1;
        if(start==NULL)
        {
            printf("List is empty\n");
            return start;
        }
       else if(pos==1)
       {
            struct node * del=start;
            start=del->link;
            free(del);
            return start;
        }
        for(;i<pos-1 && p!=NULL;i++)
        {
            p=p->link;
        }
        if(p==NULL)
        {
            printf("List has less than %d elements\n",pos);
        }
        else
        {
            struct node* del=p->link;
            p->link=del->link;
            free(del);
        }
        return start;

}
void Count(struct node* start)
{
    struct node * p=start;
    int i=0;
    while(p!=NULL)
    {
        p=p->link;
        i++;
    }
    printf("No. of elemnts in List = %d\n\n",i);

}


