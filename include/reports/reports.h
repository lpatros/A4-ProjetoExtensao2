#ifndef reports_H
#define reports_H

#include "../sale/sale.h"

typedef enum {
    DAILY_REPORT,
    MONTHLY_REPORT,
    ANNUAL_REPORT
} ReportType;

SaleList generateSalesReport(ReportType reportType);

void showSalesReport(ReportType reportType);

#endif