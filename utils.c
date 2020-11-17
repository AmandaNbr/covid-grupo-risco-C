#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <time.h>

void converterMinusculo(char texto[]);
char *ltrim(char *str, const char *seps);
char *rtrim(char *str, const char *seps);
void trim(char *str, const char *seps);
int stringEhVazia(char *stringChecada);

// Remove os caracteres do lado esquerdo da string e realoca
char *ltrim(char *str, const char *seps) {
    size_t totrim;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    totrim = strspn(str, seps);
    if (totrim > 0) {
        size_t len = strlen(str);
        if (totrim == len) {
            str[0] = '\0';
        }
        else {
            memmove(str, str + totrim, len + 1 - totrim);
        }
    }
    return str;
}

// Remove os caracteres do lado direito da string e realoca
char *rtrim(char *str, const char *seps) {
    int i;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    i = strlen(str) - 1;
    while (i >= 0 && strchr(seps, str[i]) != NULL) {
        str[i] = '\0';
        i--;
    }
    return str;
}

// Junta o ltrim e rtrim
void trim(char *str, const char *seps) {
    ltrim(rtrim(str, seps), seps);
}

// Checa se a tring eh vazia
int stringEhVazia(char *stringChecada) {
    if (stringChecada[0] == '\0'){
        return 1;
	} else {
	    return 0;
	}
}

// Calcula a idade
int pegaIdade(int dataDeNascimento[3]) {
    time_t ts;
    struct tm *ct;

    ts = time(NULL);
    ct = localtime(&ts);

	// current dd/mm/yyyy
	int diaAtual = ct->tm_mday;
	int mesAtual = ct->tm_mon + 1;
	int anoAtual = ct->tm_year + 1900;

    // days of every month
	int mes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// if birth date is greater then current birth month then do not count this month and add 30
	// to the date so as to subtract the date and get the remaining days
	if (dataDeNascimento[0] > diaAtual) {
		diaAtual = diaAtual + mes[dataDeNascimento[1] - 1];
		mesAtual = mesAtual - 1;
	}

    // if birth month exceeds current month, then do
	// not count this year and add 12 to the month so that we can subtract and find out the difference
	if (dataDeNascimento[1] > mesAtual) {
		anoAtual = anoAtual - 1;
		mesAtual = mesAtual + 12;
	}

	// calculate date, month, year
    // int calculated_day = current_day - birthdate[0];
	// int calculated_month = current_month - birthdate[1];
	int idade = anoAtual - dataDeNascimento[2];

	return idade;
}
