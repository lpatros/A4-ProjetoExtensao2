#include "reports.h"

#include <stdio.h>
#include <stdlib.h>
#include "../sale/sale.h"
#include "../../utils/utils.h"

SaleList generateSalesReport(ReportType reportType) {

    SaleList salesList = {
        .count = 0,
        .sales = NULL,
        .totalValue = 0.0
    };

    // Abre o arquivo de vendas
    FILE *file = fopen(FILE_PATH_SALE, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return salesList;
    }

    // Lê as vendas do arquivo
    Sale sale = {
        .total = 0.0, // Inicializa o total da venda
    };

    while (fscanf(file, "%d %d %lf %d %lf %s",
                  &sale.id,
                  (int *)&sale.item.type,
                  &sale.item.weight,
                  &sale.item.amount,
                  &sale.item.price,
                  sale.date) == 6)
    {
        // Realloc para aumentar o tamanho atual do array de vendas
        // e adicionar a nova venda encontrada na linha do arquivo 
        salesList.sales = realloc(salesList.sales, sizeof(Sale) * (salesList.count + 1));

        if (salesList.sales == NULL) {
            printf("Erro ao alocar memória para as vendas.\n");
            fclose(file);
            return salesList;
        }

        // Calcula o total da venda
        sale.total += (sale.item.amount * sale.item.price);

        // Atualiza o valor total das vendas
        salesList.totalValue += sale.total;

        // Adiciona a venda à lista
        salesList.sales[salesList.count++] = sale;
    }
    
    fclose(file);
    return salesList;
}

void showSalesReport(SaleList *salesList, ReportType reportType) {

    if (salesList->count == 0) {
        color_printf("Nenhuma venda registrada para o dia.\n", COLOR_YELLOW);
        return;
    }

    char *reportTypeStr;
    switch (reportType) {
        case DAILY_REPORT:
            reportTypeStr = "Relatorio Diario";
            break;
        case MONTHLY_REPORT:
            reportTypeStr = "Relatorio Mensal";
            break;
        case ANNUAL_REPORT:
            reportTypeStr = "Relatorio Anual";
            break;
        default:
            color_printf("Tipo de relatorio invalido.\n", COLOR_RED);
            return;
    }

    // Imprime as vendas registradas no formato:

    // -------------------------- reportType ---------------------------
    // | ID | Tipo |   Peso    | Quantidade | Preço Item  |    data    |
    // |  1 |   1  |   2.500   |      3     |   R$20.00   |  03/06/25  |
    // -----------------------------------------------------------------

    printf("----------------------------- %s -----------------------------\n", reportTypeStr);
    printf("| ID \t| Tipo \t| Peso \t\t| Quantidade \t| Preco Item \t| Data \t   |\n");

    int i;
    for (i = 0; i < salesList->count; i++) {
        Sale sale = salesList->sales[i];
        printf("| %d \t| %d \t| %.3fkg \t| %d \t\t| R$%.2f \t| %s |\n",
                sale.id, sale.item.type, sale.item.weight, sale.item.amount, sale.item.price, sale.date);
    }
    color_printf("----------------------------------------------------------------------------\n", COLOR_WHITE);
    printf("Total de vendas: %d\n", salesList->count);
    printf("Valor total das vendas: R$%.2f\n", salesList->totalValue);
    free(salesList->sales);
}

// // I. Função para gerar relatório diário
// void gerarRelatorioDiario() {
//     if (contadorDias >= DIAS_MES) {
//         printf("\nLimite de dias no mes atingido. Feche o mes para continuar.\n");
//         return;
//     }

//     double totalDia = 0;
//     printf("\n========================================\n");
//     printf("      RELATORIO DO DIA %d\n", contadorDias + 1);
//     printf("========================================\n");
//     int i;
//     for (i = 0; i < contadorVendasDia; i++) {
//         printf("Venda %03d: ", i + 1);
//         switch (vendasDiarias[i].tipo) {
//             case REFEICAO_QUILO:
//                 printf("Refeicao a Quilo | Peso: %.3fkg | Valor: R$ %6.2f\n", vendasDiarias[i].peso, vendasDiarias[i].valorTotal);
//                 break;
//             case QUENTINHA:
//                 printf("Quentinha        | Quantidade: %-5d | Valor: R$ %6.2f\n", vendasDiarias[i].quantidade, vendasDiarias[i].valorTotal);
//                 break;
//             case BEBIDA:
//                 printf("Bebida           | Quantidade: %-5d | Valor: R$ %6.2f\n", vendasDiarias[i].quantidade, vendasDiarias[i].valorTotal);
//                 break;
//         }
//         totalDia += vendasDiarias[i].valorTotal;
//     }
//     printf("----------------------------------------\n");
//     printf("Total Vendido no Dia: R$ %.2f\n", totalDia);
//     printf("----------------------------------------\n\n");

//     totalVendasMes[contadorDias] = totalDia;
//     contadorDias++;
//     contadorVendasDia = 0; // Prepara para o próximo dia
// }

// // I. Função para gerar relatório mensal
// void gerarRelatorioMensal() {
//     if (contadorMeses >= MESES_ANO) {
//         printf("\nLimite de meses no ano atingido. Feche o ano para continuar.\n");
//         return;
//     }
    
//     double totalMes = 0;
//     printf("\n========================================\n");
//     printf("      RELATORIO DO MES %d\n", contadorMeses + 1);
//     printf("========================================\n");
//     int j;
//     for (j = 0; j < contadorDias; j++) {
//         printf("Dia %02d: R$ %.2f\n", j + 1, totalVendasMes[j]);
//         totalMes += totalVendasMes[j];
//     }
//     printf("----------------------------------------\n");
//     printf("Total Vendido no Mes: R$ %.2f\n", totalMes);
//     printf("----------------------------------------\n\n");

//     totalVendasAno[contadorMeses] = totalMes;
//     contadorMeses++;
//     contadorDias = 0; // Prepara para o próximo mês
// }

// // I. Função com algoritmo de ordenação (Bubble Sort)
// void orderSales(double valores[], int meses[], int tamanho) {
//     int i;
//     for (i = 0; i < tamanho - 1; i++) {
//         int j;
//         for (j = 0; j < tamanho - i - 1; j++) {
//             if (valores[j] < valores[j+1]) {
//                 // Troca os valores
//                 double tempValor = valores[j];
//                 valores[j] = valores[j+1];
//                 valores[j+1] = tempValor;

//                 // Troca os índices dos meses
//                 int tempMes = meses[j];
//                 meses[j] = meses[j+1];
//                 meses[j+1] = tempMes;
//             }
//         }
//     }
// }

// // I. Função para gerar relatório anual
// void gerarRelatorioAnual() {
//     printf("\n======================================================\n");
//     printf("  RELATORIO ANUAL DE VENDAS (ORDEM DECRESCENTE)\n");
//     printf("======================================================\n");

//     // Cria cópias para não alterar os dados originais
//     double copiaValores[MESES_ANO];
//     int mesesIndices[MESES_ANO];
//     int indice;
//     for(indice = 0; indice < contadorMeses; indice++) {
//         copiaValores[indice] = totalVendasAno[indice];
//         mesesIndices[indice] = indice + 1; // Armazena o número do mês (1 a 12)
//     }

//     orderSales(copiaValores, mesesIndices, contadorMeses);

//     printf("Posicao | Mes | Total Vendido\n");
//     printf("----------------------------------\n");
//     int n;
//     for (n = 0; n < contadorMeses; n++) {
//         printf("%-7d | %-3d | R$ %.2f\n", n + 1, mesesIndices[n], copiaValores[n]);
//     }
//     printf("----------------------------------\n\n");
    
//     // Opcional: resetar os dados anuais após o relatório
//     contadorMeses = 0; 
// }
