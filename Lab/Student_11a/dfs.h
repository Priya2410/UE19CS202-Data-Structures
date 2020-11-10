#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>

//dfs function calls dfs on node v and keeps track of the component number through label parameter.
void dfs(int v , int **graph,int * visited,int n,int label);


//components returns the number of components in the graph and updates visited such that ith index of visited is the component to which ith vertex
//belongs, make sure number of the ith component is minimum as possible that is if their are 3 components {1,4,5} and {2,3} and {6,7}
// {1,4,5} component number is 1  and that of {2,3} is 2 and {6,7} is 3.
int components(int ** graph,int*visited,int n);
 
