#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int weight;
int arrlenth;
pnode graph;

pdijkstra buildDijkstra(pnode start, int src) {
    pdijkstra head = NULL;
    pdijkstra *index = &head;
    while (start != NULL) {
        (*index) = (pdijkstra) malloc(sizeof(dijkstra));
        if ((*index) == NULL) {
            exit(0);
        }

        (*index)->node = start;
        if (start->id == src) {
            (*index)->weight = 0;
        } else {
            (*index)->weight = INFINITY;
        }
        (*index)->tag = 0;
        (*index)->next = NULL;
        index = &((*index)->next);
        start = start->next;
    }
    return head;
}

void deletateDijkstra(pdijkstra dijkstra) {
    while (dijkstra != NULL) {
        pdijkstra temp = dijkstra;
        dijkstra = dijkstra->next;
        free(temp);
    }
}

pdijkstra getPdijkstra(pdijkstra head, int id) {
    while (head != NULL) {
        if (head->node->id == id) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

pdijkstra minVertical(pdijkstra head) {
    pdijkstra ver = NULL;
    while (head != NULL) {
        if (!head->tag && head->weight < INFINITY && (ver == NULL || ver->weight < head->weight)) {
            ver = head;
        }
        head = head->next;
    }
    if (ver != NULL) {
        ver->tag = 1;
    }
    return ver;
}

int shortsPath(pnode head, int src, int dest) {
    pdijkstra dijkstraHead = buildDijkstra(head, src);
    pdijkstra u = minVertical(dijkstraHead);
    while (u != NULL) {
        pedge edgeIndex = u->node->edges;
        while (edgeIndex != NULL) {
            //relax
            pdijkstra v = getPdijkstra(dijkstraHead, edgeIndex->endpoint->id);
            int newD = u->weight + edgeIndex->weight;
            if (v->weight > newD) {
                v->weight = newD;
            }
            edgeIndex = edgeIndex->next;
        }
        u = minVertical(dijkstraHead);
    }
    int D = getPdijkstra(dijkstraHead, dest)->weight;
    if (D == INFINITY) {
        D = -1;
    }
    deletateDijkstra(dijkstraHead);
    return D;
}

/////////////////TSP////////////////

void deep_copy(int* fromArr,int* toArr, int arrLenght) {
    for (int i = 0; i < arrLenght; ++i) {
        toArr[i] = fromArr[i];
    }
}

void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i]= arr[j];
    arr[j] = temp;
}

void PermotitionOfArr(int* arr, int arrLength){
    int tempWeight = 0;
    for (int i = 0; i < arrLength-1; ++i) {
        int D = shortsPath(graph,arr[i], arr[i+1]);
        if (D == -1){
            tempWeight = INFINITY;
            return;
        }
        tempWeight += D;
    }
    if (tempWeight < weight){
        weight = tempWeight;
    }
}

void permotion( int start ,int* arr, int arrLength){
    if (start == arrLength -1 ){
        PermotitionOfArr(arr, arrLength);
        return;
    }
    for (int i = start; i < arrLength; ++i) {
        int* arrCopy = (int*)(calloc(arrLength, sizeof(int)));
        deep_copy(arr,arrCopy,arrLength);
        swap(arrCopy,start, i);
        permotion(start + 1, arrCopy, arrLength);
        free(arrCopy);
    }
}

int TSP(pnode head){
    weight = INFINITY;
	arrlenth = -1;
    graph = head;
    scanf("%d", &arrlenth);
    int *arr = (int *) (calloc(arrlenth, sizeof(int)));
    for (int i = 0; i < arrlenth; i++) {
        scanf("%d", &arr[i]);
    }
    int *arrCopy = (int *) (calloc(arrlenth, sizeof(int)));
    deep_copy(arr,arrCopy,arrlenth);
    permotion(0,arrCopy,arrlenth);
    free(arr);
    free(arrCopy);
    if (weight == INFINITY){
        weight = -1;
    }
    return weight;
}

