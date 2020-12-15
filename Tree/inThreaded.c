typedef struct node {
int data;
struct node *left, *right;
int left_thread, right_thread;
} Node;

typedef struct tree {
Node *root;
} Tree;

void thread_insert(Tree *tree, int data) {
  Node *new_node = create_node(data), *temp = tree->root;
  if (temp == NULL) {
      tree->root = new_node;
      return;
     }
// Search for position to insert and then break
  while (1) {
      if (data < temp->data) {
          if (temp->left_thread == 0) {
              temp = temp->left;
          }
      else {
          break;
          }
      }
else {
      if (temp->right_thread == 0) {
      temp = temp->right;
}
else {
break;
}
}
}

// Attach to either right or left
      if (data < temp->data) {
      // Assign right_thread for new_node
            new_node->left = temp->left;
            new_node->right = temp;
            temp->left_thread = 0;
            temp->left = new_node;
      }
else {
            // Assign left_thread for new_node
            new_node->right = temp->right;
            new_node->left = temp;
            temp->right_thread = 0;
            temp->right = new_node;
      }
      }
      
      //INORDER 
      
      void thread_inorder(Tree *tree) {
Node *temp = tree->root;
if (temp == NULL) {
printf("Empty tree\n");
return;
}
// Go to leftmost node
while (temp->left_thread == 0) {
temp = temp->left;
}
// Print inorder successors
while (temp != NULL) {
printf("%d ", temp->data);
temp = inorder_successor(temp);
}
}
Node *inorder_successor(Node *root) {
if (root == NULL) {
return NULL;
}
if (root->right_thread == 1) {
root = root->right;
}
else {
root = root->right;
while (root->left != NULL && root->left_thread == 0) {
root = root->left;
}
}
return root;
}
