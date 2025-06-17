// Invocação de uma syscall (em C)
// Compilação sugerida no comentário acima:
// gcc -o hello hello.c

#include <unistd.h>   // Biblioteca que fornece acesso direto a chamadas de sistema POSIX, como write()

int main (int argc, char *argv[]) {
    
    // Chamada direta à syscall 'write' para escrever na saída padrão (stdout).
    // Parâmetros da função write:
    // 1 -> descritor de arquivo para stdout (0 = stdin, 1 = stdout, 2 = stderr)
    // "Hello World!\n" -> ponteiro para a string a ser escrita
    // 13 -> número de bytes a serem escritos (o tamanho da string)
    write(1, "Hello World!\n", 13);

    // Encerra o programa com código de saída 0 (sucesso).
    // Nota: 'exit' aqui está implícita (mas precisa de inclusão de <stdlib.h> se fosse usada diretamente).
    exit(0);
}

