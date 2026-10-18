#  Data Storage Application Using BST and AVL Tree in C++

## 1. Project Title

Data Storage Application Using Binary Search Tree (BST) and AVL Tree

## 2. Introduction

This project is a data storage application developed using C++ that demonstrates how data can be stored, organized, and searched efficiently using two tree data structures: the Binary Search Tree (BST) and the AVL Tree.

The application inserts the same sorted sequence of 15 keys into both trees and compares their heights and search paths. It helps demonstrate the difference between an ordinary BST and a self-balancing AVL tree when data is inserted in sorted order.

## 3. Objectives

- To implement a Binary Search Tree and an AVL Tree using C++.
- To insert the same sequence of 15 sorted keys into both trees.
- To calculate and display the height of each tree.
- To search for a user-specified key and display its search path.
- To compare the efficiency of searching in BST and AVL trees.

## 4. Technologies Used

- Programming Language: C++
- Libraries: `iostream` and `algorithm`
- Data Structures: Binary Search Tree and AVL Tree
- Concepts: Recursion, tree rotations, searching, and height calculation.

## 5. Working of the Project

The application works as follows:

1. Node Creation: Each node stores a key, pointers to its left and right children, and a height value.
2. BST Insertion: The 15 sorted keys are inserted into a Binary Search Tree. Since the keys are inserted in ascending order, the tree becomes skewed.
3. AVL Insertion: The same keys are inserted into an AVL Tree. The AVL tree performs rotations when necessary to maintain balance.
4. Inorder Traversal: Both trees display the keys in sorted order.
5. Height Calculation: The height of each tree is calculated and displayed.
6. Searching: The user enters a key, and the program displays the path followed to find it in each tree.

## 6. Expected Output

The program displays:

- The inorder traversal of the BST and AVL tree.
- The height of both trees.
- The search path for a user-entered key in the BST.
- The search path for the same key in the AVL tree.
- Whether the key was found or not found.

For the sorted sequence of 15 keys, the BST has a height of 15 nodes, while the AVL tree has a much smaller height of approximately 4–5 nodes, depending on the resulting structure.

## 7. Advantages

- Demonstrates efficient data storage and retrieval techniques.
- Shows how balancing improves search performance.
- Helps visualize the effect of inserting sorted data into different tree structures.
- Provides a practical understanding of tree rotations and recursive algorithms.

## 8. Applications

- Database indexing.
- Dictionary and symbol-table implementations.
- Searching and organizing records.
- File and information management systems.
- Learning and comparing data structures and algorithms.

## 9. Conclusion

The Data Storage Application demonstrates the implementation and comparison of BST and AVL trees using C++. Inserting sorted keys causes the BST to become skewed, increasing its height and search time. In contrast, the AVL tree maintains balance through rotations, reducing its height and improving search efficiency. Therefore, the project illustrates why self-balancing trees are useful for applications that require efficient data storage and retrieval.
