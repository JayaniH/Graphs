#include <stdio.h>

int graph[10][10];
int reply;
int n,i,j;

void dir_graph();
void undir_graph();
void create_graph();
void print_graph();

void main(){
	int op;
	while(1){
		printf("1. Directed Graph\n");
		printf("2. Undirected Graph\n");
		printf("3. Exit\n"); 
		printf("\nSelect option\n");
		scanf("%d",&op);
		
		switch (op){
			case 1:dir_graph();
			break;
			case 2:undir_graph();
			break;
			case 3:exit(0);
		}
	}
}

void dir_graph(){
	int in_degree=0, out_degree=0;
	
	create_graph();
	print_graph();
	
	printf("\nvertex\t in degree\t out degree\n");
	for(i=1;i<=n;i++){
		in_degree=0;
		out_degree=0;
		for(j=1;j<=n;j++){
			if(graph[i][j]==1){
				out_degree++;
			}
		}
		for(j=1;j<=n;j++){
			if(graph[j][i]==1){
				in_degree++;
			}
		}
		printf("%d\t %d\t\t %d\n\n",i,in_degree,out_degree);
	}
}

void undir_graph(){
	int degree;
	
	create_graph();
	print_graph();
	
	printf("\nvertex\t degree\n");
	for(i=1;i<=n;i++){
		degree=0;
		for(j=1;j<=n;j++){
			if(graph[i][j]==1){
				degree++;
			}
		}
		printf("%d\t %d\n\n",i,degree);
	}
}


void create_graph(){
	
	printf("How many vertices?\n");
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				graph[i][j]=0;
				continue;
			}
			else{
				printf("\n Vertices %d & %d are Adjacent ? (Y=1/N=0) :",i,j);
            	scanf("%d", &reply);
				if(reply==1){
					graph[i][j]=1;
				}
				else if(reply==0){
					graph[i][j]=0;
				}
			}
		}
	}
	
}

void print_graph(){
	printf("\n    ");
	for(i=1;i<=n;i++){
		printf("%d ",i);
	}
	printf("\n    ");
	for(i=1;i<=n;i++){
		printf("- ");
	}
	printf("\n");
	for(i=1;i<=n;i++){
		printf("%d | ",i);
		for(j=1;j<=n;j++){
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
}

