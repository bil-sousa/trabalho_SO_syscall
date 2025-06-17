; hello.asm - Exibe "Hello World!" no terminal usando syscalls
; Compile com:
; nasm -f elf64 hello.asm -o hello.o
; ld hello.o -o hello

section .data
    msg db 'Hello World!', 0xA   ; Mensagem + nova linha
    len equ $ - msg              ; Calcula o tamanho da string (13 bytes)

section .text
    global _start

_start:
    mov rax, 1       ; syscall: write
    mov rdi, 1       ; stdout (descritor de arquivo 1)
    mov rsi, msg     ; endereço da mensagem
    mov rdx, len     ; tamanho da mensagem
    syscall          ; chama write(1, msg, len)

    mov rax, 60      ; syscall: exit
    mov rdi, 0       ; código de saída 0 (sucesso)
    syscall          ; chama exit(0)
