#include <stdio.h>
#define Senha 2026
int login()
{
    char usuario[50];
    int senha;

    printf("\nOlá bem-vindo ao banco Rotom, por favor insira o usuario e a senha: \n");
    fgets(usuario, 50, stdin);
    scanf("%d", &senha);

    if (senha == Senha)
    {
        printf("Bem vindo %s", usuario);
    }

    else
    {
        printf("Senha incorreta! Por favor, tente novamente mais tarde.\n");
        return 0;
    }
}
int main(void)
{

    login();

    return 0;
}