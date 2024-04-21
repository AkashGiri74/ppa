#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left, *right;
    int data;
};

struct node *createnode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node *create_bst(struct node *root, int data) {
    if (root == NULL) {
        return createnode(data);
    }
    if (data < root->data) {
        root->left = create_bst(root->left, data);
    } else if (data >= root->data) {
        root->right = create_bst(root->right, data);
    }
    return root;
}

void inorder(struct node *root)
 {
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct node *kthSmallestAncestor(struct node *root, int k, int *count) 
{
    if (root == NULL || *count >= k) 
    {
        return NULL;
    }

    struct node *left = kthSmallestAncestor(root->left, k, count);
    if (left != NULL)
     {
        return left;
    }

    (*count)++;
    if (*count == k) 
    {
        return root;
    }

    return kthSmallestAncestor(root->right, k, count);
}


int main() {
    struct node *root = NULL;
    int data,k,count ;
    struct node *kthancestor=NULL;

    do {
        puts("Enter data (-1 to stop):");
        scanf("%d", &data);
        if (data != -1) {
            root = create_bst(root, data);
        }
    } while (data != -1);

    printf("Inorder traversal:");
    inorder(root);
    printf("\nPreorder traversal:");
    preorder(root);
    printf("\nPostorder traversal:");
    postorder(root);


    

    count = 0;
    akthancestor = kthSmallestAncestor(root, k, &count);
    if (kthancestor != NULL) 
    {
        printf("The %dth smallest ancestor is: %d\n", k, kthancestor->data);
    } else 
    {
        printf("The tree does not have %d ancestors.\n", k);
    }
    

}
