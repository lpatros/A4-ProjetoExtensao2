#include "reports.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sale/sale.h"
#include "../../utils/utils.h"

int isDateInReportRange(const char* saleDate, ReportType reportType) {

    // Obtém a data atual
    Time currentTime = {
        .now = getCurrentTime(),
    };

    // Formata o timestamp atual no formato "DD/MM/AA"
    formatDateTime(currentTime.now, currentTime.dateStr);
    
    // Extrai componentes da data atual
    sscanf(currentTime.dateStr, "%d/%d/%d", &currentTime.day, &currentTime.month, &currentTime.year);
    
    // Extrai componentes da data da venda
    Time saleTime;
    if (sscanf(saleDate, "%d/%d/%d", &saleTime.day, &saleTime.month, &saleTime.year) != 3) {
        return false;
    }
    
    // Retorna true se a data da venda estiver dentro do intervalo do relatório
    switch (reportType) {
        case DAILY_REPORT:
            return (saleTime.day == currentTime.day &&
                    saleTime.month == currentTime.month &&
                    saleTime.year == currentTime.year);

        case MONTHLY_REPORT:
            return (saleTime.month == currentTime.month &&
                    saleTime.year == currentTime.year);

        case ANNUAL_REPORT:
            return (saleTime.year == currentTime.year);

        default:
            return false;
    }
}

SaleList generateSalesReport(ReportType reportType) {

    SaleList salesList = {
        .countLines = 0,
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
    Sale sale;
    while (fscanf(file, "%d %d %lf %d %lf %s",
                  &sale.id,
                  (int *)&sale.item.type,
                  &sale.item.weight,
                  &sale.item.amount,
                  &sale.item.price,
                  sale.date) == 6)
    {
        // Verifica se a data da venda não está no período do relatório
        if (!isDateInReportRange(sale.date, reportType)) {
            continue; // Se não estiver, pula essa venda
        }
        
        // Realloc para aumentar o tamanho atual do array de vendas
        // e adicionar a nova venda encontrada na linha do arquivo 
        salesList.sales = realloc(salesList.sales, sizeof(Sale) * (salesList.countLines + 1));

        if (salesList.sales == NULL) {
            printf("Erro ao alocar memória para as vendas.\n");
            fclose(file);
            return salesList;
        }

        // Calcula o total da venda
        sale.total = (sale.item.amount * sale.item.price);

        // Atualiza o valor total das vendas
        salesList.totalValue += sale.total;

        // Incrementa o total de vendas se o id da venda atual não for o mesmo do anterior
        if (salesList.sales[salesList.countLines - 1].id != sale.id) {
            salesList.totalSales++;
        }

        // Adiciona a venda à lista
        salesList.sales[salesList.countLines++] = sale;
    }
    
    fclose(file);
    return salesList;
}

void showSalesReport(ReportType reportType) {

    // Inicializa a lista de vendas
    SaleList salesList = {
        .countLines = 0,
        .sales = NULL,
        .totalValue = 0.0
    };

    salesList = generateSalesReport(reportType);

    if (salesList.countLines == 0) {
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

    // Imprime as vendas registradas

    printf("----------------------------- %s -----------------------------\n", reportTypeStr);
    printf("| ID \t| Tipo \t| Peso \t\t| Quantidade \t| Preco Item \t| Data \t   |\n");
    color_printf("----------------------------------------------------------------------------\n", COLOR_WHITE);
    
    int i;
    for (i = 0; i < salesList.countLines; i++) {
        
        Sale sale = salesList.sales[i];
        
        printf("| %d \t| %d \t| %.3fkg \t| %d \t\t| R$%.2f \t| %s |\n",
            sale.id, sale.item.type, sale.item.weight, sale.item.amount, sale.item.price, sale.date);
            
        if (salesList.sales[i + 1].id != sale.id) {
            printf("|----\t|----\t|--------\t|----\t\t|-------\t|----------|\n");
        }
    }
    color_printf("----------------------------------------------------------------------------\n", COLOR_WHITE);
    printf("Numero total de vendas registradas: %d\n", salesList.totalSales);
    printf("Valor total vendido: R$%.2f\n", salesList.totalValue);
    free(salesList.sales);
}
