#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "utils/utils.h"
#include "include/sale/sale.h"
#include "include/reports/reports.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    int option = 0;
    while (option != 5) {
        
        menu();
        scanf("%d", &option);

        clearTerminal();

        // Verifica se a opção é válida
        if (option < 1 || option > 5) {
            color_printf("Opcao invalida! Tente novamente.\n", COLOR_RED);
            continue; // Volta para o início do loop se a opção for inválida
        }

        // Se a opção é válida

        // Verifica se o usuário escolheu a opção de sair do sistema
        if (option == 5) {
            color_printf("Saindo do sistema...\n", COLOR_YELLOW);
            break;
        }

        // Verifica se o usuário escolheu a opção de registrar venda
        if (option == 1) {
            registerSale();
        }

        // Se o usuário não escolheu a opção de registrar venda

        // Inicializa a lista de vendas
        SaleList salesList = {
            .count = 0,
            .sales = NULL,
            .totalValue = 0.0
        };
        
        // Verifica qual relatório o usuário deseja gerar
        switch (option) {

            case 2:
                salesList = generateSalesReport(DAILY_REPORT);
                showSalesReport(&salesList, DAILY_REPORT);
                break;
            case 3:
                salesList = generateSalesReport(MONTHLY_REPORT);
                showSalesReport(&salesList, MONTHLY_REPORT);
                break;
            case 4:
                salesList = generateSalesReport(ANNUAL_REPORT);
                showSalesReport(&salesList, ANNUAL_REPORT);
                break;
        }
    }
    return 0;
}
