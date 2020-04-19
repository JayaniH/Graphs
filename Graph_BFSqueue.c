#include <stdio.h>
#include <stdlib.h>
#define size 10

struct vertex{
	int vdata;
	int visited;
	int partition;
	struct vertex* next;
	struct edge* head;
};

struct edge{
	int edata;
	int weight;
	struct edge* next;
};

struct vertx* queue[size];
int front=-1, rear=-1;

void enqueue(struct vertex* v){
	if(front==-1 && rear==-1 || front>rear){
		front=0;
		rear=0;
		queue[rear]=v;
	}
	else{
		rear++;
		queue[rear]=v;
	}
}

struct vertex* dequeue(){
	return queue[front++];
}

void print_queue(){
	int i;
	printf("queue ---> ");
	for(i=front;i<=rear;i++){
		printf("%d ",queue[i]);
	}
}
