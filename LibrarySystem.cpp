#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    string title;
    string author;
    int year;

public:
    void setTitle(string t)
    {
        title = t;
    }

    string getTitle()
    {
        return title;
    }

    void setAuthor(string a)
    {
        author = a;
    }

    string getAuthor()
    {
        return author;
    }

    void setYear(int y)
    {
        year = y;
    }

    int getYear()
    {
        return year;
    }
};

const int MAX_LIBRARY_SIZE = 100;
Book library[MAX_LIBRARY_SIZE];
int librarySize = 0;

void addBook()
{
    if (librarySize >= MAX_LIBRARY_SIZE)
    {
        cout << "----------------------------------------------\n";

        cout << "Library is full! Cannot add more books." << endl;
        cout << "----------------------------------------------\n";

        return;
    }

    Book newBook;

    string title;
    cout << "Enter the title of the book: ";
    getline(cin, title);
    newBook.setTitle(title);

    string author;
    cout << "Enter the author of the book: ";
    getline(cin, author);
    newBook.setAuthor(author);

    int year;
    cout << "Enter the year of publication of the book: ";
    cin >> year;
    cin.ignore();
    newBook.setYear(year);

    library[librarySize] = newBook;
    librarySize++;
    cout << "----------------------------------------------\n";

    cout << "Book added successfully to the library!" << endl;
    cout << "----------------------------------------------\n";
}

void displayBooks()
{
    if (librarySize == 0)
    {
        cout << "----------------------------------------------\n";

        cout << "Library is empty! No books to display." << endl;
        cout << "----------------------------------------------\n";

        return;
    }
    cout << "----------------------------------------------\n";

    cout << "List of books in the library:" << endl;
    for (int i = 0; i < librarySize; i++)
    {
        cout << "---------------Book #"<<(i+1)<<"----------------\n";

        cout << "Title: " << library[i].getTitle() << endl;
        cout << "Author: " << library[i].getAuthor() << endl;
        cout << "Year: " << library[i].getYear() << endl;
        cout << endl;
    }
}

void searchBook()
{
    if (librarySize == 0)
    {
        cout << "----------------------------------------------\n";

        cout << "Library is empty! No books to search." << endl;
        cout << "----------------------------------------------\n";

        return;
    }

    string searchTitle;
    cout << "Enter the title of the book to search: ";
    getline(cin, searchTitle);

    bool found = false;
    cout << "----------------------------------------------\n";

    cout << "Matching books:" << endl;
    for (int i = 0; i < librarySize; i++)
    {
        if (library[i].getTitle() == searchTitle)
        {
            cout << "----------------------------------------------\n";

            cout << "Title: " << library[i].getTitle() << endl;
            cout << "Author: " << library[i].getAuthor() << endl;
            cout << "Year: " << library[i].getYear() << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "----------------------------------------------\n";

        cout << "No books found with the given title." << endl;
        cout << "----------------------------------------------\n";
    }
}

void removeBook()
{
    if (librarySize == 0)
    {
        cout << "----------------------------------------------\n";

        cout << "Library is empty! No books to remove." << endl;
        cout << "----------------------------------------------\n";

        return;
    }

    string removeTitle;
    cout << "Enter the title of the book to remove: ";
    getline(cin, removeTitle);

    bool found = false;
    int removeIndex;
    for (int i = 0; i < librarySize; i++)
    {
        if (library[i].getTitle() == removeTitle)
        {
            found = true;
            removeIndex = i;
            break;
        }
    }

    if (found)
    {
        for (int i = removeIndex; i < librarySize - 1; i++)
        {
            library[i] = library[i + 1];
        }
        librarySize--;
        cout << "----------------------------------------------\n";

        cout << "Book removed successfully from the library!" << endl;
        cout << "----------------------------------------------\n";
    }
    else
    {
        cout << "----------------------------------------------\n";

        cout << "No books found with the given title." << endl;
        cout << "----------------------------------------------\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "Library System Menu" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Display books" << endl;
        cout << "3. Search book" << endl;
        cout << "4. Remove book" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            removeBook();
            break;
        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}