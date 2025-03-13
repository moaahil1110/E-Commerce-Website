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
- [Usage Examples](#usage-examples)
- [Contribution Guidelines](#contribution-guidelines)
- [License](#license)

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

