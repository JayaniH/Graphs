#include <stdio.h>
#define size 10

int stack[size];
int top=-1;

void push(int v){
	top++;
	stack[top]=v;
}

int pop(){
	return stack[top--];
}

void print_s(){
	int i;
	printf("data stack --> ");
	for(i=0;i<=top;i++){
		printf("%d ",stack[i]);
	}
	printf("\n");
}
