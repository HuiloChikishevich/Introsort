#include "stdlib.h"
#include <iostream>
#include <ctime>
using namespace std;
int *a;
void quickSort(int l, int r)
{
int x = a[l + (r - l) / 2];
int i = l;
int j = r;
while(i <= j)
{
while(a[i] < x) i++;
while(a[j] > x) j--;
if(i <= j)
{
swap(a[i], a[j]);
i++;
j--;
}
}
if (i<r)
quickSort(i, r);

if (l<j)
quickSort(l, j);
}

void introSort(int* vec, unsigned int len, int min, int max)
 {

 int * cnt = new int[max-min+1];

 for (int i = min; i <= max; ++i) {
 cnt[i - min] = 0;
 }

 for (int i = 0; i < len; ++i) {
 ++cnt[vec[i] - min];
 }

 for (int i = min; i <= max; ++i) {
 for(int j = cnt[i - min]; j--;) {
 *vec++ = i;
 }
}
 delete [] cnt;
}

int main()
{

    int Min=-100;
    int Max=1000;
    int lenght=60000;
    int *f;
    a=new int [lenght];
    f=new int [lenght];
    for (int n=0;n<lenght;n++){
        a[n]=Min + rand() %Max;
        f[n]=Min + rand() %Max;
    }
    /*for (int n=0;n<lenght;n++)
        cout<<a[n]<<" ";
    cout<<endl;

    for (int n=0;n<lenght;n++)
        cout<<f[n]<<" ";
    cout<<endl;
    cout<<endl;*/

    unsigned int starttime_q =  clock();
    quickSort(0,lenght-1);
    unsigned int endtime_q = clock();
    unsigned int searchtime_q = endtime_q- starttime_q;
    unsigned int starttime_c =  clock();
    introSort(f,lenght,Min,Max);
    unsigned int endtime_c = clock();
    unsigned int searchtime_c = endtime_c - starttime_c;

    introSort(f,lenght,Min,Max);
        /*for (int n=0;n<lenght;n++)
        cout<<a[n]<<" ";
    cout<<endl;

    for (int n=0;n<lenght;n++)
        cout<<f[n]<<" ";
    cout<<endl;
    cout<<endl;*/
    cout<<searchtime_q<<" "<<searchtime_c;
    delete[]a;
    delete[]f;
}
