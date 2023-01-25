#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define texto1 "Jogo da velha para duas pessoas by Lakke:"

//Prot�tipo do mapa do tabuleiro
void tabuleiro(); 

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	printf("%s\n\n", texto1);	
	
//Vari�veis das posi��es do tabuleiro (char) e escolha do jogador(int)
	char var[9], simbolo, nomejog1[20], nomejog2[20];
	int y, jogador = 1, escolha, rodada = 1, jogadas = 0, vitoria = 0, repet=0;
	
	var[0] = ' ';
	var[1] = ' ';
	var[2] = ' ';
	var[3] = ' ';
	var[4] = ' ';
	var[5] = ' ';
	var[6] = ' ';
	var[7] = ' ';
	var[8] = ' ';
	

	printf("Jogador 1, digite seu nick:\n");
	gets(nomejog1);
	fflush(stdin);
	
	printf("\nJogador 2, digite seu nick:\n");
	gets(nomejog2);
	fflush(stdin);
	
	system("cls");
	
	tabuleiro();
	
	do{	//Repeti��o para definir fim do jogo	
	
		printf("RODADA %d\n\n", rodada);
		
		if(jogador==2){//Contagem de rodadas para finalizar o jogo em caso de empate
			rodada++;
			}			
	
			for(repet=1; repet>0; ){ //La�o de troca de jogador	
										
				if(jogador==1){     //Defini��o de s�mbolo entre jogador 1(x) e jogador 2 (o)
					simbolo='x';
					printf("%s, escolha o n�mero onde voc� quer jogar:\n", nomejog1);	//escolha da posi��o no tabuleiro
					}
					else if(jogador==2){
					simbolo='o';
					printf("%s, escolha o n�mero onde voc� quer jogar:\n", nomejog2);	//escolha da posi��o no tabuleiro					
				}
											
					scanf("%d", &escolha);
					fflush(stdin);	
					escolha = escolha -1;
					y = escolha;					
						
							if(escolha < 0 || escolha > 8){			//critia de erro caso algum numero q n exista seja escolhido				
								printf("\nDigite apenas o n�mero referente � casa q vc escolheu\n\n");							
								continue;
							}
							
							if (escolha == y){
								
								if (var[y] == 'x' || var[y] == 'o'){    //cr�tica de erro caso os jogadores escolham uma casa q j� foi escolhida
									printf("\nJOGADOR %d, a casa %d ja foi escolhida, selecione outra:\n\n", jogador, y);
									continue;
																						
									}else{		//caso seja uma jogada v�lida aqui tem a aloca��o do s�mbolo no tabuleiro, a repeti��o para o pr�ximo jogador e a soma de uma jogada q no m�ximo s�o 9 para finalizar como empate.
										var[y] = simbolo;
										repet = 0;							
										jogadas++;
										
										//Cr�tica de vit�ria caso algum jogador ven�a a partida				
										if((var[0] == simbolo) && (var[1] == simbolo) && (var[2] == simbolo)||(var[3] == simbolo) && (var[4] == simbolo) && (var[5] == simbolo)||(var[6] == simbolo) && (var[7] == simbolo) && (var[8] == simbolo)||(var[0] == simbolo) && (var[3] == simbolo) && (var[6] == simbolo)||(var[1] == simbolo) && (var[4] == simbolo) && (var[7] == simbolo)||(var[2] == simbolo) && (var[5] == simbolo) && (var[8] == simbolo)||(var[0] == simbolo) && (var[4] == simbolo) && (var[8] == simbolo)||(var[2] == simbolo) && (var[4] == simbolo) && (var[6] == simbolo)){ 
																						
											jogadas+=10;
											vitoria++;										
										}
											if(jogador==1){	//troca de jogador
												jogador++;
												}
												else if (jogador==2){
												jogador--;
													}
										}			
								}						
				}			
							system("cls");
							
								//Chamando a fun��o tabuleiro
								tabuleiro();
	
							printf("     |     |     \n");
							printf("  %c  |  %c  |  %c \n", var[6], var[7], var[8]);
							printf("_____|_____|_____\n");
							printf("     |     |     \n");
							printf("  %c  |  %c  |  %c \n", var[3], var[4], var[5]);
							printf("_____|_____|_____\n");
							printf("     |     |     \n");
							printf("  %c  |  %c  |  %c \n", var[0], var[1], var[2]);
							printf("     |     |     \n\n");

	}while(jogadas<9);	
	
		if(vitoria==1){		
			if(jogador == 2){		//Declaracao do vencedor
				printf("\n%s VENCEU O JOGO!\n\n", nomejog1);
			}else if(jogador ==1){
				printf("\n%s VENCEU O JOGO!\n\n", nomejog2);
				}				
		}else if(vitoria==2){	//Cr�tica de empate
			}else{
				printf("%s e %s VCS EMPATARAM!\n\n", nomejog1, nomejog2);
			}
	system("pause");
}

void tabuleiro(){
	printf("     |     |     \n");
	printf("  7  |  8  |  9  \n");
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  4  |  5  |  6  \n");
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  1  |  2  |  3  \n");
	printf("     |     |     \n\n\n");
}
