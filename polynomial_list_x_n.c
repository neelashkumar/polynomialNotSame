#include<stdio.h>
#include<stdlib.h>
int no1;
int no2;
int no3;
struct node
{
    int num;
    int expo;
    struct node*next;
}*head1=NULL,*head2=NULL,*head3=NULL,*p,*q,*r,*temp;
void insert()
{
    int ch;
    printf("\n1.List 1\n2.List 2\nEnter your choice\t");
    scanf("%d",&ch);
    if(ch==1)
    {
        if(head1==NULL)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter the co-efficient number and exponent power\t");
            scanf("%d %d",&(temp->num),&(temp->expo));
            temp->next=NULL;
            head1=temp;
            p=head1;
        }
        else
        {
            temp=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter the co-efficient number and exponent power\t");
            scanf("%d %d",&(temp->num),&(temp->expo));
            p->next=temp;
            temp->next=NULL;
            p=temp;
        }
    }
    else if(ch==2)
    {
        if(head2==NULL)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter the co-efficient number and exponent power\t");
            scanf("%d %d",&(temp->num),&(temp->expo));
            temp->next=NULL;
            head2=temp;
            q=head2;
        }
        else
        {
            temp=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter the co-efficient number and exponent power\t");
            scanf("%d %d",&(temp->num),&(temp->expo));
            q->next=temp;
            temp->next=NULL;
            q=temp;
        }
    }

}
void display()
{
    int ch,i;
    assign();
    printf("\nDisplay\n1.List 1\n2.List 2\n3.List 3\nEnter your choice");
    scanf("%d",&ch);
    if(ch==1)
    {
        i=0;
        p=head1;
        while(p!=NULL)
        {
            printf("\t%dx%d",p->num,p->expo);
            p=p->next;
            i++;
            if(i!=no1)
                printf(" +");
        }
        printf("=0");
    }
    else if(ch==2)
    {
        i=0;
        p=head2;
        while(p!=NULL)
        {
            printf("\t%dx%d",p->num,p->expo);
            p=p->next;
            i++;
            if(i!=no2)
                printf(" +");
        }
        printf("=0");

    }
    else if(ch==3)
     {
         i=0;
        p=head3;
        while(p!=NULL)
        {
            printf("\t%dx%d",p->num,p->expo);
            p=p->next;
            i++;
            if(i!=no3)
                printf(" +");
        }
        printf("=0");
    }

}
int count(ch)
{
    if(ch==1)
        p=head1;
    else if(ch==2)
        p=head2;
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}
void assign()
{
    no1=count(1);
    no2=count(2);
    if(no1==no2)
        no3=no1;
    else if(no1>no2)
        no3=no1;
    else
        no3=no2;
}
void addition()
{
    int i=1;
    assign();
    while(i<=no3)
    {
        if(head3==NULL)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            if(head1->expo==head2->expo)
            {
                temp->num=head1->num+head2->num;
                temp->expo=head1->expo;
                if(head1->next!=NULL)
                {
                    p=head1->next;
                }
                if(head2->next!=NULL)
                {
                    q=head2->next;
                }
            }
            else if(head1->expo>head2->expo)
            {
                temp->num=head1->num;
                temp->expo=head1->expo;
                if(head1->next!=NULL)
                {
                    p=head1->next;
                    q=head2;
                }
            }
            else
            {
                temp->num=head2->num;
                temp->expo=head2->expo;
                if(head2->next!=NULL)
                {
                    q=head2->next;
                    p=head1;
                }
            }
            head3=temp;
            temp->next=NULL;
            r=head3;
        }
        else
        {
            temp=(struct node*)malloc(sizeof(struct node));
            if(p->expo==q->expo)
            {
                temp->num=p->num+q->num;
                temp->expo=p->expo;
                if(p->next!=NULL)
                    p=p->next;
                if(q->next!=NULL)
                    q=q->next;
            }
            else if(p->expo>q->expo)
            {

                    temp->num=p->num;
                    temp->expo=p->expo;
                    if(p->next!=NULL)
                        p=p->next;
                    if(i==no3&&(p->expo>q->expo)&&(q->expo==0))
                    {
                        temp->num=q->num;
                        temp->expo=q->expo;
                        if(q->next!=NULL)
                            q=q->next;
                    }

            }
            else
            {
                    temp->num=q->num;
                    temp->expo=q->expo;
                    if(q->next!=NULL)
                        q=q->next;
                    if(i==no3&&(p->expo<q->expo)&&(p->expo==0))
                    {
                        temp->num=p->num;
                        temp->expo=p->expo;
                        if(p->next!=NULL)
                            p=p->next;
                    }

            }
            r->next=temp;
            temp->next=NULL;
            r=temp;
        }
        i++;
    }
}
int main()
{
    int ch,op;
    do
    {
        printf("\n1.Insertion\n2.Addition\n3.Display\t");
        scanf("%d",&op);
        switch(op)
        {
            case 1:insert();break;
            case 2:addition();break;
            case 3:display();break;
        }
        printf("\nEnter 1 to continue\t");
        scanf("%d",&ch);
    }while(ch==1);
    return 0;
}

