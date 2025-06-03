#include "../utils/utils.h"

#include <stdio.h>

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