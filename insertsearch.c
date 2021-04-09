#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left;
    struct node*right;
};
struct node*root=NULL;
struct node* newnode(int key)
{
   struct node*temp=(struct node*)malloc(sizeof(struct node));
   temp->data=key;
   temp->left=NULL;
   temp->right=NULL;
   return temp;
}
struct node* insert(struct node*node,int data);
struct node* search(int data)
{
    struct node *current = root;
    printf("Visiting elements: ");
    while(current->data != data){
        if(current != NULL) {
            printf("%d ",current->data);
    if(current->data > data)
        {
            current = current->left;
        }
    else
    {
        current = current->right;
    }
    if(current == NULL){
    return NULL;
}
}
}
return current;
}
int main()
{
    int a,b,ch;
    struct node*x;
    printf("enter the no. to create the root of the tree");
    scanf("%d",&a);
    root= insert(root,a);
    while(1)
    {
        printf("\npress 1 for incert\npress 2 for search\npress3 for exit\nenter your choice=\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("enter the no. you want to insert");
            scanf("%d",&b);
            insert(root,b);
            break;
        case 2:
            printf("enter the no. you want to search");
            scanf("%d",&b);
            x=search(b);
            break;
        case 3:
            return 0;
        default:
            printf("wrong choice");
            break;
        }
    }
}
struct node* insert(struct node*node,int data)
{
    if (node==NULL)
    {
        return newnode(data);
    }
    else if(data<node->data)
    {
        insert(node->left,data);
    }
    else if(node->data<data)
    {
        insert(node->right,data);
    }
    return(node);
}
