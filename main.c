#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvore.h"

int main(){

	Character *Personagens = (Character *)malloc(sizeof(Character)*20);
	Personagens = SalvarPersonagens();

    for(int i=0;i<20;i++){
    	printf("%s, %s, %d, %d, %d, %d\n", Personagens[i].name, Personagens[i].house,Personagens[i].agility, Personagens[i].strength, Personagens[i].intelligence, Personagens[i].health);
    }

    return 0;
}
