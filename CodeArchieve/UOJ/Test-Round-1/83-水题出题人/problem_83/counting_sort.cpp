#include <stdio.h>

int counter, n, max;
int a[1000001];
int b[10000001];

void counting_sort_main(){
	int i, j;
	counter++;
	scanf("%d", &n);
	counter++;
	max = 0;
	counter++;
	for(i = 1; i <= n; i++){
		counter++;
		scanf("%d", &a[i]);
		counter++;
		if(a[i] > max){
			counter++;
			max = a[i];
		}
	}
	counter++;
	for(i = 0; i <= max; i++){
		counter++;
		b[i] = 0;
	}
	counter++;
	for(i = 1; i <= n; i++){
		counter++;
		b[a[i]]++;
	}
	counter++;
	for(i = 0; i <= max; i++){
		counter++;
		for(j = 1; j <= b[i]; j++){
			counter++;
//			printf("%d ", i);
		}
	}
}

int main(){
	counter = 0;
	counting_sort_main();
	printf("\n");
	if(counter <= 2000000){
		printf("Accepted! The counter value is :%d\n", counter);
		return 0;
	}else{
		printf("Time Limit Exceeded because the counter value is :%d\n", counter);
		return 1;
	}
}
