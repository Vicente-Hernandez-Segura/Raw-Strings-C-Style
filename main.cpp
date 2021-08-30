//C-style String
#include <iostream>
#include <cstring>
//We know in C, when an array is passed to a function, it is passed as a pointer.
const char * Combine(const char *pFirst, const char *pLast)
{
    /*
     * To combine first name and last name we need a third character array.
     * So, we'll use dynamic memory allocation, we'll allocate memory for fullname by using new.
     * And we need to allocate one byte extra because in C the strings are null-terminated so when you
     * allocate memory for the combined string you also need to allocate one extra byte for the null terminator.
     * strcpy() and strcat() automatically append a null terminating character at the end of the string regardless
     * of whether the memory is available or not. If we don't allocate the extra byte + 1 the function will cause a buffer overflow.
     */
    char *fullname = new char[strlen(pFirst) + strlen(pLast) + 1];

    //We'll use the functions strcpy() which will first copy the first name into full name
    strcpy(fullname, pFirst);

    //And then we'll concatenate the last name into full name.
    strcat(fullname, pLast);

    //And then we'll return this full name to the caller.
    return fullname;
}
int main() {
    char first[10];
    char last[10];
    std::cin.getline(first, 10);
    std::cin.getline(last, 10);

    //So, Combine() returns the full name, We'll store it inside this pointer i.e. pFullName.
    const char *pFullName = Combine(first, last);

    //Print or insert into the database or whatever, etc...
    std::cout << pFullName << std::endl;

    //We allocate the memory on the heap, but we need to deallocate it somewhere.
    //So we need to deallocate it over here after we're done with the pointer.
    delete[] pFullName;

    return 0;
}