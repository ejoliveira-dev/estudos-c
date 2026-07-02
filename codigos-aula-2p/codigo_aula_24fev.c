// Aula  de Engenharia de Software.
// Este arquivo focará em usar o código apresentado em aula e destrinchá-lo/estudá-lo, adicionando anotações explicando cada pedaço.


// é aqui, no início do código que adicionamos as bibliotecas/ferramentas que o programa vai usar; tipo um "cabeçalho".

#include <stdio.h> // standart i/o: permite usar 'printf'(saída) e 'fgets' (entrada de linha inteira).
#include <string.h> // String Handling: usa a função 'strcspn' (string complement span; acha a posição do caractere que se quer remover) para limpar textos.

#define MAX_REQS 5 // aqui estamos criando uma "constante". no momento, o programa aceita 5 requsitos. 
#define MAX_LEN 100 // aqui determinamos o máximo de tamanho que cada frase/texto digitado pode ter.

int main() { // corpo principal; bloco de processamento fica a partir dessa chave;
    // [DECLARANDO AS VARIÁVEIS]
     char nomeProgramador[100]; // na prática, a conta nesse vetor só vai até 99 letras.
     char dataRequisitos[50];
    
     char reqs_funcionais[MAX_REQS][MAX_LEN]; // isso é uma matriz usando as constantes anteriores;
     // imagine uma tabela com 5 requisitos e 100 letras para cada frase sobre.
     char reqs_nao_funcionais[MAX_REQS][MAX_LEN];
     int i;

     printf("-   CADASTRO DE REQUISITOS.  -\n");
     printf("----------------------------------\n");
     printf(" Sistema Criado Por Sidney Cunha\n");
     printf("----------------------------------\n\n");
     printf("Por favor, digite o nome do programador: ");
     fgets(nomeProgramador, sizeof(nomeProgramador), stdin);
     // como dito antes, 'scanf' só lê até o primeiro espaço e 'fgets' lê a linha inteira, assim incluindo os espaços de um nome.
     nomeProgramador[strcspn(nomeProgramador, "\n")] = '\0'; // isso aqui faz com que o nome fique "limpo" sem nenhum '\n'.

     printf("Por favor, digite a data de levantamento dos requisitos (dd/mm/aaaa): ");
     fgets(dataRequisitos, sizeof(dataRequisitos), stdin);
     dataRequisitos[strcspn(dataRequisitos, "\n")] = '\0';
    
     printf("\n--- Detalhes do Projeto ---\n");
     printf("Programador: %s\n", nomeProgramador);
     printf("Data dos Requisitos: %s\n", dataRequisitos);
     printf("---------------------------\n");

     printf("\n## Requisitos Funcionais\n"); // aqui embaixo basicamente diz: começamos a contar a partir do zero, o laço roda enquanto o i for menor que 5 e guardamos o que foi adicionado na gaveta número 'i' da matriz.
     for (i = 0; i < MAX_REQS; i++) {
         printf("Digite o requisito funcional #%d: ", i + 1);
         fgets(reqs_funcionais[i], MAX_LEN, stdin);
         reqs_funcionais[i][strcspn(reqs_funcionais[i], "\n")] = '\0'; // remove o \n.
     }

     printf("\n## Requisitos Nao Funcionais\n");
     for (i = 0; i < MAX_REQS; i++) {
         printf("Digite o requisito nao funcional #%d: ", i + 1);
         fgets(reqs_nao_funcionais[i], MAX_LEN, stdin);
         reqs_nao_funcionais[i][strcspn(reqs_nao_funcionais[i], "\n")] = '\0'; // remove o \n.
     }

     printf("\n--- Requisitos Cadastrados ---\n");
 
     printf("\nProgramador: %s\n", nomeProgramador);
     printf("Data dos Requisitos: %s\n", dataRequisitos);

     printf("\n## Requisitos Funcionais\n");
     for (i = 0; i < MAX_REQS; i++) {
         printf("%d. %s\n", i + 1, reqs_funcionais[i]);
     }

     printf("\n## Requisitos Nao Funcionais\n");
     for (i = 0; i < MAX_REQS; i++) {
         printf("%d. %s\n", i + 1, reqs_nao_funcionais[i]); 
     } // '%d' é substituido pelo número do item (i + 1), e '%s' (usado para cadeias de caracteres) pelo texto do requisito.

     return 0;
}