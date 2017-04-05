#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Aluno{
	int nota[3];
	char nome[40];
}Aluno;

int compare(const void *a, const void *b){
	int x;
	x = strcmp((*(struct Aluno*)a).nome, (*(struct Aluno*)b).nome);
	if(x==0) return 0;
	if(x>0) return 1;
	else return -1;
}

int main(){
	
	int i,j,n;
	
	printf("Digite a quantidade de alunos: ");
	scanf("%d", &n);
	printf("\n");
	Aluno a[n];
	
	for(i=0; i<n; i++){
		fflush(stdin);
		printf("Nome do aluno[%d]: ", i+1);
		scanf("%[^\n]", a[i].nome);
		fflush(stdin);
			for(j=0; j<3; j++){
				printf("Nota[%d]: ", j+1);
				scanf("%d", &a[i].nota[j]);
			}
		printf("\n");
	}
	
	qsort(a,n,sizeof(struct Aluno),compare);
	
	printf("\n");
	for(i=0; i<n; i++){
		printf("%s\t", a[i].nome);
			for(j=0; j<3; j++){	
				printf("%d  ", a[i].nota[j]);
			}
		printf("\n");
	}
	
	
	return 0;
}
