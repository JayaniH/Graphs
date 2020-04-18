//add and delete edges and vertices

#include <stdio.h>
#include <stdlib.h>

struct vertex{
	int vdata;
	struct vertex* next;
	struct edge* head;
};

struct edge{
	int edata;
	int weight;
	struct edge* next;
};

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

struct vertex* delete_vertex(struct vertex* graph, int v){
	struct vertex* vptr=graph, *preptr;
	struct edge* eptr, *postptr;
	
	if(vptr->vdata==v){
		graph=vptr->next;
		vptr->next=NULL;
	}
	else{
		while(vptr->vdata!=v && vptr->next!=NULL){
			preptr=vptr;
			vptr=vptr->next;
		}
		if(vptr->vdata==v){
			preptr->next=vptr->next;
			vptr->next=NULL;
		}
		else{
			printf("vertex not found\n");
			return;
		}
	}
	eptr=vptr->head;
	vptr->head=NULL;
	while(eptr!=NULL){
		postptr=eptr->next;
		eptr->next=NULL;
		free(eptr);
		eptr=postptr;
	}
	free(vptr);
	vptr=graph;
	while(vptr->next!=NULL){
		delete_edge(graph,vptr->vdata,v);
		vptr=vptr->next;
	}
	return graph;
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

void delete_edge(struct vertex* graph, int u, int v){
	struct vertex* vptr=graph;
	struct edge* eptr, *preptr;
	
	while(vptr->next!=NULL && vptr->vdata!=u){
		vptr=vptr->next; 
	}
	if(vptr->vdata==u){
		eptr=vptr->head;
		if(eptr->edata==v){
			vptr->head=eptr->next;
			free(eptr);
		}
		else{
			while(eptr->edata!=v && eptr->next!=NULL){
				preptr=eptr;
				eptr=eptr->next;
			}
			if(eptr->edata==v){
				preptr->next=eptr->next;
				free(eptr);
			}
			else{
				printf("edge not found\n");
			}
		}
	}
	else{
		printf("edge not found\n");
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
	add_edge(graph1,3,2,1);
	add_edge(graph1,4,1,1);
	print_graph(graph1);
	
	graph1=delete_vertex(graph1,1);
	//delete_edge(graph1,6,1);
	print_graph(graph1);
}
