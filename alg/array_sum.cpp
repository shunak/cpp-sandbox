#include <stdio.h>

int main()
{
	int a[] = {4,2,11,4,15,7,9,12,3,6};
	int i, sum;

	for(i=0;i<sizeof(a)/sizeof(a[0]);i++){
		printf("a[%d]=%3d\n", i, a[i]);
	}
	printf("\n");

	sum=0;
	for(i=0; i<sizeof(a)/sizeof(a[0]); i++){
	
		sum+=a[i];
	
	}
	printf("sum=%3d\n",sum);



    return 0;
 


}

