#include <stdio.h>
#include "utils/utils.h"
#include "include/sale/sale.h"

int main() {

    int option = 0;
    while (option != 5) {
        
        menu();
        scanf("%d", &option);

        clearTerminal();

        switch (option) {

            case 1:
                registerSale();
                break;
            // case 2:
            //     gerarRelatorioDiario();
            //     break;
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
