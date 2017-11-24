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

void menu(){
 
    int op;
 
    system(CLEAR);
    printf("################################################\n");
    printf("################################################\n");
    printf("##    _____                               __  ##\n");
    printf("##   / ____|                             / _| ##\n");
    printf("##  | |  __  __ _ _ __ ____  ___    ___ | |_  ##\n");
    printf("##  | | |_ |/ _` | '_ ` _  \\/ _ \\  / _ \\|  _| ##\n");
    printf("##  | |__| | (_| | | | | | |  __/  |(_) | |   ##\n");
    printf("##  \\______|\\__,_|_| |_| |_|\\___|  \\___/|_|   ##\n");
    printf("##  _______ _                                 ##\n");
    printf("## |__   __| |                                ##\n");
    printf("##    | |  | |__  _ __ ____  _ ___  ___  ___  ##\n");
    printf("##    | |  | '_ \\| '__/  _ \\| '_  \\/ _ \\/ __| ##\n");
    printf("##    | |  | | | | |  | (_) | | | |  __/\\__ \\ ##\n");
    printf("##    |_|  |_| |_| |  \\____/|_| |_|\\___||___/ ##\n");
    printf("##                                            ##\n");
    printf("################################################\n");
    printf("################################################\n");
    printf("              By: Karan & Heitor                \n");
    printf("\n");

    printf("[1] Start New Game\n");
    printf("[2] Quit\n");
    scanf("%d" , &op);
    switch(op){
        case 1:
            
        default:
            exit(-1);
    }
}

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

t_lista* CriaLista(){
	
	t_lista *lista = (t_lista *)malloc(sizeof(t_lista));
	lista->inicio = NULL;
	lista->fim = NULL;

	return lista;
}

int Verifica(int vetor[],int valor){
    /*Essa função compara os valores obtidos aleatoriamente para ver se não possui nenhum valor repetido,se não possuir, retorna 1*/
    int i;
    for(i = 0; i < 16; i++){
        if(vetor[i] == valor){
            return 0;
        }
    }
    return 1;
}
 
void InserirInicio(Character *vetor, t_lista* lista){
    
    int v[16];/*vetor que vai armazenar os valores aleatórios*/
    int random;/*índice aleatorio*/
    srand(time(NULL));/*inicializa a função randômica*/
    int rodados[16];
    int j = 0, x;
    for(x = 0; x < 16; x++){
        v[x] = (rand() % 20);/*obtém valores de 0 a 19*/
        if(Verifica(rodados, v[x]) == 1){
            random = v[x];
            t_elemento *new_element = (t_elemento *)malloc(sizeof(t_elemento));
            new_element->proximo = NULL;
            new_element->anterior = NULL;
            new_element->character = (Character *)malloc(sizeof(Character));
            new_element->character = character_create(vetor[random].name,vetor[random].house,vetor[random].agility,vetor[random].strength,vetor[random].intelligence,vetor[random].health);
            if(lista->inicio == NULL){
                lista->inicio = new_element;
                lista->fim = new_element;
            }
            else{
                lista->inicio->anterior = new_element;
                new_element->proximo = lista->inicio;
                lista->inicio = new_element;
            }
            rodados[j] = random;
            j++;
        }
        else{
            x--;
        }
    }
}

void Printar_Personagens(t_lista *lista){

	int i, random;
	t_elemento *ptr = (t_elemento *)malloc(sizeof(t_elemento));
	ptr = lista->inicio;
	srand(time(NULL));/*inicializa a função randômica*/
	for(i = 0; i < 16; i++){
		random = (rand() % 4) + 1;
		printf("Personagem %d:\n",(i+1));
		switch(random){
			case 1:
				printf("Agility: %d  Strength: ??  Intelligence: ??  Health: ??\n\n",ptr->character->agility);
			break;
			case 2:
				printf("Agility: ??  Strength: %d  Intelligence: ??  Health: ??\n\n",ptr->character->strength);
			break;
			case 3:
				printf("Agility: ??  Strength: ??  Intelligence: %d  Health: ??\n\n",ptr->character->intelligence);
			break;
			case 4:
				printf("Agility: ??  Strength: ??  Intelligence: ??  Health: %d\n\n",ptr->character->health);
			break;
		}
	ptr = ptr->proximo;
	}
}

t_node* tree_create(){

	t_node* root = (t_node *)malloc(sizeof(t_node));
	root->character = NULL;
	root->right = NULL;
	root->left = NULL;

	return root;
}

t_node* Insere_No(t_node* root){
	if(root == NULL){
		return tree_create();
	}
	else{
		root->left = Insere_No(root->left);
		root->right = Insere_No(root->right);
	}
	return root;
}

void Character_Transfer(t_node* root, t_lista *lista){
   	
   	int i;
    if(root != NULL){
        Character_Transfer(root->left,lista);       
        Character_Transfer(root->right,lista);
		if(root->left == NULL || root->right == NULL){
		   	root->character = BuscaElemento(i,lista);    
	    	i++;
	    }
    i = 0;
    }
    
}

Character* BuscaElemento(int posicao, t_lista *lista){

	t_elemento *aux = lista->inicio ;
	for(int i = 0; i < posicao; i++){
		aux = aux->proximo;
	}
	return aux->character;
}

void tree_print_preorder(t_node* root){
    
    if(root != NULL){
        if(root->left == NULL || root->right == NULL)
        	printf("%s\n", root->character->name);
        tree_print_preorder(root->left);
        tree_print_preorder(root->right);
    }
}
