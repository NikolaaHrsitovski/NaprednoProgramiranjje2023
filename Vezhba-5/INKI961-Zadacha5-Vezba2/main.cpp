#include <iostream>

using namespace std;
void print ( const char* p,int d)
{
    for(int i=0; i<d; i++)
        {
        cout<<*(p+i);
        }
    cout<<endl;
}
int main()
{
    const char pesna[]="Line in the sand - Hot Chip";
    int d=sizeof(pesna)/sizeof(pesna[0]);
    const char* p=&pesna[0];
     print ( pesna,d);
    cout <<"Prv karakter : "<< *p << endl;
    cout<<"Adresa na prv karakter: "<<  reinterpret_cast<intptr_t>(p)  <<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    p+=18;
    cout<<"Premestuvane na pokazuvac do imato na izveduvachot za :18 mesta"<<endl;
    cout<<"Sodrzhina po premestuvane na pokazuvac: "<<p<<endl;
    cout<<"Adresa od kaj sho pocnuva premesteniot pokazuvac: "<<reinterpret_cast<intptr_t>(p)<<endl;

    return 0;
}
