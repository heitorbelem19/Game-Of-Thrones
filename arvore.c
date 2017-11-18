#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

Character* SalvarPersonagens(){
	
	FILE *arquivo = fopen("personagens.txt", "r");
	if(arquivo == NULL){
		printf("Impossivel abrir o arquivo\n");
		exit(1);
	}

	char *nome = (char *)malloc(sizeof(char)*1000);
	char *casa = (char *)malloc(sizeof(char)*1000);
	int agilidade,forca,inteligencia,saude;
	
	Character *vetorPersonagens = (Character *)malloc(sizeof(Character)*20); /*cada elemento desse vetor é uma Struct do tipo Character, que possui os atributos dos personagens*/
	int i=0; /*contador*/

	char ArquivoCompleto[10000]; /*vetor auxiliar que armazena o arquivo completo como uma unica string*/
	fscanf(arquivo,"%[^/]s",ArquivoCompleto);

	char *palavra;
	
	char quebra[4]; /*condições para separar os atributos de cada personagem: são "," , "Enter" ou "line feed" */
	quebra[0] = ',';
	quebra[1] = (char)10; /*line feed*/
	quebra[2] = (char)13; /*enter*/
	palavra = strtok(ArquivoCompleto, quebra); /*quebra a linha em outras linhas ao encontrar uma das condicoes para separar os atributos dos personagens*/

	int idx = 1;/*contador que vai definir onde armazenar cada parte da string nos atributos dos personagens*/
	while(palavra != NULL){
		if(idx != 1){/*remove o espaço que tem antes de cada palavra após a virgula*/
			for(int l = 0; palavra[l] != '\0'; l++)
				palavra[l] = palavra[l+1];
		}
		switch(idx){
			case 1:
				vetorPersonagens[i].name = palavra;
			break;
			case 2:
				vetorPersonagens[i].house = palavra;
			break;
			case 3:
				vetorPersonagens[i].agility = atoi(palavra);
			break;
			case 4:
        		vetorPersonagens[i].strength = atoi(palavra);
        	break;
        	case 5:
        		vetorPersonagens[i].intelligence = atoi(palavra);
        	break;
        	case 6:
        		vetorPersonagens[i++].health = atoi(palavra);
        	break;			
		}
		idx++;
		if(idx == 7) /*quando termina a linha, idx = 7, entao tem que retornar ele pra 1, para armazenar todos os atributos de cada linha*/
			idx = 1; 
	   	palavra = strtok (NULL,quebra);
	}

	fclose(arquivo);
	return vetorPersonagens;
}



Character* character_create(char* _name, char* _house, int _agility, int _strength, int _intelligence, int _health){
	
	Character *new_character = (Character *)malloc(sizeof(Character)); /*aloca memória para o personagem */
	new_character->name = (char *)malloc(sizeof(char)*1000);/*aloca memoria para o nome do personagem */
	new_character->house = (char *)malloc(sizeof(char)*1000);/*aloca memoria para a casa do personagem */
	new_character->name = _name; /*copia o atributo "Nome" para o novo personagem*/
	new_character->house = _house; /*copia o atributo "Casa" para o novo personagem*/
	new_character->agility = _agility; /*copia o atributo "Agilidade" para o novo personagem*/
	new_character->strength = _strength; /*copia o atributo "Força" para o novo personagem*/
	new_character->intelligence = _intelligence; /*copia o atributo "Inteligencia" para o novo personagem*/
	new_character->health = _health; /*copia o atributo "Saude" para o novo personagem*/
	
	return new_character; /*retorna o endereço do personagem criado*/
}



