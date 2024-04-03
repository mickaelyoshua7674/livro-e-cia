#include <iostream>
#include <fstream>
const std::string fileName = "./books.csv";
const std::string delimiter = ",";

struct Book {
    unsigned int id;
    std::string name;
    std::string author;
};

inline bool fileExists(const std::string& name) {
    std::ifstream f(name);
    if (f.is_open()) return true;
    else return false;
}

int getBookID() {
    std::string line;
    unsigned int id;
    char ch;
    std::ifstream f(fileName);
    std::string line;
    if (f.is_open()) {
        f.seekg(-1, std::ios::end); // go to the last position from the end of file (before EOF)
        while (true) {
            f.get(ch);
            if (f.tellg() <= 1) { // if the position is at the beginning of file
                f.seekg(0); // there is only one line, the go to the beginning
                break;
            } else if (ch == '\n') { // reach the beginnig of last line
                break;
            } else {
                f.seekg(-2, std::ios::cur); // go back one character from the current position
            }
        }
        std::getline(f, line);
        std::cout<<line<<"\n";
    } else id = 1;
    f.close();
    return 0;
}

Book getBookData() {
    Book newBook;
    std::cout<<"Name: "; std::cin>>newBook.name; std::cout<<"\n";
    std::cout<<"Author: "; std::cin>>newBook.author; std::cout<<"\n";
    return newBook;
}

void saveBook(const Book& b) {
    std::ofstream booksFile;
    if (fileExists(fileName)) {
        booksFile.open(fileName, std::ios::app);
        booksFile<<"\n"<<b.id<<","<<b.name<<","<<b.author;
    } else {
        booksFile.open(fileName);
        booksFile<<"id,name,author";
        booksFile<<"\n"<<b.id<<","<<b.name<<","<<b.author;
    }
    booksFile.close();
}

std::ostream& operator<<(std::ostream& out, const Book& b) {
    out<<"ID: "<<b.id<<"\n";
    out<<"Name: "<<b.name<<"\n";
    out<<"Author: "<<b.author<<"\n";
    return out;
}

int main() {
    Book estudo_naa;
    estudo_naa.id = 1;
    estudo_naa.name = "Bíblia de Estudo NAA";
    estudo_naa.author = "Unknown";

    int id = getBookID();
    // Book newBook = getBookData();

    // saveBook(estudo_naa);
    // saveBook(newBook);
}