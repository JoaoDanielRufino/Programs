#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

void situacao(int bomba, int n, int p, char v[100][100], char copia[100][100], char copia2[100][100], int x, int y, char opcao[20]);
void revelar(int n, int p, char v[100][100], char copia[100][100], int x, int y);
void marcar(int n, int p, char v[100][100], char copia[100][100], char copia2[100][100], int x, int y);

int main(){
	
	int i,j,m,n,p,x,y,bomba;
	char v[100][100],copia[100][100],copia2[100][100],opcao[20];
	
	system("color f0");
	printf("Digite as dimencoes do tabuleiro: ");
	scanf("%d %d", &n,&p);
	
	srand(time(NULL));
	m = rand()%(n*p);
	if(m==0) m==2;				 //Numero aleatorio de minas.
	bomba  = m;
	
	for(i=1; i<=n; i++){
		for(j=1; j<=p; j++){
			v[i][j] = '*';				//Matriz original, na qual o jogar ve.	
			copia[i][j] = '*';			//Matriz copia para as bombas.
			copia2[i][j] = '*';			//Matriz copia para saber as demarcacoes feitas pelo jogados.
			printf("%3c", v[i][j]);
		}
		printf("\n");
	}
	
	i=0; j=0; srand(time(NULL));
	while(m!=0){					
		i = 1+rand()%n;					//Linha aleatoria.
		j = 1+rand()%p;					//Coluna aleatoria.
		copia[i][j] = 'M';				//Matriz com as bombas.
		m--;
	}
	 
	while(1){
		printf("Quantidade de bombas: %d\n", bomba);
		printf("Escolha um quadrado: ");
		scanf("%d %d", &x,&y);

		printf("Deseja revelar ou declarar quadrado minado? ");
		scanf("%s", opcao);
		
		system("cls"); 	
		situacao(bomba,n,p,v,copia,copia2,x,y,opcao);
		
	}
	
	return 0;
}

void situacao(int bomba, int n, int p, char v[100][100], char copia[100][100], char copia2[100][100], int x, int y, char opcao[20]){
	int i,j,count=0;
	
	for(i=1; i<=n; i++){
		for(j=1; j<=p; j++){
			printf("%3c", v[i][j]);
		}
		printf("\n");	
	} 

	if(strcmp(opcao,"revelar")==0){		//Ao escolher a opcao "revelar", a funcao revelar eh chamada.
		revelar(n,p,v,copia,x,y);
	}
	else{
		marcar(n,p,v,copia,copia2,x,y);	//Se nao, inicia-se a funcao "marcar".
	}
}

void revelar(int n, int p, char v[100][100], char copia[100][100], int x, int y){
	int i,j,count=0;
	
	if(copia[x][y]=='M'){				//Teste para saber se a posicao que o jogador escolheu possui uma mina.			
		system("cls");
		for(i=1; i<=n; i++){
			for(j=1; j<=p; j++){
				if(x==i && y==j){		//Se possuir, imprimir a matriz, e no lugar da bom mostrar "-1".
					printf("%3d", -1);
				}
				else{	
					printf("%3c", v[i][j]);		
				}
			}
			printf("\n");
		}
		printf("Voce encostou na mina, o jogo acabou.\n");
		exit(0);
	}
	
	else{								//Se nao possuir mina, ira entrar em um laco para contar quantas minas estao ao redor.
		for(i=x-1; i<=x+1; i++){
			for(j=y-1; j<=y+1; j++){
				if(copia[i][j]=='M'){
					count++;			//Contador das minas.
				}
			}
		}
		if(count==0){
			v[x][y] = ' ';				//Se count=0, printar espaco.
		}
		else{
			v[x][y] = count + 48;		//Como v[i][j] eh um vetor de tipo char, adiciona-se 48 ao seu valor para imprimir numeros da tabela ASCII.
		}
		
		system("cls");

		for(i=1; i<=n; i++){
			for(j=1; j<=p; j++){
				printf("%3c", v[i][j]);
			}
			printf("\n");
		}
	}
}

void marcar(int n, int p, char v[100][100], char copia[100][100], char copia2[100][100], int x, int y){
	int i,j,count=0;
	
	system("cls");
	v[x][y] = 'M';						//Marcacao feita pelo jogardor. 
	copia2[x][y] = 'M';					//Copia da marcacao em outra matirz para posteriormente compara-la com a matriz "copia" e saber se todas marcacoes sao verdadeiras.
	
	for(i=1; i<=n; i++){
		for(j=1; j<=p; j++){
			printf("%3c", v[i][j]);
			if(copia2[i][j]==copia[i][j]){		
				count++;				//Contador de comparacao entre matrizes.
			}
		}
		printf("\n");
	}
	
	if(count==(n*p)){					//Se o contador atingir o produto entre colunas por linhas da matriz, significa q todas as marcacoes estao corretas. 
		printf("Voce ganhou!!!\n");
		exit(0);
	}
	
}
