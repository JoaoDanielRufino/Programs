#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int indice=0; //Variavel global para o identificar o indice de cadastros.

typedef struct aluno{
	int id;
	char nome[30];
	int turma;
	float provas[4];
	float freq;
}Aluno;

int menu();
void cadastrar(Aluno *a);
void exibir_todos(Aluno *a);
void exibir_aprovados(Aluno *a);
void exibir_media_turma(Aluno *a);

int main(){
	
	int opcao;
	Aluno a[100];
	
	while(1){
		fflush(stdin);
		opcao = menu();
		if(opcao==1) cadastrar(a);
		if(opcao==2) exibir_todos(a);
		if(opcao==3) exibir_aprovados(a);
		if(opcao==4) exibir_media_turma(a);
		if(opcao==5){
			printf("\nSaindo.....");
			break;
		}
	}
	
	return 0;
}

int menu(){	//Menu para as opcoes.
	int opcao;
	
	system("cls");
	printf("[1] - Cadastrar alunos\n");
	printf("[2] - Exibir todos os alunos\n");
	printf("[3] - Exibir alunos aprovados\n");
	printf("[4] - Exibir media final da turma\n");
	printf("[5] - Sair\n");
	printf("Escolha uma opcao: ");
	scanf("%d", &opcao);
	return opcao;
}

void cadastrar(Aluno *a){
	int i;
	
	printf("ID: ");
	scanf("%d", &a[indice].id); fflush(stdin); //Utilizacao da variavel global para cadastrar os alunos.
	
	printf("Nome: ");
	scanf("%[^\n]", a[indice].nome); fflush(stdin);
	
	printf("Turma: ");
	scanf("%d", &a[indice].turma); fflush(stdin);
	
	for(i=0; i<4; i++){
		printf("Prova[%d]: ", i+1);
		scanf("%f", &a[indice].provas[i]); fflush(stdin);
	}
	
	printf("Frequencia: ");
	scanf("%f", &a[indice].freq); fflush(stdin);
	
	indice++; //Incremento da variavel global, para o proximo aluno a cadastrar.
	
	system("pause");
}

void exibir_todos(Aluno *a){	//Funcao para mostrar todos os alunos e seus dados.
	int i,j;
	
	printf("\n");
	for(i=0; i<indice; i++){
		printf("ID: %d\n", a[i].id);
		printf("Nome: %s\n", a[i].nome);
		printf("Turma: %d\n", a[i].turma);
		for(j=0; j<4; j++){
			printf("Prova[%d]: %.2f\n", j+1,a[i].provas[j]);
		}
		printf("Frequencia: %.2f\n", a[i].freq);
		printf("-------------------------------------------------\n");
	}
	system("pause");
}

void exibir_aprovados(Aluno *a){ //Mostrar todos alunos aprovados.
	int i,j,k;
	float media,freq;
	
	printf("\n");
	for(i=0; i<indice; i++){
		media=0;
		for(j=0; j<4; j++){
			media += a[i].provas[j];
		}
		
		media = media/4; freq = (a[i].freq*100)/80;	//Total de aulas: 80.
		
		if((media)>=6.0 && (freq>=75.0)){
			printf("ID: %d\n", a[i].id);
			printf("Nome: %s\n", a[i].nome);
			printf("Turma: %d\n", a[i].turma);
			for(k=0; k<4; k++){
				printf("Prova[%d]: %.2f\n", k+1,a[i].provas[k]);
			}	
			printf("Frequencia: %.2f\n", a[i].freq);
			printf("-------------------------------------------------\n");
		}
	}
	system("pause");	
}

void exibir_media_turma(Aluno *a){	//Mostrar a media de uma determinada turma.
	int i,j,n;
	float media;
	
	printf("Qual turma deseja ver a media? ");
	scanf("%d", &n);
	printf("\n");
	
	for(i=0; i<indice; i++){
		media=0;
		if(n==a[i].turma){
			printf("Turma %d:\n", n);
			printf("Nome: %s\n", a[i].nome);
			for(j=0; j<4; j++){
				media += a[i].provas[j];
			}
			printf("Media: %.2f\n", media/4);	
			printf("-------------------------------------------------\n");
		}
	}
	system("pause");
}
