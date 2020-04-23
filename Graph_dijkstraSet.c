#include<stdio.h>
#define size 10

struct vertex{
	int vdata;
	int visited;
	int dist;
	int dtime;
	int ftime;
	struct vertex* parent;
	struct vertex* next;
	struct edge* head;
};

struct edge{
	int edata;
	int weight;
	struct edge* next;
};

struct vertex* set[size];
int count=0;

void insert(struct vertex* v){
	int i=0;
	while(set[i]!=NULL){
		i++;
	}
	set[i]=v;
	count++;
}

struct vertex* get(){
	int i=0;
	int min=1000;
	struct vertex* m, *ptr;
	while(i<size){
		ptr=set[i];
		if(ptr==NULL){
			i++;
			continue;
		}
		else if(ptr->dist<min){
			m=ptr;
			min=m->dist;
		}
		i++;
	}
	for(i=0;i<size;i++){
		if(set[i]==m){
			set[i]=NULL;
			break;
		}
	}
	count--;
	return m;
}


void print_set(){
	int i;
	printf("dijkstra set ---> ");
	for(i=0;i<size;i++){
		if(set[i]==NULL){
			continue;
		}
		else{
			printf("%d ",set[i]->vdata);
		}
	}
	printf("\n");
}
