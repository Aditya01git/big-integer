#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bigInteger.h"


int main()
{
    int option;
    struct node *head = NULL, *head1 = NULL, *head2 = NULL;
    struct node *thead = NULL;
    char str1[100];
    printf("Enter the number in string1=");
    scanf(" %s", str1);
    char str2[100];
    printf("Enter the number in string2=");
    scanf(" %s", str2);
    intailize(&head1, &head2, str1, str2);
    // display(head1);
    // display(head2);

    printf("     /**********ENTER THE OPERATION**********/   \n");
    printf("\n 1 .Perform Addition");
    printf("\n 2 .Perform Subtraction");
    printf("\n 3 .Perform Multiplication");
    printf("\n 4 .Perform Division");

    printf("\n\nEnter the option  ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        head = addition(head1, head2);
        display(head);
        break;

    case 2:
        head = subtraction(head1, head2);
        display(head);
        break;

    case 3:
        head=multiplication(head1, head2);
        display(head);
        break;

    default:
        printf("invalid option");
    }

    return 0;
}