#include<iostream>
#include<stdlib.h>

using namespace std;

class datetime
{
private:
    int day, month, year, hour, minute, second;
public:
    datetime() {}
    friend void operator>>(istream &in, datetime &dt);
    friend void operator<<(ostream &out, datetime &dt);
    ~datetime() {}
};


void operator>>(istream &in, datetime &dt)
{
    cout<<"\n Enter Date (DD/MM/YYYY): ";
    in>>dt.day>>dt.month>>dt.year;
    cout<<"\n Enter Time (HH:MM:SS): ";
    in>>dt.hour>>dt.minute>>dt.second;
    cout<<"\n ------------------";


    switch(dt.month)
        {
        case 1: //January
        case 3: //March
        case 5: //May
        case 7: //July
        case 8: //August
        case 10: //October
        case 12: //December
            if(dt.day>31)
                {
                cout<<"\n Invalid Days ";
                exit(0);
                }
            break;
        case 4: //April
        case 6: //June
        case 9: //September
        case 11: //November
            if(dt.day>30)
                {
                cout<<"\n Invalid Days ";
                exit(0);
                }
            break;
        case 2: // February

            if((dt.year%100!=0 && dt.year%4==0) || (dt.year%400==0))
                {
                if(dt.day>29)
                    {
                    cout<<"\n Invalid Days ";
                    exit(0);
                    }
                }
            else
                {
                if(dt.day>28)
                    {
                    cout<<"\n Invalid Days ";
                    exit(0);
                    }
                }
            break;
        default:
            cout<<"\n Invalid Month ";
            exit(0);
        }

    if(dt.hour > 23 || dt.minute > 59 || dt.second > 59)
        {
        cout<<"\n Invalid Time ";
        exit(0);
        }
}


void operator<<(ostream &out, datetime &dt)
{
    out<<"\n Date : ";
    out.width(2);
    out.fill('0');
    out<<dt.day;
    out<<"/";
    out.width(2);
    out.fill('0');
    out<<dt.month;
    out<<"/";
    out<<dt.year;



    int format_choice;
    cout<<"\n Select Time Format: ";
    cout<<"\n 1. 12-Hour Format";
    cout<<"\n 2. 24-Hour Format";
    cout<<"\n Enter your choice (1/2): ";
    cin>>format_choice;

    switch(format_choice)
        {
        case 1:
            if(dt.hour == 0)
                {
                out<< "12:";
                out.width(2);
                out.fill('0');
                out<<dt.minute;
                out<<":";
                out.width(2);
                out.fill('0');
                out<<dt.second<<" AM";
                }
            else if(dt.hour > 0 && dt.hour < 12)
                {
                out.width(2);
                out.fill('0');
                out<<dt.hour;
                out<<":";
                out.width(2);
                out.fill('0');
                out<<dt.minute;
                out<<":";
                out.width(2);
                out.fill('0');
                out<<dt.second<<" AM";
                }
            else if(dt.hour == 12)
                {
                out<< "12:";
                out.width(2);
                out.fill('0');
                out<<dt.minute;
                out<<":";
                out.width(2);
                out.fill('0');
                out<<dt.second<<" PM";
                }
            else
                {
                out.width(2);
                out.fill('0');
                out<<dt.hour-12;
                out<<":";
                out.width(2);
                out.fill('0');
                out<<dt.minute;
                out<<":";
                out.width(2);
                out.fill('0');
                out<<dt.second<<" PM";
                }
            break;
        case 2:
            out.width(2);
            out.fill('0');
            out<<dt.hour;
            out<<":";
            out.width(2);
            out.fill('0');
            out<<dt.minute;
            out<<":";
            out.width(2);
            out.fill('0');
            out<<dt.second;
            break;
        default:
            cout<<"\n Invalid Choice";
            exit(0);
        }
}

int main()
{
    datetime dt;
    char ch = 'y';

    while(ch == 'y' || ch == 'Y')
        {
        cin>>dt;
        cout<<dt;

        cout<<"\n\n Do you want to enter another datetime? (y/n): ";
        cin>>ch;
        }

    return 0;
}
