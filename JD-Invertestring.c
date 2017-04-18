#include<stdio.h>

void inverte_string(char *v);

int main(){
	
	char v[100];
	
	printf("Digite uma string: ");
	scanf("%[^\n]", v);
	
	printf("Inversa da string: ");
	inverte_string(v);
	
	return 0;
}

void inverte_string(char *v){
	if(*v){
		inverte_string(v+1);
	}
	else {
		return;
	}
	printf("%c", *v);	
}
