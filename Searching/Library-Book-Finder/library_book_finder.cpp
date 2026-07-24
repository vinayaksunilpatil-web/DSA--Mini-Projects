// 2. Library Book Search System
//  Features
// Add Books
// Search by Book ID
//  Search by Title
//  Display Available Books
//  Sort Books by ID or Title

#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;

struct Library{
    int id;
    string title;
    string author;
    int copies;
};

void print(vector<Library> &books){
    if(books.empty()){
        cout << "No books in library ..." << endl;
        cout << "Try contacting librarian to add books" << endl;
        return;
    }
    int n = books.size();
    cout << string(100, '-');
    cout << endl;
    cout << left
         << setw(10) << "Book Id"
         << setw(40) << "Book name"
         << setw(40) << "BookAuthor"
         << setw(10) << "Copies"
         << endl;
    cout << string(100, '-');
    cout << endl;
    for (int i = 0;i<n;i++){
        cout << left
             << setw(10) << books[i].id
             << setw(40) << books[i].title
             << setw(40) << books[i].author
             << setw(10) <<books[i].copies
             << endl;
    }
    cout << string(100, '-');

}

class Library_System {
public:
    string title;
    int id;
    Library l;
    void Add_Books(vector<Library> &books)
    {

        int n;
        cout << "Enter number of books to add:" << endl;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "-------" << "Book " << (i + 1) << "-------" << endl;

            while (true)
            {
                bool is_find = false;
                cout << "Enter a id:";
                cin >> l.id;
                for (int j = 0; j < books.size(); j++)
                {
                    if (books[j].id == l.id)
                    {
                        is_find = true;
                        break;
                    }
                }
                if (is_find)
                {
                    cout << "ID already exists..." << endl;
                }
                else
                {
                    break;
                }
            }

            cout << "Enter a title of book:";
            getline(cin >> ws, l.title);

            cout << "Enter author:";
            getline(cin >> ws, l.author);

            cout << "Enter the copies of the book:";
            cin >> l.copies;

            books.push_back(l);
        }
        cout << "Books added succesfully!!!" << endl;
        sort(books.begin(), books.end(), [](Library a, Library b)
             { return a.id < b.id; });
    }

    void serachByTitle(const vector<Library> &books)
    {
        if (books.empty())
        {
            cout << "No books exists to serach..." << endl;
            cout << "Try contacing librarian to add a book to library..." << endl;
            return;
        }
        bool is_find = false;

        cout << "Enter a name of book to search";
        getline(cin >> ws, title);
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].title == title)
            {
                is_find = true;
                cout << endl;
                cout << "Book found in library.." << endl;
                cout << "Book author is:" << books[i].author << endl;
                cout << "Book copies are:" << books[i].copies << endl;
                cout << "Book id is: " << books[i].id << endl;
                break;
            }
        }
        if (!is_find)
        {
            cout << "Book not found..." << endl;
            cout << "Try contacting the librarian to add a book" << endl;
        }
    }

    void serachById(const vector<Library> &books)
    {
        if (books.empty())
        {
            cout << "No books exists to serach..." << endl;
            cout << "Try conatcting a libraian to add a book to library..." << endl;
            return;
        }
        bool is_found = false;
        cout << "Enter a book id to serch in library:";
        cin >> id;
        int start = 0, end = books.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (books[mid].id == id)
            {
                is_found = true;
                cout << endl;
                cout << "Book with " << id << " found in library... " << endl;
                cout << "Book title is:" << books[mid].title << endl;
                cout << "Book author is:" << books[mid].author << endl;
                cout << "Book copies are:" << books[mid].copies << endl;
                break;
            }
            else if (books[mid].id > id)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        if (!is_found)
        {
            cout << "Book not  found in library.." << endl;
            cout << "Try contacting librarian to add a book" << endl;
        }
    }
};

int main(){
    vector<Library> books;
    int ch;

    cout << "------Welcome to Library Book Finder System-----" << endl;
    Library_System ls;
    while(true){
        cout << "---Menu---" << endl;
        cout << "1.Add Book" << endl;
        cout << "2.Search Book by id" << endl;
        cout << "3.Search Book by name" << endl;
        cout << "4.Display available books" << endl;
        cout << "5.Exit" << endl;
        cout << "------------------------------" << endl;
        cout << "Enter a choice:";
        cin >> ch;
        if(ch==1){
            ls.Add_Books(books);
            cout << endl;
        }else if(ch==2){
            ls.serachById(books);
            cout << endl;
        }else if(ch==3){
            ls.serachByTitle(books);
            cout << endl;
        }else if(ch==4){
            print(books);
            cout << endl;
        }else{
            cout << "Thank You for using library book finder...";
            break;
        }
    }

    return 0;
}
