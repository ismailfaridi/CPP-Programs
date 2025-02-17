// ismailfaridi.com
// https://www.linkedin.com/in/ismailfaridi/
#include <iostream>
#include <fstream>
using namespace std;

// Display all data of file in one line
void func1()
{
    ifstream file("reading.txt", ios::in);

    if (!file)
    {
        cout << "Erorr while opening file." << endl;
        return;
        // return 1; // error here bez of void
    }

    string line;
    while (getline(file, line))
    {
        cout << line;
    }

    file.close();
}

// Display all data of file as it it
void func2()
{
    ifstream file;
    file.open("reading.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Error while opening the file" << endl;
        return;
    }
    else
    {
        // # Method-1
        char ch;
        // Read and print characters one by one
        while (file.get(ch)) // Continue until file.get() fails (i.e., EOF or error)
            cout << ch;
        file.close();

        // # Method-2
        // char ch;
        // while (!file.eof())
        // {
        //     ch = file.get();
        //     cout << ch;
        // }
        // file.close();

        // # Method-3
        // string str;
        // Read and print srings line by line
        // while (getline(file, str))
        //     cout << str << endl;
        // file.close();
    }
}

// Display all data of file in one line without spaces
void func3()
{
    ifstream file("reading.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Error while opening the file." << endl;
        return;
    }
    else
    {
        char ch;
        while (file.get(ch))
        {
            if ((ch != ' ') && (ch != '\n'))
                cout << ch;
        }

        file.close();
    }
}

// Dispaly first & last 7 character of file
void func4()
{
    ifstream file("reading.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Error while opening the file.";
        return;
    }
    else
    {
        // Dispaly first 7 character of file
        // cout << file.tellg();
        int pos = file.tellg();
        // int post = 0;
        char ch;

        for (int i = pos; i < 7; i++)
        {
            file.get(ch);
            cout << ch;
        }
        cout << endl;

        // Dispaly last 7 character of file
        file.seekg(-7, ios::end); // position the cursor in file
        char chr;

        for (int i = 0; i < 7; i++)
        {
            chr = file.get(); // It will also print \n
            cout << chr;
        }

        file.close();
    }
}

// Display all data of file after 5 characters (first 5 char shouldn't be displayed)
void func5()
{
    ifstream file("reading.txt", ios::in);

    if (!file)
    {
        cout << "Error while opening the file.";
        return;
    }
    else
    {
        file.seekg(5, ios::beg);
        string str;

        while (!file.eof())
        {
            getline(file, str);
            cout << str << endl;
        }

        file.close();
    }
}

// Dispaly all data of file after first 'a' is reached
void func6()
{
    ifstream file("reading.txt", ios::in);

    if (!file)
    {
        cout << "Error while opening the file.";
        return;
    }
    else
    {
        bool show = false;
        char ch;

        while (file.get(ch))
        {
            if (ch == 'a')
                show = true;

            // It will not print a that first reached
            // if (!show && ch == 'a')
            // {
            //     show = true;  // Start printing after this
            //     continue;     // Skip the first 'a'
            // }

            if (show == true)
                cout << ch;
        }

        file.close();
    }
}

// Count the number of characters in file
void func7()
{
    ifstream file("reading.txt", ios::in);

    if (!file)
    {
        cout << "Error while opening the file.";
        return;
    }
    else
    {
        int count = 0;
        char ch;

        while (file.get(ch)) // also read \n
            count++;

        file.close();

        cout << "File has " << count << " characters." << endl;
    }
}

// Count the number of words in file
void func8()
{
    ifstream file("reading.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Error while opening the file.";
        return;
    }
    else
    {
        int wordCount = 0;
        string str;

        while (file >> str)
        {
            wordCount++;
        }
        cout << "The number of words in file is: " << wordCount;
    }
}

// Count the number of lines in file
void func9()
{
    ifstream file("reading.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Error while opening the file.";
        return;
    }
    else
    {
        int lineCount = 0;
        string str;

        while (getline(file, str))
        {
            lineCount++;
        }
        cout << "The number of words in file is: " << lineCount;

        file.close();
    }
}

// Count the number of ('p', ' ', 'vowels') in file
void func10()
{
    ifstream file("reading.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Error while opening the file.";
        return;
    }

    int pCount = 0, spaceCount = 0, vowelsCount = 0;
    char ch;

    while (file.get(ch))
    {
        if (ch == 'p')
            pCount++;

        if (ch == ' ')
            spaceCount++;

        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            vowelsCount++;
    }

    cout << "The numbers of p in the file is: " << pCount << endl;
    cout << "The numbers of spaced in the file is: " << spaceCount << endl;
    cout << "The numbers of vowels in the file is: " << vowelsCount;

    file.close();
}

// Store the second line in a variable
void func11()
{
    ifstream file("reading.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Error while opening the file.";
        return;
    }

    string str;

    getline(file, str);

    if (getline(file, str))
        cout << str;
    else
        cout << "There is no 2nd line in the file.";

    file.close();
}

// Display next five character after first 'e'
void func12()
{
    ifstream file("reading.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Error while opening the file.";
        return;
    }
    else
    {
        char ch;
        bool reached = false;
        int count = 0;

        while (file.get(ch))
        {
            if (reached && count < 5)
            {
                cout << ch;
                count++;
            }

            if (!reached && ch == 'e')
            {
                reached = true;
            }
        }

        file.close();
    }
}

int main()
{
    // func1();
    // func2();
    // func3();
    // func4();
    // func5();
    // func6();
    // func7();
    // func8();
    // func9();
    // func10();
    // func11();
    // func12();
}