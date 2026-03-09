#include<stdio.h>
#define MAX 100
int queue[MAX],front=0,rear=-1;
void enqueue(int val){
	if(rear==MAX-1){
		printf("Overflow\n");
		return;
	}
	queue[++rear]=val;
}
int dequeue(){
	if(front>rear){
		printf("Underflow\n");
		return -1;
	}
	return queue[front++];
}
void display(){
	if(front>rear){
		printf("Queue Empty\n");
		return;
	}
	int i;
	for(i=front;i<=rear;i++){
		printf("%d ",queue[i]);
	}
}
int main(){
	int n,x,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		enqueue(x);
	}
	printf("After dequeue(): %d\n",dequeue());
	display();
	return 0;
}
