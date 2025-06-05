#include <stdio.h>
#include <stdlib.h>
#include "utils/utils.h"
#include "include/sale/sale.h"
#include "include/reports/reports.h"

int main() {

    int option = 0;
    while (option != 4) {
        
        menu();
        scanf("%d", &option);

        clearTerminal();

        // Verifica se a opção é válida
        if (option < 1 || option > 4) {
            color_printf("Opcao invalida! Tente novamente.\n", COLOR_RED);
            printPause();
            continue; // Volta para o início do loop se a opção for inválida
        }

        // Se a opção é válida

        // Verifica se o usuário escolheu a opção de sair do sistema
        if (option == 4) {
            color_printf("Saindo do sistema...\n", COLOR_YELLOW);
            break;
        }

        // Verifica se o usuário escolheu a opção de registrar venda
        if (option == 1) {
            registerSale();
            continue;
        }

        // Se o usuário não escolheu a opção de registrar venda

        // Verifica qual relatório o usuário deseja gerar
        switch (option) {

            case 2:
                showSalesByDay();
                break;
            case 3:
                showSalesByMonth();
                break;
            
        }

        printPause();
        clearTerminal();
    }
    return 0;
}
