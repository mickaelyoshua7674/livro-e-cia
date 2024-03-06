#include <iostream>

struct Book {
    int id;
    std::string name;
    std::string author;
    float price;
};

std::ostream& operator<<(std::ostream& out, const Book b) {
    out<<"ID: "<<b.id<<std::endl;
    out<<"Name: "<<b.name<<std::endl;
    out<<"Author: "<<b.author<<std::endl;
    out<<"Price: "<<b.price<<std::endl;
    return out;
}

int main(){
    Book estudo_naa;
    estudo_naa.id = 1;
    estudo_naa.name = "Bíblia de Estudo NAA";
    estudo_naa.author = "Unknown";
    estudo_naa.price = 289.9;

    std::cout<<estudo_naa;
}