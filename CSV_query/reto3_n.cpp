// Agustín Pumarejo Ontañón, A01028997
// Adriana Abella Kuri, A01329591
// Reto 3

// g++ -std=c++11 reto3.cpp -o reto3
// ./reto3

#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <sstream>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Record
{
public:
    string date;
    string time;
    string sourceIP;
    string sourcePort;
    string sourceName;
    string destIP;
    string destPort;
    string destName;

    Record(){};

    Record(string _date, string _time, string _sourceIP, string _sourcePort, string _sourceName, string _destIP, string _destPort, string _destName)
    {
        date = _date;
        time = _time;
        sourceIP = _sourceIP;
        sourcePort = _sourcePort;
        sourceName = _sourceName;
        destIP = _destIP;
        destPort = _destPort;
        destName = _destName;
    }

    void printRecord()
    {
        cout << date << ", " << time << ", " << sourceIP << ", " << sourcePort << ", " << sourceName << ", " << destIP << ", " << destPort << ", " << destName << endl;
    }
};

class RecordManager
{
public:
    vector<Record> entries;
    string order;

    void read(string file)
    {
        ifstream fileIn;
        fileIn.open(file);
        string record, parts;
        vector<string> data;
        while (getline(fileIn, record))
        {
            istringstream sIn(record);
            while (getline(sIn, parts, ','))
            {
                data.push_back(parts);
            }
            if (data[7].find('\r') != data[7].npos)
            {
                data[7] = data[7].substr(0, data[7].size() - 1);
            }
            Record r(data[0], timeFixer(data[1]), data[2], data[3], data[4], data[5], data[6], data[7]);
            entries.push_back(r);
            data.clear();
        }
    }

    void sort(vector<Record> &ent, string type)
    {
        order = type;
        sortAux(ent, 0, entries.size() - 1, type);
    }

    void sortAux(vector<Record> &ent, int low, int high, string type)
    {
        if (low >= high)
        {
            return;
        }
        int j = partition(ent, low, high, type);
        sortAux(ent, low, j - 1, type);
        sortAux(ent, j + 1, high, type);
    }

    int partition(vector<Record> &ent, int low, int high, string type)
    {
        int pivote = low;
        int i = low + 1;
        int j = high;
        while (true)
        {
            while (comparator(ent[i], ent[pivote], type) <= 0 && i < high)
            {
                i++;
            }
            while (comparator(ent[j], ent[pivote], type) > 0 && j > low)
            {
                j--;
            }
            if (i >= j)
            {
                break;
            }
            else
            {
                intercambiar(ent, i, j);
            }
        }
        intercambiar(ent, pivote, j);
        return j;
    }

    void intercambiar(vector<Record> &ent, int pos1, int pos2)
    {
        Record t = ent[pos1];
        ent[pos1] = ent[pos2];
        ent[pos2] = t;
    }

    int binarySearch(string target)
    {
        int inicio = 0;
        int fin = entries.size() - 1;
        if ((compareStrVsR(target, entries[fin], order) > 0) || (compareStrVsR(target, entries[inicio], order) < 0))
        {
            return -1;
        }
        while (fin >= inicio)
        {
            int medio = (inicio + fin) / 2;
            if (compareStrVsR(target, entries[medio], order) == 0)
            {
                return medio;
            }
            else if (compareStrVsR(target, entries[medio], order) > 0)
            {
                inicio = medio + 1;
            }
            else
            {
                fin = medio - 1;
            }
        }
        return -1;
    }

    int comparatorAux(string a, string b)
    {
        if (a < b)
        {
            return -1;
        }
        else if (a == b)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    int comparator(Record a, Record b, string type)
    {
        if (type == "date")
        {
            if (comparatorAux(a.date, b.date) == 0)
            {
                return comparatorAux(a.time, b.time);
            }
            else
            {
                return comparatorAux(a.date, b.date);
            }
        }
        else if (type == "time")
        {
            return comparatorAux(a.time, b.time);
        }
        else if (type == "sourceIP")
        {
            return comparatorAux(a.sourceIP, b.sourceIP);
        }
        else if (type == "sourcePort")
        {
            return comparatorAux(a.sourcePort, b.sourcePort);
        }
        else if (type == "sourceName")
        {
            return comparatorAux(a.sourceName, b.sourceName);
        }
        else if (type == "destIP")
        {
            return comparatorAux(a.destIP, b.destIP);
        }
        else if (type == "destPort")
        {
            return comparatorAux(a.destPort, b.destPort);
        }
        else
        {
            return comparatorAux(a.destName, b.destName);
        }
    }

    int compareStrVsR(string a, Record b, string type)
    {
        if (type == "date")
        {
            return comparatorAux(a, b.date);
        }
        else if (type == "time")
        {
            return comparatorAux(a, b.time);
        }
        else if (type == "sourceIP")
        {
            return comparatorAux(a, b.sourceIP);
        }
        else if (type == "sourcePort")
        {
            return comparatorAux(a, b.sourcePort);
        }
        else if (type == "sourceName")
        {
            return comparatorAux(a, b.sourceName);
        }
        else if (type == "destIP")
        {
            return comparatorAux(a, b.destIP);
        }
        else if (type == "destPort")
        {
            return comparatorAux(a, b.destPort);
        }
        else
        {
            return comparatorAux(a, b.destName);
        }
    }

    string timeFixer(string badTime)
    {
        string goodTime;
        int pos;
        pos = badTime.find(":");
        if (pos == 1)
        {
            badTime.insert(0, "0");
        }
        goodTime = badTime.substr(0, 3);
        badTime = badTime.substr(3, string::npos);
        pos = badTime.find(":");
        if (pos == 1)
        {
            badTime.insert(0, "0");
        }
        goodTime += badTime.substr(0, 3);
        badTime = badTime.substr(3, string::npos);
        if (badTime.length() == 1)
        {
            badTime.insert(0, "0");
        }
        goodTime += badTime;
        return goodTime;
    }

    unordered_set<string> findDomain()
    {
        unordered_set<string> d;
        string temp1, temp2;
        for (int i = 0; i < entries.size(); i++)
        {
            temp1 = entries[i].sourceName;
            if (temp1 != "-" && temp1.find(".reto.com") == string::npos)
            { // no lo encuentra
                d.insert(temp1);
            }
            temp2 = entries[i].destName;
            if (temp2 != "-" && temp2.find(".reto.com") == string::npos)
            { // no lo encuentra
                d.insert(temp2);
            }
        }
        return d;
    }
};

class ConexionesComputadora
{
public:
    string IP;
    string nombre;
    stack<Record> con_entrantes;
    list<Record> con_salientes;

    ConexionesComputadora(){};

    ConexionesComputadora(string num, RecordManager rm, bool print, string _nombre)
    {
        IP = num;
        nombre = _nombre;
        if (print == true)
        {
            cout << "IP: " << IP << endl;
        }
    }

    void insertSaliente(Record saliente)
    {
        con_salientes.push_back(saliente);
    }

    void insertEntrante(Record entrante)
    {
        con_entrantes.push(entrante);
    }
};

unordered_map<string, ConexionesComputadora> createDictionary(RecordManager rm, bool print)
{
    unordered_map<string, ConexionesComputadora> d;
    string temp;
    for (int i = 0; i < rm.entries.size(); i++)
    {
        if (rm.entries[i].sourceIP != "-")
        {
            if (d.find(rm.entries[i].sourceIP) == d.end())
            {
                ConexionesComputadora a(rm.entries[i].sourceIP, rm, print, rm.entries[i].sourceName);
                d[rm.entries[i].sourceIP] = a;
            }
            d[rm.entries[i].sourceIP].insertSaliente(rm.entries[i]);
        }
        if (rm.entries[i].destIP != "-")
        {
            if (d.find(rm.entries[i].destIP) == d.end())
            {
                ConexionesComputadora a(rm.entries[i].destIP, rm, print, rm.entries[i].destName);
                d[rm.entries[i].destIP] = a;
            }
            d[rm.entries[i].destIP].insertEntrante(rm.entries[i]);
        }
    }
    return d;
}

int main()
{
    RecordManager equipo11;
    equipo11.read("nuevo11.csv");
    cout << "Datos leídos" << endl
         << endl;
    unordered_set<string> domains = equipo11.findDomain();
    unordered_map<string, ConexionesComputadora> dictionary = createDictionary(equipo11, false);

    // Pregunta 1 (dominios anómalos obtenidos con inspección visual)
    string name = "9kmiofxfryfxdyoypub1.com";
    string name2 = "kcsi9jgefgh3rfsjmv6l.com";

    // Pregunta 2
    cout << "Pregunta 2\nIP de dominios anómalos" << endl;
    string ip = "";
    // auto = pair<string, ConexionesComputadora>
    for (auto par : dictionary)
    {
        if (par.second.nombre == name)
        {
            ip = par.first;
            cout << "La IP del dominio " << name << " es: " << ip << endl;
            break;
        }
    }
    for (auto par : dictionary)
    {
        if (par.second.nombre == name2)
        {
            ip = par.first;
            cout << "La IP del dominio " << name2 << " es: " << ip << endl;
            break;
        }
    }
    cout << endl;

    // Preguntas 3 y 4
    cout << "Preguntas 3 y 4\nComputadoras del dominio reto.com con conexiones entrantes y las IP únicas de las conexiones entrantes de algunas de ellas" << endl;
    string key = "";
    int preg3 = 0;
    unordered_set<string> ipUnicas;
    stack<Record> temp;
    for (int i = 1; i < 255; i++)
    {
        key = "172.23.97." + to_string(i);
        if (dictionary[key].con_entrantes.empty() == false)
        {
            if (i == 113 || i == 18 || i == 123)
            {
                cout << "IP destino: " << key << endl;
                temp = dictionary[key].con_entrantes;
                while (temp.empty() == false)
                {
                    ipUnicas.insert(temp.top().sourceIP);
                    temp.pop();
                }
                for (string iterador : ipUnicas)
                {
                    cout << " IP fuente: " << iterador << endl;
                }
                ipUnicas.clear();
            }
            preg3++;
        }
    }
    cout << "Número de computadoras de reto.com con conexiones entrantes: " << preg3 << endl;
    cout << endl;

    // Preguntas 6 y 7
    cout << "Preguntas 6 y 7\nComunicación entre la computadora con IP 172.23.97.22 y los dominios anómalos y las fechas y puertos de las primeras conexiones" << endl;
    string ipPaul = "172.23.97.22";
    for (auto i : dictionary[ipPaul].con_salientes)
    {
        if (i.destName == name)
        {
            cout << i.sourceName << " (" << ipPaul << ") se conectó a " << name << " por primera vez el día " << i.date << " con el puerto " << i.destPort << endl;
            break;
        }
    }
    for (auto i : dictionary[ipPaul].con_salientes)
    {
        if (i.destName == name2)
        {
            cout << i.sourceName << " (" << ipPaul << ") se conectó a " << name2 << " por primera vez el día " << i.date << " con el puerto " << i.destPort << endl;
            break;
        }
    }
    cout << endl;

    return 0;
}