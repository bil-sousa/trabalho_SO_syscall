#include <unistd.h>   // Inclui funções de sistema como write(), _exit(), close()
#include <stdio.h>    // Inclui funções da biblioteca padrão como scanf(), printf(), fflush()
#include <stdlib.h>   // Inclui definições como EXIT_SUCCESS e EXIT_FAILURE (não usado aqui)

int main() {
    // Declaração de variáveis inteiras para armazenar os números digitados e os resultados
    int A, B, C, maiorAB, maior;

    // Mensagem a ser exibida para pedir os números ao usuário
    const char msg1[] = "Escreve 3 numeros:\n";

    // Mensagem a ser exibida antes de mostrar o maior número
    const char msg2[] = "O maior numero eh:\n";

    // Chamada de sistema write(): escreve a mensagem msg1 na saída padrão (descritor 1)
    // sizeof(msg1) - 1 evita escrever o caractere nulo '\0' no final da string
    write(1, msg1, sizeof(msg1) - 1);

    // Usa scanf (da biblioteca C) para ler três números inteiros digitados pelo usuário
    scanf("%d %d %d", &A, &B, &C);

    // Usa operador ternário para encontrar o maior entre A e B
    maiorAB = (A > B) ? A : B;

    // Usa operador ternário para encontrar o maior entre maiorAB e C
    maior = (maiorAB > C) ? maiorAB : C;

    // Escreve a segunda mensagem na tela com write() (syscall) novamente
    write(1, msg2, sizeof(msg2) - 1);

    // Imprime o valor do maior número com printf (da biblioteca C)
    // Aqui usa buffer, então o texto pode não aparecer de imediato
    printf("%d", maior);

    // Garante que o conteúdo do buffer de printf seja enviado para a tela
    // Isso é necessário porque close(1) logo em seguida pode impedir a exibição se não for feito o flush
    fflush(stdout);

    // Chamada de sistema close(): fecha a saída padrão (descritor 1)
    // A partir daqui, qualquer tentativa de escrever em stdout falhará
    close(1);

    // Chamada de sistema _exit(): encerra o programa imediatamente, sem chamar funções de limpeza
    _exit(0);
}

