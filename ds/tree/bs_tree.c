#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node * left,*right;
    int data;
};
struct node * createnode(int data)
{
    struct node * new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->left=new->right=NULL;
    return new;
}
struct node * create_bst(struct node * root,int data)
{
    if(root==NULL)
    {
        return createnode(data);
        
    }
    if(data <root->data)
    {
        root->left=create_bst(root->left,data);
    }
    if(data >=root->data)
    {
      root->right=create_bst(root->right,data);  
    }
    return root;
}
void inorder(struct node* root)
{ 
     if(root!=NULL)
   { 
     inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);  
  }

}
void preorder(struct node* root)
{ 
     if(root!=NULL)
   { 
    
     printf("%d ",root->data);
     preorder(root->left);
     preorder(root->right);  
  }

}
void postorder(struct node* root)
{ 
     if(root!=NULL)
   { 
    
     postorder(root->left);
     postorder(root->right);  
     printf("%d ",root->data);
  }

}

void pathSumHelper(struct node *root, int sum, int targetSum, int *found) 
{
    if (root == NULL) return; // Base case: empty node

    // Update the current sum with the value of the current node
    sum += root->data;

    // Check if the current node is a leaf and its value is equal to the target sum
    if (root->left == NULL && root->right == NULL && sum == targetSum) 
    {
        *found = 1; // Set found flag to true
        return;
    }

    // Recursively check the left and right subtrees
    pathSumHelper(root->left, sum, targetSum, found);
    pathSumHelper(root->right, sum, targetSum, found);
}

void hasPathSum(struct node *root, int targetSum) 
{
    int found = 0; // Initialize a flag to track if path with target sum is found
    pathSumHelper(root, 0, targetSum, &found);
    
    if (found) {
        printf("Path with sum %d exists.\n", targetSum);
    } else {
        printf("No path with sum %d exists.\n", targetSum);
    }
}

int findMin(struct node *root) 
{
    if (root == NULL)
     {
        fprintf(stderr, "Error: Tree is empty.\n");
        exit(EXIT_FAILURE);
    }

    while (root->left != NULL)
     {
        root = root->left;
    }
    return root->data;
}

int findMax(struct node *root) 
{
    if (root == NULL)
     {
        fprintf(stderr, "Error: Tree is empty.\n");
        exit(EXIT_FAILURE);
    }

    while (root->right != NULL)
     {
        root = root->right;
    }
    return root->data;
}


void main ()
{
    struct node * root=NULL;
    int data;
    do
    {
        puts("enter data");
        scanf("%d",&data);
        if (data !=-1)
        {
           root= create_bst(root,data);
        }
    } while (data!=-1);

    printf("inorder traversal:");
    inorder(root);
    printf("preorder traversal :");
    preorder(root);
    printf("postorder traversal :");
    postorder(root);


    int targetSum;
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    hasPathSum(root, targetSum);

    printf("Minimum value in the BST: %d\n", findMin(root));
    printf("Maximum value in the BST: %d\n", findMax(root));


    



    
}