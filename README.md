# E-Commerce Platform with Recommendation System
**Final Project in Data Structures Subject**

## Table of Contents
- [Overview](#overview)
- [Modules & Responsibilities](#modules--responsibilities)
- [Data Structures](#data-structures)
- [Prerequisites](#prerequisites)
- [Compilation & Execution](#compilation--execution)
  - [User Management Module](#1-user-management-module)
  - [Product Management Module](#2-product-management-module)
  - [Browsing History Module](#3-browsing-history-module)
  - [Purchase History Module](#4-purchase-history-module)
  - [Recommendation Engine Module](#5-recommendation-engine-module)
- [Contribution Guidelines](#contribution-guidelines)



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

## Prerequisites
- GCC (GNU Compiler Collection)
- Ensure you have the necessary permissions to compile and run C programs on your machine.


## Compilation & Execution

Since each module was developed separately, compile and run them individually:

### 1. User Management Module
Compile:
```sh
gcc -o user_manage User-Management.c -lm
```
```sh
./user_manage
```
### 2. Product Management Module
Compile:
```sh
gcc -o prod_manage Product-Management.c -lm
```
```sh
./prod_manage
```
### 3. Browsing History Module
Compile:
```sh
gcc -o browser_history Browsing-History.c -lm
```
```sh
./browser_history
```

### 4. Purchase History Module
Compile:
```sh
gcc -o purchase_history Purchase-History.c -lm
```
```sh
./purchase_history
```
### 5. Recommendation Engine Module
Compile:
```sh
gcc -o recommend Recommendation-Engine.c -lm
```
```sh
./recommend
```

## Contribution Guidelines
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes.
4. Commit your changes (`git commit -m 'Add some feature'`).
5. Push to the branch (`git push origin feature-branch`).
6. Create a new Pull Request.
