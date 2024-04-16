#ifndef BOOK_CLASS // make sure the header is included once
#define BOOKS_FILENAME "./books.csv"
#define DELIMITER ','
#define BOOK_CLASS
#include <iostream>
#include <fstream>
using namespace std;

/*
Receive a path to a file and return true if exists and false if doesn't.
*/
inline bool fileExists(const string& path) { // inline function is expanded in line when is called, may incriese performance if is a small function
    ifstream f(path);
    if (f.is_open()) return true;
    else return false;
}

class Book {
    public:
        unsigned int id;
        string name;
        string author;

        /*
        Object initializer will ask the name of the book and the author when object is crated.
        */
        Book() {
            id = getBookID();
            cout<<"Name: "; cin>>name; cout<<endl;
            cout<<"Author: "; cin>>author; cout<<endl;
        }

        /*
        If Book file already exists will append the file creating new lines on csv file,
        if Book file doesn't exists will crate a new file.
        */
        void saveBook() {
            ofstream booksFile;
            if (fileExists(BOOKS_FILENAME)) {
                booksFile.open(BOOKS_FILENAME, ios::app);
                booksFile<<endl<<id<<DELIMITER<<name<<DELIMITER<<author;
            } else {
                booksFile.open(BOOKS_FILENAME);
                booksFile<<"id"<<DELIMITER<<"name"<<DELIMITER<<"author";
                booksFile<<endl<<id<<DELIMITER<<name<<DELIMITER<<author;
            }
            booksFile.close();
        }

    private:
        /*
        Search if book csv file exists, then return the proper id for register a new book
        */
        int getBookID() {
            string line;
            unsigned int idCollected;
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
                        idCollected = stoi(line.substr(0,i))+1; // get substring of id, convert to integer and add 1
                        break;
                    }
                }
                f.close();
            } else idCollected = 1;
            return idCollected;
        }
};

ostream& operator<<(ostream& out, const Book& b) {
    out<<"ID: "<<b.id<<endl;
    out<<"Name: "<<b.name<<endl;
    out<<"Author: "<<b.author<<endl;
    return out;
}

#endif