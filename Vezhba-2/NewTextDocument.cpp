/*
-Библиотеката <ctime> овозможува  работа со времето и датумите. Тоа е стандардна библиотека која дефинира функции и
 типови за работа со информации поврзани со времето, како што се мерење временски интервали, форматирање и парсирање
  на датуми и времиња и манипулирање со датуми и времиња.Ги користамнејзините функцији time и NULL. Истотака од библијотеката
   <cstdlib> ги користам srand() која генерира некој непознат број, rand() го иницијализира тој број.

-Покажувачот е променлива која ја зачувува мемориската адреса на друга променлива. Покажувачите користат за директно манипулирање
 со меморијата и овозможуваат пулсирање по ефективно кодирање. Тие се декларираат со помош на симболот *, се доделува мемориска
 адреса со помош на операторот &.

- Мојата програма користи енумерација за костумот и вредноста на картата и потоа тие променливи ги клавам во структурата во структурата
правам унија вокојо имам тип на вредност од енумерација и карактери надвор од унијата во структурата имам и променлива од Suit enumeracijata
 и ова а структура мија прави картата.makeDeckOfCards функцијата ми ја иницијализирва низата deck od structurata Card.displayDeck функцијата
  ми ја принта низата со карти.
-Во функцијата shuffleDeck користам Fisher-Yates алгоритам  која го меша редоследот  со помош на генерирање на непознат број користејки го
 моменталното време  и со тој број прави индекс j кој е остаток од должината на низата и непознатиот број .Потоа со тој немознат индекс ј прави
 swap со моменталниот i indeks .
  */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum SUIT
{
    SPADES,
    HEARTS,
    CLUBS,
    DIAMONDS,
    JOKER,
};

enum Value
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
};

struct Card
{
    union
    {
        Value numberValue;
        char charValue;
    };
    SUIT suit;
};

void makeDeckOfCard(Card* deck, int deckSize)
{
    int index = 0;
    for (int i = SPADES; i <= DIAMONDS; i++)
        {
        for (int j = ACE; j <= KING; j++)
            {

            deck[index].suit = static_cast<SUIT>(i);

            if (j >= TWO && j <= TEN)
                {
                deck[index].numberValue = static_cast<Value>(j);
                }
            else
                {
                switch (j)
                    {
                    case ACE:
                        deck[index].charValue = 'A';
                        break;
                    case JACK:
                        deck[index].charValue = 'J';
                        break;
                    case QUEEN:
                        deck[index].charValue = 'Q';
                        break;
                    case KING:
                        deck[index].charValue = 'K';
                        break;
                    default:
                        break;
                    }
                }
            index++;
            }
        }
    deck[index].suit = JOKER;
    index++;
    deck[index].suit = JOKER;
}

void displayDeck(Card deck[], int deckSize)
{
    for (int i = 0; i < deckSize; i++)
        {
        if (deck[i].suit == JOKER)
            {
            cout << "Joker" << endl;
            }
        else if (deck[i].numberValue >= TWO && deck[i].numberValue <= TEN)
            {
            cout << deck[i].numberValue << " of ";
            }
        else
            {
            cout << deck[i].charValue << " of ";
            }
        switch (deck[i].suit)
            {
            case SPADES:
                cout << "Spades" << endl;
                break;
            case HEARTS:
                cout << "Hearts" << endl;
                break;
            case CLUBS:
                cout << "Clubs" << endl;
                break;
            case DIAMONDS:
                cout << "Diamonds" << endl;
                break;
            default:
                break;
            }

        }
}
void shuffleDeck(Card* deck, int deckSize )
{
    srand(time(NULL));
    for (int i = deckSize - 1; i > 0; i--)
        {
        int j = rand() % (i + 1);
        swap(deck[i], deck[j]);
        }
}

int main()
{
    const int deckSize = 54;
    Card deck[deckSize];

    makeDeckOfCard(deck, deckSize);

    cout<<"Cards shuffled:"<<endl;
    cout<<endl;
    shuffleDeck(deck, deckSize );
    displayDeck(deck, deckSize);
    return 0;
}
