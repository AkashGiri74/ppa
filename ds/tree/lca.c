#include <stdio.h>
#include <stdlib.h>

struct TreeNode
 {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int val)
 {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *buildTree()
 {
    int data;
    printf("Enter data : ");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }

    struct TreeNode *root = createNode(data);
    printf("Enter left child of %d:\n", data);
    root->left = buildTree();
    printf("Enter right child of %d:\n", data);
    root->right = buildTree();
    return root;
}

void inorderTraversal(struct TreeNode *root) 
{
    if (root == NULL) 
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) 
{
    if (root == NULL || root == p || root == q) 
    {
        return root;
    }

    struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left && right)
     {
        return root;
    } else if (left)
     {
        return left;
    } else 
    {
        return right;
    }
}

int main() {
    struct TreeNode *root = buildTree();
    printf("Inorder traversal of the tree: ");
    inorderTraversal(root);
    printf("\n");

    int pData, qData;
    printf("Enter data for node p: ");
    scanf("%d", &pData);
    struct TreeNode *p = createNode(pData);

    printf("Enter data for node q: ");
    scanf("%d", &qData);
    struct TreeNode *q = createNode(qData);

    struct TreeNode *lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL) 
    {
        printf("Lowest Common Ancestor of %d and %d is %d\n", pData, qData, lca->val);
    } 
    else
     {
        printf("Lowest Common Ancestor not found\n");
    }

    return 0;
}
