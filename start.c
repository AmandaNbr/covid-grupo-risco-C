#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void start();

void start()
{
    const char usuarioPadrao[] = "funcionario";
    char usuario[12];
    const char senhaPadrao[] = "123456";
    char senha[7];


    printf("\nBem vindo ao software de cadastro de pacientes!\n");

    // Valida o nome de usuario
    do {
        printf("\nNome de usuario: ");
        scanf("%s", usuario);
        fflush(stdin);
        if (strcmp(usuarioPadrao, usuario) != 0){
          printf("Usuario invalido. Tente novamente!\n");
        } else {
        // Nada a fazer
        }
    } while ((strcmp(usuarioPadrao, usuario) != 0));

    // Valida a senha
    do {
        printf("Senha: ");
        scanf("%s", senha);
        fflush(stdin);
        if (strcmp(senhaPadrao, senha) != 0){
          printf("Senha invalida. Tente novamente!\n");
        } else {
        // Nada a fazer
        }
    } while ((strcmp(senhaPadrao, senha) != 0));

    system("cls");
    registrarPaciente();
}


