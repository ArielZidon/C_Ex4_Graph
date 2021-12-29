# include <stdio.h>
# include<stdlib.h>
# define TRUE 1
# define FALSE 0

typedef struct node{
    int id;
    struct node *next;
    struct edge *My_edges ;
}node,*pnode; 

typedef struct edge{
    float val;
    struct edge *next_edge;
    struct node *connect_to;   
}edge,*pedge;

node *  creat_graph(int num_of_nodes);

void print_graph(node * graph);


edge edd_adge(edge *head,node *graph);

node coneected(int dest,node *graph);