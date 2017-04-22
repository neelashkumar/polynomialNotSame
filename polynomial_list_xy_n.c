#include<stdio.h>
#include<stdlib.h>
int no1;
int no2;
int no3;
struct node
{
    int num;
    int expo_x;
    int expo_y;
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
            printf("\nEnter the co-efficient number and exponent power for x and y\t");
            scanf("%d %d %d",&(temp->num),&(temp->expo_x),&(temp->expo_y));
            temp->next=NULL;
            head1=temp;
            p=head1;
        }
        else
        {
            temp=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter the co-efficient number and exponent power for x and y\t");
            scanf("%d %d %d",&(temp->num),&(temp->expo_x),&(temp->expo_y));
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
            printf("\nEnter the co-efficient number and exponent power for x and y\t");
            scanf("%d %d %d",&(temp->num),&(temp->expo_x),&(temp->expo_y));
            temp->next=NULL;
            head2=temp;
            q=head2;
        }
        else
        {
            temp=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter the co-efficient number and exponent power for x and y\t");
            scanf("%d %d %d",&(temp->num),&(temp->expo_x),&(temp->expo_y));
            q->next=temp;
            temp->next=NULL;
            q=temp;
        }
    }

}
void display()
{
    int ch,i;
    printf("\nDisplay\n1.List 1\n2.List 2\n3.List 3\nEnter your choice");
    scanf("%d",&ch);
    assign();
    if(ch==1)
    {
        i=0;
        p=head1;
        while(p!=NULL)
        {
            printf("\t%dx%dy%d",p->num,p->expo_x,p->expo_y);
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
            printf("\t%dx%dy%d",p->num,p->expo_x,p->expo_y);
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
            printf("\t%dx%dy%d",p->num,p->expo_x,p->expo_y);
            p=p->next;
            i++;
            if(i!=no3)
                printf(" +");
        }
        printf("=0");
    }

}
int count(int ch)
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
    int i=1,a;
    assign();
    while(i<=no3)
    {
        if(head3==NULL)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            if((head1->expo_x==head2->expo_x)&&(head1->expo_y==head2->expo_y))
            {
                temp->num=head1->num+head2->num;
                temp->expo_x=head1->expo_x;
                temp->expo_y=head1->expo_y;
                if(head1->next!=NULL)
                {
                    p=head1->next;
                }
                if(head2->next!=NULL)
                {
                    q=head2->next;
                }
            }
            else if((head1->expo_x>head2->expo_x)&&(head1->expo_y>head2->expo_y))
            {
                temp->num=head1->num;
                temp->expo_x=head1->expo_x;
                temp->expo_y=head1->expo_y;
                if(head1->next!=NULL)
                {
                    p=head1->next;
                    q=head2;
                }
            }
            else
            {
                temp->num=head2->num;
                temp->expo_x=head2->expo_x;
                temp->expo_y=head2->expo_y;
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
            if((p->expo_x==q->expo_x)&&(p->expo_y==q->expo_y))
            {
                temp->num=p->num+q->num;
                temp->expo_x=p->expo_x;
                temp->expo_y=p->expo_y;
                if(p->next!=NULL)
                    p=p->next;
                if(q->next!=NULL)
                    q=q->next;
            }
            else if((p->expo_x>q->expo_x)&&(p->expo_y>q->expo_y)||((p->expo_x<q->expo_x)&&(p->expo_y>q->expo_y))||((p->expo_x>q->expo_x)&&(p->expo_y<q->expo_y)))
            {
                temp->num=q->num;
                temp->expo_x=q->expo_x;
                temp->expo_y=q->expo_y;
                if(no1>no2)
                {
                    temp->num=p->num;
                    temp->expo_x=p->expo_x;
                    temp->expo_y=p->expo_y;
                    if(p->next!=NULL)
                    {
                        p=p->next;
                    }
                }
                else if(q->next!=NULL)
                {
                    q=q->next;
                }
                if(i==no3&&((p->expo_x>q->expo_x)&&(p->expo_y>q->expo_y))&&(q->expo_x==0)&&(q->expo_y==0))
                {
                    temp->num=q->num;
                    temp->expo_x=q->expo_x;
                    temp->expo_y=q->expo_y;
                    if(q->next!=NULL)
                        q=q->next;
                }
            }
            else
            {
                temp->num=p->num;
                temp->expo_x=p->expo_x;
                temp->expo_y=p->expo_y;
                if(p->next!=NULL)
                {
                    p=p->next;
                }
                if(i==no3&&((p->expo_x<q->expo_x)&&(p->expo_y<q->expo_y))&&(p->expo_x==0)&&(p->expo_y==0))
                {
                    temp->num=p->num;
                    temp->expo_x=p->expo_x;
                    temp->expo_y=p->expo_y;
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


