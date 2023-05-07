#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Profil
{
    int IDbroj;
    string Nickname;
    float Nivo;
    bool operator<(const Profil& other) const
    {
        return Nickname < other.Nickname;
    }
};

int main()
{
    vector<Profil> profili;

    for (int i = 0; i < 5; i++)
        {
        Profil p;
        cout << "Vnesi IDbroj za profil " << i + 1 << ": ";
        cin >> p.IDbroj;


        while (cin.fail())
            {
            cout << "Vnesi IDbroj za profil " << i + 1 << " (mora da bide broj!): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> p.IDbroj;
            }

        cout << "Vnesi Nickname za profil " << i + 1 << ": ";
        cin >> p.Nickname;
        cout << "Vnesi Nivo za profil " << i + 1 << ": ";
        cin >> p.Nivo;

        while (cin.fail())
            {
            cout << "Vnesi Nivo za profil " << i + 1 << " (mora da bide broj!): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> p.Nivo;
            }
        profili.push_back(p);
        cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-\n";
        }
    cout<<endl;

    cout << "Profilite vo vektorite:" << endl;

    for (vector<Profil>::iterator it = profili.begin(); it != profili.end(); ++it)
        {
        cout << "IDbroj: " << it->IDbroj << ", Nickname: " << it->Nickname << ", Nivo: " << it->Nivo << endl;
        }


    sort(profili.begin(), profili.end());
    cout<<endl;

    cout << "Sortiranite profili:" << endl;

    for (vector<Profil>::iterator it = profili.begin(); it != profili.end(); ++it)
        {
        cout << "IDbroj: " << it->IDbroj << ", Nickname: " << it->Nickname << ", Nivo: " << it->Nivo << endl;
        }

    cout<<endl;

    string indeksImePrezime;
    cout << "Vnesigi indeksot imeto prezimeto" << endl;
    cin.ignore();
    getline(cin, indeksImePrezime);

    cout<<endl;

    ofstream outFile(indeksImePrezime);

    if (outFile.is_open())
        {
        for (vector<Profil>::iterator it = profili.begin(); it != profili.end(); ++it)
            {
            outFile << it->IDbroj << " " << it->Nickname << " " << it->Nivo << endl;
            }

        outFile.close();
        cout << "Profilite se zachuvani! " << endl;
        }

    else
        {
        cout << "Profilite ne se zachuvani! " << endl;
        }


    return 0;
}
