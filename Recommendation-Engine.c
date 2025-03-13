#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 100

typedef struct HashNode {
    int product_id;
    char product_name[100];
    float price;
    int frequency;
    struct HashNode* next;
} HashNode;

typedef struct Recommendation {
    int product_id;
    char product_name[100];
    float price;
    struct Recommendation* next;
} Rec;

// Hash function to map product IDs to hash table indices
int hash(int product_id) {
    return product_id % HASH_TABLE_SIZE;
}

// Insert or update product frequency in hash table
void updateFrequency(HashNode* hashTable[], int product_id, const char* product_name, float price) {
    int index = hash(product_id);
    HashNode* current = hashTable[index];
    while (current != NULL) {
        if (current->product_id == product_id) {
            current->frequency++;
            return;
        }
        current = current->next;
    }
    // Add new product to hash table
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->product_id = product_id;
    strcpy(newNode->product_name, product_name);
    newNode->price = price;
    newNode->frequency = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Find the top 3 products with the highest frequency
Rec* getTopRecommendations(HashNode* hashTable[]) {
    Rec* top3 = NULL;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HashNode* current = hashTable[i];
        while (current != NULL) {
            Rec* newRec = (Rec*)malloc(sizeof(Rec));
            if (!newRec) {
                printf("Memory allocation failed.\n");
                exit(1);
            }
            newRec->product_id = current->product_id;
            strcpy(newRec->product_name, current->product_name);
            newRec->price = current->price;
            newRec->next = top3;
            top3 = newRec;
            current = current->next;
        }
    }
    return top3;
}

// Free memory allocated for the hash table
void freeHashTable(HashNode* hashTable[]) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HashNode* current = hashTable[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

// Generate recommendations based on browsing and purchase history
Rec* generateRecommendations(struct node* browsingHistory, struct purchase* purchaseHistory) {
    HashNode* hashTable[HASH_TABLE_SIZE] = {NULL};

    // Process browsing history
    struct node* bTemp = browsingHistory;
    while (bTemp != NULL) {
        updateFrequency(hashTable, bTemp->product_id, bTemp->product_name, bTemp->price);
        bTemp = bTemp->next;
    }

    // Process purchase history
    struct purchase* pTemp = purchaseHistory;
    while (pTemp != NULL) {
        updateFrequency(hashTable, pTemp->id, pTemp->name, pTemp->amount);
        pTemp = pTemp->next;
    }

    // Get top 3 recommendations
    Rec* recommendations = getTopRecommendations(hashTable);
    freeHashTable(hashTable);
    return recommendations;
}

// Display the recommendations
void displayRecommendations(Rec* head) {
    if (head == NULL) {
        printf("No recommendations available.\n");
        return;
    }
    printf("\n--- Top Recommendations ---\n");
    Rec* temp = head;
    while (temp != NULL) {
        printf("Product ID: %d, Name: %s, Price: %.2f\n",
               temp->product_id, temp->product_name, temp->price);
        temp = temp->next;
    }
}

// Free the recommendation list
void freeRecommendations(Rec** head) {
    Rec* temp = *head;
    while (temp != NULL) {
        Rec* toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    *head = NULL;
}