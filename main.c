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
	t_node* arvore;
	t_lista *ListaCharacter = CriaLista();
	InserirInicio(Personagens,ListaCharacter);
	Printar_Personagens(ListaCharacter);
	arvore = Insere_No(arvore);
	arvore = Insere_No(arvore);
	arvore = Insere_No(arvore);
	arvore = Insere_No(arvore);
	arvore = Insere_No(arvore);
	Character_Transfer(arvore,ListaCharacter,1);
	tree_print_preorder(arvore);
	

    return 0;
}
