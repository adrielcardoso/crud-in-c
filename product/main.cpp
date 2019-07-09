//
//  main.cpp
//  product
//
//  Created by ctima setec on 09/07/19.
//  Copyright © 2019 ctima setec. All rights reserved.
//

#include <iostream>

struct node{
    int number;
    node *next;
};

bool isEmpty(node *head);
char menu();
void insertAsFirtElement(node *&head, node *&last, int number);
void insert(node *&head, node *&last, int number);
void remove(node *&head, node *&last);
void showList(node *current);

bool isEmpty(node *head)
{
    if(head == NULL)
        return true;
    else
    return false;
}

char menu()
{
    char choice;
    
    std::cout << "Menu\n";
    
    std::cout << "1. Add an item. \n";
    std::cout << "2. Remove an item. \n";
    std::cout << "3. Show the list. \n";
    std::cout << "4. Exit. \n";
    
    std::cin >> choice;
    
    return choice;
}

void insertAsFirtElement(node *&head, node *&last, int number)
{
    node *temp = new node;
    temp->number = number;
    temp->next = NULL;
    head = temp;
    last = temp;
}

void insert(node *&head, node *&last, int number)
{
    if(isEmpty(head))
        insertAsFirtElement(head, last, number);
    else
    {
        node *temp = new node;
        temp->number = number;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void remove(node *&head, node *&last)
{
    if (isEmpty(head)) {
        std::cout << "The List is already empty \n";
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


void showList(node *current)
{
    if (isEmpty(current)) {
        std::cout << "The List is empty \n";
    }else{
        std::cout << "The List Contains: \n";
        while (current != NULL) {
            std::cout << current->number << std::endl;
            current = current->next;
        }
    }
}

int main(int argc, const char * argv[])
{
    node *head = NULL;
    node *last = NULL;
    
    char choice;
    int number;
    
    do{
        choice = menu();
        
        switch (choice) {
            case '1':
                    std::cout << "Please enter a number: ";
                    std::cin >> number;
                    insert(head, last, number);
                 break;
                
            case '2' : remove(head, last);
                break;
                
            case '3' : showList(head);
                break;
                
            default:
                    std::cout << "System exit\n ";
                break;
        }
        
    }while(choice != '4');
    
    return 0;
}
