#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arvore.h"
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int main(){
	
	Character *Personagens = SalvarPersonagens();
	int x = 0;
	int altura;
	t_node* arvore;
	t_lista *ListaCharacter = CriaLista();
	InserirInicio(Personagens,ListaCharacter);
	Printar_Personagens(ListaCharacter);
	arvore = tree_create();
	arvore = Insere_No(arvore);
	arvore = Insere_No(arvore);
	arvore = Insere_No(arvore);
	arvore = Insere_No(arvore);
	altura = height(arvore);
	printf("%d\n",altura);
	pos_order(arvore,ListaCharacter);
	pre_order(arvore);
    return 0;
}
