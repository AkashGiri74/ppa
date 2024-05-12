#include<stdio.h>
#include<stdlib.h>
struct btreenode
{
int key;
struct btreenode *left, *right;
};
struct btreenode* newNodeCreate(int value)
{
struct btreenode* temp
=(struct btreenode*)malloc(sizeof(struct btreenode));
temp->key=value;
temp->left=temp->right=NULL;
return temp;
}
struct btreenode*
insertNode(struct btreenode* node,int value)
{
if(node==NULL)
{
return newNodeCreate(value);
}
if(value < node->key)
{
node->left = insertNode(node->left,value);
}
else if(value > node->key)
{
node->right = insertNode(node->right,value);
}
return node;
}
void preOrder(struct btreenode* root)
{
if(root != NULL)
{
printf("%d\t",root->key);
preOrder(root->left);
preOrder(root->right);
}
}

// Function to calculate the height of the BST.
int height(struct btreenode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
int height_balanced(struct node * root)
{
    int lh,rh;
    if(root ==NULL)
    {
        return 1;
        
    }
}
int main()
{
struct btreenode* root=NULL;
int n, a, i;
printf("how many nodes to insert");
scanf("%d", &n);
for(i=0; i<n;i++)
{
 printf("enter element");
scanf("%d", &a);
root = insertNode(root,a);
}
//root = insertNode(root,50);
//insertNode(root,20);
//insertNode(root,30);
//insertNode(root,40);
//insertNode(root,50);
//insertNode(root,60);
//insertNode(root,70);
//insertNode(root,80);
preOrder(root);
printf("\n");
return 0;
}

