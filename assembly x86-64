section .data
    msg db "escreve 3 numeros inteiros:", 0xA      ; Mensagem inicial para o usuário
    tan_msg equ $ - msg                            ; Tamanho da mensagem acima
    maior db "O maior é:", 0xA                     ; Mensagem para indicar o maior número
    tan_maior equ $ - maior                        ; Tamanho da mensagem "O maior é:"

section .bss
    num1 resb 32      ; Reserva 32 bytes para armazenar o primeiro número digitado
    num2 resb 32      ; Reserva 32 bytes para o segundo número
    num3 resb 32      ; Reserva 32 bytes para o terceiro número

section .text
    global _start     ; Ponto de entrada do programa

_start:

    ; Escreve mensagem inicial na tela
    mov rax, 1            ; syscall write
    mov rdi, 1            ; stdout (saída padrão)
    mov rsi, msg          ; ponteiro para a mensagem
    mov rdx, tan_msg      ; tamanho da mensagem
    syscall

    ; -------- LEITURA DE num1 ----------
    mov rax, 0            ; syscall read
    mov rdi, 0            ; stdin (entrada padrão)
    mov rsi, num1         ; buffer onde armazenar
    mov rdx, 32           ; até 32 bytes
    syscall
    mov r8, rax           ; salva a quantidade de bytes lidos

    ; -------- LEITURA DE num2 ----------
    mov rax, 0
    mov rdi, 0
    mov rsi, num2
    mov rdx, 32
    syscall
    mov r9, rax           ; salva bytes lidos de num2

    ; -------- LEITURA DE num3 ----------
    mov rax, 0
    mov rdi, 0
    mov rsi, num3
    mov rdx, 32
    syscall
    mov r10, rax          ; salva bytes lidos de num3

    ; -------- CONVERSÃO DE STRINGS PARA INTEIROS ----------
    mov rsi, num1
    call atoi             ; converte num1 (string) para inteiro
    mov r11, rax          ; r11 ← valor inteiro de num1

    mov rsi, num2
    call atoi
    mov r12, rax          ; r12 ← valor inteiro de num2

    mov rsi, num3
    call atoi
    mov r13, rax          ; r13 ← valor inteiro de num3

    ; -------- ENCONTRANDO O MAIOR NÚMERO ----------
    mov r14, r11          ; r14 ← valor máximo (inicialmente num1)
    mov r15, num1         ; r15 ← ponteiro para string do número atual
    mov rbx, r8           ; rbx ← tamanho da string de num1

    ; Se num2 > r14, atualiza maior
    cmp r12, r14
    jg .num2_maior

.continue1:
    ; Se num3 > r14, atualiza maior
    cmp r13, r14
    jg .num3_maior
    jmp .escreve_maior

.num2_maior:
    mov r14, r12          ; atualiza maior para num2
    mov r15, num2
    mov rbx, r9
    jmp .continue1

.num3_maior:
    mov r14, r13          ; atualiza maior para num3
    mov r15, num3
    mov rbx, r10

.escreve_maior:
    ; Escreve mensagem "O maior é:"
    mov rax, 1
    mov rdi, 1
    mov rsi, maior
    mov rdx, tan_maior
    syscall

    ; Escreve string do número que é o maior
    mov rax, 1
    mov rdi, 1
    mov rsi, r15          ; ponteiro para string
    mov rdx, rbx          ; tamanho da string
    syscall

fim:
    ; Encerra o programa
    mov rax, 60           ; syscall exit
    xor rdi, rdi          ; código de saída 0
    syscall

; --------------------------------------
; Função atoi - converte string para inteiro
; Entrada: RSI → ponteiro para string (ex: "123\n")
; Saída:  RAX ← valor inteiro (ex: 123)
; --------------------------------------
atoi:
    xor rax, rax          ; zera acumulador
    xor rcx, rcx          ; índice na string = 0
.next_char:
    mov bl, byte [rsi + rcx]  ; pega caractere atual

    cmp bl, 10            ; é '\n' (Enter)?
    je .done              ; fim da conversão

    cmp bl, '0'           ; menor que '0'?
    jl .done              ; fim

    cmp bl, '9'           ; maior que '9'?
    jg .done              ; fim

    sub bl, '0'           ; converte char ASCII para número
    imul rax, rax, 10     ; rax *= 10
    add rax, rbx          ; rax += novo dígito

    inc rcx               ; próximo caractere
    jmp .next_char

.done:
    ret                   ; retorna valor em rax
