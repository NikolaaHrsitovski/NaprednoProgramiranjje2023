/*Nikola Hristovski 961
1. od red32 do red 36 na sekoj red kaj sho e iskoristena rand() generira random broj i toj broj go deli so 6 i kako rezultat go
dobivame ostatokot i ppotoa se dodadava 1
2.71 i 72 se nepotrebni vo kodot bidejki num nema da e nikogash pomal od 1 ili pogolem od 6
3.97 i 96 se nepotrebni vo kodot bidejki num nema da e nikogash pomal od 1 ili pogolem od 6
4. vo 119 i 120 system("pause") se koristi za da se zapre izvrshuvaneto na proogramata i treba ta se pritisni na koe bilo kopche
 za da se prodolzhi system("cls") of funkcija go chisti konzolata za da bidi pochitlivo


 prvin se deklariraat funkcijte koj ke se koristitat za da ja isprintat stranata od kockata koja ke mu padne na igrachot potoa vo
  main se deklariraat promenlivite pa vo while se genrirat random brojoj do 6 i korisnikot koke pricni na r se prikazhva brojot sho
  mu padna a ako pricne na q izlegva od while i nema mozhnost za nov obid na broj og kockata i ako pricni nekoj drug karakter se chisti konzolata
i mu kazhuva dali pobedi kompjuterot ili igrachot
*/



#include <iostream>
#include <time.h>
#include <cstdlib>
//#include <windows.h>
using namespace std;
void one();
void two();
void three();
void four();
void five();
void six();
//Declare Functions used
int main()
{
    short unsigned int score = 0;
    short unsigned int compScore = 0;
    short unsigned int num = 0;
    short unsigned int num2 = 0;
    short unsigned int compNum = 0;
    short unsigned int compNum2 = 0;
    short unsigned int sum = 0;
    short unsigned int compSum = 0;
    char letter;
//Declare Variables
    srand(time(NULL));
    while (letter != 'q')
        {
        cout << "Your Score: " << score << endl;
        cout << "computer's Score: " << compScore << endl << endl;
        cout << "Press r to roll or q to quit: ";
        cin >> letter;
        num = 1 + rand()%6;
        num2 = 1 + rand() %6;
        compNum = 1 + rand() %6;
        compNum2 = 1 + rand() %6;
//sto se sluciva so redovite 32 do 36 i koi se vrednostite na promenlivite ?

        sum = num + num2;
        compSum = compNum + compNum2;

//Calculate Sums

        if (letter == 'q')
            break;
        if (letter != 'r')
            {
            system("cls");
            continue;
            }

        switch (num)
            {
            case 1:
                one();
                break;
            case 2:
                two();
                break;
            case 3:
                three();
                break;
            case 4:
                four();
                break;
            case 5:
                five();
                break;
            case 6:
                six();
                break;
            default: //dali 71 i 72 se neophodni i koja im e funkcijata vo kodot ?
                cout << "Error...";
                break;
            } //end switch

        switch (num2)
            {
            case 1:
                one();
                break;
            case 2:
                two();
                break;
            case 3:
                three();
                break;
            case 4:
                four();
                break;
            case 5:
                five();
                break;
            case 6:
                six();
                break;
            default:// //dali 71 i 72 se neophodni i koja im e funkcijata vo kodot ?
                cout << "Error...";
                break;
            } //end switch

        cout << endl << "Yours: " << num << ", " << num2 << endl;
        cout << "Computer's: " << compNum << ", " << compNum2 << "\n\n";

//Display dice and numbers

        if (sum > compSum)
            {
            cout << "You won!!" << endl << endl;
            score++;
            }
        else
            {
            compScore++;
            cout << "you lost..." << endl << endl;
            }

//shto rabotat naredbite 119 i 120 ?

        system("pause");
        system("cls");


        }
    return 0;
}

void one()
{
    cout << "-----" << endl;
    cout << "|   |" << endl;
    cout << "| O |" << endl;
    cout << "|   |" << endl;
    cout << "-----" << endl;
}
void two()
{
    cout << "-----" << endl;
    cout << "| O |" << endl;
    cout << "|   |" << endl;
    cout << "| O |" << endl;
    cout << "-----" << endl;
}
void three()
{
    cout << "-----" << endl;
    cout << "| O |" << endl;
    cout << "| O |" << endl;
    cout << "| O |" << endl;
    cout << "-----" << endl;
}
void four()
{
    cout << "-----" << endl;
    cout << "|O O|" << endl;
    cout << "|   |" << endl;
    cout << "|O O|" << endl;
    cout << "-----" << endl;
}
void five()
{
    cout << "-----" << endl;
    cout << "|O O|" << endl;
    cout << "| O |" << endl;
    cout << "|O O|" << endl;
    cout << "-----" << endl;
}
void six()
{
    cout << "-----" << endl;
    cout << "|O O|" << endl;
    cout << "|O O|" << endl;
    cout << "|O O|" << endl;
    cout << "-----" << endl;
}
