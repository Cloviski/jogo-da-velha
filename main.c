/*
 Falta fazer:
 - Não deixar que os usuários digitem letras nas coordenadas
 - Não deixar que os jogadores tenham o mesmo nome
 - Não deixar que os usuários enviem ' ' no lugar do nome ou das coordenadas
 - Otimizar o código
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM_MAT 4
#define TAM_NAME 20
#define OK 200
#define FAIL 418
char tab[TAM_MAT][TAM_MAT];
void name(char ply1[TAM_NAME], char ply2[TAM_NAME]);
void newTab(void);
void exibeTab();
int marca(int lin, int col, int vez);
int vitoria(int lin, int col);
int main(void){
	int vez=2, lin=0, col=0, ctr=FAIL, z=0;
	char ply1[TAM_NAME], ply2[TAM_NAME];
	setlocale(LC_ALL, "Portuguese_Brazil");
	name(ply1, ply2);
	newTab();
	while(ctr == FAIL && z<9){
		vez == 1 ? vez++ : vez--;
		do{
			system("clear");
			exibeTab();
			printf("\n\n Vez de %s jogar!", vez == 1 ? ply1 : ply2);
			printf("\n Defina a linha: ");
			scanf("%d", &lin);
			printf(" Defina a coluna: ");
			scanf("%d", &col);
		} while(marca(lin, col, vez) == FAIL);
		z++;
		if (z > 4){
			ctr = vitoria(lin, col);
		}
	}
	system("clear");
	exibeTab();
	printf(ctr == FAIL ? "\n\n Deu velha!\n" : 
		"\n\n Parabéns, %s, você ganhou!\n", (vez == 1 ? ply1 : ply2));
	return 0;
}
void name(char ply1[TAM_NAME], char ply2[TAM_NAME]){
	scanf("%s %s", ply1, ply2);
}
void newTab(void){
	int i, a;
	for(i=1; i<TAM_MAT; i++){
		tab[0][i] = i + '0';
		tab[i][0] = i + '0';
	}
	for(i=1; i<TAM_MAT; i++){
		for(a=1; a<TAM_MAT; a++){
			tab[i][a] = ' ';
		}
	}
	tab[0][0] = ' ';
}
void exibeTab(){
	int i, a;
	for(i=0; i<TAM_MAT; i++){
		printf("   ");
		for(a=0; a<TAM_MAT; a++){
			printf("%c", tab[i][a]);
			printf( a != TAM_MAT-1 ? "|" : "");
		}
		printf( i != TAM_MAT-1 ? "\n  ----------\n" : "");
	}
}
int marca(int lin, int col, int vez){
	if(tab[lin][col] != ' ' || (lin>=TAM_MAT || col >= TAM_MAT)){
		return FAIL;
	}
	tab[lin][col] = (vez == 1 ? 'X' : 'O');
	return OK;
}
int vitoria(int lin, int col){
	int nLin=1, nCol=1, nDp=1, nDs=1,i;
	for(i=1; i<TAM_MAT; i++){
		if(tab[lin][col] == tab[lin][i] && col != i){
			nLin++;
		}
		if(tab[lin][col] == tab[i][col] && lin != i){
			nCol++;
		}
	}
	if (nLin == 3 || nCol == 3){
		return OK;
	}
	else if(lin == col || ( (lin * 3) == col || lin == (col * 3))){
		for(i=1; i<TAM_MAT; i++){
			if(tab[lin][col] == tab[i][i] && lin != i){
				nDp++;
			}
			if(tab[lin][col] == tab[i][TAM_MAT-i] && lin != i){
				nDs++;
			}
		}
	}
	if (nDp == 3 || nDs == 3){
		return OK;
	}
	else{
		return FAIL;
	}
}
