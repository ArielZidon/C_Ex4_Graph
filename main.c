#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    char choice;
    int num_of_nodes;
    node *graph = NULL;
    int ID = 0;

    while(TRUE)
    {
        scanf("%c",&choice);

        if(choice == 'A')
        {
            scanf("%d",&num_of_nodes);
            graph = creat_graph(num_of_nodes);
        }

        if(choice == 'p')
        {
            print_graph(graph);
        }

        if(choice == 'n')
        {   
            int dest = 0;
            float V =0;
            scanf("%d",&ID);
            scanf("%d",&dest);
            scanf("%f",&V);
            node *p = graph;
            while(p->next!=NULL){
                if(p->id ==ID)
                {
                    if(p->My_edges!=NULL)
                    {
                        edge *y = NULL;
                        y = p->My_edges;

                        while(y->next_edge != NULL){
                            y=y->next_edge;
                        }
                        y->next_edge = (edge*)malloc(sizeof(edge));
                        y->next_edge->val = V;
                        node to = coneected(dest,graph);
                        y->next_edge->connect_to = &to;
                        break;
                
                    }

                    else
                    {
                        p->My_edges = (edge*)malloc(sizeof(edge));
                        p->My_edges->val = V;
                        node to = coneected(dest,graph);
                         p->My_edges->connect_to = &to;
                        break;
                    }
                }
                p = p->next;
            }
        }
    }
}

