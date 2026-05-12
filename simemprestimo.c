#include <stdio.h>
int simemp(void)
{
    int escolaridade, nparcelas, vparcelas, taxa = 100, emp, emptotal = 0, pparcela = 0, pgparcela = 0;

    // conferindo escolaridade
    printf("Bem vindo a simulação de emprestimos do banco Rotom. Por favor insira o seu nível de escolaridade: \n");
    printf("Caso tenha ensino fundamental insira(1), caso tenha médio insira(2), caso tenha ensino supeior insira 3) e caso tenha pós graduação insira(4).\n");
    scanf("%d", &escolaridade);
    if (escolaridade == 1)
    {
        printf("Não podemos liberar emprestimos para alguém no ensino fundamental, sentimos muito. Tenha um bom dia.\n");
        return 0;
    }
    else if (escolaridade < 1 || escolaridade > 4)
    {
        printf("Erro! tente novamente mais tarde.\n");
        return 0;
    }

    printf("Quanto você planeja para o valor do emprestimo?\n");
    scanf("%d", &emp);

    printf("Em quantas parcelas gostaria de efetuar o pagamento? \n");
    scanf("%d", &nparcelas);

    vparcelas = emp / nparcelas;
    vparcelas = vparcelas + taxa;
    emptotal = vparcelas * nparcelas;

    if (escolaridade == 2 || escolaridade == 3)
    {
        printf("Perfeito, nós temos uma pequena taxa de 100 reais por parcela, então o emprestimo de %d, vai ser pago em %d parcelas de %d, para um total de: %d.\n", emp, nparcelas, vparcelas, emptotal);
    }

    else if (escolaridade == 4)
    {
        pparcela = vparcelas - taxa;
        pgparcela = pparcela + (vparcelas * (nparcelas - 1));

        printf("Perfeito, como você é Pós Graduado(a), temos um desconto de 100 reais na primeira parcela. nós temos uma pequena taxa de 100 reais por parcela, então o emprestimo de %d, vai ser pago em %d parcelas de %d, para um total de: %d.\n", emp, nparcelas, vparcelas, pgparcela);
    };

    return 0;
}

int main()
{
    simemp();
    return 0;
}