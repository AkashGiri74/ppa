#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> // Include bool type for C99 and later

struct node
{
    struct node * left,*right;
    int data;
};

// Create a new node
struct node * createnode(int data)
{
    struct node * new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->left=new->right=NULL;
    return new;
}

// Insert a node into the BST
struct node * create_bst(struct node * root,int data)
{
    if(root==NULL)
    {
        return createnode(data);
    }
    if(data < root->data)
    {
        root->left=create_bst(root->left,data);
    }
    else if(data >= root->data)
    {
        root->right=create_bst(root->right,data);  
    }
    return root;
}

// Function to check if a binary tree is a valid BST
bool isValidBSTHelper(struct node* root, struct node* minNode, struct node* maxNode) {
    if (root == NULL) return true; // An empty tree is a valid BST

    // Check if the current node violates the BST property
    if ((minNode != NULL && root->data <= minNode->data) ||
        (maxNode != NULL && root->data >= maxNode->data)) {
        return false;
    }

    // Recursively check the left and right subtrees
    return isValidBSTHelper(root->left, minNode, root) && isValidBSTHelper(root->right, root, maxNode);
}

bool isValidBST(struct node* root) {
    return isValidBSTHelper(root, NULL, NULL);
}

int main() {
    struct node * root = NULL;
    int data;
    do {
        printf("Enter data (-1 to stop): ");
        scanf("%d", &data);
        if (data != -1) {
            root = create_bst(root, data);
        }
    } while (data != -1);

    if (isValidBST(root)) {
        printf("The binary tree is a valid BST.\n");
    } else {
        printf("The binary tree is not a valid BST.\n");
    }

    return 0;
}
