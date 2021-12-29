#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



void print_graph(node * graph)
{
    node * p = graph;

    while(p->next!=NULL)
    {   
        printf("%d: \n",p->id);

        if(p->My_edges!=NULL){
            edge *j = NULL;
            j = p->My_edges;
            printf("-> %d value: %f \n",p->My_edges->connect_to->id,p->My_edges->val);
        while(j->next_edge!=NULL)
        {
            printf("-> %d value: %f \n",j->connect_to->id,j->val);
            j = j->next_edge;
        }
        }
        p = p->next;
    }
}

node * creat_graph(int num_of_nodes)
{   
    node *head = NULL;
    struct node *newNode, *temp;
    int i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL)
    {
        exit(0);
    }   
    head->id = 0; 
    head->next = NULL; 

    temp = head;
    for(i=1; i<=num_of_nodes; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }
        newNode->id = i; 
        newNode->next = NULL;  

        temp->next = newNode; 
        temp = temp->next;    
    }
    return head;
}

// edge edd_adge(edge *head,node *graph){
//     int dest = 0;
//     float V =0;

//     scanf("%d",&dest);
//     scanf("%f",&V);

//     edge *p = NULL;
//     p = head;

//     if(head == NULL)
//     {
//         head = (edge*)malloc(sizeof(edge));
//         node t = coneected(dest,graph);
//         head->connect_to = &t;
//         // printf("%d\n",t.id);
//         head -> val = V;
//         return *head;
//     }
//     else
//     {
//     while(p->next_edge!=NULL)
//     {
//         p = p->next_edge;
//     }
//     p->next_edge=(edge*)malloc(sizeof(edge));
//     node t = coneected(dest,graph);
//     p->connect_to = &t;
//     // printf("%d\n",t.id);
//     p->next_edge->val = V;
//     p = p->next_edge;
//     return *p;
//     }
// }

node coneected(int dest,node *graph)
{
    node *p = NULL;
    p = graph;

    while(p->next!=NULL)
    {
        if(p->id == dest)
        {   
            return *p;
        }
        p = p->next;
    }
}   
