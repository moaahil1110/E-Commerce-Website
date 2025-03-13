#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100
#define USERNAME_LEN 50
#define PASSWORD_LEN 50

typedef struct User
 {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    char profile[100];
    struct User *next;
} User;

User *hashTable[TABLE_SIZE];

unsigned int hash(const char *key)
 {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++;
    }
    return hash % TABLE_SIZE;
}

void initializeHashTable()
 {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

User *createUser(const char *username, const char *password, const char *profile)
 {
    User *newUser = (User *)malloc(sizeof(User));
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);
    strcpy(newUser->profile, profile);
    newUser->next = NULL;
    return newUser;
}

int addUser(const char *username, const char *password, const char *profile)
 {
    unsigned int index = hash(username);
    User *newUser = createUser(username, password, profile);
    User *current = hashTable[index];
    while (current) {
        if (strcmp(current->username, username) == 0) {
            free(newUser);
            return 0;
        }
        current = current->next;
    }
    newUser->next = hashTable[index];
    hashTable[index] = newUser;
    return 1;
}

User *getUser(const char *username)
 {
    unsigned int index = hash(username);
    User *current = hashTable[index];
    while (current) {
        if (strcmp(current->username, username) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int updateUserProfile(const char *username, const char *newProfile)
 {
    User *user = getUser(username);
    if (user) {
        strcpy(user->profile, newProfile);
        return 1;
    }
    return 0;
}

int login(const char *username, const char *password)
 {
    User *user = getUser(username);
    if (user && strcmp(user->password, password) == 0) {
        return 1;
    }
    return 0;
}

void displayUsers()
 {
    printf("\n--- User List ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        User *current = hashTable[i];
        while (current) {
            printf("Username: %s, Profile: %s\n", current->username, current->profile);
            current = current->next;
        }
    }
}

int main() 
{
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    char profile[100];
    int choice;

    initializeHashTable();

    do 
    {
        printf("\n1. Add User\n2. Login\n3. Update Profile\n4. Display Users\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Enter username: ");
            fgets(username, USERNAME_LEN, stdin);
            username[strcspn(username, "\n")] = '\0';
            printf("Enter password: ");
            fgets(password, PASSWORD_LEN, stdin);
            password[strcspn(password, "\n")] = '\0';
            printf("Enter Name:");
            fgets(profile, 100, stdin);
            profile[strcspn(profile, "\n")] = '\0';

            if (addUser(username, password, profile)) {
                printf("User added successfully.\n");
            } else {
                printf("User already exists.\n");
            }

        } 
        else if (choice == 2) {
            printf("Enter username: ");
            fgets(username, USERNAME_LEN, stdin);
            username[strcspn(username, "\n")] = '\0';
            printf("Enter password: ");
            fgets(password, PASSWORD_LEN, stdin);
            password[strcspn(password, "\n")] = '\0';

            if (login(username, password)) {
                printf("Login successful.\n");
            } else {
                printf("Invalid username or password.\n");
            }

        } else if (choice == 3) {
            printf("Enter username: ");
            fgets(username, USERNAME_LEN, stdin);
            username[strcspn(username, "\n")] = '\0';
            printf("Enter new name: ");
            fgets(profile, 100, stdin);
            profile[strcspn(profile, "\n")] = '\0';

            if (updateUserProfile(username, profile)) {
                printf("Profile updated successfully\n");
            } else {
                printf("User not found\n");
            }

        } else if (choice == 4) {
            displayUsers();
        } else if (choice == 5) {
            printf("Exiting program.\n");
        } else {
            printf("Invalid choice,please try it again.\n");
        }
    } while (choice != 5);

    return 0;
}