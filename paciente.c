#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

//void registrarPaciente();
void pegaNome(char nome[100]);
char nome[100];
char cpf[13];
char telefone[9];
int dataDeNascimento[3];
char email[50];
int dataDiagnostico[3];
char comorbidade[50];

struct Endereco {
    char rua[50];
    int numero;
    char bairro[100];
    char cidade[50];
    char estado[50];
    char cep[8];
};

struct Endereco *novoEndereco;

void registrarPaciente()
{
    novoEndereco = (struct Endereco*) malloc(sizeof(struct Endereco));
    printf("Informe os dados do paciente.\n");

    printf("Nome:\n");
    pegaNome(nome);

    printf("Cpf (11 digitos, somente numeros):\n");
    pegaCpf(cpf);

    printf("Telefone (12 ou 13 digitos, apenas numeros):\n");
    pegaTelefone(telefone);

    printf("Data de nascimento\n");
    pegaData(dataDeNascimento);

    printf("E-mail:\n");
    pegaEmail(email);

    printf("Data do diagnostico\n");
    pegaData(dataDiagnostico);

    printf("Comorbidade:(se nao possui, aperte ENTER)\n");
    pegaComorbidade(comorbidade);
    printf(comorbidade);

    printf("Endereco------------\n");
    printf("Rua:\n");
    pegaRua();

    printf("Numero:");


    printf("Rua:");


    printf("Bairro:");


    printf("Cidade:");


    printf("Estado:");


    printf("Cep:");



}

void pegaNome(char nome[100]) {
    int validacao = 0;
    do{
        fgets(nome, 100, stdin);
        fflush(stdin);

        converterMinusculo(nome);
        trim(nome, NULL);

        validacao = stringEhVazia(nome);

        if (validacao){
            printf("Nome nulo, informe um nome valido.\nNome:\n");
        } else {
            // Nada a fazer
        }

    }while(validacao);
}

void pegaCpf(char cpf[]) {
    int validacao = 0;
    do{
        fgets(cpf, 13, stdin);
        fflush(stdin);

        // Verifica o tamanho da string
        if(strlen(cpf) != 12){
            printf("Cpf invalido. Tente novamente!\nCpf (11 digitos, somente numeros):\n");
            validacao = 1;
        } else {
            validacao = 0;
        }
    }while(validacao);
}

void pegaTelefone(char telefone[]) {
    int validacao = 0;
    do{
        fgets(telefone, 15, stdin);
        fflush(stdin);

        // Verifica o tamanho da string
        if(strlen(telefone) != 14 && strlen(telefone) != 13){
            printf("Numero de telefone ivalido. Tente novamente!\nTelefone (12 ou 13 digitos, apenas numeros):\n");
            validacao = 1;
        } else {
            validacao = 0;
        }
    }while(validacao);
}

void pegaData(int data[]) {
    int validacao = 0;
    do{ // Pega cada valor do ano
        printf("Dia: ");
        scanf("%d", &data[0]);
        fflush(stdin);

        printf("Mes: ");
        scanf("%d", &data[1]);
        fflush(stdin);

        printf("Ano: ");
        scanf("%d", &data[2]);
        fflush(stdin);

        validacao = validaData(data);
        if (validacao){
            printf("\nData invalida, informe uma data existente.\n");
            validacao = 1;
        } else {
            // Nothing to do;
            validacao = 0;
        }

    }while(validacao);
}

int validaData(int data[]) {
    // Valida ano
    if (data[2] <= 1899 || data[2] >= 2021){
        return 1;
    }

    // Valida mes
    if (data[1] <= 0 || data[1] > 12) {
        return 1;
    }

    // Valida meses com 31 dias
    if (data[1] == 1 || data[1] == 3 || data[1] == 5 ||
        data[1] == 7 || data[1] ==  8 || data[1] == 10 || data[1] == 12) {
        if (data[0] <= 0 || data[0] >31) {
            return 1;
        }
    }

    // Valida meses com 30 dias
    if (data[0] == 4 || data[0] == 6 || data[0] == 9 || data[0] == 11) {
        if (data[1] <= 0 || data[1] > 30) {
            return 1;
        }
    }

    // Valida ano bissexto
    if (data[1] == 2) {
        if ((data[2] % 4 == 0 && data[2] % 100 != 0) || data[2] % 400 == 0) {
            if (data[0] <= 0 || data[0] > 29) {
                return 1;
            }
        } else {
            if (data[0] <= 0 || data[0] > 28) {
                return 1;
            }
        }
    }
    return 0;
}

void pegaEmail(char email[]){
    int validacao = 0;

    do {
        fgets(email, 50, stdin);
        fflush(stdin);

        trim(email, NULL);

        validacao = stringEhVazia(email);

        if(validacao) {
            printf("Email invalido. Tente novamente!\nEmail:\n");
            validacao = 1;
        } else {
            // Nada a fazer
            validacao = 0;
        }

    } while(validacao);
}

void pegaComorbidade(char comorbidade[]){
    fgets(comorbidade, 50, stdin);
    fflush(stdin);
    trim(comorbidade, NULL);

    if(strlen(comorbidade)<=1){
        strcpy(comorbidade, "nenhuma");
    }
    converterMinusculo(comorbidade);
}

void pegaRua(){

}
