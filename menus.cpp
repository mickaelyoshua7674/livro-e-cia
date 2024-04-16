#include <iostream>
using namespace std;

void BookMenu() {

}

int main() {
    int option;
	cout<<"*************************************************"<<endl;
	cout<<"         BOOKSHOP MANGEMENT SYSTEM"<<endl;
	cout<<"*************************************************"<<endl;
	cout<<"   1. Livros"<<endl;
	cout<<"   2. Compras"<<endl;
	cout<<"   3. Sair"<<endl<<endl<<endl;
	cout<<"Enter Your Choice : ";
	cin>>option;
	switch (option) {
        case 1:
            system("cls");
            BookMenu();
            break;
        case 3:
            exit();
        default:
            cout<<"Opção incorreta/inválida"<<endl;
            break;
    }
}