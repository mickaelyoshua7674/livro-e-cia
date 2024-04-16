#include <iostream>
#define PASSWORD "4242"
using namespace std;

void bookMenu() {

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
            BookMenu();
            break;
        case 3:
            exit(EXIT_SUCCESS); // successful termination
        default:
            cout<<"Opção incorreta/inválida"<<endl;
            break;
    }
}

void password() {
    int num = 0;
    cout<<"Insira senha: ";

    for (int i=0; i<4; i++) {
        num = num*10+(getch()-48);
        cout<<"*";
    }
    
    if (num == PASSWORD) {
        cout<<endl<<endl<<"Senha correta"<<endl<<endl;
        cout<<"Pressione qualquer tecla...";
        getch();
    } else {
        cout<<endl<<endl<<"Senha incorreta"<<endl<<endl;
        cout<<"Pressione qualquer tecla...";
        getch();
        exit(EXIT_FAILURE);
    }

    return;
}

int main() {

}