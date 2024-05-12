
// C program to implement binary search tree
#include <stdio.h>
#include <stdlib.h>
 
// Define a structure for a binary tree node
struct btreenode {
    int key;
    struct btreenode *left, *right;
};
 
// Function to create a new node with a given value
struct btreenode* newNodeCreate(int value)
{
    struct btreenode* temp
        = (struct btreenode*)malloc(
            sizeof(struct btreenode));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}
 

// Function to insert a node with a specific value in the
// tree
struct btreenode*
insertNode(struct btreenode* node, int value)
{
    if (node == NULL) {
        return newNodeCreate(value);
    }
    if (value < node->key) {
        node->left = insertNode(node->left, value);
    }
    else if (value > node->key) {
        node->right = insertNode(node->right, value);
    }
    return node;
}
 

 
// Function to perform in-order traversal
void postOrder(struct btreenode* root)
{
    if (root != NULL) {
       
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->key);
    }
}
 
int main()
{
    // Initialize the root node
    struct btreenode* root = NULL; 
    int n, i;
 
    // Insert nodes into the binary search tree
    printf("enter thr nodes to be inserted");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
     printf("enter the element to be inserted");
     scanf("%d", &a); 
     root = insertNode(root,a );
     }
    //insertNode(root, 30);
   // insertNode(root, 20);
   // insertNode(root, 40);
    //insertNode(root, 70);
   // insertNode(root, 60);
   // insertNode(root, 80);
    
    // Perform post-order traversal
    postOrder(root);
    printf("\n");
     
    return 0;
}

