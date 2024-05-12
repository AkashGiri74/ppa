#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node * createnode(int value)
{
    struct node * newnode=(struct node *)malloc(sizeof(struct node ));
       newnode->data=value;
       newnode->left=newnode->right=NULL;
       return newnode;
}
struct node *insertnode(struct node * root,int value)
{
   if(root==NULL)
   {
    return createnode(value);
   }
   else if(value <root->data)
   {
    root->left=insertnode(root->left,value);
   }
  else if(value >= root->data)
  {
    root->right=insertnode(root->right,value);
  }
  return root;

}
void inorder(struct node * root)
{
    struct node * temp=root;
      if(temp!=NULL)
      {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
      }
}
void preorder(struct node * root)
{
    struct node * temp=root;
      if(temp!=NULL)
      {printf("%d ",root->data);
        preorder(root->left);
        // printf("%d",root->data);
        preorder(root->right);
      }
}
void postorder(struct node * root)
{
    struct node * temp=root;
      if(temp!=NULL)
      {
        postorder(root->left);
        // printf("%d",root->data);
        postorder(root->right);
        printf("%d ",root->data);
      }
}
struct node * search(struct node * root,int value)
{ if(value==root->data)
  {
   return root;
 }
 else if(value <root->data)
 {
    return search(root->left,value);
 }
 else if(value >root->data)
 {
    return search(root->right,value);
 }
 else
 {
 return NULL;
 }

}
struct node * treecopy(struct node * root)
{
    struct node * temp=(struct node*)malloc(sizeof(struct node));
      if(root!=NULL)
      {
        temp->data=root->data;
        temp->left=treecopy(root->left);
        temp->right=treecopy(root->right);
        return temp;
      }
      else
      return NULL;
}
void mirror (struct node * root)
{
    struct node *temp=root;
    struct node * temp1;
    if(temp!=NULL)
    {
      if(temp->left!=NULL)
      mirror(temp->left);
      if(temp->right !=NULL)
        mirror(temp->right);
      temp1=temp->left;
      temp->left=temp->right;
      temp->right=temp1;  
    }
}
int counttotal(struct node * root)
{
    static int count=0;
    if(root!=NULL)

    {   count++;
        counttotal(root->left);
        counttotal(root->right);
        return count;

    }
}
int countleaf(struct node * root)
{  static int count=0;
    if(root!=NULL)
    {
        countleaf(root->left);
        if(root->left==NULL && root->right==NULL)
        {
            count ++;
        }
        countleaf(root->right);
        return count;
    }
}
int min(struct node * root)
{
    while(root!=NULL && root->left !=NULL)
    {  root=root->left;
    //    return root->data;

    }
    return root->data;
}
int max(struct node * root)
{
    while(root!=NULL && root->right!=NULL)
    {  root=root->right;
    //    return root->data;

    }
    return root->data;
}
int main()
{  int choice;
    struct node * root=NULL;
    root=insertnode(root,30);
    insertnode(root,10);
    insertnode(root,5);
    insertnode(root,40);
    insertnode(root,35);
    insertnode(root,45);
    insertnode(root,20);

    do
    {
    printf("\n1.inorder\n");
    printf("2.preorder\n");
    printf("3.postorder\n");
    puts("4.search");
    puts("5.treecopy");
    puts("6.mirror");
    puts("7.counttotal");
    puts("8.countleaf");
    puts("9.min");
    puts("10.max");
    printf("0.exit\n");
    printf("enter your choice");
    scanf("%d",&choice);

        switch (choice)
        {
        case 1:inorder(root);
            
            break;
            case 2:preorder(root);
            
            break;
            case 3:postorder(root);
            
            break;
            case 4:{struct node * s=NULL;
            // s=search(root,value);
            int value;
            printf("enter element to search :");
            scanf("%d",&value);
             s=search(root,value);
            if(s!=NULL)
            { printf("%d fouund at address %u",value,s);
                
            }
        
            }
            break;
            case 5:{struct node * root1=NULL;
             root1 =treecopy(root);
              printf("after copy:");
               inorder(root1);
               printf("\n");
            }
                break;
             case 6:{
                mirror(root);
             printf("after mirror:");
             inorder(root);
        }
                break; 
             case 7:{
                int n=counttotal(root);
                printf("total nodes %d",n);
             } break; 
             case 8:{
                int n=countleaf(root);
                printf("leafnodes %d",n);
             } break;  
             case 9:{int n=min(root);
             printf("min element %d",n);
        }
             break;
               case 10:{int n=max(root);
             printf("max element %d",n);
        }
             break;  
            
        
        
    
        }
    } while(choice!=0);
    
}