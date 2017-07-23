#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int indice=0; //Variavel global para facilitar acessar o indice da agenda.

typedef struct pessoa{
	char nome[50],email[50],rua[50],bairro[50],cidade[50],estado[50],pais[50],complemento[100],observacoes[100];
	int cep,DDD,numero,dia,mes,ano;
}Pessoa;

int menu();
void cadastro(Pessoa *agenda);
void busca(Pessoa *agenda);
void mesaniversario(Pessoa *agenda);
void aniversario(Pessoa *agenda);
void ordemalfabetica(Pessoa *agenda);
void retirar(Pessoa *agenda);
void nome_tel_email(Pessoa *agenda);
void dados(Pessoa *agenda);

int main(){
	
	int opcao;
	Pessoa agenda[100];
	
	while(1){
		fflush(stdin);
		opcao = menu();
		if(opcao==1) cadastro(agenda);
		if(opcao==2) busca(agenda);
		if(opcao==3) mesaniversario(agenda);
		if(opcao==4) aniversario(agenda);
		if(opcao==5) retirar(agenda);
		if(opcao==6) nome_tel_email(agenda);
		if(opcao==7) dados(agenda);
		if(opcao==8){
			printf("\nSaindo.....");
			break;
		}
	}
	
	return 0;
}

int menu(){
	int opcao;
	
	system("cls");
	printf("Menu da agenda:\n");
	printf("[1] - Cadastrar pessoa\n");
	printf("[2] - Buscar por nome\n");
	printf("[3] - Buscar por mes de aniversario\n");
	printf("[4] - Buscar por dia e mes de aniversario\n");
	printf("[5] - Deletar contato\n");
	printf("[6] - Mostrar nome, telefone e email\n");
	printf("[7] - Mostrar a agenda\n");
	printf("[8] - Sair\n");
	printf("Escolha uma opcao: ");
	scanf("%d", &opcao);
	return opcao;
}

void cadastro(Pessoa *agenda){
	
	fflush(stdin);
	printf("Nome: "); 
	scanf("%[^\n]", agenda[indice].nome); fflush(stdin); 
	
	printf("E-mail: ");
	scanf("%[^\n]", agenda[indice].email); fflush(stdin);
	 
	printf("Pais: ");
	scanf("%[^\n]", agenda[indice].pais); fflush(stdin);
	
	printf("Estado: ");
	scanf("%[^\n]", agenda[indice].estado); fflush(stdin);
	 
	printf("Cidade: ");
	scanf("%[^\n]", agenda[indice].cidade); fflush(stdin);
	 
	printf("Bairro: ");
	scanf("%[^\n]", agenda[indice].bairro); fflush(stdin);
	 
	printf("Rua: ");
	scanf("%[^\n]", agenda[indice].rua); fflush(stdin);
	
	printf("Cep: ");
	scanf("%d", &agenda[indice].cep); fflush(stdin);
	
	printf("DDD: ");
	scanf("%d", &agenda[indice].DDD); fflush(stdin);
	
	printf("Numero: ");
	scanf("%d", &agenda[indice].numero); fflush(stdin);
	
	printf("Data do aniversario: ");
	scanf("%d %d %d", &agenda[indice].dia,&agenda[indice].mes,&agenda[indice].ano); fflush(stdin);
	
	printf("Complemento: ");
	scanf("%[^\n]", agenda[indice].complemento); fflush(stdin);
	
	printf("Observacoes: ");
	scanf("%[^\n]", agenda[indice].observacoes); fflush(stdin);
	
	if(indice>=1){
		ordemalfabetica(agenda);	//Funcao para ordenar na ordem alfabetica, logo em seguida do cadastro.
	}
	
	indice++;	//Utilizacao da variavel global para armazenar os indices.

	system("pause");
}

void busca(Pessoa *agenda){
	int i,j,count;
	char nome[100];
	
	fflush(stdin);
	printf("Qual nome deseja buscar? ");
	scanf("%[^\n]", nome);
	printf("\n");
	
	for(i=0; i<100; i++){		//Percorrendo todo o array e comparando nome indicado pelo usuario com os dados salvados.
		j=0; count=0;
		while(agenda[i].nome[j]){
			if(nome[j]==agenda[i].nome[j]){
			count++;			//contador para a quantidades de letras iguais.
			}
			j++;
		}
		if(count==strlen(nome)){	//Se o contador for do mesmo tamanho da dimencao do nome, printar os enderecos.
			printf("Nome: %s\n", agenda[i].nome);
			printf("E-mail: %s\n", agenda[i].email);
			printf("Pais: %s\n", agenda[i].pais);
			printf("Estado: %s\n", agenda[i].estado);
			printf("Cidade: %s\n", agenda[i].cidade);
			printf("Bairro: %s\n", agenda[i].bairro);
			printf("Rua: %s\n", agenda[i].rua);
			printf("Cep: %d\n", agenda[i].cep);
			printf("DDD: %d\n", agenda[i].DDD);
			printf("Numero: %d\n", agenda[i].numero);
			printf("Data de aniversario: %d %d %d\n", agenda[i].dia,agenda[i].mes,agenda[i].ano);
			printf("Complemento: %s\n", agenda[i].complemento);
			printf("Observacoes: %s\n", agenda[i].observacoes);
			printf("-------------------------------------------------\n");
		}
	}
	system("pause");
}

void mesaniversario(Pessoa *agenda){
	int i,n;
	
	printf("Qual mes de aniversario deseja buscar? ");
	scanf("%d", &n);
	printf("\n");
	
	for(i=0; i<100; i++){
		if(n==agenda[i].mes){		//Comparacao do numero informado pelo usuario com os meses no array.
		    printf("Nome: %s\n", agenda[i].nome);
			printf("E-mail: %s\n", agenda[i].email);
			printf("Pais: %s\n", agenda[i].pais);
			printf("Estado: %s\n", agenda[i].estado);
			printf("Cidade: %s\n", agenda[i].cidade);
			printf("Bairro: %s\n", agenda[i].bairro);
			printf("Rua: %s\n", agenda[i].rua);
			printf("Cep: %d\n", agenda[i].cep);
			printf("DDD: %d\n", agenda[i].DDD);
			printf("Numero: %d\n", agenda[i].numero);
			printf("Data de aniversario: %d %d %d\n", agenda[i].dia,agenda[i].mes,agenda[i].ano);
			printf("Complemento: %s\n", agenda[i].complemento);
			printf("Observacoes: %s\n", agenda[i].observacoes);
			printf("-------------------------------------------------\n");
		}	
	}
	system("pause");
}

void aniversario(Pessoa *agenda){
	int i,dia,mes;
	
	printf("Digite o dia e o mes para buscar: ");
	scanf("%d %d", &dia,&mes);
	printf("\n");
	
	for(i=0; i<100; i++){
		if(dia==agenda[i].dia && mes==agenda[i].mes){		//Comparacao de dia e mes informados com o array.
			printf("Nome: %s\n", agenda[i].nome);
			printf("E-mail: %s\n", agenda[i].email);
			printf("Pais: %s\n", agenda[i].pais);
			printf("Estado: %s\n", agenda[i].estado);
			printf("Cidade: %s\n", agenda[i].cidade);
			printf("Bairro: %s\n", agenda[i].bairro);
			printf("Rua: %s\n", agenda[i].rua);
			printf("Cep: %d\n", agenda[i].cep);
			printf("DDD: %d\n", agenda[i].DDD);
			printf("Numero: %d\n", agenda[i].numero);
			printf("Data de aniversario: %d %d %d\n", agenda[i].dia,agenda[i].mes,agenda[i].ano);
			printf("Complemento: %s\n", agenda[i].complemento);
			printf("Observacoes: %s\n", agenda[i].observacoes);
			printf("-------------------------------------------------\n");
		}
	}
	system("pause");
}

void ordemalfabetica(Pessoa *agenda){	//Funcao chamada toda vez que um contato novo eh inserido.
	int i,j=0;
	Pessoa aux;
	
	while(j!=indice){	//Laco para organizar os nomes.	
		for(i=0; i<indice; i++){	//O indice possui o tamanho do array no momento.
			if(strcmp(agenda[i].nome, agenda[i+1].nome) > 0){ //Checando a ordem alfabetica, e fazendo a troca de posicoes.
				aux  = agenda[i];	
				agenda[i] = agenda[i+1];
				agenda[i+1] = aux;
			}
		}
		j++;
	}
}

void retirar(Pessoa *agenda){
	int i,pos;
	char n[50];
	
	printf("Qual contato deseja excluir? "); fflush(stdin);
	scanf("%[^\n]", n);
	
	for(i=0; i<indice; i++){
		if(strcmp(n, agenda[i].nome)==0){ //Comparacao do nome informado com o array.
			pos = i;	//Salvando a posicao do nome.
		}
	}
	for(i=pos; i<indice; i++){
		agenda[i] = agenda[i+1]; //Troca de posicoes que ocasionam o "deletar" da pessoa informada.
	}
	
	indice--;	//Diminuindo o tamanho do array, pois um contato foi excluido.
	system("pause");
}

void nome_tel_email(Pessoa *agenda){	//Printar os contatos somente com os dados de nome, telefone e e-mail.
	int i;
	
	printf("\n");
	for(i=0; i<indice; i++){
		printf("Nome: %s\n", agenda[i].nome);
		printf("Telefone: %d\n", agenda[i].numero);
		printf("E-mail: %s\n", agenda[i].email);
		printf("-------------------------------------------------\n");
	}
	system("pause");
}

void dados(Pessoa *agenda){		//Printar todos dados da agenda.
	int i;
	
	printf("\n");
	for(i=0; i<indice; i++){
			printf("Nome: %s\n", agenda[i].nome);
			printf("E-mail: %s\n", agenda[i].email);
			printf("Pais: %s\n", agenda[i].pais);
			printf("Estado: %s\n", agenda[i].estado);
			printf("Cidade: %s\n", agenda[i].cidade);
			printf("Bairro: %s\n", agenda[i].bairro);
			printf("Rua: %s\n", agenda[i].rua);
			printf("Cep: %d\n", agenda[i].cep);
			printf("DDD: %d\n", agenda[i].DDD);
			printf("Numero: %d\n", agenda[i].numero);
			printf("Data de aniversario: %d %d %d\n", agenda[i].dia,agenda[i].mes,agenda[i].ano);
			printf("Complemento: %s\n", agenda[i].complemento);
			printf("Observacoes: %s\n", agenda[i].observacoes);
			printf("-------------------------------------------------\n");
	}
	system("pause");
}
