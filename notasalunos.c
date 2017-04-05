#include<stdio.h>

int main(){
	
	int i,j,n;
	float notas[50][50],soma[3]={0.0},media,max=0.0;
	
	printf("Digite o numero de alunos: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		for(j=0; j<3; j++){
			printf("Nota[%d] do aluno[%d]: ", j+1,i+1);
			scanf("%f", &notas[i][j]);
			soma[j] += notas[i][j]; 
		}
		if(max < notas[i][2])
			max = notas[i][2];
		printf("\n");
	}
	
	printf("-----------------------------------------\n");
	 
	for(i=0; i<3; i++){
		media = soma[i]/n;	
		printf("Media da avaliacao[%d]: %.1f\n", i+1,media);
	}
	
	printf("\nNotas da terceira avaliacao normalizadas:\n\nAv1\tAv2\tAv3\n");
	
	for(i=0; i<n; i++){	
		notas[i][2] *= 	(10.0/max);	
		for(j=0; j<3; j++){
			printf("%.1f\t", notas[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
