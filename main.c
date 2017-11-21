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
	t_lista *ListaCharacter = CriaLista(); 
	InserirInicio(Personagens,ListaCharacter);
	Printar_Personagens(ListaCharacter);
	
	
    return 0;
}
