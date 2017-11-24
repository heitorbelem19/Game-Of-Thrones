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

typedef struct elemento{
	
	Character *character; /*Ponteiro para a struct que armazena os atributos dos personagens*/
	struct elemento *proximo; /*Ponteiro para o proximo elemento da lista*/
	struct elemento *anterior; /*Ponteiro para o elemento anterior da lista*/
}t_elemento;

typedef struct lista{
	
	t_elemento *inicio; /*Ponteiro para o primeiro elemento da lista*/
	t_elemento *fim; /*Ponteiro para o último elemento da lista*/
}t_lista;

typedef struct node{

	Character *character; /*Ponteiro para a struct que guarda os atributos dos personagens*/
	struct node *left; /*Ponteiro para o filho da esquerda*/
	struct node *right; /*Ponteiro para o filho da direita*/
}t_node;

void menu();
void jogo();

Character* SalvarPersonagens();

Character* character_create(char* _name, char* _house, int _agility, int _strength, int _intelligence, int _health);
t_lista* CriaLista();
int Verifica(int vetor[],int valor);
void InserirInicio(Character *vetor, t_lista* lista);
void Printar_Personagens(t_lista *lista);

t_node* tree_create();
t_node* Insere_No(t_node* root);
void Character_Transfer(t_node* root, t_lista *lista);
void  tree_print_preorder(t_node* root);
Character* BuscaElemento(int posicao, t_lista *lista);

#endif
