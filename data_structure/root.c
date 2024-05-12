#include<stdio.h>
#include<stdlib.h>
struct btreenode
  {
    int data;
    struct btreenode *left,*right;
  };
  struct btreenode *newnodecreate(int value)
  {
    struct btreenode*temp=(struct btreenode *)malloc (sizeof(struct btreenode));
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
  }
  struct btreenode*
  insertnode(struct btreenode *node,int value)
{
    if(node==NULL)
    {
        return newnodecreate(value);
    }
    if (value<node->data)
    {
        node->left=insertnode(node->left,value);
    }
    else if (value>node->data)
    { node->right=insertnode(node->right,value);

    }
    return node;
}
void ino(struct btreenode*root)
{ if(root!=NULL)
    {
        ino(root->left);
        printf("%d\t",root->data);
        ino(root->right);
    }
}
int main ()
{ struct btreenode*root=NULL;
    root=insertnode(root,50);
    insertnode(root,30);
    insertnode(root,20);
    insertnode(root,40);
    insertnode(root,70);
    insertnode(root,60);
    insertnode(root,60);
    insertnode(root,80);
    ino(root);
    printf("\n");
    return 0;

}