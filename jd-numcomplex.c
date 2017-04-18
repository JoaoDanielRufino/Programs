#include<stdio.h>
#include<math.h>
#include<conio.h>

typedef struct complexo{
	float x,y;
}Complexos;

int menu();
void mudulo(Complexos c1);
void adicao(Complexos c1, Complexos c2);
void subtracao(Complexos c1, Complexos c2);
void multiplicacao(Complexos c1, Complexos c2);
void divisao(Complexos c1, Complexos c2);

int main(){
	
	Complexos c1,c2;
	int opcao;
	while(1){
		fflush(stdin);
		opcao = menu();
		if(opcao==1) modulo(c1);
		if(opcao==2) adicao(c1,c2);
		if(opcao==3) subtracao(c1,c2);
		if(opcao==4) multiplicacao(c1,c2);
		if(opcao==5) divisao(c1,c2);
		if(opcao==6){
			printf("\nSaindo....\n");
			break;
		}
	
	}
	return 0;
}

int menu(){	//Menu de opcoes.
	int opcao;
	
	system("cls");
	printf("[1] - Modulo\n");
	printf("[2] - Adicao\n");
	printf("[3] - Subtracao\n");
	printf("[4] - Multiplicacao\n");
	printf("[5] - Divisao\n");
	printf("[6] - Sair\n");
	printf("Escolha uma opcao: ");
	scanf("%d", &opcao);
	return opcao;
}

void modulo(Complexos c1){	//Calculo do modulo.
	float z;
	char i[10];
	
	printf("\n");
	printf("Escreva na forma: a+bi\n");
	printf("Digite o numero complexo: ");
	scanf("%f %f %s", &c1.x, &c1.y, i);
	
	z = sqrt(pow(c1.x,2)+pow(c1.y,2));
	printf("Modulo = %.4f\n\n", z);
	
	system("pause");
}

void adicao(Complexos c1, Complexos c2){
	float soma1,soma2;
	char i[10];
	
	printf("\n");
	printf("Adicao:\n");
	printf("Escreva na forma: a+bi\n");
	printf("Digite o primeiro numero complexo: ");
	scanf("%f %f %s", &c1.x, &c1.y, i);fflush(stdin);
	printf("Digite o segundo numero complexo: ");
	scanf("%f %f %s", &c2.x, &c2.y, i);fflush(stdin);
	
	soma1 = c1.x + c2.x;	//Soma dos termos reais.
	soma2 = c1.y + c2.y;	//Soma dos termos imaginarios.
	
	if(soma2>=0) printf("Adicao = %.2f+%.2fi\n\n", soma1,soma2); //Ajustando o sinal no print.
	if(soma2<0)	printf("Adicao = %.2f%.2fi\n\n", soma1,soma2);
	
	system("pause");
}

void subtracao(Complexos c1, Complexos c2){
	float sub1,sub2;
	char i[10];
	
	printf("\n");
	printf("Subtracao:\n");
	printf("Escreva na forma: a+bi\n");
	printf("Digite o primeiro numero complexo: ");
	scanf("%f %f %s", &c1.x, &c1.y, i);fflush(stdin);
	printf("Digite o segundo numero complexo: ");
	scanf("%f %f %s", &c2.x, &c2.y, i);fflush(stdin);
	
	sub1 = c1.x - c2.x;	//Subtracao dos numeros reais.
	sub2 = c1.y - c2.y;	//Subtracao dos numeros imaginarios.
	
	if(sub2>=0) printf("Subtracao = %.2f+%.2fi\n\n", sub1,sub2); //Ajustando o sinal do print.
	if(sub2<0)	printf("Subtracao = %.2f%.2fi\n\n", sub1,sub2);
	
	system("pause");
}

void multiplicacao(Complexos c1, Complexos c2){
	float mult1,mult2;
	char i[10];
	
	printf("\n");
	printf("Multiplicacao:\n");
	printf("Escreva na forma: a+bi\n");
	printf("Digite o primeiro numero complexo: ");
	scanf("%f %f %s", &c1.x, &c1.y, i);fflush(stdin);
	printf("Digite o segundo numero complexo: ");
	scanf("%f %f %s", &c2.x, &c2.y, i);fflush(stdin);
	
	mult1 = (c1.x * c2.x) - (c1.y * c2.y);
	mult2 = (c1.x * c2.y) + (c1.y * c2.x);
	
	if(mult2>=0) printf("Multiplicacao = %.2f+%.2fi\n\n", mult1,mult2); //Ajustando o sinal.
	if(mult2<0)	printf("Multiplicacao = %.2f%.2fi\n\n", mult1,mult2);
	
	system("pause");	
}

void divisao(Complexos c1, Complexos c2){
	float div1,div2;
	char i[10];
	
	printf("\n");
	printf("Divisao:\n");
	printf("Escreva na forma: a+bi\n");
	printf("Digite o primeiro numero complexo: ");
	scanf("%f %f %s", &c1.x, &c1.y, i);fflush(stdin);
	printf("Digite o segundo numero complexo: ");
	scanf("%f %f %s", &c2.x, &c2.y, i);fflush(stdin);
	
	div1 = ((c1.x * c2.x) + (c1.y * c2.y))/(pow(c2.x,2) + pow(c2.y,2));
	div2 = ((c1.y * c2.x) - (c1.x * c2.y))/(pow(c2.x,2) + pow(c2.y,2));
	
	if(div2>=0) printf("Divisao = %.2f+%.2fi\n\n", div1,div2); //Ajustando o sinal.
	if(div2<0)	printf("Divisao = %.2f%.2fi\n\n", div1,div2);
	
	system("pause");	
}



