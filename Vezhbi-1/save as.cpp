/* Алгоритмот работи така што првиот елемент предпоставува дека е најмал,
потоа проверува дали во елементите после најмалиот ке најди некој што е помал,
доколку најде помал тој му прави промена на местата на новиот најмал број со претходниот најмал број,
почнува нов круг и и го земва следниот елемент за најмал и ја прави истата проверка,
доколку најде помал му ги заменува местата, и истото се повторува повторно. */
#include <iostream>

using namespace std;
void fillArrayWithElements(int n,int arr[100])
{
    int element;

    for(int i=0; i<n; i++)
        {
        cin>>element;
        arr[i]=element;
        }
}
void printArray(int n,int arr[100])
{
    for(int i=0; i<n; i++)
        {
        cout<<arr[i]<<"\t";
        }
}
void swapElements(int *num1,int *num2 )
{
    int temp=*num1;
    *num1=*num2;
    *num2=temp;
}

void sectionSort(int n,int arr[100])
{
    for(int i=0; i<n-1; i++)
        {
        int miN=i;
        for(int j=i+1; j<n; j++)
            {
            if(arr[miN]>arr[j])
                {
                miN=j;
                }
            }
        if(miN!=i)
            {
            swapElements(&arr[miN],&arr[i]);
            }
        }
}
int main()
{
    int arr[100];
    int n;

    cout << "Enter the number of elements in array:"<<endl;
    cin>>n;

    cout<<"Vnesigi elementite na nizata:"<<endl;
    fillArrayWithElements(n,arr);
    cout<<"Vashata niza e:"<<endl;
    printArray(n,arr);
    cout<<endl;
    sectionSort(n,arr);
    cout<<"Sortiranata niza:"<<endl;
    printArray(n,arr);
    cout<<"Nikola Hristovski"<<endl;
    return 0;
}

