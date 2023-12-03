#include <iostream>
#include <string>

using namespace std;

struct Book
{
    string title;
    string author;
    int year;
};

const int MAX_LIBRARY_SIZE = 100;
Book library[MAX_LIBRARY_SIZE];
int librarySize = 0;

void addBook()
{
    if (librarySize >= MAX_LIBRARY_SIZE)
    {
        cout << "Library is full! Cannot add more books." << endl;
        return;
    }

    Book newBook;

    cout << "Enter the title of the book: ";
    getline(cin, newBook.title);

    cout << "Enter the author of the book: ";
    getline(cin, newBook.author);

    cout << "Enter the year of publication of the book: ";
    cin >> newBook.year;
    cin.ignore();

    library[librarySize] = newBook;
    librarySize++;

    cout << "Book added successfully to the library!" << endl;
}

void displayBooks()
{
    if (librarySize == 0)
    {
        cout << "Library is empty! No books to display." << endl;
        return;
    }
cout<<"----------------------------------------------\n";
    cout << "List of books in the library:" << endl;
    for (int i = 0; i < librarySize; i++)
    { cout<<" -----------Book #"<<(i+1)<<"-----------"<<endl;
        cout << "Title: " << library[i].title << endl;
        cout << "Author: " << library[i].author << endl;
        cout << "Year: " << library[i].year << endl;

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

    cout << "Matching books:" << endl;
    for (int i = 0; i < librarySize; i++)
    {
        if (library[i].title == searchTitle)
        {
            cout << "----------------------------------------------\n";

            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "Year: " << library[i].year << endl;
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
        return;
    }

    string removeTitle;
    cout << "Enter the title of the book to remove: ";
    getline(cin, removeTitle);

    bool found = false;
    int removeIndex;
    for (int i = 0; i < librarySize; i++)
    {
        if (library[i].title == removeTitle)
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