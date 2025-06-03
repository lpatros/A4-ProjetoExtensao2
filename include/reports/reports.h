#ifndef reports_H
#define reports_H

typedef enum {
    DAILY_REPORT,
    MONTHLY_REPORT,
    ANNUAL_REPORT
} ReportType;

void generateSalesReport(ReportType reportType);

// void gerarRelatorioMensal();
// void gerarRelatorioAnual();

// void orderSales(double valores[], int meses[], int tamanho);

#endif