#include <stdio.h>

int counter, n;
int a[1000001];

// 下面实现了一个伪随机数生成器

// Below is a random number generator

unsigned int seed, RNG_a, RNG_b;

void RNG_init(){
	counter++;
	seed = 2166136261u;
	counter++;
	RNG_a = 26648577u;
	counter++;
	RNG_b = 10108929u;
}

int RNG_next(){
	counter++;
	seed = seed * RNG_a + RNG_b;
	counter++;
	return seed & 0x7fffffff;
}

bool check(){
	int i;
	counter++;
	for(i = 2; i <= n; i++){
		counter++;
		if(a[i - 1] > a[i]){
			counter++;
			return false;
		}
	}
	counter++;
	return true;
}

void bogo_sort_main(){
	int i, j, temp;
	counter++;
	scanf("%d", &n);
	counter++;
	for(i = 1; i <= n; i++){
		counter++;
		scanf("%d", &a[i]);
	}
	counter++;
	RNG_init();
	counter++;
	while(!check()){
		counter++;
		for(i = 1; i <= n; i++){
			counter++;
			seed = (seed * 16777619u) ^ a[i];
		}
		counter++;
		for(i = 1; i <= n; i++){
			counter++;
			j = RNG_next() % n + 1;
			counter++;
			temp = a[i];
			counter++;
			a[i] = a[j];
			counter++;
			a[j] = temp;
		}
		counter++;
		RNG_a = (RNG_next() >> 5) + 1;
		counter++;
		RNG_b = (RNG_next() >> 5) + 3;
	}
	counter++;
	for(i = 1; i <= n; i++){
		counter++;
		printf("%d ", a[i]);
	}
}

int main(){
	counter = 0;
	bogo_sort_main();
	printf("\n");
	if(counter <= 2000000){
		printf("Accepted! The counter value is :%d\n", counter);
	}else{
		printf("Time Limit Exceeded because the counter value is :%d\n", counter);
	}
	return 0;
}
