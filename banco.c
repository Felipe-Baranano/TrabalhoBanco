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

    return 1;
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