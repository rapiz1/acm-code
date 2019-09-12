#include <stdio.h>

int counter, n;
int a[1000001];

void selection_sort_main(){
	int i, j, min, minj, temp;
	counter++;
	scanf("%d", &n);
	counter++;
	for(i = 1; i <= n; i++){
		counter++;
		scanf("%d", &a[i]);
	}
	counter++;
	for(i = 1; i <= n; i++){
		counter++;
		min = 2147483647;
		counter++;
		for(j = i; j <= n; j++){
			counter++;
			if(a[j] < min){
				counter++;
				min = a[j];
				counter++;
				minj = j;
			}
		}
		counter++;
		temp = a[minj];
		counter++;
		a[minj] = a[i];
		counter++;
		a[i] = temp;
	}
	counter++;
	for(i = 1; i <= n; i++){
		counter++;
		//printf("%d ", a[i]);
	}
}

int main(){
	counter = 0;
	selection_sort_main();
	printf("\n");
	if(counter <= 2000000){
		printf("Accepted! The counter value is :%d\n", counter);
	}else{
		printf("Time Limit Exceeded because the counter value is :%d\n", counter);
	}
	return 0;
}
