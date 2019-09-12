#include <stdio.h>

int counter, n;
int a[1000001];

void bubble_sort_main(){
	int i, j, temp;
	counter++;
	scanf("%d", &n);
	counter++;
	for(i = 1; i <= n; i++){
		counter++;
		scanf("%d", &a[i]);
	}
	counter++;
	for(i = n - 1; i >= 1; i--){
		counter++;
		for(j = 1; j <= i; j++){
			counter++;
			if(a[j] > a[j + 1]){
				counter++;
				temp = a[j];
				counter++;
				a[j] = a[j + 1];
				counter++;
				a[j + 1] = temp;
			}
		}
	}
	counter++;
	for(i = 1; i <= n; i++){
		counter++;
//		printf("%d ", a[i]);
	}
}

int main(){
	counter = 0;
	bubble_sort_main();
	printf("\n");
	if(counter <= 2000000){
		printf("Accepted! The counter value is :%d\n", counter);
		return 0;
	}else{
		printf("Time Limit Exceeded because the counter value is :%d\n", counter);
		return 1;
	}
}
