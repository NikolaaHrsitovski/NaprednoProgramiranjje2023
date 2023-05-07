#include <iostream> // standard input/output library
#include <fstream> // file input/output library
#include <vector> // container for storing multiple objects of same type
#include <algorithm> // contains functions for performing operations on ranges of elements

using namespace std;

struct Profil // a structure representing a profile
{
    int IDbroj; // an integer identifier for the profile
    string Nickname; // a string representing the nickname of the profile
    float Nivo; // a float representing the level of the profile

    bool operator<(const Profil& other) const // a comparison operator that compares profiles based on their nicknames
    {
        return Nickname < other.Nickname;
    }
};

int main()
{
    vector<Profil> profili; // create an empty vector named profili to hold objects of type Profil

    for (int i = 0; i < 5; i++) // repeat the following code 5 times
        {
        Profil p; // create a new object of type Profil named p
        cout << "Vnesi IDbroj za profil " << i + 1 << ": "; // print a message to the console
        cin >> p.IDbroj; // read a value from the console and store it in the IDbroj member of p

        // Check if the input is a number
        while (cin.fail()) // if the previous input failed
            {
            cout << "Vnesi IDbroj za profil " << i + 1 << " (mora da bide broj!): "; // print an error message to the console
            cin.clear(); // clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any remaining characters in the input buffer up to the next newline character
            cin >> p.IDbroj; // read a new value from the console and store it in the IDbroj member of p
            }

        cout << "Vnesi Nickname za profil " << i + 1 << ": "; // print a message to the console
        cin >> p.Nickname; // read a value from the console and store it in the Nickname member of p
        cout << "Vnesi Nivo za profil " << i + 1 << ": "; // print a message to the console
        cin >> p.Nivo; // read a value from the console and store it in the Nivo member of p

        while (cin.fail()) // if the previous input failed
            {
            cout << "Vnesi Nivo za profil " << i + 1 << " (mora da bide broj!): "; // print an error message to the console
            cin.clear(); // clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any remaining characters in the input buffer up to the next newline character
            cin >> p.Nivo; // read a new value from the console and store it in the Nivo member of p
            }
        profili.push_back(p); // add the object p to the end of the profili vector
        cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-\n"; // print a separator to the console
        }
    cout<<endl;

cout << "Profilite vo vektorite:" << endl;
// Iterate through each profile in the vector and print its ID, nickname, and level
for (vector<Profil>::iterator it = profili.begin(); it != profili.end(); ++it)
{
    cout << "IDbroj: " << it->IDbroj << ", Nickname: " << it->Nickname << ", Nivo: " << it->Nivo << endl;
}

// Sortiraj gi zapisi vo vektorot po Nickname
// Sort the profiles in the vector by their nicknames
sort(profili.begin(), profili.end());
cout<<endl;
// Ispetchati gi sortiranite zapisi
cout << "Sortiranite profili:" << endl;
// Iterate through each profile in the sorted vector and print its ID, nickname, and level
for (vector<Profil>::iterator it = profili.begin(); it != profili.end(); ++it)
{
    cout << "IDbroj: " << it->IDbroj << ", Nickname: " << it->Nickname << ", Nivo: " << it->Nivo << endl;
}

cout<<endl;
// Ask the user to input their ID, name, and surname
string indeksImePrezime;
cout << "Vnesigi indeksot imeto prezimeto" << endl;
cin.ignore();
getline(cin, indeksImePrezime);

cout<<endl;
// Zachuvaj gi zapisi vo izlezna datoteka
// Create an output file stream with the user's name as the filename
ofstream outFile(indeksImePrezime);
// If the output file stream is open, iterate through each profile in the vector and write its ID, nickname, and level to the file
if (outFile.is_open())
{
    for (vector<Profil>::iterator it = profili.begin(); it != profili.end(); ++it)
    {
        outFile << it->IDbroj << " " << it->Nickname << " " << it->Nivo << endl;
    }
    // Close the output file stream and print a message to the console
    outFile.close();
    cout << "Profilite se zachuvani! " << endl;
}
// If the output file stream failed to open, print an error message to the console
else
{
    cout << "Profilite ne se zachuvani! " << endl;
}

// Exit the program
return 0;
}
