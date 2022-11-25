#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define TAM 5

struct tipo_pessoa {
    int numero_conta;
    char nome[20];
    int rg;
    char cpf[20];
    float renda_mensal;
    char tipo_conta[20];
    char endereco[20];
    int telefone;
    char email[20];

};

typedef struct tipo_pessoa tipo_pessoa;

void cadastrar_clientes(char nome[], char tipo_conta[], int numero_conta, int rg, char cpf[], float renda_mensal, char endereco[], int telefone, char email[]){
    
    tipo_pessoa lista[TAM];
    
    for(int i=0; i<TAM;i++){
        lista[i].numero_conta = numero_conta;
        strcpy(lista[i].nome, nome);
        strcpy(lista[i].nome, tipo_conta);
        lista[i].rg = rg;
        strcpy(lista[i].nome, cpf);
        lista[i].renda_mensal= renda_mensal;
        strcpy(lista[i].nome, endereco);
        lista[i].telefone = telefone;
        strcpy(lista[i].nome, email);
    }
}


void listar_clientes(){
    tipo_pessoa lista[TAM];
    
    for(int i=0;i<TAM;i++) {
        setlocale(LC_ALL,"Portuguese");

        printf(" ============= Pessoa %d =============\n", i+1);
        printf("Nome completo: %s\n",lista[i].nome);
        printf("Tipo de conta: %s\n",lista[i].tipo_conta);
        printf("Numero da conta: %d\n",lista[i].numero_conta);
        printf("Rg: %d\n",lista[i].rg);
        printf("Cpf: %s\n",lista[i].cpf);
        printf("Renda mensal: %.2f\n",lista[i].renda_mensal);
        printf("Endereço: %s\n",lista[i].endereco);
        printf("Telefone: %d\n",lista[i].telefone);
        printf("E-mail: %s\n",lista[i].email);

    }
}

int main() {
    
    setlocale(LC_ALL, "Portuguese");
    int numero_conta;
    char nome[50];
    int rg;
    char cpf[11];
    float renda_mensal;
    char tipo_conta[50];
    char endereco[50];
    int telefone;
    char email[50];
    
    int opcao;
    
    printf("\n ============= Bank ============ \n");
    printf("""[1] Cadastrar\n[2] Listar Clientes\n[3] Pesquisar\n[4] Sair do Sistema\n""");
    scanf("%d",&opcao);

    while(opcao != 4){
        if (opcao == 1){
            // CADASTRAR
            //scanf("%s",nome);
            scanf("%d",&opcao);
                while (opcao!=0){
                    scanf("%s",tipo_conta);
                    scanf("%d",&numero_conta);
                    scanf("%d",&rg);
                    scanf("%s",cpf);
                    scanf("%f",&renda_mensal);
                    scanf("%s",endereco);
                    scanf("%d",&telefone);
                    scanf("%s",email);
            
                    cadastrar_clientes(nome, tipo_conta, numero_conta, rg, cpf, renda_mensal,endereco, telefone, email);
                    scanf("%s",nome);
                }
                scanf("%d",&opcao);
        }else{
            printf("opção inválida.");
            scanf("%d",&opcao);
        }
    }
    

}