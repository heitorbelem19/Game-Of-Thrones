#ifndef __ARVORE_H__
#define __ARVORE_H__ 

typedef struct character{

	char *name; /*nome do personagem (ALOCAR DINAMICAMENTE) */
	char *house; /*casa do personagem (ALOCAR DINAMICAMENTE) */
	int agility; /*agilidade (inteiro de 0-100) */
	int strength; /*força (inteiro de 0-100) */
	int intelligence; /*Inteligência (inteiro de 0-100) */
	int health; /*Saúde (inteiro de 0-100) */
}Character;

typedef struct {

	char *cu, *buceta;
}auxiliar;

typedef struct node{

	Character *character; /*Ponteiro para a struct que guarda os atributos dos personagens*/
	struct no *left; /*Ponteiro para o filho da esquerda*/
	struct no *right; /*Ponteiro para o filho da direita*/
}t_node;

typedef struct elemento{
	
	Character *character; /*Ponteiro para a struct que armazena os atributos dos personagens*/
	struct elemento *proximo; /*Ponteiro para o proximo elemento da lista*/
	struct elemento *anterior; /*Ponteiro para o elemento anterior da lista*/
}t_elemento;

typedef struct lista{
	
	t_elemento *inicio; /*Ponteiro para o primeiro elemento da lista*/
	t_elemento *fim; /*Ponteiro para o último elemento da lista*/
}t_lista;

Character* SalvarPersonagens();


Character* character_create(char* _name, char* _house, int _agility, int _strength, int _intelligence, int _health);


#endif
