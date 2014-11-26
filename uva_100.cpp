#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 1000000;
int number[MAX];

// dynamic programming
int cycleLength(long long n)
{
	if(n == 1) return 1;

	if(n & 1)
	{
		if((n*3+1) < MAX && number[n*3+1] == 0){
			number[n*3+1] = cycleLength(n*3+1);
			return number[n*3+1]+1;
		}
		return cycleLength(n*3+1) + 1;
	}else{
		if((n/2) < MAX && number[n/2] == 0){
			number[n/2] = cycleLength(n/2);
			return number[n/2]+1;
		}
		return cycleLength(n/2)+1;
	}
}

/*
int cycleLength_2(int n)
{
	int count=0;
	while(n!=1)
	{
		if(n%2==0) n/=2;
		else n = n*3+1;
		count++;
	}
	count++;
	return count;
}
*/
void swapValue(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int begin, end, max, i, temp, flagSwap;
	memset(number, 0, sizeof(number));

	number[1] = 1;
	while (scanf("%d %d", &begin, &end) == 2) {
		max = 0;
		flagSwap = 0;
		if (end < begin) {
			flagSwap = 1;
			swapValue(&begin, &end);
		}
		for (i = begin; i <= end; i++) {
			//  main meth
			temp = cycleLength(i);
			if (temp > max)
				max = temp;
		}
		if (flagSwap)
			printf("%d %d %d\n", end, begin, max);
		else
			printf("%d %d %d\n", begin, end, max);
	}
	return 0;
}
