#include<stdio.h>
#include<string.h>

int main(){
	
	int i,j,k=0;
	char maior[300], menor[50];
	
	printf("Digite a string maior: ");
	gets(maior);
	printf("Digite a string menor: ");
	gets(menor);
	
	for(i=0; i<strlen(maior); i++){	
		if(maior[i] == menor[0]){		//Percorrendo a string ate achar a primeira letra compativel em ambas.
			j=0;
			while(menor[j] == maior[i+j] && menor[j]){		//Ao tornar-se verdadeira tal afirmacao, a string entra em um laco para compara-las por intiero ate seu final.
				++j;
				if(menor[j] == '\0'){
					++k;
				}
			}
		}
	}
	
	printf("\n");
	printf("A string menor aparece %d vez(es)\n", k);
	
	return 0;
}
