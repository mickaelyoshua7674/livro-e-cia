#include <iostream>
#include <fstream>
#define BOOKS_FILENAME "./books.csv"
#define DELIMITER ','
using namespace std;

struct Book {
    unsigned int id;
    string name;
    string author;
};

inline bool fileExists(const string& name) {
    ifstream f(name);
    if (f.is_open()) return true;
    else return false;
}
/*
Search if book csv file exists, then return the proper id for register a new book
*/
int getBookID() {
    string line;
    unsigned int id;
    char ch;
    ifstream f(BOOKS_FILENAME);
    if (f.is_open()) {
        f.seekg(-1, ios::end); // go to the last position from the end of file (before EOF)
        while (true) {
            f.get(ch);
            if (f.tellg() <= 1) { // if the position is at the beginning of file
                f.seekg(0); // there is only one line, the go to the beginning
                break;
            } else if (ch == '\n') { // reach the beginnig of last line
                break;
            } else {
                f.seekg(-2, ios::cur); // go back one character from the current position
            }
        }
        getline(f, line); // get last line
        for (int i=1; i<line.length(); i++) {
            if (line[i] == DELIMITER) { // search for first delimiter
                id = stoi(line.substr(0,i))+1; // get substring of id, convert to integer and add 1
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
    cout<<"Name: "; cin>>newBook.name; cout<<"\n";
    cout<<"Author: "; cin>>newBook.author; cout<<"\n";
    return newBook;
}

void saveBook(const Book& b) {
    ofstream booksFile;
    if (fileExists(BOOKS_FILENAME)) {
        booksFile.open(BOOKS_FILENAME, ios::app);
        booksFile<<"\n"<<b.id<<DELIMITER<<b.name<<DELIMITER<<b.author;
    } else {
        booksFile.open(BOOKS_FILENAME);
        booksFile<<"id"<<DELIMITER<<"name"<<DELIMITER<<"author";
        booksFile<<"\n"<<b.id<<DELIMITER<<b.name<<DELIMITER<<b.author;
    }
    booksFile.close();
}

ostream& operator<<(ostream& out, const Book& b) {
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