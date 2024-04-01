#include <iostream>
#include <fstream>

struct Book {
    int id;
    std::string name;
    std::string author;
    float price;
};

inline bool fileExists(const std::string& name) {
    std::ifstream f(name);
    if (f.is_open()) return true;
    else return false;
}

void saveBook(const Book& b) {
    const std::string fileName = "./books.csv";
    std::ofstream booksFile;
    if (fileExists(fileName)) {
        booksFile.open(fileName, std::ios::app);
        booksFile<<b.id<<","<<b.name<<","<<b.author<<","<<b.price<<"\n";
        booksFile.close();
    } else {
        booksFile.open(fileName);
        booksFile<<"id,name,author,price"<<"\n";
        booksFile<<b.id<<","<<b.name<<","<<b.author<<","<<b.price<<"\n";
        booksFile.close();
    }
}

std::ostream& operator<<(std::ostream& out, const Book& b) {
    out<<"ID: "<<b.id<<"\n";
    out<<"Name: "<<b.name<<"\n";
    out<<"Author: "<<b.author<<"\n";
    out<<"Price: "<<b.price<<"\n";
    return out;
}

int main() {
    Book estudo_naa;
    estudo_naa.id = 1;
    estudo_naa.name = "Bíblia de Estudo NAA";
    estudo_naa.author = "Unknown";
    estudo_naa.price = 289.9;

    std::cout<<estudo_naa;

    saveBook(estudo_naa);
}