#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* we use a doubly linked list structure for purchase history */
typedef struct purchase 
{
    char date[25];
    char name[50];
    int id;
    float amount;
    struct purchase* next;
    struct purchase* prev;
} PUR;

typedef struct counter
{
    char name[50];
    int count;
} COUNTER;

PUR* createNode() 
{
    PUR* temp = (PUR*)malloc(sizeof(PUR));
    if (temp == NULL) 
    {   
        printf("Allocation Failure\n");
        exit(1);
    }
    printf("Enter the date: ");
    scanf("%s", temp->date);
    printf("Enter the name: ");
    scanf("%s", temp->name);
    printf("Enter the amount: ");
    scanf("%f", &(temp->amount));
    temp->id = rand();
    temp->next = temp->prev = NULL;
    return temp;
}

PUR* addPurchase(PUR* head) 
{
    PUR* newNode = createNode();
    if (head == NULL) 
    {
        newNode->next = newNode->prev = newNode;
        return newNode;
    }
    PUR* tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    return head;
}

void display(PUR* head)
{
    if (head == NULL) 
    {
        printf("No purchases to display.\n");
        return;
    }
    PUR* temp = head;
    do 
    {
        printf("ID: %d, Date: %s, Name: %s, Amount: %.2f\n", 
            temp->id, temp->date, temp->name, temp->amount);
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    PUR* head = NULL;
    for (int i = 0; i < 5; i++)
    {
        head = addPurchase(head);
    }
    display(head);
    return 0;
}