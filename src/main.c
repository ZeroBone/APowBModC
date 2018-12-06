#include <stdio.h>
#include <stdlib.h>

long int aPowbModC(long int a, long int b, long int c);

int main(int argc, char *argv[]) {
	
	long int a, b, c;
	
	puts("Enter a:");
	scanf("%d", &a);
	
	puts("Enter b:");
	scanf("%d", &b);
	
	puts("Enter c:");
	scanf("%d", &c);
	
	printf("a ^ b %% c = %d\n", aPowbModC(a, b, c));
	
	system("pause");
	
	return 0;
	
}

long int aPowbModC(long int a, long int b, long int x) {
	
	long int t = a;
	long int x1 = b;
	/* long int d = (a * a * a * a * a * a) % x; */
	long int d = 1;
	
	while (x1 > 0) {
		
		if (x1 % 2 == 1) {
			
			d = (d * t) % x;
			
		}
		
		t = (t * t) % x;
		
		
		x1 /= 2;
		
	}
	
	return d;
	
}
