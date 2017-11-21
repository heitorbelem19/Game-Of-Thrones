#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "arvore.h"

int main(){

	Character *Personagens = SalvarPersonagens();
	int x = 0;
	t_lista *ListaCharacter = CriaLista(); 
	InserirInicio(Personagens,ListaCharacter);
	Printar_Lista(ListaCharacter);
	
    return 0;
}
