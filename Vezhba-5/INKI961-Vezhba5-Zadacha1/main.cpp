#include <iostream>

using namespace std;

void print(char* a,int* d)
{
    for(int i=0; i<*d; i++)
        {
        cout<<*(a+i);
        }
    cout<<endl;
}
 void dodavaneKarakteriNaImeto(char* ime){
  *ime=39;
  ime++;
  *ime=126;
  ime++;
  *ime=94;
  ime++;
  *ime=45;

 }
 void dodavaneKarakteriNaPrezime(char* prezime){
  *prezime=126;
  prezime++;
  *prezime=39;
  prezime++;
  *prezime=45;
  prezime++;
  *prezime=94;

 }
int main()
{
    char ime []="Nikola";
    int dolzhinaNaIme=sizeof(ime)/sizeof(ime[0]);
    int* dI=&dolzhinaNaIme;

    char prezime []="Hristovski";
    int dolzhinaNaPrezime=sizeof(prezime)/sizeof(prezime[0]);
    int* dP=&dolzhinaNaPrezime;

    print(ime,dI);
    print(prezime,dP);

    cout<<endl;
    cout<<endl;

    dodavaneKarakteriNaImeto(ime);
    dodavaneKarakteriNaPrezime(prezime);

    print(ime,dI);
    print(prezime,dP);

    return 0;
}
