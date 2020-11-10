typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int rightThread;
    int leftThread;
} Node;

typedef struct tree
{
    Node *root;
} Tree;
Tree my_tree;
void tree_initialize(Tree *tree);
void tree_insert(Tree *tree, int data);

/* Finds the inorder successor and predecessor of the given node */
Node *inorder_successor(Node *ptr);
Node *inorder_predecessor(Node *ptr);

/* Prints all the elements of the tree in ascending and descending order respectively */
void print_ascending(Tree *tree);
void print_descending(Tree *tree);
void printfun(int);
void nextline();

void tree_destroy(Tree *tree);
/* Advisory: While some guarded discernment could perhaps lead you to 
 * more efficient implementations, you are requested to provide suitable recursive
 * solutions for the following function declarations. 
 */
