#include<stdio.h>

int main(){
	
	int i,j,n,count,esq,dir;
	
	printf("Digite um numero impar: ");
	scanf("%d", &n);
	printf("\n");
	
	count = n/2;
	esq = n/2-1; dir = n/2+1;
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(j>esq && j<dir)
				printf("*");
			else 
				printf(" ");
		}
		printf("\n");
		if(i<count){
			esq--; dir++;
		}
		else{
			esq++; dir--;
		}
	}
		
	return 0;
}

