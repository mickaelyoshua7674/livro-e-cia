#include <iostream>
#include <fstream>
const std::string fileName = "./books.csv";

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

int getBookID() {
    int id;
    std::ifstream f(fileName);
    std::string line;
    if (f.is_open()) {
        int count = 0;
        while (std::getline(f, line)) {
            if (count>0) { // skip csv header
                
            }
            count++;
        }
    } else id = 1;
    f.close();
    return id;
}

Book getBookData() {
    Book newBook;
    std::cout<<"Name: "; std::cin>>newBook.name; std::cout<<"\n";
    std::cout<<"Author: "; std::cin>>newBook.author; std::cout<<"\n";
    std::cout<<"Price: "; std::cin>>newBook.price; std::cout<<"\n";
    return newBook;
}

void saveBook(const Book& b) {
    std::ofstream booksFile;
    if (fileExists(fileName)) {
        booksFile.open(fileName, std::ios::app);
        booksFile<<b.id<<","<<b.name<<","<<b.author<<","<<b.price<<"\n";
    } else {
        booksFile.open(fileName);
        booksFile<<"id,name,author,price"<<"\n";
        booksFile<<b.id<<","<<b.name<<","<<b.author<<","<<b.price<<"\n";
    }
    booksFile.close();
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

    Book newBook = getBookData();

    saveBook(estudo_naa);
    saveBook(newBook);
}