#include<stdio.h>
#include "bst.h"
int main()
{
    int choice, loop = 1;
    Tree my_tree;
    tree_initialize(&my_tree);
    while (loop)
    {
        scanf("%d", &choice);
        switch (choice)
        {
            int number_of_elements, element, index;
            int data;
        case 1:
            /* Insert elements */
            scanf("%d", &element);
            tree_insert(&my_tree, element);
            break;
        case 2:
            /* Print elements in the preorder fashion */
            preorder(&my_tree);
            break;
        case 3:
            /* Print elements in the inorder fashion */
            inorder(&my_tree);
            break;
        case 4:
            /* Print elements in the postorder fashion */
            postorder(&my_tree);
            break;
	case 5:
            /* Delete elements */
            scanf("%d", &element);
            tree_delete(&my_tree, element);
            break;
        default:
            tree_destroy(&my_tree);
            loop = 0;
            break;
        }
    }
    return 0;
}

