#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define rec_table_size 100

struct node
{
    int user_id;
    char username[100];
    int product_id;
    char product_name[100];
    float price;
    struct node *next;
};

typedef struct Recomandations
{
    int prod_id;
    char prod_name[100];
    struct Recomandations *next;
} Rec;

// Function to add browsing history
void add(struct node **head, int user_id, const char *username, int product_id, const char *product_name, float price)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->user_id = user_id;
    strcpy(newNode->username, username);
    newNode->product_id = product_id;
    strcpy(newNode->product_name, product_name);
    newNode->price = price;
    newNode->next = *head;
    *head = newNode;
}

// Function to display browsing history 
struct node *getHistory(struct node *head, int user_id)
{
    struct node *current = head;
    struct node *userHistory = NULL;
    printf("\nBrowsing History for User ID %d:\n", user_id);
    while (current != NULL)
    {
        if (current->user_id == user_id)
        {
            printf("Username: %s\n", current->username);
            printf("Product: %s\n Price: ₹%.2f\n Product ID: %d\n\n",
                   current->product_name, current->price, current->product_id);

            // Add this product to the filtered browsing history
            add(&userHistory, current->user_id, current->username, current->product_id, current->product_name, current->price);
        }
        current = current->next;
    }

    if (userHistory == NULL)
    {
        printf("No browsing history found for User ID %d.\n", user_id);
    }

    return userHistory;
}

// Function to generate recommendations based on the browsing history
Rec *generateRecommendations(struct node *userHistory)
{
    Rec *recHead = NULL;
    struct node *current = userHistory;
    printf("\nGenerating Recommendations:\n");
    while (current != NULL)
    {
        Rec *newRec = (Rec *)malloc(sizeof(Rec));
        if (newRec == NULL)
        {
            printf("Memory allocation failed for recommendation.\n");
            return NULL;
        }
        newRec->prod_id = current->product_id;
        strcpy(newRec->prod_name, current->product_name);
        newRec->next = recHead;
        recHead = newRec;

        printf("Recommended Product: %s (ID: %d)\n", newRec->prod_name, newRec->prod_id);

        current = current->next;
    }

    return recHead;
}

// Function to display recommendations
void displayRecommendations(Rec *rec)
{
    if (rec == NULL)
    {
        printf("No recommendations available.\n");
        return;
    }

    printf("\nRecommended Products:\n");
    while (rec != NULL)
    {
        printf("Product ID: %d, Product Name: %s\n", rec->prod_id, rec->prod_name);
        rec = rec->next;
    }
}

// Main function
int main()
{
    struct node *head = NULL;
    Rec *recommendations = NULL;

    int n, user_id, product_id;
    char username[100], product_name[100];
    float price;

    do
    {
        printf("\nEnter the choice:\n");
        printf("1. Add Browsing History\n");
        printf("2. Display Browsing History\n");
        printf("3. Generate Recommendations\n");
        printf("4. Display Recommendations\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter User ID: ");
            scanf("%d", &user_id);
            printf("Enter Username: ");
            scanf("%99s", username);
            printf("Enter Product ID: ");
            scanf("%d", &product_id);
            printf("Enter Product Name: ");
            scanf("%99s", product_name);
            printf("Enter Price: ");
            scanf("%f", &price);
            add(&head, user_id, username, product_id, product_name, price);
            printf("Browsing history added successfully.\n");
            break;

        case 2:
            printf("Enter User ID to display browsing history: ");
            scanf("%d", &user_id);
            getHistory(head, user_id);
            break;

        case 3:
            printf("Enter User ID to generate recommendations: ");
            scanf("%d", &user_id);
            struct node *userHistory = getHistory(head, user_id);
            recommendations = generateRecommendations(userHistory);
            break;

        case 4:
            displayRecommendations(recommendations);
            break;

        case 5:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice, please select a valid option.\n");
            break;
        }
    } while (n != 5);

    return 0;
}