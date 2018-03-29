#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graphalgs.h"
#include "graph.h"


void intializeVector(int* f, int value, int n) {

	for(int i=0; i < n; i++)
		f[i] = value;
}

void printPairs(int* v, int n) {

	printf("  Node |  Father\n\n");
	for(int i=0; i < n; i++)
		printf("  %2d   |  %2d\n", i, v[i]);

	printf("\n* -1 = root\n* -2 = unreachable\n\n");
}

void breadthFirstSearch(GRAPH* g, int vertex) {

	int queue[g->vertexNum];
	int fatherOf[g->vertexNum];
	int* wasVisited = calloc(g->vertexNum, sizeof(int));
	int add = 0;
	int rem = 0;
	int curr; //Current Vertex

	intializeVector(queue, -2, g->vertexNum);	
	intializeVector(fatherOf, -2, g->vertexNum);

	fatherOf[vertex] = -1;
	queue[add++] = vertex;
	wasVisited[vertex] = 1;

	while(rem < g->vertexNum) {
		curr = queue[rem++];

		if(curr < 0)
			break;

		for(int j=0; j < g->vertexNum; j++) {
			if(0 < g->adjMatrix[curr][j] && g->adjMatrix[curr][j] < INFINITY) 
				if(!wasVisited[j]) {
					queue[add++] = j;
					wasVisited[j] = 1;
					fatherOf[j] = curr;
				}
		}
	}

	printPairs(fatherOf, g->vertexNum);	
}

void dfsRec(GRAPH* g, int vertex, int n, int* visited, int* father) {

	visited[vertex] = 1;

	for(int j=0; j < n; j++)
		if(0 < g->adjMatrix[vertex][j] && g->adjMatrix[vertex][j])
			if(!visited[j]) { 
				father[j] = vertex;
				dfsRec(g, j, n, visited, father);
			}
}

void depthFirstSearch(GRAPH* g, int vertex) {

	int* wasVisited = calloc(g->vertexNum, sizeof(int));
	int fatherOf[g->vertexNum];

	intializeVector(fatherOf, -2, g->vertexNum);

	fatherOf[vertex] = -1;

	//for(int i=0; i < g->vertexNum; i++)
	dfsRec(g, vertex, g->vertexNum, wasVisited, fatherOf);

	printPairs(fatherOf, g->vertexNum);
}

void minimumPath(GRAPH* g, int vertex) {

}

void minimumSpanningTree(GRAPH* g) {

}
