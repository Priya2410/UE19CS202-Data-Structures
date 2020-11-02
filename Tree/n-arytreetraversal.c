//Just algorithm dont execute

struct node
{
    int data;
    struct node *child;//to store the link of oldest child
    struct node *sibling;
};

//Preorder
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->child);
        preorder(root->sibling);
    }
}

//Inorder
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->child);
        printf("%d\t",root->data);
        inorder(root->sibling);
    }
}

//Postorder
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->child);
        postorder(root->sibling);
        printf("%d\t",root->data);
    }
}