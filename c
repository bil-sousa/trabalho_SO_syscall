#include <unistd.h>   // Para funções de sistema como write() e _exit()
#include <stdio.h>    // Para funções de I/O padrão como scanf() e snprintf()
#include <stdlib.h>   // Para definição de EXIT_SUCCESS/FAILURE (não usado aqui)

int main() {
    // Declaração de variáveis
    int A, B, C, maiorAB, maior;  // Variáveis para armazenar os números e resultados
    char str[20];                 // Buffer para armazenar o número como string
    const char msg1[] = "Escreve 3 numeros:\n";  // Mensagem inicial (constante)
    const char msg2[] = "O maior numero eh:\n";  // Mensagem de resultado (constante)
    int tamanho;                  // Para armazenar o tamanho da string convertida

    // Escreve mensagem pedindo os números
    // write(1, ...) escreve no descritor de arquivo 1 (stdout)
    // sizeof(msg1) - 1 para não incluir o caractere nulo final
    write(1, msg1, sizeof(msg1) - 1);

    // Lê três números inteiros da entrada padrão
    // scanf retorna o número de itens lidos com sucesso
    scanf("%d %d %d", &A, &B, &C);

    // Encontra o maior entre A e B usando operador ternário
    // Se A > B, maiorAB = A, senão maiorAB = B
    maiorAB = (A > B) ? A : B;
    
    // Encontra o maior entre o resultado anterior (maiorAB) e C
    // Se maiorAB > C, maior = maiorAB, senão maior = C
    maior = (maiorAB > C) ? maiorAB : C;
    
    // Converte o maior número para string e obtém seu comprimento
    // snprintf escreve no buffer 'str' com tamanho máximo sizeof(str)
    // Formato "%d\n" converte o número e adiciona quebra de linha
    tamanho = snprintf(str, sizeof(str), "%d\n", maior);

    // Escreve a mensagem de saída indicando o resultado
    write(1, msg2, sizeof(msg2) - 1);
    
    // Escreve o número convertido (apenas os caracteres necessários)
    // Usa 'tamanho' retornado por snprintf para saber quantos bytes escrever
    write(1, str, tamanho);
    
    // Termina o programa com status 0 (sucesso)
    // _exit() é uma chamada de sistema que termina imediatamente o processo
    _exit(0);
}
