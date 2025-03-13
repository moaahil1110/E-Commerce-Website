#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define prod_table_SIZE 100

typedef struct Product {
    char name[50];
    int id;
    float price;
    struct Product* next;
} PROD;

int hashing(int id) {
    return id % prod_table_SIZE;
}

PROD* newNode(int id) {
    PROD* temp = (PROD*)malloc(sizeof(PROD));
    if (temp == NULL) {   
        printf("Allocation Failure\n");
        exit(1);
    }
    printf("Enter the id: ");
    scanf("%d", &id);
    printf("Enter the name: ");
    scanf("%s", temp->name);
    printf("Enter the price: ");
    scanf("%f", &(temp->price));
    temp->id = id;  // Generates a random product ID
    temp->next = NULL;
    return temp;
}

PROD* addProduct(PROD* prod_table[],int id) {
    PROD* prod_No = newNode(id);
    int index = hashing(prod_No->id);  // Corrected: Use prod_No, not newNode

    if (prod_table[index] == NULL) {
        prod_table[index] = prod_No;
        return prod_table[index];
    }

    PROD* temp = prod_table[index];
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = prod_No;
    return prod_table[index];
}

PROD* updateProduct(PROD* prod_table[], int id) {  // Added id parameter
    int index = hashing(id);
    PROD* temp = prod_table[index];

    // Search for the product by ID
    while (temp != NULL) {
        if (temp->id == id) {
            // Product found, prompt user for new details
            printf("Enter the new name: ");
            scanf("%s", temp->name);
            printf("Enter the new price: ");
            scanf("%f", &(temp->price));
            printf("Product updated successfully.\n");
            return temp;
        }
        temp = temp->next;
    }

    // If product not found, display message
    printf("Product with ID %d not found.\n", id);
    return NULL;
}

void displayProducts(PROD* prod_table[]) {
    for (int i = 0; i < prod_table_SIZE; i++) {
        PROD* temp = prod_table[i];
        while (temp != NULL) {
            printf("ID: %d, Name: %s, Price: %.3f\n", temp->id, temp->name, temp->price);
            temp = temp->next;
        }
    }
}

int main() {
    PROD* prod_table[prod_table_SIZE] = {NULL};
    int y, id;
    PROD* product;
    do {
        printf("Product Management System\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. Display All Products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &y);

        switch (y) {
            case 1:
                addProduct(prod_table,id);
                break;
            case 2:
                printf("Enter the product ID to update: ");
                scanf("%d", &id);
                updateProduct(prod_table, id);
                break;
            case 3:
                displayProducts(prod_table);
                break;
            case 4:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (y != 4);

    return 0;
}
