#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int id;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

void build_graph_cmd(pnode *head,int v);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void print_graph(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

node* creat_graph(int num_of_nodes);

void add_adge(pnode *head,int src);

void insert_edge(pnode temp,int dest,int w,pnode *head);

pnode getNode(int id, pnode *head);

#endif























// # include <stdio.h>
// # include<stdlib.h>
// # define TRUE 1
// # define FALSE 0

// typedef struct node{
//     int id;
//     int edge_size;
//     struct node *next;
//     struct edge *My_edges ;
// }node,*pnode; 

// typedef struct edge{
//     float val;
//     struct edge *next_edge;
//     struct node *connect_to;   
// }edge,*pedge;

// node *  creat_graph(int num_of_nodes);

// void print_graph(node * graph);

// void edd_adge(node *graph);

// void coneected(int dest,node *p);

// void del_E(node *p);