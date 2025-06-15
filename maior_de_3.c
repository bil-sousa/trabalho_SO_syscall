#include <unistd.h>   // Para write()
#include <stdio.h>    // Para scanf() e printf()
#include <stdlib.h>   // Para exit()

int main() {
    // Variáveis para armazenar os três números e os maiores parciais
    int A, B, C, maiorAB, maior;

    // Mensagens que serão exibidas ao usuário
    const char msg1[] = "Escreve 3 numeros:\n";
    const char msg2[] = "O maior numero eh:\n";

    // Exibe a primeira mensagem usando a syscall write (descritor 1 = stdout)
    write(1, msg1, sizeof(msg1) - 1);

    // Lê três números inteiros da entrada padrão
    scanf("%d %d %d", &A, &B, &C);

    // Determina o maior entre A e B
    maiorAB = (A > B) ? A : B;

    // Determina o maior entre maiorAB e C
    maior = (maiorAB > C) ? maiorAB : C;

    // Escreve a segunda mensagem
    write(1, msg2, sizeof(msg2) - 1);

    // Imprime o maior número com printf
    printf("%d\n", maior);

    // Finaliza o programa com código de sucesso
    exit(0);
}
