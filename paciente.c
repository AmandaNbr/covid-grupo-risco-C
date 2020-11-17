#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

//void registrarPaciente();
void pegaNome(char nome[100]);


struct Endereco {
    char rua[50];
    int numero;
    char bairro[100];
    char cidade[50];
    char estado[50];
    char cep[10];
};



void registrarPaciente()
{
    char desejaCadastrar;
    char nome[100];
    char cpf[13];
    char telefone[9];
    int dataDeNascimento[3];
    char email[50];
    int dataDiagnostico[3];
    char comorbidade[50];
    struct Endereco *novoEndereco;

    do{
        novoEndereco = (struct Endereco*) malloc(sizeof(struct Endereco));
        printf("\nInforme os dados do paciente.\n");

        printf("Nome:\n");
        pegaNome(nome);

        printf("Cpf (11 digitos, somente numeros):\n");
        pegaCpf(cpf);

        printf("Telefone (12 ou 13 digitos, apenas numeros):\n");
        pegaTelefone(telefone);

        printf("DATA DE NASCIMENTO------------\n");
        pegaDataDeNascimento(dataDeNascimento);

        printf("E-mail:\n");
        pegaEmail(email);

        printf("DATA DIAGNOSTICO------------\n");
        pegaDataDiagnostico(dataDiagnostico);

        printf("Comorbidade:(se nao possui, aperte ENTER)\n");
        pegaComorbidade(comorbidade);
//
//        printf("ENDERECO------------\n");
//        printf("Rua:\n");
//        pegaRua(novoEndereco);
//
//        printf("Numero:\n");
//        pegaNumero(novoEndereco);
//
//        printf("Bairro:\n");
//        pegaBairro(novoEndereco);
//
//        printf("Cidade:\n");
//        pegaCidade(novoEndereco);
//
//        printf("Estado:\n");
//        pegaEstado(novoEndereco);
//
//        printf("Cep: (8 digitos, somente numeros)\n");
//        pegaCep(novoEndereco);

        guardarPaciente(nome, cpf, telefone, dataDeNascimento, email, dataDiagnostico, comorbidade);

        printf("\nDeseja cadastrar novo paciente?(s/n) ");
        scanf("%c", &desejaCadastrar);
        fflush(stdin);
    } while(desejaCadastrar == 's' || desejaCadastrar == 'S');

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
        fgets(cpf, 20, stdin);
        fflush(stdin);

        // Verifica o tamanho da string
        if(strlen(cpf) != 12){
            printf("Cpf invalido. Tente novamente!\nCpf (11 digitos, somente numeros):\n");
            validacao = 1;
        } else {
            validacao = 0;
        }

      //  trim(cpf, NULL);
    }while(validacao);
}

void pegaTelefone(char telefone[]) {
    int validacao = 0;
    do{
        fgets(telefone, 20, stdin);
        fflush(stdin);

        // Verifica o tamanho da string
        if(strlen(telefone) != 13 && strlen(telefone) != 12){
            printf("Numero de telefone invalido. Tente novamente!\nTelefone (12 ou 13 digitos, apenas numeros):\n");
            validacao = 1;
        } else {
            validacao = 0;
        }

        trim(telefone, NULL);
    }while(validacao);
}

void pegaDataDeNascimento(int dataDeNascimento[]) {
    int validacao = 0;
    do{ // Pega cada valor do ano
        printf("Dia: ");
        scanf("%d", &dataDeNascimento[0]);
        fflush(stdin);

        printf("Mes: ");
        scanf("%d", &dataDeNascimento[1]);
        fflush(stdin);

        printf("Ano: ");
        scanf("%d", &dataDeNascimento[2]);
        fflush(stdin);

        validacao = validaData(dataDeNascimento);
        if (validacao){
            printf("\nData invalida, informe uma data existente.\n");
            validacao = 1;
        } else {
            // Nothing to do;
            validacao = 0;
        }

    }while(validacao);
}

void pegaDataDiagnostico(int dataDiagnostico[]) {
    int validacao = 0;
    do{ // Pega cada valor do ano
        printf("Dia: ");
        scanf("%d", &dataDiagnostico[0]);
        fflush(stdin);

        printf("Mes: ");
        scanf("%d", &dataDiagnostico[1]);
        fflush(stdin);

        printf("Ano: ");
        scanf("%d", &dataDiagnostico[2]);
        fflush(stdin);

        validacao = validaData(dataDiagnostico);
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

void pegaRua(struct Endereco *novoEndereco){
    int validation = 0;

    do{
        fgets(novoEndereco->rua, 100, stdin);
        fflush(stdin);

        converterMinusculo(novoEndereco->rua);
        trim(novoEndereco->rua, NULL);

        validation = stringEhVazia(novoEndereco->rua);

        if (validation){
            printf("Campo vazio, informe uma rua valida.\nRua:\n");
            validation = 1;
        } else {
            validation = 0;
        }
    }while(validation);
}

void pegaNumero(struct Endereco *novoEndereco){
    int validation = 0;

        scanf("%d", &novoEndereco->numero);
        fflush(stdin);
}

void pegaBairro(struct Endereco *novoEndereco){
    int validation = 0;

    do{
        fgets(novoEndereco->bairro, 100, stdin);
        fflush(stdin);

        converterMinusculo(novoEndereco->bairro);
        trim(novoEndereco->bairro, NULL);

        validation = stringEhVazia(novoEndereco->bairro);

        if (validation){
            printf("Campo vazio, informe um bairro valido.\nBairro:\n");
            validation = 1;
        } else {
            validation = 0;
        }
    }while(validation);
}

void pegaCidade(struct Endereco *novoEndereco){
    int validation = 0;

    do{
        fgets(novoEndereco->cidade, 100, stdin);
        fflush(stdin);

        converterMinusculo(novoEndereco->cidade);
        trim(novoEndereco->cidade, NULL);

        validation = stringEhVazia(novoEndereco->cidade);

        if (validation){
            printf("Campo vazio, informe uma cidade valida.\nCidade:\n");
            validation = 1;
        } else {
            validation = 0;
        }
    }while(validation);
}

void pegaEstado(struct Endereco *novoEndereco){
    int validation = 0;

    do{
        fgets(novoEndereco->estado, 100, stdin);
        fflush(stdin);

        converterMinusculo(novoEndereco->estado);
        trim(novoEndereco->estado, NULL);

        validation = stringEhVazia(novoEndereco->estado);

        if (validation){
            printf("Campo vazio, informe um estado valido.\nEstado:\n");
            validation = 1;
        } else {
            validation = 0;
        }
    }while(validation);
}

void pegaCep(struct Endereco *novoEndereco) {
    int validacao = 0;

    do{
        fgets(novoEndereco->cep, 20, stdin);
        fflush(stdin);

        // Verifica o tamanho da string
        if(strlen(novoEndereco->cep) != 9){
            printf("CEP invalido. Tente novamente!\nCEP (8 digitos, somente numeros):\n");
            validacao = 1;
        } else {
            validacao = 0;
        }

        trim(novoEndereco->cep, NULL);
    }while(validacao);
}

void guardarPaciente(char *nome,
                     char *cpf,
                     char *telefone,
                     int dataDeNascimento[],
                     char *email,
                     int dataDiagnostico[],
                     char *comorbidade) {

    FILE *pacienteFile;
    pacienteFile = fopen("paciente.txt", "a+");

    fprintf(pacienteFile, "%s|%s|%s|%d/%d/%d|%s|%d/%d/%d|%s\n",
            nome,
            cpf,
            telefone,
            dataDeNascimento[0],
            dataDeNascimento[1],
            dataDeNascimento[2],
            email,
            dataDiagnostico[0],
            dataDiagnostico[1],
            dataDiagnostico[2],
            comorbidade);
//            novoEndereco->rua,
//            novoEndereco->numero,
//            novoEndereco->bairro,
//            novoEndereco->cidade,
//            novoEndereco->estado,
//            novoEndereco->cep);

    printf("\nPaciente cadastrado com sucesso!\n");

    fclose(pacienteFile);
}
