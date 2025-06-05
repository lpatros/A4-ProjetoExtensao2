#include "../utils/utils.h"

#include <stdio.h>
#include <stdlib.h>

time_t getCurrentTime() {
    time_t currentTime;
    time(&currentTime);
    return currentTime;
}

void formatDateTime(time_t timestamp, char *buffer) {
    struct tm *timeInfo = localtime(&timestamp);
    sprintf(buffer, "%02d/%02d/%02d", 
            timeInfo->tm_mday,
            timeInfo->tm_mon + 1,
            timeInfo->tm_year % 100);
}

void color_printf(char *text, ColorText color)
{
    printf("\033[%dm%s\033[0m", color, text);
}

void menu()
{
    color_printf("\n----- Sistema de Vendas -----\n", COLOR_GREEN);
    color_printf("1. Registrar Venda\n", COLOR_RESET);
    color_printf("2. Relatorio Diario\n", COLOR_RESET);
    color_printf("3. Relatorio Mensal\n", COLOR_RESET);
    color_printf("4. Relatorio Anual\n", COLOR_RESET);
    color_printf("5. Sair\n", COLOR_RED);
    color_printf("-----------------------------\n", COLOR_GREEN);
    color_printf("Escolha uma opcao: ", COLOR_WHITE);
}

void menuSale()
{
    color_printf("\n---- Registrar Venda ----\n", COLOR_GREEN);
    color_printf("Selecione o tipo de venda:\n", COLOR_YELLOW);
    color_printf("1. Refeicao a Quilo\n", COLOR_RESET);
    color_printf("2. Quentinha\n", COLOR_RESET);
    color_printf("3. Bebida\n", COLOR_RESET);
    color_printf("4. Voltar\n", COLOR_RED);
    color_printf("-------------------------\n", COLOR_GREEN);
    color_printf("Opcao: ", COLOR_WHITE);
}

void clearTerminal()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}