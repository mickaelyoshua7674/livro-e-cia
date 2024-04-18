#include "Book.hpp"
#define PASSWORD "4242"
using namespace std;

void bookMenu() {
    int option;
    Book b;
	cout<<"*************************************************"<<endl;
	cout<<"                Menu Livros"<<endl;
	cout<<"*************************************************"<<endl;
	cout<<"   1. Adicionar"<<endl;
	cout<<"   2. Deletar"<<endl;
	cout<<"   3. Alterar"<<endl;
	cout<<"   4. Mostar Todos"<<endl;
	cout<<"   4. Voltar Menu Principal"<<endl<<endl<<endl;
	cout<<"Escolha a opção: ";
	cin>>option;
	switch (option) {
        case 1:
            system("clear");
            b.add();
            b.save();
            break;
        case 2:
            system("clear");
            b.delete();
        default:
            cout<<"Opção incorreta/inválida"<<endl;
            break;
    }
}

void mainMenu() {
    int option;
	cout<<"*************************************************"<<endl;
	cout<<"      Sistema de Gerenciamento de Compras"<<endl;
	cout<<"*************************************************"<<endl;
	cout<<"   1. Livros"<<endl;
	cout<<"   2. Compras"<<endl;
	cout<<"   3. Sair"<<endl<<endl<<endl;
	cout<<"Escolha a opção: ";
	cin>>option;
	switch (option) {
        case 1:
            system("cls");
            bookMenu();
            break;
        case 3:
            exit(EXIT_SUCCESS); // successful termination
        default:
            cout<<"Opção incorreta/inválida"<<endl;
            break;
    }
}

int main() {

}