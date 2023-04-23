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
char tocniVtori[4]= {'c', 'd', 'a', 'a'};
char tocniTreti[4][2]= {{'c', 'e'}, {'a', 'c'}, {'a', 'd'}, {'a', 'c'}};

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

void writeOdgovor(fstream &file, char odg, char odg2, int br)
{
    file << br << ". " << odg << " " << odg2 << endl;
}

float checkOdgovor(int brojnaprasanje, char answer, char answer2)
{
    if (brojnaprasanje <= 4)
        {

        if ( answer == tocniPrvi[brojnaprasanje-1] )
            return 5.5;

        }
    else if (brojnaprasanje > 4 && brojnaprasanje <= 8 )
        {
        if ( answer == tocniVtori[brojnaprasanje-5] )
            return 11.0;
        }
    else if (brojnaprasanje > 8 && brojnaprasanje <= 12 )
        {
        if ((( answer == tocniTreti[brojnaprasanje-9][0] ) && ( answer2 == tocniTreti[brojnaprasanje-9][1] )) || (( answer == tocniTreti[brojnaprasanje-9][1] ) && ( answer2 == tocniTreti[brojnaprasanje-9][0] )))
            return 8.5;
        }
    return 0;
}

float handleInput(int brojprasanje, fstream &file)
{

    char odgovor,odgovor2;
    if (brojprasanje <= 4)
        {
        do
            {
            cout<<"Vashiot odgovor: ";
            cin>>odgovor;

            }
        while( odgovor != 'a' && odgovor != 'b' && odgovor != 'c' );
        writeOdgovor(file, odgovor, ' ', brojprasanje);

        }
    else if (brojprasanje > 4 && brojprasanje <= 8 )
        {
        do
            {
            cout<<"Vashiot odgovor: ";
            cin>>odgovor;

            }
        while( odgovor != 'a' && odgovor != 'b' && odgovor != 'c' && odgovor != 'd' );
        writeOdgovor(file, odgovor, ' ', brojprasanje);
        }
    else if (brojprasanje > 8 && brojprasanje <= 12 )
        {
        do
            {
            cout<<"Vashiot odgovor: ";
            cin>>odgovor;
            }
        while( odgovor != 'a' && odgovor != 'b' && odgovor != 'c' && odgovor != 'd' && odgovor != 'e' );
        do
            {
            cout<<"Vashiot odgovor: ";
            cin>>odgovor2;

            }
        while(( odgovor2 == odgovor )  || ( odgovor2 != 'a' && odgovor2 != 'b' && odgovor2 != 'c' && odgovor2 != 'd' && odgovor2 != 'e' ));
        writeOdgovor(file, odgovor, odgovor2, brojprasanje);
        }

    return checkOdgovor(brojprasanje, odgovor, odgovor2);
}

int score(float poeni)
{
    if (poeni >= 0 && poeni <= 9)
        return 1;
    else if (poeni >= 10 && poeni <= 19)
        return 2;
    else if (poeni >= 20 && poeni <= 29)
        return 3;
    else if (poeni >= 30 && poeni <= 39)
        return 4;
    else if (poeni >= 40 && poeni <= 49)
        return 5;
    else if (poeni >= 50 && poeni <= 59)
        return 6;
    else if (poeni >= 60 && poeni <= 69)
        return 7;
    else if (poeni >= 70 && poeni <= 79)
        return 8;
    else if (poeni >= 80 && poeni <= 89)
        return 9;
    else if (poeni >= 90 && poeni <= 100)
        return 10;
    else
        return 0;
}

void answersTable()
{

    cout<<"___________________________________________________________"<<endl;

    cout<<"Tocni odgovori na prasanjata se:"<<endl;
    for(int i=1; i<=12; i++)
        {
        if (i <= 4)
            cout<<i<<". "<<tocniPrvi[i-1]<<endl;
        else if (i > 4 && i <= 8 )
            cout<<i<<". "<<tocniVtori[i-5]<<endl;
        else if (i > 8 && i <= 12 )
            cout<<i<<". "<<tocniTreti[i-9][0] << " " <<tocniTreti[i-9][1]<<endl;
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

    fstream file, test;
    student lice;
    string prasanje;
    unsigned long brojnaprasanje = 1;
    float poeni = 0;
    const string filelog = "folder za prashana i student.log/Students.log";
    int br =0;
    string Brojach="folder za prashana i student.log/Brojach.txt";

    fstream logFile(filelog, ios::app);

    file.open(Brojach.c_str(), ios::in);
    if (file.is_open())
        {
        file >> br;
        }
    file.close();

    br++;

    file.open(Brojach.c_str(), ios::out);
    if (file.is_open())
        {
        file << br;
        }
    file.close();

    if (!logFile)
        {
        cerr << "Eror ,ne se otvara  " << filelog << "\n";
        return 1;
        }
    studentInput(lice);

    string vremeS = getCurrentDateTime();

    logFile<<br<<". "<< "Pochetok:"<<vremeS<<";" << lice.ime << ";" << lice.prezime << ";" <<"INKI"<< lice.indeks << ";"  << "\n";

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
