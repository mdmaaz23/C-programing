//Circular Linked List
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

//Insertion at beginning
struct node *ciraddbeg(struct node *head,int num)
{
    printf("\nEnter the number to be inserted->");
    scanf("%d",&num);
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)        //
    {
        temp->data=num;
        head=temp;
        temp->link=head;
        return head;
    }
    else
    {
        temp->data=num;
        temp->link=head->link;
        head->link=temp;
        return head;
    }
}
//Function for insertion at the end
struct node *ciraddend(struct node *head,int num)
{
    printf("\nEnter the number to be inserted->");
    scanf("%d",&num);
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->link=head->link;              //link of new node temp will go to head
    head->link=temp;                    // 
    head=temp;
    return head;
}
//Function to delete a number
struct node *cirdel(struct node *head,int num)
{
    printf("\nEnter the number to be deleted->");
    scanf("%d",&num);
    struct node *p,*temp;
    if(head==NULL)
    {
        printf("\nList is empty");
        return 0;
    }
    p=head;
    while(p->link->data!=num)                  //traverse the list until it finds the no 
        p=p->link;
    temp=p->link;
    p->link=temp->link;
    if(temp==head)
    {
        head=p;
    }
    free(temp);
    return head;
}

//Functions..
void cirdisplay(struct node *head) //Display the list........
{
    struct node *p;
    if(head==NULL)
    {
        printf("\nList is empty");
        return;
    }
        p=head->link;                     
    do
        {
            printf("%d->",p->data);
            p=p->link;
        }
        while(p!=head->link);
        printf("\n");
}

void main()
{
    struct node *head=NULL;
    int choice,num,num2;
    while(1)
    {
        printf("\n**********Circular List*********");
        printf("\n1.Display");
        printf("\n2.Add node to empty list/add at beginning");
        printf("\n3.Add at end");
        printf("\n4.Delete from list");
        printf("\n5.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                cirdisplay(head);
                break;
            }
        case 2:
            {
                head=ciraddbeg(head,num);
                break;
            }
        case 3:
            {
                head=ciraddend(head,num);
                break;
            }
        case 4:
            {
                head=cirdel(head,num);
                break;
            }
        case 5:
            {
                exit(1);
            }
        default :
            printf("\nInvalid Choice");
        }
    }
}