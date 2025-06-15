#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include<locale.h>

#define NUM_COLUNAS 5
#define ALTURA_MAXIMA 10
#define NUM_TIPOS_BLOCOS 3

typedef struct Bloco {
    char tipo;             
    struct Bloco* abaixo;   
} Bloco;

typedef struct {
    Bloco* topo;            
    int altura;             
} Pilha;

typedef struct {
    Pilha colunas[NUM_COLUNAS];
    int pontuacao;              
    int linhas_eliminadas;      
    bool game_over;            
} Jogo;

void inicializar_jogo(Jogo* jogo) {
    jogo->pontuacao = 0;
    jogo->linhas_eliminadas = 0;
    jogo->game_over = false;

    for (int i = 0; i < NUM_COLUNAS; i++) {
        jogo->colunas[i].topo = NULL;
        jogo->colunas[i].altura = 0;
    }
}

Bloco* criar_bloco(char tipo) {
    Bloco* novo = (Bloco*)malloc(sizeof(Bloco));
    if (novo == NULL) {
        printf("Erro ao alocar memória para bloco!\n");
        exit(1);
    }
    novo->tipo = tipo;
    novo->abaixo = NULL;
    return novo;
}

bool empilhar_bloco(Jogo* jogo, int coluna, char tipo) {
    if (coluna < 0 || coluna >= NUM_COLUNAS) {
        return false;
    }

    if (jogo->colunas[coluna].altura >= ALTURA_MAXIMA) {
        jogo->game_over = true;
        return false;
    }

    Bloco* novo = criar_bloco(tipo);
    novo->abaixo = jogo->colunas[coluna].topo;
    jogo->colunas[coluna].topo = novo;
    jogo->colunas[coluna].altura++;

    return true;
}

char desempilhar_bloco(Jogo* jogo, int coluna) {
    if (coluna < 0 || coluna >= NUM_COLUNAS || jogo->colunas[coluna].topo == NULL) {
        return '\0';
    }

    Bloco* topo = jogo->colunas[coluna].topo;
    char tipo = topo->tipo;
    jogo->colunas[coluna].topo = topo->abaixo;
    jogo->colunas[coluna].altura--;
    free(topo);

    return tipo;
}

void verificar_linhas(Jogo* jogo) {
    bool linha_completa = true;
    int altura_minima = ALTURA_MAXIMA;

    for (int i = 0; i < NUM_COLUNAS; i++) {
        if (jogo->colunas[i].altura < altura_minima) {
            altura_minima = jogo->colunas[i].altura;
        }
    }

    if (altura_minima > 0) {
        for (int i = 0; i < NUM_COLUNAS; i++) {
            if (jogo->colunas[i].altura > 0) {
                desempilhar_bloco(jogo, i);
            }
        }

        jogo->linhas_eliminadas++;
        jogo->pontuacao += NUM_COLUNAS * 10;
    }
}

void exibir_tabuleiro(Jogo* jogo) {
    printf("\n=== STACKTRIS === Pontuação: %d Linhas Eliminadas: %d ===\n",
           jogo->pontuacao, jogo->linhas_eliminadas);

    int altura_maxima_atual = 0;
    for (int i = 0; i < NUM_COLUNAS; i++) {
        if (jogo->colunas[i].altura > altura_maxima_atual) {
            altura_maxima_atual = jogo->colunas[i].altura;
        }
    }

    for (int linha = altura_maxima_atual; linha >= 0; linha--) {
        for (int col = 0; col < NUM_COLUNAS; col++) {
            if (linha < jogo->colunas[col].altura) {
                Bloco* atual = jogo->colunas[col].topo;
                for (int i = 0; i < (jogo->colunas[col].altura - linha - 1); i++) {
                    atual = atual->abaixo;
                }
                printf(" %c ", atual->tipo);
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    for (int col = 0; col < NUM_COLUNAS; col++) {
        printf("[%d]", col);
    }
    printf("\n");
}

char gerar_bloco_aleatorio() {
    char tipos[NUM_TIPOS_BLOCOS] = {'#', 'w', 'r'};
    return tipos[rand() % NUM_TIPOS_BLOCOS];
}

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    Jogo jogo;
    inicializar_jogo(&jogo);

    printf("=== BEM-VINDO AO STACKTRIS ===\n");
    printf("Instruções:\n");
    printf("- Digite o número da coluna (0-%d) para colocar o bloco\n", NUM_COLUNAS-1);
    printf("- O jogo acaba quando uma coluna atingir altura %d\n", ALTURA_MAXIMA);
    printf("- Linhas completas são eliminadas automaticamente\n");
    printf("- Pressione 'q' para sair\n\n");

    while (!jogo.game_over) {
        char bloco_atual = gerar_bloco_aleatorio();
        printf("Próximo bloco: %c\n", bloco_atual);

        exibir_tabuleiro(&jogo);

        printf("Digite a coluna (0-%d) ou 'q' para sair: ", NUM_COLUNAS-1);

        char entrada[10];
        fgets(entrada, sizeof(entrada), stdin);

        if (tolower(entrada[0]) == 'q') {
            break;
        }

        int coluna = atoi(entrada);
        if (coluna < 0 || coluna >= NUM_COLUNAS) {
            printf("Coluna inválida! Tente novamente.\n");
            continue;
        }

        if (!empilhar_bloco(&jogo, coluna, bloco_atual)) {
            if (jogo.game_over) {
                printf("JOGO ENCERRADO! Coluna %d atingiu a altura máxima!\n", coluna);
            }
            break;
        }

        verificar_linhas(&jogo);
        limpar_tela();
    }

    exibir_tabuleiro(&jogo);
    printf("\n=== FIM DE JOGO ===\n");
    printf("Pontuação final: %d\n", jogo.pontuacao);
    printf("Linhas eliminadas: %d\n", jogo.linhas_eliminadas);

    for (int i = 0; i < NUM_COLUNAS; i++) {
        while (jogo.colunas[i].topo != NULL) {
            desempilhar_bloco(&jogo, i);
        }
    }

    return 0;
}
