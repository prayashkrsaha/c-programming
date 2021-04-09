#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left;
    struct node*right;
};
struct node *newnode(int data)
{
    struct node*node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
void inorder(struct node*node)
{
    if(node==NULL)
    {
        return;
    }
    inorder(node->left);
    printf("%d  ",node->data);
    inorder(node->right);
}
void preorder(struct node*node)
{
     if(node==NULL)
    {
        return;
    }
    printf("%d  ",node->data);
    preorder(node->left);
    preorder(node->right);
}
void postorder(struct node *node)
{
     if(node==NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%d  ",node->data);
}
int main()
{
    struct node*root= newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->right->left=newnode(5);
    root->right->right=newnode(6);
    int ch;
    printf("\npress 1 for inorder traversal\npress 2 for preoder traversal\n press 3 for post order traversal\nenter your choice=\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        inorder(root);
        break;
    case 2:
        preorder(root);
        break;
    case 3:
        postorder(root);
        break;
    case 4:
        return 0;
    default:
        printf("wrong choice");
    }
}
