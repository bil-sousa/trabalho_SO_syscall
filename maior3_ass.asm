section .data
    msg db "escreve 3 numeros inteiros:", 0xA
    tan_msg equ $ - msg

    maior db "O maior é:", 0xA
    tan_maior equ $ - maior

section .bss
    A resb 32
    B resb 32
    C resb 32

section .text
    global _start

_start:

    ;-----Escreve mensagem inicial----
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, tan_msg
    syscall

    ; -------- LEITURA DE A ----------
    mov rax, 0
    mov rdi, 0
    mov rsi, A
    mov rdx, 32
    syscall
    mov r8, rax

    ; -------- LEITURA DE B ----------
    mov rax, 0
    mov rdi, 0
    mov rsi, B
    mov rdx, 32
    syscall
    mov r9, rax

    ; -------- LEITURA DE C ----------
    mov rax, 0
    mov rdi, 0
    mov rsi, C
    mov rdx, 32
    syscall
    mov r10, rax

    ; -------- CONVERSÃO DE STRINGS PARA INTEIROS ----------
    mov rsi, A
    call atoi
    mov r11, rax

    mov rsi, B
    call atoi
    mov r12, rax

    mov rsi, C
    call atoi
    mov r13, rax

    ; -------- ENCONTRANDO O MAIOR NÚMERO ----------
    mov r14, r11
    mov r15, A
    mov rbx, r8

    cmp r12, r14
    jg .B_maior

.continue1:
    cmp r13, r14
    jg .C_maior
    jmp .escreve_maior

.B_maior:
    mov r14, r12
    mov r15, B
    mov rbx, r9
    jmp .continue1

.C_maior:
    mov r14, r13
    mov r15, C
    mov rbx, r10

.escreve_maior:
    ;--------Escreve "O maior é:"--------
    mov rax, 1
    mov rdi, 1
    mov rsi, maior
    mov rdx, tan_maior
    syscall

    ;--------Escreve o número maior------
    mov rax, 1
    mov rdi, 1
    mov rsi, r15
    mov rdx, rbx
    syscall

fim:
    mov rax, 60
    xor rdi, rdi
    syscall

; --------------------------------------
; Função atoi - converte string para inteiro
; Entrada: RSI → ponteiro para string (ex: "123\n")
; Saída:  RAX ← valor inteiro (ex: 123)
; --------------------------------------
atoi:
    xor rax, rax
    xor rcx, rcx
.next_char:
    mov bl, byte [rsi + rcx]

    cmp bl, 10
    je .done

    cmp bl, '0'
    jl .done

    cmp bl, '9'
    jg .done

    sub bl, '0'
    imul rax, rax, 10
    add rax, rbx

    inc rcx
    jmp .next_char

.done:
    ret
