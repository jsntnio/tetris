# Stacktris - Projeto de Estrutura de Dados

## O que foi implementado

Definição de uma estrutura de **bloco** (`struct Bloco`) com:
- Tipo do bloco (caractere).
- Ponteiro para o bloco abaixo (implementando uma lista encadeada).

Definição de uma estrutura de **pilha** (`struct Pilha`) para representar cada coluna do jogo com:
- Ponteiro para o topo da pilha.
- Contador de altura da pilha.

Definição de uma estrutura para o **estado do jogo** (`struct Jogo`) contendo:
- Um vetor de 5 pilhas (colunas).
- Contador de pontuação.
- Contador de linhas eliminadas.
- Estado de término de jogo (game over).

Função para **inicializar o jogo** (`inicializar_jogo`):
- Zera todas as pilhas e variáveis de controle.

Função para **criar um novo bloco** (`criar_bloco`):
- Alocação dinâmica de memória para blocos.

Função para **empilhar blocos nas colunas** (`empilhar_bloco`):
- Insere um bloco no topo da coluna escolhida.
- Verifica se a altura máxima foi atingida.

Função para **desempilhar blocos** (`desempilhar_bloco`):
- Remove o bloco do topo de uma coluna.

Função para **verificar e eliminar linhas completas** (`verificar_linhas`):
- Remove um bloco de cada coluna quando todas têm blocos na mesma altura.
- Atualiza pontuação e número de linhas eliminadas.

Função para **exibir o tabuleiro** no terminal (`exibir_tabuleiro`):
- Mostra visualmente as colunas, blocos e pontuação.

Função para **gerar tipos de blocos aleatórios** (`gerar_bloco_aleatorio`):
- Sorteia entre três tipos possíveis de bloco.

Função para **limpar a tela** do terminal (`limpar_tela`):
- Implementada de forma compatível com Windows e Linux.

Laço principal de jogo na função `main`:
- Controle do fluxo de jogo.
- Leitura da escolha do jogador.
- Atualização do estado do jogo a cada rodada.
- Encerramento do jogo quando necessário.

Liberação da memória alocada ao final da execução:
- Esvaziamento de todas as pilhas antes de encerrar o programa.
