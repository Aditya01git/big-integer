#ifndef biginteger
#define biginterger

struct node
{
    int data;
    struct node*next;
};

void intialize(struct node **head1, struct node **head2, char str1[100], char str2[100]);
void display(struct node *head);
struct node*addition(struct node *head1, struct node*head2);
struct node* subtraction(struct node *head1, struct node *head2);
struct node* multiplication(struct node *head1, struct node *head2);

#endif
