#include <stdio.h>
int main(){
	int a[10],i,n;
	int twt,tat,ttat,wt;
	printf("Enter n:");
	scanf("%d",&n);
	printf("Enter burst times:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	wt = 0;
	printf("ArrayIndex\tBurstTime\tWaitingTime\tTurnAroundTime\n");
	printf("0\t\t");
	printf("%d\t\t",a[0]);
	printf("%d\t\t",wt);
	tat = a[0];
	printf("%d\n",tat);
	twt = 0;
	ttat = a[0];
	for(i=1;i<n;i++){
		printf("%d\t\t",i);
		printf("%d\t\t",a[i]);
		wt = tat;
		printf("%d\t\t",wt);
		twt += wt;
		tat = wt + a[i];
		printf("%d\n",tat);
		ttat += tat;
	}
	
	
	
	
	printf("Average Waiting Time is %.2f\n",(float)twt/(float)n);
	printf("Average Turn Around Time is %.2f\n",(float)ttat/(float)n);
	
	return 0;
}
