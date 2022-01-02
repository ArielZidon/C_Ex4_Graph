#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    pnode temp = NULL;
    pnode *head = &temp;
    char choise;
    char ch;
    int v = 0;
    int src = 0;

    while (scanf("%c", &choise) != EOF)
    {
 
        if(choise == 'A')
        {
            freeGraph(head);
            scanf("%d", &v);
            *head =  creat_graph(v);
            
            scanf("%c", &ch);
            
            while(scanf("%c", &ch)!=0){
                if(ch == 'n')
                {
                scanf("%d",&src);
                add_adge(head,src);
                }
                else
                {
                    break;
                }
            }
            // print_graph(*head);
            
            choise = ch;
        }

        if(choise == 'B')
        {
            add_node(head);
            // print_graph(*head);
            continue;
        }
        if(choise == 'D')
        {
            del_node(head);
            // print_graph(*head);
            continue;
        }
        if(choise == 'S')
        {
            // shortsPath(*head);
            int src = -1, dest = -1;
            scanf("%d %d", &src, &dest);
            int dis = shortest_Path(*head, src, dest);
            printf("Dijsktra shortest path: %d ",dis);
            printf("\n");
            continue;
        }
        if(choise == 'T')
        {
            int tsp = TSP(*head);
            printf("TSP shortest path: %d ",tsp);
            printf("\n");
            continue;
        }
       
    
    }
    freeGraph(head);
}

