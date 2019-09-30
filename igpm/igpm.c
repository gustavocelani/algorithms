/*
 * =====================================================================================
 *
 *       Filename:  igpm.c
 *
 *    Description:  Calculo de IGPM
 *
 *        Version:  1.0
 *        Created:  20/04/2018 10:15:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gustavo Celani
 *
 * =====================================================================================
 */

/** Includes */
#include <stdlib.h>
#include <stdio.h>

/** Defines */
#define SEPARATOR "############################################\n"

/**
 * calcula_igpm
 */
void calcula_igpm(unsigned int ano_base, float valor_total, unsigned int parcelas_total, float igpm_percent) {
	float valor_restante = valor_total;
	float valor_parcela_atual = 0;
	float valor_pago_no_ano = 0;
	float reajuste = 0;
	float percent_reajuste = 0;
	float valor_real_pago = valor_total;
	unsigned int num_parcelas_restantes = parcelas_total;
	unsigned int num_parcelas_no_ano = 0;

	unsigned int num_anos = ((parcelas_total % 12) + 1);

	for (unsigned int i = 0; i < num_anos; i++) {
		printf("[%d]\n", (ano_base + i));

		valor_parcela_atual = valor_restante / num_parcelas_restantes;
		num_parcelas_no_ano = (num_parcelas_restantes >= 12 ? 12: num_parcelas_restantes);
		valor_pago_no_ano = num_parcelas_no_ano * valor_parcela_atual;

		printf("    x%2d parcelas de     R$%.2f\n", num_parcelas_no_ano, valor_parcela_atual);
		printf("    Valor pago no ano:  R$%.2f\n", valor_pago_no_ano);

		num_parcelas_restantes = num_parcelas_restantes - num_parcelas_no_ano;
		valor_restante = valor_restante - valor_pago_no_ano;
		reajuste = valor_restante * igpm_percent / 100;
		valor_restante = valor_restante + reajuste;
		valor_real_pago = valor_real_pago + reajuste;

		printf("    Reajuste:           R$%.2f\n", reajuste);
		printf("\n");
	}

	printf(SEPARATOR);
	printf("\n");

	percent_reajuste = ((valor_real_pago * 100) / valor_total);

	printf("Valor inicial:          R$%.2f\n", valor_total);
	printf("Total de reajuste:      R$%.2f\n\n", valor_real_pago - valor_total);

	printf("Valor real pago:        R$%.2f\n", valor_real_pago);
	printf("Reajuste [%%]:           %.2f%%\n", percent_reajuste);
}

/**
 * Main loop
 */
int main(void) {

	float valor_total               = 0;
	float igpm_percent              = 0;
	unsigned int ano_base           = 0;
	unsigned int num_parcelas_total = 0;

	system("clear");

	printf("\n\n");
	printf(SEPARATOR);
	printf("Indice Geral de Precos do Mercado - IGPM\n");
	printf(SEPARATOR);
	printf("\n");

	printf("Valor do Imovel:    R$");
	scanf("%f", &valor_total);

	printf("Numero de Parcelas: ");
	scanf("%d", &num_parcelas_total);

	printf("Ano Base:           ");
	scanf("%d", &ano_base);

	printf("IGPM Fixo [%%]:      ");
	scanf("%f", &igpm_percent);

	printf("\n");
	printf(SEPARATOR);
	printf("\n");

	calcula_igpm(ano_base, valor_total, num_parcelas_total, igpm_percent);

	printf("\n");
	printf(SEPARATOR);
	printf("\n\n");

	return 0;
}
