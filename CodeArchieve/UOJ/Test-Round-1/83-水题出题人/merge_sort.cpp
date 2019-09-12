#include <stdio.h>

int n, counter;
int a[1000001];
int b[1000001], c[1000001];
int bn, cn;

void merge_sort_r(int ll, int rr){
	int lr, rl, i;
	counter++;
	if(ll < rr){
		counter++;
		lr = (ll + rr) / 2;
		counter++;
		rl = lr + 1;
		counter++;
		merge_sort_r(ll, lr);
		counter++;
		merge_sort_r(rl, rr);
		counter++;
		for(i = ll; i <= lr; i++){
			counter++;
			b[i - ll] = a[i];
		}
		counter++;
		b[lr - ll + 1] = 2147483647;
		counter++;
		for(i = rl; i <= rr; i++){
			counter++;
			c[i - rl] = a[i];
		}
		counter++;
		c[rr - rl + 1] = 2147483647;
		counter++;
		bn = 0;
		counter++;
		cn = 0;
		counter++;
		for(i = ll; i <= rr; i++){
			counter++;
			if(b[bn] < c[cn]){
				counter++;
				a[i] = b[bn];
				counter++;
				bn++;
			}else{
				counter++;
				a[i] = c[cn];
				counter++;
				cn++;
			}
		}
	}
}

void merge_sort_main(){
	int i;
	counter++;
	scanf("%d", &n);
	counter++;
	for(i = 1; i <= n; i++){
		counter++;
		scanf("%d", &a[i]);
	}
	counter++;
	merge_sort_r(1, n);
	counter++;
	for(i = 1; i <= n; i++){
		counter++;
		printf("%d ", a[i]);
	}
}

int main(){
	counter = 0;
	merge_sort_main();
	printf("\n");
	if(counter <= 2000000){
		printf("Accepted! The counter value is :%d\n", counter);
	}else{
		printf("Time Limit Exceeded because the counter value is :%d\n", counter);
	}
	return 0;
}
