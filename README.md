# Stacktris - Projeto de Estrutura de Dados

## O que foi implementado

- **Definição de uma estrutura de bloco (`struct Bloco`) com:**
  - Tipo do bloco (caractere).
  - Ponteiro para o bloco abaixo (implementando uma lista encadeada).

- **Definição de uma estrutura de pilha (`struct Pilha`) para representar cada coluna do jogo com:**
  - Ponteiro para o topo da pilha.
  - Contador de altura da pilha.

- **Definição de uma estrutura para o estado do jogo (`struct Jogo`) contendo:**
  - Um vetor de 5 pilhas (colunas).
  - Contador de pontuação.
  - Contador de linhas eliminadas.
  - Estado de término de jogo (game over).

- **Função para inicializar o jogo (`inicializar_jogo`):**
  - Zera todas as pilhas e variáveis de controle.

- **Função para criar um novo bloco (`criar_bloco`):**
  - Alocação dinâmica de memória para blocos.

- **Função para empilhar blocos nas colunas (`empilhar_bloco`):**
  - Insere um bloco no topo da coluna escolhida.
  - Verifica se a altura máxima foi atingida e, caso positivo, encerra o jogo.

- **Função para desempilhar blocos (`desempilhar_bloco`):**
  - Remove o bloco do topo de uma coluna.
  - Libera a memória alocada para o bloco removido.

- **Função para obter um bloco em uma altura específica (`obter_bloco_na_altura`):**
  - Percorre a pilha e retorna o bloco localizado no nível desejado.

- **Função para verificar e eliminar linhas completas (`verificar_linhas`):**
  - Verifica em cada altura se todas as colunas possuem blocos do mesmo tipo.
  - Caso afirmativo, remove a linha completa.
  - Atualiza a pontuação (+10 pontos por coluna) e o número de linhas eliminadas.

- **Função para exibir o tabuleiro no terminal (`exibir_tabuleiro`):**
  - Mostra visualmente as colunas e seus blocos.
  - Exibe a pontuação atual e o número de linhas eliminadas.
  - Indica o índice de cada coluna para auxiliar na jogada.

- **Função para gerar tipos de blocos aleatórios (`gerar_bloco_aleatorio`):**
  - Sorteia entre três tipos possíveis de blocos: `#`, `w`, `r`.

- **Função para limpar a tela do terminal (`limpar_tela`):**
  - Compatível tanto com Windows quanto com Linux.

- **Laço principal de jogo na função `main`:**
  - Exibe instruções iniciais.
  - Sorteia o próximo bloco.
  - Recebe a entrada do jogador (coluna escolhida ou `q` para sair).
  - Empilha o bloco e atualiza o tabuleiro.
  - Verifica e elimina linhas completas.
  - Encerra o jogo caso uma coluna atinja a altura máxima.

- **Liberação da memória ao final da execução:**
  - Desempilha todos os blocos restantes para liberar a memória alocada dinamicamente.
