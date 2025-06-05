#ifndef reports_H
#define reports_H

#include "../sale/sale.h"
#include "../../utils/utils.h"

typedef enum {
    DAY,
    MONTH,
    YEAR
} ReportType;

typedef struct {
    char* text;     // Nome do mês
    double total;   // Valor total vendido no mês
} MonthMap;

int isDateInRange(const char* saleDate, Time* time, ReportType reportType);

SaleList getSalesByTime(ReportType reportType, Time* time);

void showSalesByDay();

void sortMonthSalesByTotal(MonthMap *month);

void showSalesByMonth();

#endif