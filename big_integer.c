#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

void insertAtend(struct node **head, int value)
{
    // node is created
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    // now if link list is empty Here (*head)means value at (**head),which pointing to null
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    // when node created
    struct node *itr = *head;
    itr = *head;
    while (itr->next != NULL)
    {
        itr = itr->next;
    }
    itr->next = temp;
}

void insertAtbegin(struct node **head, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = *head;
    if (*head == NULL)
    {
        *head = temp;
        (*head)->next = NULL;
        return;
    }
    *head = temp;
}

void intailize(struct node **head1, struct node **head2, char str1[100], char str2[100])
{
    int x = 0, y = 0;
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    while (l1 != 0)
    {
        insertAtbegin(head1, str1[x] - '0');
        x++;
        l1--;
    }
    while (l2 != 0)
    {
        insertAtbegin(head2, str2[y] - '0');
        y++;
        l2--;
    }
}

void display(struct node *head)
{
    struct node *itr = head;
    while (itr != NULL)
    {
        printf("%d", itr->data);
        itr = itr->next;
    }
    printf("\n");
}

struct node *addition(struct node *head1, struct node *head2)
{
    struct node *head=NULL;
    int carry = 0;
    while (head1 != NULL || head2 != NULL || carry != 0)
    {
        int result;

        int x = (head1 != NULL) ? head1->data : 0;
        int y = (head2 != NULL) ? head2->data : 0;

        result = x + y + carry;

        carry = result / 10;
        result = result % 10;
        insertAtbegin(&head, result);

        if (head1 != NULL)
        {
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            head2 = head2->next;
        }
    }
    return head;
}

struct node* subtraction(struct node *head1, struct node *head2)
{
    int l1 = 0, l2 = 0;
    int negative = 0, borrow = 0, result;
    struct node *temp1 = head1, *temp2 = head2, *t,*head;
    while (temp1 != NULL)
    {
        l1 = l1 + 1;
        temp1 = temp1->next;
        // printf("%d",l1);
    }
    while (temp2 != NULL)
    {
        l2 = l2 + 1;
        temp2 = temp2->next;
        // printf("%d",l2);
    }
    temp1 = head1;
    temp2 = head2;

    if (l1 < l2)
    {
        t = head1;
        head1 = head2;
        head2 = t;
        negative++;
    }
    else if (l1 == l2)
    {
        while (temp1->next != NULL || temp2->next != NULL)
        {

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if (temp1->data < temp2->data)
        {
            t = head1;
            head1 = head2;
            head2 = t;
            negative++;
        }
        else
        {
            negative = 0;
        }
    }
    else
    {
        negative = 0;
    }
    while (head1 != NULL || head2 != NULL)
    {
        int x = (head1 != NULL) ? head1->data : 0;
        int y = (head2 != NULL) ? head2->data : 0;
        x = x - borrow;
        int result = x - y;
        if (result < 0)
        {
            result = result + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        insertAtbegin(&head, result);
        if (head1 != NULL)
        {
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            head2 = head2->next;
        }
    }

    while ((head)->data == 0)
    {
        head = (head)->next;
    }
    if (negative > 0)
    {
        (head)->data = (head)->data * -1;
    }
   
    free(t);
    return head;
}

struct node* multiplication(struct node *head1, struct node *head2)
{
    int carry = 0, l1 = 0, l2 = 0,numzero=0,product=0;
    struct node *temp1 = head1, *temp2 = head2, *t,*result=NULL,*tresult=NULL,*ttemp=NULL;
    while (temp1 != NULL)
    {
        l1 = l1 + 1;
        temp1 = temp1->next;
        // printf("%d",l1);
    }
    while (temp2 != NULL)
    {
        l2 = l2 + 1;
        temp2 = temp2->next;
        // printf("%d",l2);
    }
    if (l1 < l2)
    {
        t = head1;
        head1 = head2;
        head2 = t;
    }
    t = NULL;
    struct node *thead1=head1,*thead2=head2;
    while (head2 != NULL)
    {
        t=NULL;
        for(int i=0;i<numzero;i++)
        {
            insertAtbegin(&t,0);
        }
        while (thead1 != NULL)
        {
            int x = (thead1 != NULL) ? thead1->data : 0;
            int y = (head2 != NULL) ? head2->data : 0;

            int multiply = x * y+carry;
            carry=multiply/10;
            multiply=multiply%10;
            
            insertAtbegin(&t,multiply);
            thead1 = thead1->next;

        }
            if(carry!=0)
            {
                insertAtbegin(&t,carry);
            }
        thead1=head1;
        
         ttemp=t;
        t=NULL;
        while(ttemp) 
        {
            insertAtbegin(&t,ttemp->data);
            ttemp=ttemp->next;
        }

        ttemp=NULL;
        //display(t);

        result=addition(t,result);

        tresult=result;
        result=NULL;
        while(tresult)
        {
            insertAtbegin(&result,tresult->data);
            tresult=tresult->next;
        }
        tresult=NULL;


        carry=0;
        //display(result);
        numzero++;
        head2 = head2->next;
        
    }
    tresult=result;
    result=NULL;
    while(tresult)
    {
        insertAtbegin(&result,tresult->data);
        tresult=tresult->next;
    }
    tresult=NULL;

    while(result->data==0)
    {
        result=result->next;
    }
    
    return result;
}
