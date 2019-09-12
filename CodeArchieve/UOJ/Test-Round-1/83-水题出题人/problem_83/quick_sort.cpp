#include <stdio.h>

int n, counter;
int a[1000001];

void quick_sort_r(int l, int r){
	int i, j, x, y;
	counter++;
	i = l;
	counter++;
	j = r;
	counter++;
	x = a[(l + r) / 2];
	counter++;
	do{
		counter++;
		while(a[i] < x){
			counter++;
			i++;
		}
		while(x < a[j]){
			counter++;
			j--;
		}
		counter++;
		if(i <= j){
			counter++;
			y = a[i];
			counter++;
			a[i] = a[j];
			counter++;
			a[j] = y;
			counter++;
			i++;
			counter++;
			j--;
		}
	}while(i <= j);
	counter++;
	if(l < j){
		counter++;
		quick_sort_r(l, j);
	}
	counter++;
	if(i < r){
		counter++;
		quick_sort_r(i, r);
	}
}

void quick_sort_main(){
	int i;
	counter++;
	scanf("%d", &n);
	counter++;
	for(i = 1; i <= n; i++){
		counter++;
		scanf("%d", &a[i]);
	}
	counter++;
	quick_sort_r(1, n);
	counter++;
	for(i = 1; i <= n; i++){
		counter++;
		printf("%d ", a[i]);
	}
}

int main(){
	counter = 0;
	quick_sort_main();
	printf("\n");
	if(counter <= 2000000){
		printf("Accepted! The counter value is :%d\n", counter);
	}else{
		printf("Time Limit Exceeded because the counter value is :%d\n", counter);
	}
	return 0;
}
