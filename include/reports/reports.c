#include "reports.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDateInRange(const char* saleDate, Time* time, FilterType filterType) {

    // Formata o timestamp atual no formato "DD/MM/AA"
    formatDateTime(time->now, time->dateStr);
    
    // Extrai componentes da data atual
    sscanf(time->dateStr, "%d/%d/%d", &time->day, &time->month, &time->year);
    
    // Extrai componentes da data da venda
    Time saleTime;
    if (sscanf(saleDate, "%d/%d/%d", &saleTime.day, &saleTime.month, &saleTime.year) != 3) {
        return false;
    }
    
    // Retorna true se a data da venda estiver dentro do intervalo do relatório
    switch (filterType) {
        case DAY:
            return (saleTime.day == time->day &&
                    saleTime.month == time->month &&
                    saleTime.year == time->year);

        case MONTH:
            return (saleTime.month == time->month &&
                    saleTime.year == time->year);

        case YEAR:
            return (saleTime.year == time->year);

        default:
            return false;
    }
}

SaleList getSalesByTime(FilterType filterType, Time* time) {

    SaleList salesList = {
        .countLines = 0,
        .sales = NULL,
        .totalValue = 0.0,
        .totalSales = 0
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
        if (!isDateInRange(sale.date, time, filterType)) {
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

void showSalesByDay() {

    // Inicializa a lista de vendas
    SaleList salesList = {
        .countLines = 0,
        .sales = NULL,
        .totalValue = 0.0,
        .totalSales = 0
    };

    Time time = {
        .now = getCurrentTime(),
    };

    salesList = getSalesByTime(DAY, &time);

    if (salesList.countLines == 0) {
        color_printf("Nenhuma venda registrada para o dia.\n", COLOR_YELLOW);
        return;
    }

    // Imprime as vendas registradas

    color_printf("------------------------------------- Relatorio Diario -------------------------------------\n", COLOR_WHITE);
    printf("| ID \t| Tipo \t| Peso \t\t| Quantidade \t| Preco Item \t| Total Venda\t| Data \t   |\n");
    color_printf("--------------------------------------------------------------------------------------------\n", COLOR_WHITE);
    
    int i;
    for (i = 0; i < salesList.countLines; i++) {
        
        Sale sale = salesList.sales[i];
        
        printf("| %d \t| %d \t| %.3fkg \t| %d \t\t| R$%.2f \t| R$%.2f \t| %s |\n",
            sale.id, sale.item.type, sale.item.weight, sale.item.amount, sale.item.price, sale.total, sale.date);
            
        if (salesList.sales[i + 1].id != sale.id) {
            printf("|----\t|----\t|--------\t|----\t\t|-------\t|-------\t|----------|\n");
        }
    }
    color_printf("--------------------------------------------------------------------------------------------\n", COLOR_WHITE);
    color_printf("|\t   Total Vendas Registradas\t\t|\t   Valor Total Vendido\t\t   |\n", COLOR_WHITE);
    color_printf("--------------------------------------------------------------------------------------------\n", COLOR_WHITE);
    printf("|\t\t\t%d\t\t\t|\t\tR$%.2f\t\t\t   |\n", salesList.totalSales, salesList.totalValue);
    color_printf("--------------------------------------------------------------------------------------------\n", COLOR_WHITE);
    
    free(salesList.sales);
}

void sortMonthSalesByTotal(MonthMap *month) {

    // Ordena os meses com base no total de vendas usando o algoritmo Bubble Sort
    for (int i = 0; i < 12; i++) {

        // Percorre os meses restantes para comparar e ordenar
        for (int j = 0; j < 12 - i; j++) {

            // Compara o total do mês atual com o próximo mês
            if (month[j].total < month[j + 1].total) {

                // Troca os meses se o total do mês atual for menor que o próximo
                MonthMap temp = month[j];
                month[j] = month[j + 1];
                month[j + 1] = temp;
            }
        }
    }
}

void showSalesByMonth() {

    // Inicializa a lista de vendas para o ano
    SaleList yearList = {
        .countLines = 0,
        .sales = NULL,
        .totalValue = 0.0,
        .totalSales = 0
    };

    // Obtém o timestamp atual e inicializa a estrutura Time
    Time currentYearTime = {
        .now = getCurrentTime(),
    };

    // Pega as vendas do ano atual
    yearList = getSalesByTime(YEAR, &currentYearTime);

    // Verifica se há vendas registradas no ano atual
    if (yearList.countLines == 0) {
        color_printf("Nenhuma venda registrada durante esse ano.\n", COLOR_YELLOW);
        return;
    }

    // Se há vendas registradas:

    // Inicializa o array de meses com nomes e totais zerados
    MonthMap monthName[12] = {
        {"Janeiro", 0.0}, {"Fevereiro", 0.0}, {"Marco", 0.0},
        {"Abril", 0.0}, {"Maio", 0.0}, {"Junho", 0.0},
        {"Julho", 0.0}, {"Agosto", 0.0}, {"Setembro", 0.0},
        {"Outubro", 0.0}, {"Novembro", 0.0}, {"Dezembro", 0.0}
    };

    // Acumula os totais de vendas para cada mês
    for (int i = 0; i < yearList.countLines; i++) {
        
        int saleDay, saleMonth, saleYearInSale;

        // Extrai o mês da data da venda (formato "DD/MM/AA")
        if (sscanf(yearList.sales[i].date, "%d/%d/%d", &saleDay, &saleMonth, &saleYearInSale) == 3) {

            // Converte mês (1-12) para índice (0-11)
            int monthIndex = saleMonth - 1;

            monthName[monthIndex].total += yearList.sales[i].total;
        }
    }

    // Ordena os meses com base no total de vendas
    sortMonthSalesByTotal(monthName);

    color_printf("---------------------- Relatorio Mensal ---------------------\n", COLOR_WHITE);
    color_printf("\tMes\t\t\t|\t\tTotal\t\n", COLOR_WHITE);
    color_printf("-------------------------------------------------------------\n", COLOR_WHITE);
    
    // Imprime os totais de vendas por mês
    for (int i = 0; i < 12; i++) {

        // Imprime apenas os meses com vendas registradas
        if (monthName[i].total > 0.1) {

            // %-15s para alinhar o nome do mês a esquerda
            printf("\t%-15s\t\t|\t\tR$%.2f\t\n", monthName[i].text, monthName[i].total);
        }
    }

    color_printf("-------------------------------------------------------------\n", COLOR_WHITE);
    
    free(yearList.sales);
}
