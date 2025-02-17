// ismailfaridi.com
// https://www.linkedin.com/in/ismailfaridi/
#include <iostream>
#include <fstream>
using namespace std;

// Store all user input names in a File
void func1()
{
    ofstream file("writing.txt", ios::app);

    if (!file.is_open())
    {
        cout << "Error while opeing the file.";
        return;
    }
    else
    {
        string name;
        while (true)
        {
            cout << "Enter names (type 'stop' to end): ";
            getline(cin, name);

            if (name == "stop")
                break;

            file << name << endl;
        }

        file.close();
    }
}

// Store names and grades of student enter by user in the file
void func2()
{
    ofstream file("writing.txt", ios::app);

    if (!file.is_open())
    {
        cout << "File is unable to open.";
        return;
    }
    else
    {
        string name;
        int grade;

        while (true)
        {
            cout << "\nEnter student name (type 'stop' to end): ";
            getline(cin, name);

            if (name == "stop")
                break;

            cout << "\nEnter student grade: ";
            cin >> grade;

            cin.ignore(); // Clear the input buffer to avoid issues with getline()

            file << name << ", " << grade << endl;
        }

        file.close();
    }
}

// Log user message into a file
void func3()
{
    ofstream file("writing.txt", ios::app);

    if (!file.is_open())
    {
        cout << "Unable to open the file.";
        return;
    }

    string message;

    cout << "Enter messages to log (type 'exit' to stop)" << endl;

    while (true)
    {
        cout << "Enter message: ";
        getline(cin, message);

        if (message == "stop")
            break;

        file << message << endl;
    }
    file.close();
}

// Asks the user for a position (in bytes) and writes a message at that position in the file
void func4()
{
    ofstream file("writing.txt", ios::out);

    if (!file)
    {
        cout << "Unable to open the file.";
        return;
    }

    int pos;
    string message;

    cout << "Enter the position (in bytes) where you want to insert the message: ";
    cin >> pos;

    cin.ignore(); // Clear the input buffer before using getline

    cout << "Enter your message: ";
    getline(cin, message);

    file.seekp(pos, ios::beg);
    cout << "The current postion in the file" << file.tellp() << endl;

    file << message << endl;

    file.close();
}

// Overwrite data in the file
void func5()
{
    ofstream file("writing.txt", ios::in | ios::out); // Open file in write mode without truncating

    if (!file.is_open())
    {
        cout << "Unable to open the file.";
        return;
    }
    else
    {
        int pos;
        cout << "Enter the position (in bytes) where you want to overwrite: ";
        cin >> pos;
        cin.ignore(); // Ignore leftover newline from cin

        string newData;
        cout << "Enter the new data: ";
        getline(cin, newData);

        file.seekp(pos, ios::beg);
        cout << "Overwriting at position: " << file.tellp();

        file << newData;
        file.close();
    }
}

// Repeatedly ask user to write data in file. After every write operation display position of file pointer. After every 5 write operations move the pointer to beginning of the file.
void func6()
{
    ofstream file("writing.txt", ios::app);

    if (!file.is_open())
    {
        cout << "Unable to open the file.";
        return;
    }

    int count = 0;

    while (true)
    {
        string message;
        cout << "Enter the data to write in the file (write 'stop' to end): ";
        getline(cin, message);

        if (message == "stop")
            break;

        if (count < 5)
        {
            file << message;
            count++;
            cout << "File poiner position: " << file.tellp() << endl;
        }
        else
        {
            count = 0;
        }
    }

    file.close();
}

int main()
{
    // func1();
    // func2();
    // func3();
    // func4();
    // func5();
    // func6();
}