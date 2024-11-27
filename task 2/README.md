# Inventory Management System

## Introduction
This program is an inventory management system designed to practice implementing linked lists and dynamically allocated data structures in C. The system allows users to manage items and warehouses, associate them, and perform various operations to simulate the management of inventory. The program is designed to use basic operations like creating new items, assigning items to warehouses, and generating random warehouse-item assignments.

## Task Overview
The goal of this task is to manage a collection of items and warehouses. Each item and warehouse has a unique code and a name. The system allows multiple warehouses to store the same item and vice versa. The operations include adding items, creating warehouses, and assigning or unassigning items from warehouses. A key feature of the task is generating random warehouse-item assignments and ensuring that duplicates are handled correctly.

## Features
- **Adding New Items**: Ensure that an item is added only if it does not already exist, identified by its unique code.
- **Adding New Warehouses**: Similarly, warehouses are added only if they do not already exist based on their unique code.
- **Assigning and Unassigning Items to Warehouses**: Items can be associated with multiple warehouses and vice versa.
- **Generating Random Warehouse-Item Assignments**: The system can generate 100 items assigned to 10 warehouses randomly, ensuring no duplicate items or warehouses are created.
- **Printing Status**: The current status of items and warehouses can be printed in a formatted output.

## Program Workflow
1. **Item Creation (`i`)**: Adds a new item if the item code does not already exist.
2. **Warehouse Creation (`w`)**: Adds a new warehouse if the warehouse code does not already exist.
3. **Assign Item to Warehouse (`a`)**: Associates an item with a warehouse.
4. **Unassign Item from Warehouse (`u`)**: Removes the association between an item and a warehouse.
5. **Print Status (`p`)**: Displays the current status of all items and warehouses, showing which items are assigned to which warehouses.
6. **Generate and Assign Items (`g`)**: Generates 100 items and assigns them randomly to 10 warehouses.
7. **Quit (`q`)**: Ends the program.

## Requirements
- The main logic must adhere strictly to the specifications, and function signatures must not be altered.
- Debugging outputs should be handled using a `DEBUGON` variable that prints additional debugging information when enabled.
- The program must print error messages when something unexpected happens, using the `print_error_message()` function.
- All output must follow the exact format specified in the `output02.txt` file to ensure compatibility with the test system.
