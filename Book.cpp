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
/*
Search if book csv file exists, then return the proper id for register a new book
*/
int getBookID() {
    std::string line;
    unsigned int id;
    char ch;
    std::ifstream f(fileName);
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
        std::getline(f, line); // get last line
        for (int i=1; i<line.length(); i++) {
            if (line[i] == ',') { // search for first ','
                id = std::stoi(line.substr(0,i))+1; // get substring of id, convert to integer and add 1
                break;
            }
        }
        f.close();
    } else id = 1;
    return id;
}

Book getBookData() {
    Book newBook;
    newBook.id = getBookID();
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
    Book newBook = getBookData();
    saveBook(newBook);

    Book newBook2 = getBookData();
    saveBook(newBook2);
}