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

        switch (option) {

            case 1:
                registerSale();
                break;

            case 2: {
                SaleList salesList = generateSalesReport(DAILY_REPORT);
                if (salesList.count > 0) {

                    color_printf("----------------------------- RELATORIO DIARIO -----------------------------\n", COLOR_WHITE);
                    printf("| ID \t| Tipo \t| Peso \t\t| Quantidade \t| Preco Item \t| Data \t   |\n");

                    int i;
                    for (i = 0; i < salesList.count; i++) {
                        Sale sale = salesList.sales[i];
                        printf("| %d \t| %d \t| %.3fkg \t| %d \t\t| R$%.2f \t| %s |\n",
                               sale.id, sale.item.type, sale.item.weight, sale.item.amount, sale.item.price, sale.date);
                    }
                    color_printf("----------------------------------------------------------------------------\n", COLOR_WHITE);
                    printf("Total de vendas: %d\n", salesList.count);
                    free(salesList.sales);
                } else {
                    color_printf("Nenhuma venda registrada para o relatório diário.\n", COLOR_YELLOW);
                }
                break;
            }
            // case 3:
            //     gerarRelatorioMensal();
            //     break;
            // case 4:
            //     gerarRelatorioAnual();
            //     break;
            case 5:
                color_printf("Saindo do sistema...\n", COLOR_YELLOW);
                break;
            default:
                color_printf("Opcao invalida! Tente novamente.\n", COLOR_RED);
                break;
        }
    }
    return 0;
}
