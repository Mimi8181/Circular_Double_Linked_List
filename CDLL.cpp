#include <iostream>
using namespace std;

struct Pekerja
{
    string nama;
    int umur, id;

    Pekerja *next, *prev;
};

Pekerja *head, *tail, *newNode, *cur, *del, *afterNode;

void createData(string nama, int umur, int id)
{
    head = new Pekerja();
    head->nama = nama;
    head->umur = umur;
    head->id = id;

    head->prev = head;
    head->next = head;
    tail = head;
}

void addFirst(string nama, int umur, int id)
{
    newNode = new Pekerja();
    newNode->nama = nama;
    newNode->umur = umur;
    newNode->id = id;

    newNode->prev = tail;
    newNode->next = head;

    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
}

void addMid(string nama, int umur, int id, int posisi)
{
    if (head == NULL)
    {
        cout << "linked list belum dibuat" << endl;
    }
    else
    {
        if (posisi <= 1)
        {
            cout << "bukan posisi tengah" << endl;
        }
        else
        {
            newNode = new Pekerja();
            newNode->nama = nama;
            newNode->umur = umur;
            newNode->id = id;

            cur = head;
            for (int i = 1; i < posisi - 1; i++)
            {
                cur = cur->next;
            }
            afterNode = cur->next;
            cur->next = newNode;
            afterNode->prev = newNode;
            newNode->prev = cur;
            newNode->next = afterNode;
        }
    }
}

void addLast(string nama, int umur, int id)
{
    newNode = new Pekerja();
    newNode->nama = nama;
    newNode->umur = umur;
    newNode->id = id;

    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
}

void delFirst()
{
    del = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    delete del;
}

void delMid(int posisi)
{
    if (head == NULL)
    {
        cout << "linked list belum dibuat" << endl;
    }
    else
    {
        if (posisi <= 1)
        {
            cout << "bukan posisi tengah" << endl;
        }
        else
        {
            cur = head;
            for (int i = 1; i < posisi - 1; i++)
            {
                cur = cur->next;
            }
            del = cur->next;
            afterNode = del->next;
            cur->next = afterNode;
            afterNode->prev = cur;
            delete del;
        }
    }
}

void delLast()
{
    del = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete del;
}

void printData()
{
    if (head == NULL)
    {
        cout << "Linked List belum dibuat" << endl;
    }
    else
    {
        cur = head;
        while (cur->next != head)
        {
            cout << "nama\t: " << cur->nama << endl;
            cout << "umur\t: " << cur->umur << endl;
            cout << "id\t: " << cur->id << endl
                 << endl;
            cur = cur->next;
        }
        cout << "nama\t: " << cur->nama << endl;
        cout << "umur\t: " << cur->umur << endl;
        cout << "id\t: " << cur->id << endl
             << endl;
    }
}

int main(int argc, char const *argv[])
{
    createData("Agus", 21, 01);
    addFirst("Bagus", 30, 02);
    addLast("Cecep", 28, 03);
    addMid("Dudung", 33, 04, 6);
    printData();
    cout << "---------------------" << endl;
    delMid(2);
    printData();

    return 0;
}
