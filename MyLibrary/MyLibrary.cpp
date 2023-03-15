#include "MyLibrary.h"
#include<iostream>
#include<string>
#include<cstring>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

MyLibrary::~MyLibrary() {
    delete[] books;
}

MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(output_stream);


MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books) : output_stream(output_stream), books_count(books_count)
{
    this->books = new int[books_count];
    for (unsigned i = 0; i < books_count; i++)
    {
        this->books[i] = books[i];
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max) : output_stream(output_stream), books_count(books_count)
{
    books = new int[books_count];
    for (unsigned i = 0; i < books_count; i++)
        books[i] = min + rand() % (max - min + 1);
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(output_stream)
{
    char* Books_Values = new char[strlen(books_values) + 1];
    strcpy(Books_Values, books_values);

    books = new int[strlen(books_values) + 1];
    books_count = 0;

    char* char_number = strtok(Books_Values, ";");
    while (char_number)
    {
        int number = std::stoi(char_number);
        books[books_count++] = number;

        char_number = strtok(NULL, ";");
    }
    books_count--;
}


MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream), books_count(books_count)
{
    books = new int[books_count];
    va_list(args);
    va_start(args, books_count);

    for (unsigned i = 0; i < books_count; i++)
        books[i] = va_arg(args, int);

    va_end(args);
}

MyLibrary::MyLibrary(std::initializer_list<int> v) : output_stream(std::cout)
{
    books = new int[v.size()];
    books_count = 0;
    for (const int* i = v.begin(); i <= v.end(); i++)
    {
        books[books_count++] = *i;
    }
    books_count--;
}

void MyLibrary::print_books() 
{
    if (books_count != 0)
    {
        output_stream << books_count << " ";
        for (unsigned i = 0; i < books_count; i++)
            output_stream << books[i] << " ";
    }
    else
        output_stream << -1;
    printf("\n");
}
void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id) const
{
    if (books[book_index])
        books[book_index] = book_id;

}

unsigned MyLibrary::get_books_count() const 
{
    return books_count;
}

int MyLibrary::get_book_id_by_index(unsigned book_index) const
{
    int number;
    if (books[book_index])
        number = books[book_index];
    else
        number = -1;
    return number;
}

//constructorul lipsa:
MyLibrary::MyLibrary(MyLibrary& l) : output_stream(l.output_stream)
{
    books_count = l.books_count;
    books = new int(*l.books);
}

