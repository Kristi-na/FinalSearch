#include <iostream>
#include <stdlib.h>
template <class T> void exch(T &, T &);
template <class T> void compexch(T &, T &);
template <class T> void selection(T *, int, int, int *, int *);
template <class T> void insertion(T *, int, int, int &, int &);
template <class T> void bubble(T *, int, int);
using namespace std;
int main(int argc, char *argv[])
{
    int i, N = atoi(argv[1]), KaDaryt = atoi(argv[2]);
    int *a = new int[N];
    if (KaDaryt) // Atsitiktinai sugeneruoja N skaiciu intervale: 1,...,1000.
      for (i = 0; i < N; i++)
        a[i] = 1000*(1.0*rand()/RAND_MAX);
    else // Savo nuožiura ivedame skaicius. Noredami baigti ivedima, ivedame bet koki simboli - ne skaiciu.
      { N = 0; while (cin >> a[N]) N++; }
    cout << "Ivestas skaiciu masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
    selection(a, 0, N-1, &L, &S);
    cout << "Surusiuotas skaiciu masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
}
// Sukeicia elementus vietomis
template <class T>
  void exch(T &A, T &B)
    { T t = A ; A = B; B = t; }
// Sukeicia elementus vietomis tik jei patenkinta salyga
template <class T>
  void compexch(T &A, T &B)
    { if (B < A) exch(A, B); }
// Išrinkimo algoritmo realizacija
template <class T>
void selection(T a[], int l, int r, int * L, int * S)
  { for (int i = l; i < r; i++)
      { int min = i;
        for (int j = i+1; j <= r; j++)
            if (a[j] < a[min]) min = j;
        exch(a[i], a[min]);
        *S = *S + 1;
      }
  }
// Iterpimo algoritmo realizacija
template <class T>
void insertion(T a[], int l, int r)
  { int i;
    for (i = r; i > l; i--) compexch(a[i-1], a[i]);
    for (i = l+2; i <= r; i++)
      { int j = i; T v = a[i];
        while (v < a[j-1])
          { a[j] = a[j-1]; j--; }
        a[j] = v;
      }
  }
// Burbulo algoritmas
template <class T>
void bubble(T a[], int l, int r)
  { for (int i = l; i < r; i++)
      for (int j = r; j > i; j--)
        compexch(a[j-1], a[j]);
  }
  
// Quick sort
template <class T>
void quick_sort(T a[], int l, int r)
  { pirmas=a[0]; paskutinis=a[r-1]; pivot=a[1];
    for (int i = l; i < r; i++)
      for (int j = r; j > i; j--)
        while (pirmas != paskutinis]){
              if(cmp(*pirmas, *pivot)){
                pirmas++;}
              else{
                   while((pirmas != --paskutinis) && cmp(*pivot, *paskutinis))
                     std::inter_swap(pirmas, paskutinis);
                     }
              }
        }
        --pirmas;
        std::inter_swap(a[0], pirmas);
        quick_sort(a[0], pirmas, cmp);
        quick_sort(paskutinis, a[r-1],cmp);
  }
