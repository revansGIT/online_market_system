# Online Market System

This project is an implementation of an online market system in C. It allows for the management of products, including adding, modifying, displaying, deleting, and purchasing products. The data is stored in a linked list, and the program includes functionalities for saving and loading product data from a file.

## Features
- Add new products
- Display all products
- Modify existing products
- Delete products
- Search for products by ID
- Buy products (adjust stock quantities)
- Save products to a file
- Load products from a file

## Requirements
- GCC (GNU Compiler Collection)
- A terminal or command prompt

## Instructions

### Compiling the Program
1. Open a terminal or command prompt.
2. Navigate to the directory where the `main.c` file is located.
3. Compile the program using GCC:
    ```sh
    gcc main.c -o online_market
    ```

### Running the Program
1. After compiling, run the executable:
    ```sh
    ./online_market
    ```
2. Follow the on-screen instructions to interact with the system.

### Menu Options
- **1: Add a new product** - Adds a new product to the list.
- **2: Display all products** - Displays all the products currently in the list.
- **3: Modify an existing product** - Modifies the details of an existing product.
- **4: Delete a product** - Deletes a specified product from the list.
- **5: Search for a product** - Searches for a product by ID.
- **6: Buy a product** - Allows a customer to buy a product and adjusts the stock quantity.
- **7: Save products to file** - Saves the current list of products to a file.
- **0: Exit** - Exits the program.

### File Persistence
- The program automatically loads products from `products.txt` when it starts.
- When exiting the program, it saves the current list of products to `products.txt`.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing
Feel free to contribute to this project by submitting pull requests or issues. Your contributions are welcome!

## Contact
For any questions or suggestions, please contact [revan74k@gmail.com](mailto:revan74k@gmail.com).
