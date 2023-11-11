#include <stdio.h>

#define MAX_SIZE 100

// Function to perform in-order traversal
void inOrderTraversal(int tree[], int index, int size) {
    if (index < size) {
        // Traverse the left subtree
        inOrderTraversal(tree, 2 * index + 1, size);

        // Process the current node
        printf("%d ", tree[index]);

        // Traverse the right subtree
        inOrderTraversal(tree, 2 * index + 2, size);
    }
}

int main() {
    // Example array representing a binary tree
    int tree[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7};

    int size = 7;  // Size of the array

    printf("In-order traversal: ");
    inOrderTraversal(tree, 0, size);
    
    return 0;
}
