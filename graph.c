#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"


void build_graph_cmd(pnode *head,int v)
{
    // deleteGraph_cmd(head);
    *head = creat_graph(v);
    // int i;
    // for (i = 0; i < v; i++)
    // {
    //     scanf("%c", &ch);
    //     insert_node_cmd(head);
    // }
}

node * creat_graph(int num_of_nodes)
{   
    node *head = NULL;
    pnode newNode, temp = NULL;
    int i;

    head = (pnode)malloc(sizeof(node));

    if(head == NULL)
    {
        exit(0);
    }   

    head->id = 0; 
    head->next = NULL;
    head->edges = NULL;

    temp = head;

    for(i=1; i<num_of_nodes; i++)
    {
        newNode = (pnode)malloc(sizeof(node));

        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }
        newNode->id = i; 
        newNode->next = NULL;  
        newNode->edges = NULL;

        temp->next = newNode; 
        temp = temp->next;    
    }
    return head;
}

pnode getNode(int id, pnode *head)
{
    pnode temp = *head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}

// void insert_node_cmd(pnode *head)
// {
//     int id = -1;
//     scanf("%d", &id);
//     pnode src = getNode(id, head);
//     if (src == NULL) // crate new node
//     {
//         src = (pnode)(malloc(sizeof(node)));
//         if (src == NULL)
//         {
//             printf("malloc didnt work");
//             return;
//         }
//         else
//         {
//             src->node_num = id;
//             src->next = *head;
//             src->edges = NULL;
//             *head = src;
//         }
//     }
//     else
//     { // we are run over exsist node
//         pedge inx = src->edges;
//         while (head != NULL)
//         {
//             pedge temp = inx->next;
//             free(inx);
//             inx = temp;
//         }
//         src->edges = NULL;
//     }
//     pedge *endEdge = &(src->edges);
//     int dest = -1;

//     while (scanf("%d", &dest) != 0)
//     {
//         pnode destNode = getNode(dest, head);
//         if (destNode == NULL)
//         {
//             destNode = (pnode)(malloc(sizeof(node)));
//             if (destNode == NULL)
//             {
//                 perror("malloc didnt work");
//             }
//             else
//             {
//                 destNode->node_num = dest;
//                 destNode->edges = NULL;
//                 destNode->next = *head;
//                 *head = destNode;
//             }
//         }
//         int weight = -1;
//         scanf("%d", &weight);
//         *endEdge = (pedge)(malloc(sizeof(edge)));
//         if ((*endEdge) == NULL)
//         {
//             perror("malloc didnt work");
//         }
//         (*endEdge)->weight = weight;
//         (*endEdge)->next = NULL;
//         (*endEdge)->endpoint = destNode;
//         endEdge = &((*endEdge)->next);
//     }
// }

void add_adge(pnode *head,int src){

    int dest;
    int count = 0;
    int w;
    pnode temp = getNode(src,head);
    while(scanf("%d",&dest)!=0 && scanf("%d",&w)!=0)
    {
        if((dest >= 'A' && dest <= 'Z') || (w >= 'A' && w <= 'Z'))
        {
        break;
        }
        if((dest >= 'a' && dest <= 'z') || (w >= 'a' && w <= 'z'))
        {
        break;
        }
        insert_edge(temp,dest,w,head);
        printf("%d",temp->edges->weight);
    }
}

void insert_edge(pnode temp,int dest,int w,pnode *head){

    if(temp->edges == NULL)
    {
        temp->edges = (pedge)malloc(sizeof(edge));
        if(temp->edges == NULL)
        {
            exit(0);
        }
        temp->edges->weight = w;
        temp->edges->next =NULL;
        node *D = getNode(dest,head);
        temp->edges->endpoint = &(*D);
        printf("if");
    }
    else{
        pedge n = temp->edges;

        while(n->next!=NULL)
        {
            n = n->next;
        }
        n->next = (pedge)malloc(sizeof(edge));
        if(n == NULL)
        {
            exit(0);
        }
        n->next->next = NULL;
        n->next->weight = w;
        node *D = getNode(dest,head);
        n->next->endpoint = &(*D);
        printf("else");
    }
}



void print_graph(pnode head){// for self debug
    pnode tempNode = head;
    while (tempNode != NULL)
    {
        printf("Node: %d {", tempNode->id);
        pedge tempEdge = tempNode->edges;
        while (tempEdge != NULL)
        {
            printf("dest: %d weight: %d ", tempEdge->endpoint->id,tempEdge->weight);
            tempEdge = tempEdge->next;
        }
        printf("}");
        tempNode = tempNode->next;
    }
}