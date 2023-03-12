#include <iostream>
#include <math.h>
using namespace std;
struct nod{
    int numar;
    nod *next;
};
void rezolva_ec2()
{
    float a,b,c;
    cout<<"Rezolva ecuatie a*x^2+b*x+c=0"<<endl;
    cout<<"a= "; cin>>a;
    cout<<"b= "; cin>>b;
    cout<<"c= "; cin>>c;
    // rezolva ecuatia

    float d,x1,x2,x1i,x2i;
    if(a==0)
        cout<<"ecuatia este de gradul I";
    else
        {
            d=b*b-4*a*c;
            cout<<endl<<"d="<<d<<endl;
            if(d>0)
            {
                x1=(-b+sqrt(d))/(2*a);
                x2=(-b-sqrt(d))/(2*a);
                cout<<"x1="<<x1<<endl;
                cout<<"x2="<<x2<<endl;
            }
            if(d==0)
            {
                x1=-b/(2*a);

                cout<<"x1=x2="<<x1<<endl;
            }
            if(d<0)
            {
                x1=-b/(2*a);
                x2=-b/(2*a);
                x1i=sqrt(-d);
                x2i=-sqrt(-d);
                cout<<"x1="<<x1<<"+i"<<x1i<<endl;
                cout<<"x2="<<x2<<"+i"<<x2i<<endl;
            }

        }
}
void matrice()
{
    int n,m,p;
    cout<<"n=";cin>>n;
    cout<<"m=";cin>>m;
    cout<<"p=";cin>>p;
    int a[n][m], b[m][p], c[n][p];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {
                cout<<"a["<<i<<"]["<<j<<"]=";cin>>a[i][j];
            }
     for(int i=0;i<m;i++)
        for(int j=0;j<p;j++)
            {
                cout<<"b["<<i<<"]["<<j<<"]=";cin>>b[i][j];
            }
    for(int i=0;i<n;i++)
        for(int j=0;j<p;j++)
            {
                c[i][j]=0;
            for(int k=0;k<m;k++)
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
    for(int i=0;i<n;i++)
        {
            cout<<endl;
            for(int j=0;j<p;j++)
                cout<<c[i][j]<<" ";
        }
    cout<<endl;
}
void numar_prim()
{
    int n;
    int k=0;
    cout<<"n=";cin>>n;
    for(int i=2;i<=n/2;i++)
        if(n%i==0)
            {k=1;break;}
    if(k==0)
        cout<<"e prim"<<endl;
    else
        cout<<"nu e prim"<<endl;
}
void schimbare_baza()
{
    int n,m=0,b;
    cout<<"n=";cin>>n;
    cout<<"baza=";cin>>b;
    int v[100];
    while(n!=0)
    {
        m++;
        v[m]=n%b;
        n=n/b;
    }
    for(int i=m;i>=1;i--)
        cout<<v[i]<<" ";
    cout<<endl;
}
void sortare()
{
    int ind,v[100];
    int n;
    cout<<"n=";cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"v["<<i<<"]=";cin>>v[i];
    }
    do{
        ind=1;
        for(int i=0;i<n-1;i++)
            if(v[i]>v[i+1])
            {
                int aux;
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                ind=0;
            }
        }while(ind==0);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    }

void sortare2()
{
    int v[100];
    int n;
    cout<<"n=";cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"v["<<i<<"]=";cin>>v[i];
    }
    int minim=v[0],poz;
    for(int j=0;j<=n-2;j++)
    {
        minim=v[j];
        poz=j;
        for(int k=j+1;k<=n-1;k++)
            if(minim>v[k])
                {
                    minim=v[k];
                    poz=k;
                }
        if(poz!=j)
        {
            int aux;
            aux=v[j];
            v[j]=v[poz];
            v[poz]=aux;
        }
    }
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

void sortare3()
{
    int x[100];
    int n;
    cout<<"n=";cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"x["<<i<<"]=";cin>>x[i];
    }
    int b[100];
    for(int i=0;i<n;i++)
    {
        b[i]=0;
    }
    for(int i=0;i<=n-2;i++)
        for(int j=i+1;j<=n-1;j++)
            if(x[i]<=x[j])
                b[j]++;
            else
                b[i]++;
    int y[100];
    for(int j=0;j<=n-1;j++)
        y[b[j]]=x[j];
    for(int i=0;i<n;i++)
        cout<<y[i]<<" ";
    cout<<endl;
}

void interclasare(int x[100], int s, int m, int d)
{

    int i,j,k,y[100];
    i=s;
    j=m+1;
    k=0;
    while(i<=m && j<=d)
    {
        if(x[i]<=x[j])
        {
            y[k]=x[i];
            k++;
            i++;
        }
        else
            {
            y[k]=x[j];
            k++;
            j++;
            }
    }
    if(i<=m)
        for(int r=i;r<=m;r++)
        {
            y[k]=x[r];
            k++;
        }
    if(j<=d)
        for(int r=j;r<=d;r++)
        {
            y[k]=x[r];
            k++;
        }
    for(int r=0;r<=k-1;r++)
        x[s+r]=y[r];
}
void merge_sort(int *x, int s,int d)
{
    if(s<d)
    {
        int m;
        m=(s+d)/2;
        merge_sort(x,s,m);
        merge_sort(x,m+1,d);
        interclasare(x,s,m,d);
    }
}

void cautare()
{
    int n, v[100], x, k;
    cout<<"n=";cin>>n;
    cout<<"x=";cin>>x;
    for (int i=0;i<n;i++)
    {
        cout<<"v["<<i<<"]=";cin>>v[i];
    }
    k=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==x)
            k++;
    }
    if(k==0)
        cout<<"nu am gasit "<<x<<"in v";
    else
        cout<<"am gasit "<<x<<" in v de "<<k<<" ori";
}
int cautare_binara(int v[],int s, int d, int x)
{

    if(s > d)
        return -1;
    else
    {
        int m =(s+d)/2;
        if(x == v[m])
            return m;
        if(x < v[m])
            return cautare_binara(v,s, m-1, x);
        else
            return cautare_binara(v,m+1, d, x);
    }
}
void quicksort(int s,int d,int *x)
{
    int pivot,i,j;
    if(s<d)
    {
        pivot=x[s];
        i=s;
        j=d;
        while(i<j)
        {
            while((x[i]<pivot) && i<d)
                i++;
            while((x[j]>=pivot) && j>s)
                j--;
            if(i<=j)
            {
                int aux;
                aux=x[i];
                x[i]=x[j];
                x[j]=aux;
                i++;
                j--;
            }
        }
        quicksort(s,j,x);
        quicksort(i,d,x);
    }
}
void sortare_prin_insertie()
{
    int n,x[100];
    cout<<"n=";cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"x["<<i<<"]=";cin>>x[i];
    }
    for(int i=0;i<n;i++)
    {
        int aux,j;
        aux=x[i];
        j=i-1;
        while(x[j]>aux)
        {
            x[j+1]=x[j];
            j--;
        }
        x[j+1]=aux;
    }
    for(int i=0;i<n;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}
void shell_sort()
{
    int n,x[100];
    cout<<"n=";cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"x["<<i<<"]=";cin>>x[i];
    }
    int pas=n/2;
    int i,j;
    while(pas>=1)
    {
        i=0;
        while((i+pas)<=n-1)
        {
            int aux;
            j=i;
            aux=x[i+pas];
            while((x[j]>aux) && (j>=0))
            {
                x[j+pas]=x[j];
                j=j-pas;
            }
            x[j+pas]=aux;
            i++;
        }
        pas=pas/2;
    }
    for(int i=0;i<n;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}
void radix()
 {
    int n,x[100];
    cout<<"n=";cin>>n;
    for(int i=0;i<n;i++)
    {
    cout<<"x["<<i<<"]=";cin>>x[i];
    }
    int maxim=x[0];
      int y[50];
     for (int i=1;i<n;i++)
         if(x[i]>maxim)
           maxim=x[i];
     int M=0;
     while(maxim!=0)
        {M++;
        maxim=maxim/10;}
     int  C[50][50]={0};
     for(int i=0;i<=n-1;i++)
     {
       for(int j=0;j<=M-1;j++)
          y[j]=0;
       int aux=x[i];
       int M1=0;
       while(aux!=0)
       {
           y[M1]=aux%10;
           aux=aux/10;
           M1++;
       }
       for(int j=0;j<=M1-1;j++)
       C[i][M-1-j]=y[j];

     }

     for(int j=M-1;j>=0;j--)

     {  int i=0;
        for(int k=0;k<=9;k++)
         {
           for(int s=i;s<=n-1;s++)
              {
                if(C[s][j]==k)
                 {
                   for(int r=0;r<=M-1;r++)
                      y[r]=C[s][r];
                   for(int p=s-1;p>=i;p--)
                      for(int r=0;r<=M-1;r++)
                         C[p+1][r]=C[p][r];
                   for (int r=0;r<=M-1;r++)
                      C[i][r]=y[r];
                   i++;
                 }
              }
         }

     }
     for(int i=0;i<=n-1;i++)
     {
         for (int j=0;j<=M-1;j++)
            cout<<C[i][j];
        cout<<" ";
     }
     cout<<endl;
 }
 void afisare_lista_simpla(nod* cap)
{
    while(cap != NULL)
    {
        cout<<cap->numar<<" ";
        cap=cap->next;
    }
}
void inserare_inceput_lista_simpla(nod* &cap, int x)
{
    nod* p=new nod;
    p->numar=x;
    p->next=cap;
    cap=p;
}
void inserare_final_lista_simpla(nod* &cap, int x)
{
    nod* p=new nod;
    p->numar=x;
    p->next=NULL;
    if(cap == NULL)
        cap=p;
    else
    {
        nod *a=cap;
        while(a->next != NULL)
        {
            a=a->next;
        }
        a->next=p;
    }
}
void modificare_lista_simpla(nod* cap,int x,int y)
{
    while(cap != NULL)
    {
        if(cap->numar==x)
            cap->numar=y;
        cap=cap->next;
    }
}
void stergere_lista_simpla(nod* &cap, int valoare)
{
    if(cap->numar == valoare)
    {
        nod* victima = cap;
        cap = cap->next;
        delete victima;
        return;
    }
    nod* elem = cap;
    while (elem->next != NULL && elem->next->numar != valoare)
        elem = elem->next;
    if (elem->next != NULL)
        {
            nod* victima = cap->next;
            cap->next = cap->next->next;
            delete victima;
        }
}
 void lista_simpla()
 {
     int op;
     nod* cap=NULL;
     do{
        cout<<"3.1.  Inserare la inceput de lista"<<endl;
        cout<<"3.2.  Inserare la final de lista"<<endl;
        cout<<"3.3.  Modificare"<<endl;
        cout<<"3.4.  Stergere"<<endl;
        cout<<"3.5.  Afisare"<<endl;
        cout<<"3.0.  Incheiere  meniu lista simpla"<<endl;
        cout<<"Optiune lista = "; cin>>op;
        switch (op){
        case 1:
            int x;cout<<"numar nou=";cin>>x;
            inserare_inceput_lista_simpla(cap,x);
            break;
        case 2:
            int x2;cout<<"numar nou=";cin>>x2;
            inserare_final_lista_simpla(cap,x2);
            break;
        case 3:
            int y;cout<<"numar vechi=";cin>>y;
            int x3;cout<<"numar nou=";cin>>x3;
            modificare_lista_simpla(cap,y,x3);
            break;
        case 4:
            int x4;cout<<"numar sters=";cin>>x4;
            stergere_lista_simpla(cap,x4);
            break;
        case 5:
            afisare_lista_simpla(cap);
            cout<<endl;
            break;


        case 0:
            cout<<"A terminat lucrul cu meniu 3!"<<endl;
            break;

        default:
            cout<<"Optiune gresita in meniul 3!"<<endl;
            break;
        }// end switch meniu
        }while(op!=0);
 }
int main()
{
    // variabile ale main-ului
    int op, op1,op2,op3;
    //main
    // do
    cout<<"PROGRAME ASD - 2021"<<endl<<endl;
    cout<<"Ciobanu Andrei, 1333"<<endl;
    cout<<"________________________________"<<endl<<endl;
    do{
    cout<<endl<<"MENIU PRINCIPAL"<<endl<<"_____________________"<<endl;
    cout<<"1. Probleme simple de programare "<<endl;
    cout<<"2. Algoritmi de sortare si cautare"<<endl;
    cout<<"3. Lista simpla"<<endl;
    cout<<"0. Terminare program."<<endl;
    cout<<endl;
    cout<<"Optiune meniu principal op= "; cin>>op;
    switch (op){
    case 1:
        do{
        cout<<"1.1. Rezolvare completa pentru ecuatia de gradul al doilea"<<endl;
        cout<<"1.2. Inmultirea a doua matricea"<<endl;
        cout<<"1.3. Verificare numar prim"<<endl;
        cout<<"1.4. Trecerea unui numar din baza 10 in baza b=2,...,9"<<endl;
        cout<<"1.0. Incheiere meniu 1"<<endl;
        cout<<"Optiune pentru meniu 1 op1 = "; cin>>op1;
        switch (op1){
        case 1:
            rezolva_ec2();
            break;
        case 2:
            matrice();
            break;
        case 3:
            numar_prim();
            break;
        case 4:
            schimbare_baza();
            break;

        case 0:
            cout<<"A terminat lucrul cu meniu 1!"<<endl;
            break;

        default:
            cout<<"Optiune gresita in meniul 1!"<<endl;
            break;
        }// end switch meniu
        }while(op1!=0); // end repeta meniu 1
        break;

    case 2:
        do{
        cout<<"2.1.  Bubble Sort"<<endl;
        cout<<"2.2.  Selection Sort"<<endl;
        cout<<"2.3.  Counting Sort"<<endl;
        cout<<"2.4.  Merge Sort"<<endl;
        cout<<"2.5.  QuickSORT"<<endl;
        cout<<"2.6.  Insertion Sort "<<endl;
        cout<<"2.7.  Shell Sort"<<endl;
        cout<<"2.8.  Radix Sort "<<endl;
        cout<<"2.9.  Cautare secventiala"<<endl;
        cout<<"2.10. Cautare binara "<<endl;
        cout<<"2.0.  Incheiere meniu 2"<<endl;
        cout<<"Optiune pentru meniu 2 op1 = "; cin>>op2;
        switch (op2){
        case 1:
            sortare();
            break;
        case 2:
            sortare2();
            break;
        case 3:
            sortare3();
            break;
        case 4:
            int n,x[100];
            cout<<"n=";cin>>n;
            for(int i=0;i<n;i++)
            {
                cout<<"x["<<i<<"]=";cin>>x[i];
            }
            merge_sort(x,0,n-1);
            for(int i=0;i<n;i++)
                cout<<x[i]<<" ";
            cout<<endl;
            break;
        case 5:
            int p,z[100];
            cout<<"p=";cin>>p;
            for(int i=0;i<p;i++)
            {
                cout<<"z["<<i<<"]=";cin>>z[i];
            }
            quicksort(0,p-1,z);
            for(int i=0;i<p;i++)
            {
                cout<<z[i]<<" ";
            }
            cout<<endl;
            break;
        case 6:
            sortare_prin_insertie();
            break;
        case 7:
            shell_sort();
            break;
        case 8:
            radix();
            break;
        case 9:
            cautare();
            break;
        case 10:
            int m, v[100];
            cout<<"m=";cin>>m;
            for (int i=0;i<m;i++)
                {cout<<"v["<<i<<"]=";cin>>v[i];}
            int y;cout<<"y=";cin>>y;
            if(cautare_binara(v,0,m-1,y))
                cout<<"am gasit"<<endl;
            else
                cout<<"nu am gasit"<<endl;

            break;
        case 0:
            cout<<"A terminat lucrul cu meniu 2!"<<endl;
            break;

        default:
            cout<<"Optiune gresita in meniul 2!"<<endl;
            break;
        }// end switch meniu
        }while(op2!=0); // end repeta meniu 1
        break;

    case 3:
        do{
        cout<<"3.1.  Operatii cu liste simplu inlantuite: creare, parcurgere, adaugare, stergere, modificare."<<endl;
        cout<<"3.0.  Incheiere meniu 3"<<endl;
        cout<<"Optiune pentru meniu 3 op1 = "; cin>>op3;
        switch (op3){
        case 1:
            lista_simpla();
            break;

        case 0:
            cout<<"A terminat lucrul cu meniu 3!"<<endl;
            break;

        default:
            cout<<"Optiune gresita in meniul 3!"<<endl;
            break;
        }// end switch meniu
        }while(op3!=0); // end repeta meniu 3
        break;

    case 0:
        cout<<"Terminare program principal. La revedere!"<<endl;
        break;

    default:
        cout<<"Optiune gresita! "<<endl;
        break;
    } // end switch meniu principal
    }while(op!=0);
    return 0;
}
