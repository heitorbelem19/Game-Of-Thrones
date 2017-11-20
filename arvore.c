#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arvore.h"

Character* SalvarPersonagens(){
	
	FILE *arquivo = fopen("personagens.txt", "r");
	if(arquivo == NULL){
		printf("Impossivel abrir o arquivo\n");
		exit(1);
	}

	char *nome = (char *)malloc(sizeof(char)*100);
	char *casa = (char *)malloc(sizeof(char)*100);
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

t_node* tree_create(){

	t_node *tree = (t_node*)malloc(sizeof(t_node));
	tree->character = NULL;
	tree->left = NULL;
	tree->right = NULL;

	return tree;
}

t_lista* CriaLista(){
	
	t_lista *lista = (t_lista *)malloc(sizeof(t_lista));
	lista->inicio = NULL;
	lista->fim = NULL;

	return lista;
}


void InserirInicio(Character *vetor, t_lista* lista){
	
	t_elemento *new_element = (t_elemento *)malloc(sizeof(t_elemento));
	new_element->proximo = NULL;
	new_element->anterior = NULL;
	new_element->character->name = vetor->name;
	new_element->character->house = vetor->house;
	new_element->character->agility = vetor->agility;
	new_element->character->strength = vetor->strength;
	new_element->character->intelligence = vetor->intelligence;
	new_element->character->health = vetor->health;
	 
	if(lista->inicio == NULL){
		lista->inicio = new_element;
		lista->fim = new_element;
	}
	else{
		lista->inicio->anterior = new_element;
		new_element->proximo = lista->inicio;
		lista->inicio = new_element;
	}
}

t_lista* ListaPersonagem(Character *vetor){

	t_lista *ListaCharacter = CriaLista();
	int i,x;

	for(i=0;i<16;i++){
		srand((unsigned)time(NULL));
		x = rand() % 16;
		Character *novo;
		novo = character_create(vetor[x].name, vetor[x].house, vetor[x].agility, vetor[x].strength, vetor[x].intelligence, vetor[x].health);
		InserirInicio(novo, ListaCharacter);
	}

	return ListaCharacter;
}

void Printar_Lista(t_lista* lista){
	t_elemento* ptr = lista->inicio;
	if(lista->inicio == NULL){
		printf("LISTA VAZIA!\n");
		return;
	}
	while(ptr != NULL){
		printf("%s, %s, %d, %d, %d, %d\n",ptr->character->name, ptr->character->house, ptr->character->agility, ptr->character->strength, ptr->character->intelligence, ptr->character->health);
		ptr = ptr->proximo;
	}
}



