//
//  main.cpp
//  product
//
//  Created by ctima setec on 09/07/19.
//  Copyright © 2019 ctima setec. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    node *next;
    int codigo;
    string nome;
    int quantidade;
    float preco;
};

/**
 declarando variaveis que serao utilizadas
 */
bool isEmpty(node *head);
char menu();
void insertAsFirtElement(node *&head, node *&last, string nome, int quantidade, float preco, int codigo);
void insert(node *&head, node *&last, string nome, int quantidade, float preco, int codigo);
void remove(node *&head, node *&last);
void showList(node *current);

/**
 funcao principal
 */
int main(int argc, const char * argv[])
{
    node *head = NULL;
    node *last = NULL;
    
    char choice;
    int codigo;
    string nome;
    int quantidade;
    float preco;
    
    do{
        choice = menu();
        
        switch (choice) {
            case '1':
                
                cout << "CADASTRO DE PRODUTO ";
                cout << "Insira Nome: ";
                cin >> nome;
                
                cout << "Insira Quantidade: ";
                cin >>  quantidade;

                cout << "Insira Preco: ";
                cin >>  preco;

                cout << "Insira codigo: ";
                cin >>  codigo;
                
                insert(head, last, nome, quantidade, preco, codigo);
                break;
                
            case '2' : remove(head, last);
                break;
                
            case '3' : showList(head);
                break;
                
            default:
                std::cout << "Saindo do sistema\n ";
                break;
        }
        
    }while(choice != '4');
    
    return 0;
}

void write(node *produto){
    FILE *outfile;
    
    outfile = fopen ("produtos.dat", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\n Erro ao abrir o arquivo \n");
        exit (1);
    }
    
    fwrite (produto, sizeof(produto), 1, outfile);
    
    if(fwrite != 0)
        cout << "Escrito no arquivo com sucesso !\n";
    else
        cout << "Erro ao ler o arquivo !\n";
    
    // close file
    fclose (outfile);
}
//
//void read(){
//    FILE *infile;
//    struct node input;
//
//    infile = fopen ("person.dat", "r");
//    if (infile == NULL)
//    {
//        cout << "\n Erro ao abrir o arquivo \n";
//        exit (1);
//    }
//
//    while(fread(&input, sizeof(node), 1, infile))
//        std::cout << "Nome: \n";
//        std::cout << input.nome << std::endl;
//        std::cout << "Preco: \n";
//        std::cout << input.preco << std::endl;
//        std::cout << "Quantidade: \n";
//        std::cout << input.quantidade << std::endl;
//        std::cout << "Codigo: \n";
//        std::cout << input.codigo << std::endl;
//        std::cout << "_________________________ \n";
//
//    fclose (infile);
//}

/**
 funcao para validar se object esta null
 */
bool isEmpty(node *head)
{
    if(head == NULL)
        return true;
    else
    return false;
}

/**
 funcao responsavel por montar a estrutura do menu
 */
char menu()
{
    char choice;
    
    /**
     std inclui a funcionalidade da biblioteca padrão C
     */
    
    std::cout << "Menu\n";
    
    std::cout << "1. Add item. \n";
    std::cout << "2. Remover Item. \n";
    std::cout << "3. Mostrar Lista. \n";
    std::cout << "4. Sair. \n";
    
    std::cin >> choice;
    
    return choice;
}

/**
    adicionamento o primeiro elemento do index.
 */
void insertAsFirtElement(node *&head, node *&last, string nome, int quantidade, float preco, int codigo)
{
    node *temp = new node;
    temp->nome = nome;
    temp->quantidade = quantidade;
    temp->preco = preco;
    temp->codigo = codigo;
    temp->next = NULL;
    head = temp;
    last = temp;
    
    write(temp);
}


/**
 inserindo novos elementos no index
 */
void insert(node *&head, node *&last, string nome, int quantidade, float preco, int codigo)
{
    if(isEmpty(head))
        insertAsFirtElement(head, last, nome, quantidade, preco, codigo);
    else
    {
        node *temp = new node;
        temp->nome = nome;
        temp->quantidade = quantidade;
        temp->preco = preco;
        temp->codigo = codigo;
        temp->next = NULL;
        last->next = temp;
        last = temp;
        
        write(temp);
    }
}

/**
 removendo elementos da estrutura
 */
void remove(node *&head, node *&last)
{
    if (isEmpty(head)) {
        std::cout << "A lista esta vazia \n";
    }else if(head == last){
        delete head;
        head = NULL;
        last = NULL;
    }else{
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 mostrando todos os itens da estrutura
 */
void showList(node *current)
{
    if (isEmpty(current)) {
        std::cout << "Lista Vazia \n";
    }else{
        std::cout << "A Lista contain: \n";
        while (current != NULL) {
            std::cout << "Nome: \n";
            std::cout << current->nome << std::endl;
            std::cout << "Preco: \n";
            std::cout << current->preco << std::endl;
            std::cout << "Quantidade: \n";
            std::cout << current->quantidade << std::endl;
            std::cout << "Codigo: \n";
            std::cout << current->codigo << std::endl;
            std::cout << "_________________________ \n";
            current = current->next;
        }
    }
}
