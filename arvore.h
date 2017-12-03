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

void menu();/*Função que apresenta o menu inicial do jogo*/
void jogo();/*Função que executa todo o jogo*/

Character* SalvarPersonagens();/*Função que lê o arquivo e armazena em um vetor do tipo Character*/

Character* character_create(char* _name, char* _house, int _agility, int _strength, int _intelligence, int _health); /*Aloca espaço na memoria para um novo personagem e seta seus atributos*/
t_lista* CriaLista();/*Cria lista vazia*/
int Verifica(int vetor[],int valor); /*verifica se o indice randomico do vetor ja foi selecionado alguma vez*/
void InserirInicio(Character *vetor, t_lista* lista); /*insere um novo personagem no inicio da lista duplamente encadeada, aleatoriamente do arquivo*/
void Printar_Personagens(t_lista *lista); /*Printa os personagens escondendo os atributos e os seus respectivos nomes*/

t_node* tree_create(); /*Cria um no raiz, apontando seus ponteiros esquerda, direita e character para NULL*/
t_node* Insere_No(t_node* root); /*insere um novo Nó na árvore*/
void Character_Transfer(t_node* root, t_lista *lista, int i); /*Faz os nós folhas apontarem para os personagens da lista duplamente encadeada*/
void  tree_print_preorder(t_node* root); /*printa a árvore utilizando o algoritmo de pre-ordem*/
Character* BuscaPersonagem(int posicao, t_lista *lista); /*busca o elemento na lista duplamente encadeada para que a folha da arvore possa apontar para esse personagem tambem*/
Character* fight(Character* fighter_one, Character* fighter_two, int atribute);

void character_free(Character* character);
void tree_free(t_node* tree);


#endif
