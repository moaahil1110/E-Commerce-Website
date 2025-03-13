# E-Commerce Platform with Recommendation System
**Final Project in Data Structures Subject**
## Overview

This project implements the backend of an E-Commerce platform in C. It features a recommendation engine that provides personalized product suggestions based on users' browsing and purchase history. The system leverages **hash tables** for fast user and product lookups and uses a **doubly linked list** to manage purchase transactions.

## Modules & Responsibilities

- **User Management (Mohit Kumar)**  
  Handles registration, login, and profile management.
  
- **Purchase History (Ehan Sheikh)**  
  Records purchase details such as product, date, and quantity.
  
- **Browsing History (Affan Khan)**  
  Tracks and stores users' product interaction data.
  
- **Recommendation Engine & Product Management (@moaahil1110)**  
  Analyzes user data to generate personalized recommendations and manages product details, inventory, and categories.

## Data Structures

- **Hash Tables**: Efficient storage and retrieval of user and product data.
- **Doubly Linked List**: Manages purchase records.

## Compilation & Execution

Compile the project with the following command:

```sh
gcc -o ecommerce Main-Rec-Eng.c user-manage.c prod-manage.c browser-history.c Purchase-History.c -lm
```
```sh
./ecommerce
```
