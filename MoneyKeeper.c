#include <stdio.h>
#include <string.h>

int opcao = -1;
float saldo, despesa, receita;
int total = 0;

struct Transacao {
    int id;
    char nome[50];
    float valor;
    char data[11];
    char tipo[11];
};
struct Transacao transacoes[100];

int main()
{
    char confirmar;

    while (opcao != 0) 
    {

        printf ( "Selecione uma das opções abaixo \n 1 - Registrar receita \n 2 - Registrar despesa \n 3 - Consultar saldo \n 0 - Sair \n");
        
        if (scanf("%d", &opcao) != 1)
        {
            printf("Invalido.\n");

            while (getchar() != '\n');

            opcao = -1;
        }

        else
        {
             if (opcao == 1 || opcao == 2)
            {
                printf("Deseja continuar? (S/N): ");
                scanf(" %c", &confirmar);

                if (confirmar == 'N' || confirmar == 'n')
                {
                    continue;
                }
            }

            switch (opcao) 
            {
                case 1:
                    transacoes[total].id = total + 1;

                    printf("Digite o nome da receita: ");
                    scanf(" %49[^\n]", transacoes[total].nome);

                    printf("Digite o valor da receita: ");
                    scanf("%f", &transacoes[total].valor);

                    printf("Digite a data (DD/MM/AAAA): ");
                    scanf(" %10s", transacoes[total].data);

                    strcpy(transacoes[total].tipo, "receita");

                    total++;

                    break;
                case 2:
                    transacoes[total].id = total + 1;

                    printf("Digite o nome da despesa: ");
                    scanf(" %49[^\n]", transacoes[total].nome);

                    printf("Digite o valor da despesa: ");
                    scanf("%f", &transacoes[total].valor);

                    printf("Digite a data (DD/MM/AAAA): ");
                    scanf(" %10s", transacoes[total].data);

                    strcpy(transacoes[total].tipo, "despesa");

                    total++;

                    break;
                
                case 3:
                    saldo = 0;

                    for (int i = 0 ; i < total; i++)
                    {
                        if (strcmp(transacoes[i].tipo, "receita") == 0)
                        {
                            saldo += transacoes[i].valor;
                        }
                        else
                        {
                            saldo -= transacoes[i].valor;
                        }
                    }

                    printf("consultar saldo.\n");
                    printf("Seu saldo é: R$ %.2f\n", saldo);
                    break;
                
                case 0:
                    printf("Saindo do programa\n");
                    break;

                default:
                    printf("numero invalido!\n");
                    break;
            }

        }
      

    }
    
    return 0;
    
}