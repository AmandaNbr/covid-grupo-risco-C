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
    char telefone[13];
    int dataDeNascimento[3];
    char email[50];
    int dataDiagnostico[3];
    char comorbidade[50];
    struct Endereco *novoEndereco;
    novoEndereco = (struct Endereco*) malloc(sizeof(struct Endereco));

    do{
        printf("\nInforme os dados do paciente.\n");

        printf("Nome:\n");
        pegaNome(nome);

        printf("Cpf (11 digitos, somente numeros):\n");
        pegaCpf(cpf);

        printf("Telefone (10 ou 11 digitos, apenas numeros):\n");
        pegaTelefone(telefone);

        printf("DATA DE NASCIMENTO------------\n");
        pegaDataDeNascimento(dataDeNascimento);

        printf("E-mail:\n");
        pegaEmail(email);

        printf("DATA DIAGNOSTICO------------\n");
        pegaDataDiagnostico(dataDiagnostico);

        printf("Comorbidade:(se nao possui, aperte ENTER)\n");
        pegaComorbidade(comorbidade);

        printf("ENDERECO------------\n");
        printf("Rua:\n");
        pegaRua(novoEndereco);

        printf("Numero:\n");
        pegaNumero(novoEndereco);

        printf("Bairro:\n");
        pegaBairro(novoEndereco);

        printf("Cidade:\n");
        pegaCidade(novoEndereco);

        printf("Estado:\n");
        pegaEstado(novoEndereco);

        printf("Cep: (8 digitos, somente numeros)\n");
        pegaCep(novoEndereco);

        guardarPaciente(nome,
                        cpf,
                        telefone,
                        dataDeNascimento,
                        email,
                        dataDiagnostico,
                        comorbidade,
                        novoEndereco);

        printf("\nDeseja cadastrar novo paciente?(s/n) ");
        scanf("%c", &desejaCadastrar);
        fflush(stdin);
    } while(desejaCadastrar == 's' || desejaCadastrar == 'S');

    validaPacienteGrupoDeRisco();
}

void pegaNome(char *nome) {
    int validacao = 0;
    do{
        fgets(nome, 100, stdin);
        fflush(stdin);

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
        trim(cpf, NULL);

        // Verifica o tamanho da string
        if(strlen(cpf) != 11){
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
        fgets(telefone, 20, stdin);
        fflush(stdin);
        trim(telefone, NULL);

        // Verifica o tamanho da string
        if(strlen(telefone) != 10 && strlen(telefone) != 11){
            printf("Numero de telefone invalido. Tente novamente!\nTelefone (10 ou 11 digitos, apenas numeros):\n");
            validacao = 1;
        } else {
            validacao = 0;
        }
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
}

void pegaRua(struct Endereco *novoEndereco){
    int validation = 0;

    do{
        fgets(novoEndereco->rua, 100, stdin);
        fflush(stdin);

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
                     char *comorbidade,
                     struct Endereco *novoEndereco) {

    FILE *pacienteFile;
    pacienteFile = fopen("paciente.txt", "a+");

    fprintf(pacienteFile, "%s|%s|%s|%d/%d/%d|%s|%d/%d/%d|%s|%s|%d|%s|%s|%s|%s\n",
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
            comorbidade,
            novoEndereco->rua,
            novoEndereco->numero,
            novoEndereco->bairro,
            novoEndereco->cidade,
            novoEndereco->estado,
            novoEndereco->cep);

    printf("\nPaciente cadastrado com sucesso!\n");

    fclose(pacienteFile);
}


void validaPacienteGrupoDeRisco(){

    int idade = 0;
    char linha[256];
    int achouPacienteGrupoDeRisco = 0;
    char nome[100];
    char cpf[13];
    char telefone[13];
    int dataDeNascimento[3];
    char email[50];
    int dataDiagnostico[3];
    char comorbidade[50];
    struct Endereco *lerEndereco;
    lerEndereco = (struct Endereco*) malloc(sizeof(struct Endereco));

    FILE *pacienteFile;
    pacienteFile = fopen("paciente.txt", "r");

    while(fgets(linha, sizeof(linha), pacienteFile) != NULL) {
        formatoArquivoPaciente(nome,
                               cpf,
                               telefone,
                               dataDeNascimento,
                               email,
                               dataDiagnostico,
                               comorbidade,
                               lerEndereco,
                               linha);

        idade = pegaIdade(dataDeNascimento);
        // Se o paciente tiver alguma comorbidade e se o paciente tiver mais de 65 anos
        if (strcmp(comorbidade, "nenhuma") != 0 || idade > 65) {
            achouPacienteGrupoDeRisco = 1;
            printf("\nPaciente ");
            printf(nome);
            printf(" pertence ao grupo de risco.\n");
        }

        if(achouPacienteGrupoDeRisco) {
            guardarPacienteGrupoDeRisco(lerEndereco, pegaIdade(dataDeNascimento));
        }

    }

    if (!achouPacienteGrupoDeRisco) {
        printf("\nNão ha pacientes pertencentes ao grupo de risco.\n");
    }
    fclose(pacienteFile);
}

void guardarPacienteGrupoDeRisco(struct Endereco *novoEndereco,
                                 int idade) {

    FILE *pacienteGrupoDeRiscoFile;
    pacienteGrupoDeRiscoFile = fopen("pacienteGrupoDeRisco.txt", "a+");

    fprintf(pacienteGrupoDeRiscoFile, "%s|%d\n",
            novoEndereco->cep,
            idade);

    printf("\nPacientes do grupo de risco cadastrados com sucesso!\n");

    fclose(pacienteGrupoDeRiscoFile);
}

void formatoArquivoPaciente(char *nome,
                            char *cpf,
                            char *telefone,
                            int dataDeNascimento[],
                            char *email,
                            int dataDiagnostico[],
                            char *comorbidade,
                            struct Endereco *lerEndereco,
                            char *linha){
    sscanf(linha, "%[^|]|%[^|]|%[^|]|%d/%d/%d|%[^|]|%d/%d/%d|%[^|]|%[^|]|%d|%[^|]|%[^|]|%[^|]|%[^\n]\n",
            nome,
            cpf,
            telefone,
            &dataDeNascimento[0],
            &dataDeNascimento[1],
            &dataDeNascimento[2],
            email,
            &dataDiagnostico[0],
            &dataDiagnostico[1],
            &dataDiagnostico[2],
            comorbidade,
            lerEndereco->rua,
            &lerEndereco->numero,
            lerEndereco->bairro,
            lerEndereco->cidade,
            lerEndereco->estado,
            lerEndereco->cep);
}
