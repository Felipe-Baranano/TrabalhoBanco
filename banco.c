#include <stdio.h>
#define Senha 2026
int login()
{
    char usuario[50];
    int senha;

    printf("\nOla bem-vindo ao banco Rotom, por favor insira o usuario e a senha: \n");
    fgets(usuario, 50, stdin);
    scanf("%d", &senha);
    getchar(); /* limpa o '\n' que o scanf deixa no buffer */

    if (senha == Senha)
    {
        printf("Bem vindo %s", usuario);
        return 1;
    }
    else
    {
        printf("Senha incorreta! Por favor, tente novamente mais tarde.\n");
        return 0;
    }
}

int cadastroCliente()
{
    char nome[100];
    int idade;
    int escolaridade;

    printf("\n=== Cadastro de Cliente ===\n");

    printf("\nInforme o nome completo: ");
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0'; /* remove o '\n' do final */

    printf("Informe a idade: ");
    scanf("%d", &idade);

    printf("\nNivel de escolaridade:\n");
    printf("1 - Ensino Fundamental\n");
    printf("2 - Ensino Medio\n");
    printf("3 - Ensino Superior\n");
    printf("4 - Pos-Graduacao\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolaridade);

    if (escolaridade == 1)
    {
        printf("\nCadastro nao permitido: clientes com ensino fundamental nao podem fazer emprestimos.\n");
        return 0;
    }

    printf("\n--- Dados salvos com sucesso! ---\n");
    printf("Nome       : %s\n", nome);
    printf("Idade      : %d\n", idade);

    if (escolaridade == 2)
        printf("Escolaridade: Ensino Medio\n");
    else if (escolaridade == 3)
        printf("Escolaridade: Ensino Superior\n");
    else if (escolaridade == 4)
    {
        printf("Escolaridade: Pos-Graduacao\n");
        printf("Desconto de R$100,00 aplicado na primeira parcela!\n");
    }
    else
    {
        printf("Opcao de escolaridade invalida.\n");
        return 0;
    }

    simemp(escolaridade);

    return 1;
}

int simemp(int escolaridade)
{
    int avancar;
    int nparcelas, vparcelas, taxa = 100, emp, emptotal = 0, pparcela = 0, pgparcela = 0;

    printf("\nBem vindo a simulação de emprestimos do banco Rotom.\n");
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
        // confirmando o emprestimo
        printf("Perfeito, agora que concluiu a simulação, gostaria de realizar o emprestimo? se sim, insira (1) \n");
        scanf("%d", &avancar);

        if (avancar == 1)
        {
            printf("Perfeito, o emprestimo foi realizado em um total de %d para ser pago em %d parcelas de %d.\n", emptotal, nparcelas, vparcelas);
            return 0;
        }
        else
        {
            printf("Encerrando a simulação. Tenha um bom dia.\n");
            return 0;
        }
    }

    else if (escolaridade == 4)
    {
        pparcela = vparcelas - taxa;
        pgparcela = pparcela + (vparcelas * (nparcelas - 1));

        printf("Perfeito, como você é Pós Graduado(a), temos um desconto de 100 reais na primeira parcela. nós temos uma pequena taxa de 100 reais por parcela, então o emprestimo de %d, vai ser pago em %d parcelas de %d, para um total de: %d.\n", emp, nparcelas, vparcelas, pgparcela);
        // confirmando o emprestimo
        printf("Perfeito, agora que concluiu a simulação, gostaria de realizar o emprestimo? se sim, insira (1) \n");
        scanf("%d", &avancar);

        if (avancar == 1)
        {
            printf("Perfeito, o emprestimo foi realizado em um total de %d para ser pago em %d parcelas de %d, Sendo a primeira parcela de: %d\n", pgparcela, nparcelas, vparcelas, pparcela);
            return 0;
        }
        else
        {
            printf("Encerrando a simulação. Tenha um bom dia.\n");
            return 0;
        }
    }

    return 0;
}

int main(void)
{

    int logado = login();

    if (logado == 1)
    {
        cadastroCliente();
    }

    return 0;
}