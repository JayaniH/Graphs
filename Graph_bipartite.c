//bipartite

#include <stdio.h>
#include <stdlib.h>
#include "Graph_BFSqueue.c"
/*
struct vertex{
	int vdata;
	int visited;
	struct vertex* next;
	struct edge* head;
};

struct edge{
	int edata;
	int weight;
	struct edge* next;
};*/

struct vertex* create_vertex(int data){
	struct vertex* v=(struct vertex*)malloc(sizeof(struct vertex));
	v->vdata=data;
	v->next=NULL;
	v->head=NULL;
	
	return v;
}

struct vertex* create_graph(int start){
	struct vertx* graph=create_vertex(start);
	
	return graph;
}

void add_vertex(struct vertex* graph, int data){
	struct vertex* v=create_vertex(data);
	struct vertex* vptr=graph;
	
	while(vptr->next!=NULL){
		vptr=vptr->next;
	}
	vptr->next=v;
}

struct edge* create_edge(int v, int w){
	struct edge* e=(struct edge*)malloc(sizeof(struct edge));
	e->edata=v;
	e->weight=w;
	e->next=NULL;
	
	return e;
}

void add_edge(struct vertex* graph, int u, int v, int w){
	struct edge* e=create_edge(v,w);
	struct edge* eptr;
	struct vertex* vptr=graph;
	
	while(vptr!=NULL){
		
		if(vptr->vdata==u){
			e->next=vptr->head;
			vptr->head=e;
		}
		vptr=vptr->next;
	}
}

void print_graph(struct vertex* graph){
	struct vertex* vptr=graph;
	struct edge* eptr;
	
	while(vptr!=NULL){
		printf("%d ---> ",vptr->vdata);
		eptr=vptr->head;
		while(eptr!=NULL){
			printf("%d (%d) ",eptr->edata,eptr->weight);
			eptr=eptr->next;
		}
		vptr=vptr->next;
		printf("\n");
	}
	printf("\n");
}

void bipartite(struct vertex* graph, int start){
	struct vertex* vptr=graph, *findv;
	struct edge* eptr;
	
	while(vptr!=NULL){
		vptr->visited=0;
		vptr->partition=0;
		vptr=vptr->next;
	}
	vptr=graph;
	while(vptr->vdata!=start){
		vptr=vptr->next;
	}
	vptr->visited=1;
	vptr->partition=1;
	
	while(vptr!=NULL){
		if(vptr->visited!=2){
			vptr->visited=2;
			eptr=vptr->head;
			
			while(eptr!=NULL){
				findv=graph;
				while(findv->vdata!=eptr->edata){
					findv=findv->next;
				}
				if(findv->partition==vptr->partition){
					printf("not bipartite\n");
					return;
				}
				else{
					findv->partition=3-vptr->partition;
				}
				if(findv->visited==0){
					findv->visited=1;
					enqueue(findv);
				}
				eptr=eptr->next;
			}
		}
		vptr=dequeue();
	}
	printf("bipartite\n");
}
int main(){
	struct vertex* graph1=create_graph(1);
	add_vertex(graph1,2);
	add_vertex(graph1,3);
	add_vertex(graph1,4);
	add_vertex(graph1,5);
	print_graph(graph1);
	
	add_edge(graph1,1,2,1);
	add_edge(graph1,1,3,1);
	add_edge(graph1,2,4,1);
	//add_edge(graph1,3,2,1);
	//add_edge(graph1,4,1,1);
	add_edge(graph1,3,5,1);
	print_graph(graph1);
	
	bipartite(graph1,1);
}
