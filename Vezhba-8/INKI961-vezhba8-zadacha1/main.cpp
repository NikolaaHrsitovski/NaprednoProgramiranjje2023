#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct student
{
    string ime;
    string prezime;
    string indeks;
};

char tocniPrvi[4]= {'a', 'c', 'c', 'c'};
char tocniVtori[4]= {'b', 'b', 'b', 'a'};
char tocniTreti[2]= {'c', 'c'};

void studentInput(student &lice)
{
    cout << "Vnesete go imeto na studentot: "<<endl;
    cin >> lice.ime;
    cout << "Vnesete go prezimeto na studentot: "<<endl;
    cin >> lice.prezime;

    do
        {
        cout << "Vnesete go indeksot na studentot: "<<endl;
        cin >> lice.indeks;
        }
    while (lice.indeks.size() != 3);
}

void writeOdgovor(fstream &file, char odg, int br)
{
    file << br << ". " << odg << endl;
}

float checkOdgovor(int brojnaprasanje, char answer)
{
    if (brojnaprasanje <= 4)
        {
        if (answer == tocniPrvi[brojnaprasanje-1])
            return 5.5;
        }
    else if (brojnaprasanje > 4 && brojnaprasanje <= 8)
        {
        if (answer == tocniVtori[brojnaprasanje-5])
            return 3;
        }
    else if (brojnaprasanje > 8 && brojnaprasanje <= 10)
        {
        if (answer == tocniTreti[brojnaprasanje-9])
            return 8;
        }
    return 0;
}
float handleInput(int brojprasanje, fstream &file)
{
    char odgovor;
    if (brojprasanje <= 4 || (brojprasanje > 4 && brojprasanje <= 8)||(brojprasanje > 8 && brojprasanje <= 10))
        {
        while (odgovor != 'a' && odgovor != 'b' && odgovor != 'c')
            {
            cout << "Vashiot odgovor: ";
            cin >> odgovor;
            };
        writeOdgovor(file, odgovor, brojprasanje);
        }
    return checkOdgovor(brojprasanje, odgovor);
}
int score(float poeni)
{

    if ( poeni >= 0 && poeni <= 24 )
        return 5;
    else if ( poeni >= 25 && poeni <= 32 )
        return 6;
    else if ( poeni >= 32.5 && poeni <= 37 )
        return 7;
    else if ( poeni >= 37.5 && poeni <= 40.5 )
        return 8;
    else if ( poeni >= 41 && poeni <= 45 )
        return 9;
    else if ( poeni >= 45.5 && poeni <= 50 )
        return 10;
    else
        {
        return 0;
        }
}
void answersTable()
{
    cout<<"Tocni odgovori na prasanjata se:"<<endl;
    for(int i=1; i<=10; i++)
        {
        if (i <= 4)
            cout<<i<<". "<<tocniPrvi[i-1]<<endl;
        else if (i > 4 && i <= 8 )
            cout<<i<<". "<<tocniVtori[i-5]<<endl;
        else if (i > 8 && i <= 10 )
            cout<<i<<". "<<tocniTreti[i-9] << endl;
        }
}
bool checkFileExists(string filename)
{
    ifstream infile(filename.c_str());
    return infile.good();
}
string getCurrentDateTime()
{
    time_t t = time(nullptr);
    char vreme[20];
    strftime(vreme, sizeof(vreme), "%d.%m.%Y %H:%M:%S", localtime(&t));
    return vreme;
}
int main()
{
    const string filelog = "folder za prashana i student.log/Students.log";
    fstream logFile(filelog, ios::app);
    fstream file, test;
    student lice;
    string prasanje;
    unsigned long brojnaprasanje = 1;
    float poeni = 0;

    if (!logFile)
        {
        cerr << "Eror ,ne se otvara  " << filelog << "\n";
        return 1;
        }
    studentInput(lice);

    string vremeS = getCurrentDateTime();

    logFile<<"#."<< "Pochetok:"<<vremeS<<";" << lice.ime << ";" << lice.prezime << ";" <<"INKI"<< lice.indeks << ";"  << "\n";

    const string filename = lice.ime + lice.prezime + "INKI" + lice.indeks;
    if (checkFileExists(filename))
        {
        cout << "Nemash pravo na test povtorno!" ;
        return 0;
        }


    file.open(filename.c_str(), ios::out);

    file<<"IME: "<<lice.ime<<endl;
    file<<"PREZIME: "<<lice.prezime<<endl;
    file<<"INDEKS: "<<lice.indeks<<endl;
    file<<"Vreme na pochetok:"<<vremeS<<endl;
    file<<endl;
    file<<"_____________________________"<<endl;
    file<<endl;
    file<<"Vneseni odgovori:"<<endl;
    file.close();

    test.open("folder za prashana i student.log/prasanja.txt", ios::in);

    while (getline(test, prasanje))
        {
        for (unsigned long i = 0; i < prasanje.size(); i++)
            {
            if (prasanje[i] == ';')
                {
                cout << endl;
                i++;
                }
            else
                {
                cout << prasanje[i];
                }
            }
        cout << endl;

        file.open(filename.c_str(), ios::app);
        poeni += handleInput(brojnaprasanje, file);
        file.close();
        brojnaprasanje++;
        }

    test.close();
    file.open(filename.c_str(), ios::app);
    file<<"_____________________________"<<endl;
    file<<endl;
    file << "Ocenka: " << score(poeni) << endl;
    file << "Poeni: " << poeni << endl;
    file<<"_____________________________"<<endl;
    file.close();

    string vremeK = getCurrentDateTime();
    file.open(filename.c_str(), ios::app);
    file<<endl;
    file<<"Vreme na zavrshetok:"<<vremeK<<endl;
    file.close();

    answersTable();

    logFile<<"  "<< "Zavrshetok:"<<vremeK<<";" << lice.ime << ";" << lice.prezime << ";" <<"INKI"<< lice.indeks << ";"  << "\n";
    logFile.close();

    return 0;
}
