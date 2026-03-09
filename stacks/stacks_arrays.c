#include<stdio.h>
#define MAX 100
int stack[MAX],top=-1;
void push(int val){
	if(top==MAX-1){
		printf("Overflow\n");
		return;
	}
	stack[++top]=val;
}
int pop(){
	if(top<0){
		printf("Underflow\n");
		return -1;
	}
	return stack[top--];
}
void display(){
	if(top<0){
		printf("Stack Empty\n");
		return;
	}
	int i;
	for(i=top;i>=0;i--){
		printf("%d ",stack[i]);
	}
}
int main(){
	int n,x,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		push(x);
	}
	printf("After pop(): %d\n",pop());
	display();
	return 0;
}
