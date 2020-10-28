// Agustín Pumarejo Ontañón, A01028997
// Adriana Abella Kuri, A01329591
// Actividad 2.1: Métodos de listas ligadas

#include <iostream>

using namespace std;

template <class T>
class Nodo
{
public:
    T value;
    Nodo<T> *next;

    Nodo(T val)
    {
        value = val;
        next = NULL;
    }
};

template <class T>
class LinkedList
{
public:
    Nodo<T> *root;

    LinkedList(T *values, int size)
    {
        Nodo<T> *temp = new Nodo<T>(values[0]);
        root = temp;
        for (int i = 1; i < size; i++)
        {
            temp->next = new Nodo<T>(values[i]);
            temp = temp->next;
        }
        temp->next = NULL;
    }

    void print()
    {
        Nodo<T> *temp = root;
        while (temp != NULL)
        {
            cout << temp->value;
            if (temp->next != NULL)
            {
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // 1
    // Complejidad temporal: O(n)
    // Complejidad espacial: O(1)
    int count(T target)
    {
        Nodo<T> *temp = root;
        int counter = 0;
        while (temp != NULL)
        {
            if (temp->value == target)
            {
                counter++;
            }
            temp = temp->next;
        }
        return counter;
    }

    // 2
    // Complejidad temporal: O(n)
    // Complejidad espacial: O(1)
    void deleteList()
    {
        Nodo<T> *temp = root;
        root = NULL;
        while (temp != NULL)
        {
            Nodo<T> *trash = temp;
            temp = temp->next;
            delete trash;
        }
    }

    // 3
    // Complejidad temporal: O(n)
    // Complejidad espacial: O(1)
    void sortedInsert(T n)
    {
        Nodo<T> *temp = root;
        Nodo<T> *nuevo = new Nodo<T>(n);
        if (root == NULL)
        {
            root = nuevo;
        }
        else if (nuevo->value < temp->value)
        {
            nuevo->next = temp;
            root = nuevo;
        }
        else
        {
            while (temp->next != NULL && temp->next->value < nuevo->value)
            {
                temp = temp->next;
            }
            nuevo->next = temp->next;
            temp->next = nuevo;
        }
    }

    // 4
    // Complejidad temporal: O(n)
    // Complejidad espacial: O(1)
    void removeDuplicates()
    {
        Nodo<T> *temp = root;
        while (temp->next != NULL)
        {
            if (temp->value == temp->next->value)
            {
                Nodo<T> *trash = temp->next;
                temp->next = temp->next->next;
                delete trash;
                continue;
            }
            temp = temp->next;
        }
    }

    // 5
    // Complejidad temporal: O(n)
    // Complejidad espacial: O(1)
    void reverse()
    {
        Nodo<T> *tp = root;
        Nodo<T> *t = root->next;
        Nodo<T> *tn = root->next->next;
        tp->next = NULL;
        while (tn->next != NULL)
        {
            t->next = tp;
            tp = t;
            t = tn;
            tn = tn->next;
        }
        t->next = tp;
        tn->next = t;
        root = tn;
    }
};

int main()
{
    // Creación de la lista
    int values[] = {2, 2, 3, 3, 3, 3, 5, 9, 20};
    int size = sizeof(values) / sizeof(values[0]);
    LinkedList<int> LL(values, size);
    cout << "\nInitial values: " << endl;
    LL.print();
    cout << endl;
    // 1. Contar apariciones de un elemento en la lista
    int value = 3;
    cout << "1. Counting an element's occurrences\nNumber " << value << " occurrences: " << LL.count(value) << endl
         << endl;
    // 2. Borrar una lista completa
    LL.deleteList();
    cout << "2. Deleting all the elements in the list\n";
    LL.print();
    // 3. Insertar elementos en una lista ordenada
    LL = *new LinkedList<int>(values, size);
    cout << "3. Inserting elements in a sorted list\n";
    LL.sortedInsert(0);
    cout << "Inserting 0\n";
    LL.print();
    LL.sortedInsert(9);
    cout << "Inserting 9\n";
    LL.print();
    LL.sortedInsert(22);
    cout << "Inserting 22\n";
    LL.print();
    cout << endl;
    // 4. Eliminar los elementos duplicados en una lista ordenada
    cout << "4. Removing duplicates\n";
    LL.removeDuplicates();
    LL.print();
    cout << endl;
    // 5. Invertir el orden de una lista
    cout << "5. Reversing the list\n";
    LL.reverse();
    LL.print();
    cout << endl;

    return 0;
}