#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node * left;
    int data;
    struct node * right;
};

struct node * createnode(int value)
{
    struct node* newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        return NULL;
    }
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct node * build_tree()
{   
    struct node * root=NULL;
    int data;
    printf("Enter data (or -1 for no node): ");
    scanf("%d",&data);
    if(data==-1)
    {
        return NULL;
    }
    root=createnode(data);
    printf("Enter data for left of %d: ", data);
    root->left=build_tree();
    printf("Enter data for right of %d: ", data);
    root->right=build_tree();
    return root;
}

void inorder (struct node * root)
{    
    if(root==NULL)
    {
        return ;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int pathSumHelper(struct node* root, int sum, int* path, int pathLen) {
    if (root == NULL) return 0;

    // Add current node's value to the path
    path[pathLen++] = root->data;

    sum -= root->data;
    if (root->left == NULL && root->right == NULL && sum == 0) {
        printf("Path with sum %d: ", sum);
        for (int i = 0; i < pathLen; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return 1;
    }

    // Check in left and right subtrees
    if (pathSumHelper(root->left, sum, path, pathLen) || pathSumHelper(root->right, sum, path, pathLen))
        return 1;

    // If no path found, remove current node from path and return 0
    pathLen--;
    return 0;
}

int pathSum(struct node* root, int sum) {
    if (root == NULL) return 0;

    int* path = (int*)malloc(sizeof(int));
    int pathLen = 0;
    int result = pathSumHelper(root, sum, path, pathLen);
    free(path);
    return result;
}

int main ()
{
    struct node * root=NULL;
    root=build_tree();
    inorder(root);

    int targetSum;
    printf("\nEnter the target sum to check path: ");
    scanf("%d", &targetSum);

    if (pathSum(root, targetSum))
        printf("There exists a path with sum %d.\n", targetSum);
    else
        printf("No path found with sum %d.\n", targetSum);

    return 0;
}
