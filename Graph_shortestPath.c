//edge classification

#include <stdio.h>
#include <stdlib.h>
#include "Graph_dijkstraSet.c"
#include "Graph_dataStack.c"
/*
struct vertex{
	int vdata;
	int visited;
	int dist;
	int dtime;
	int ftime;
	struct vertex* next;
	struct edge* head;
};

struct edge{
	int edata;
	int weight;
	struct edge* next;
};*/

int time=0;

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

int get_length(struct vertex* u, struct vertex* v){
	struct edge *eptr=u->head;
	while(eptr->edata!=v->vdata){
		eptr=eptr->next;
	}
	return (eptr->weight);
}
void shortest_path(struct vertex* graph, int src,int dest){
	struct vertex* vptr=graph, *findv, *path;
	struct edge* eptr;
	while(vptr!=NULL){
		vptr->visited=0;
		vptr=vptr->next;
	}
	vptr=graph;
	while(vptr->vdata!=src){
		vptr=vptr->next;
	}
	vptr->visited=1;
	vptr->dist=0;
	vptr->parent=NULL;
	
	while(count>=0){
		eptr=vptr->head;
		while(eptr!=NULL){
			findv=graph;
			while(findv->vdata!=eptr->edata){
				findv=findv->next;
			}
			if(findv->visited==0){
				findv->visited=1;
				findv->dist=vptr->dist+get_length(vptr,findv);
				findv->parent=vptr;
				if(findv->vdata==dest){
					path=findv;
					while(path!=NULL){
						push(path->vdata);
						path=path->parent;
					}
					
					printf("shortest path --->");
					while(top>=0){
						printf("%d ",pop());
					}
					printf("distance ---> %d\n",findv->dist);
					return;
				}
				insert(findv);
			}
			eptr=eptr->next;
		}
		vptr->visited=2;
		vptr=get();
	}
	printf("no path found\n");
}
int main(){
	struct vertex* graph1=create_graph(1);
	add_vertex(graph1,2);
	add_vertex(graph1,3);
	add_vertex(graph1,4);
	add_vertex(graph1,5);
	print_graph(graph1);
	
	add_edge(graph1,1,2,2);
	add_edge(graph1,1,3,4);
	add_edge(graph1,2,4,3);
	add_edge(graph1,3,2,1);
	add_edge(graph1,4,1,2);
	add_edge(graph1,3,5,1);
	add_edge(graph1,2,5,1);
	print_graph(graph1);
	
	shortest_path(graph1,5,1);
}
