#include <stdio.h>
#include <stdlib.h>
int mutex=1;
int full=0;
int empty=10,x=0;
void producer(){
	--mutex;
	++full;
	--empty;
	x++;
	printf("Producer produced %d\n",x);
	++mutex;
}
void consumer(){
	--mutex;
	--full;
	++empty;
	printf("Consumer consumed %d\n",x);
	++mutex;
}
int main(){
	int n,i;
	printf("Press 1 for producer, 2 for Consumer, 3 for Exit:\n");
	for(i=1;i>0;i++){
		printf("Enter choice:");
		scanf("%d",&n);
		switch(n){
		case 1:if((mutex==1)&&(empty!=0)){
		           producer();
		       }
		       else{
		       	    printf("Buffer is full");
		       }
		       break;
		case 2:if((mutex==1)&&(full!=0)){
		           consumer();
		       }
		       else{
		       	    printf("Buffer is empty");
		       }
		       break;
		case 3:exit(0);
			break;
		}
	}
}
