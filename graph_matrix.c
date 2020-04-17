#include <stdio.h>
#define size 10

int graph[size][size];

void add_edge(int u, int v ){
	graph[u][v]=1;
}

void print_graph(){
	int i,j;
	
	for(i=0;i<size;i++){
		printf("%d ---> ",i);
		for(j=0;j<size;j++){
			if(graph[i][j]==1){
				printf("%d ",j);
			}
		}
		printf("\n");
	}
}

void BFS(int start){
	int i=start, j;
	for(j=0;j<size;j++){
		if(graph[i][j]==1){
			
		}
	}
}
int main(){
	add_edge(1,2);
	add_edge(1,5);
	add_edge(3,2);
	add_edge(2,1);
	
	print_graph();
}
