#include <iostream>

using namespace std;

class Nod
{
    char valoare;
    Nod *next;
public:

    friend class Coada;

    Nod();
    char getValoare();
    Nod* getNext();

    friend ostream &operator <<(ostream &out,const Nod &p);
    friend istream &operator >>(istream &in, Nod &p);
};

Nod::Nod()
{
    next=nullptr;
}

char Nod::getValoare()
{
    return valoare;
}

Nod* Nod::getNext()
{
    return next;
}

ostream &operator <<(ostream &out,const Nod &p)
{
    out<<p.valoare<<" ";
    return out;
}

istream &operator >>(istream &in,Nod &p)
{
    in>>p.valoare;
    return in;
}

class Coada
{
    Nod *primul;
    Nod *ultimul;
public:

    Coada();
    Coada(const Coada &c);
    ~Coada();

    void adauga_element(char);
    void scoate_element();
    void afiseaza_varf();
    void afiseaza_coada();
    void sterge_coada();

    friend Coada operator +(const Coada &c,const Coada &q);
    friend Coada operator -(const Coada &c, const Coada &q);

    void operator =(const Coada &q);

    friend ostream &operator <<(ostream &out,Coada &c);
    friend istream &operator >>(istream &in,Coada &c);

    friend bool operator ==(const Coada &c,const Coada &q);
    friend bool operator !=(const Coada &c,const Coada &q);

    friend bool operator <(const Coada &c,const Coada &q);
    friend bool operator >(const Coada &c,const Coada &q);



};

Coada::Coada()
{
    primul=nullptr;
    ultimul=nullptr;
}

Coada::Coada(const Coada &c)
{
    if(c.primul==nullptr)
        {
            primul=nullptr;
            ultimul=nullptr;
        }
    else
    {
        primul=new Nod;
        ultimul=new Nod;
        Nod *p=c.primul;
        int poz=0;
        while(p!=nullptr)
        {
            if(poz==0)
            {
                primul->valoare=p->getValoare();
                primul->next=nullptr;
                ultimul=primul;
                poz++;
            }
            else
            {
                Nod *t=new Nod;
                t->valoare=p->getValoare();
                t->next=nullptr;
                ultimul->next=t;
                ultimul=ultimul->next;
            }
            p=p->getNext();
        }
    }
}

Coada::~Coada()
{
    Nod *p;
    while(primul!=nullptr)
    {
        p=primul;
        primul=primul->next;
        delete p;
    }
}

void Coada::adauga_element(char litera)
{
    if(primul==nullptr)
    {
        primul=new Nod;
        primul->valoare=litera;
        primul->next=nullptr;
        ultimul=primul;
    }
    else
    {
        Nod *p=new Nod;
        p->valoare=litera;
        p->next=nullptr;
        ultimul->next=p;
        ultimul=ultimul->next;

    }
}

void Coada::scoate_element()
{
    if(primul==nullptr)
        cout<<"Coada este goala";
    else
    {
         Nod *p=primul;
         primul=primul->next;
         delete p;
         cout<<"A fost extras un element din coada!";

    }
}

void Coada::afiseaza_varf()
{
   if(primul==nullptr)
    cout<<"Coada este goala";
   else
   {
       cout<<"Varful cozii este: "<<primul->valoare;
   }
}

void Coada::afiseaza_coada()
{
    if(primul==nullptr)
        cout<<"Coada este goala";
    else
    {
        cout<<"Elementele cozii sunt: ";
        Nod *p=primul;
        while(p!=nullptr)
        {
            cout<<p->getValoare()<<" ";
            p=p->getNext();
        }
    }
}

void Coada::sterge_coada()
{
    if(primul==nullptr)
        cout<<"Coada este deja goala";
    else
    {
        Nod *p;
        while(primul!=nullptr)
        {
            p=primul;
            primul=primul->next;
            delete p;
        }
    }
}

Coada operator +(const Coada &c,const Coada &q)
{
    if(c.primul==nullptr)
        return q;
    else if(q.primul==nullptr)
        return c;
    else
    {
        Coada noua;
        Nod *p=new Nod;
        p=c.primul;
        while(p!=nullptr)
        {
            noua.adauga_element(p->getValoare());
            p=p->getNext();
        }
        p=q.primul;
        while(p!=nullptr)
        {
            noua.adauga_element(p->getValoare());
            p=p->getNext();
        }
        return noua;
    }
}

Coada operator -(const Coada &c,const Coada &q)
{
    if(q.primul==nullptr)
        return c;
    else if(c.primul==nullptr)
        return c;
    else
    {
        Coada noua;
        Nod *pc=c.primul;
        Nod *pq=q.primul;
        int ok=0;
        while(pc!=nullptr)
        {
            ok=0;
            pq=q.primul;
            while(pq!=nullptr)
            {
                if(pc->getValoare()==pq->getValoare())
                    ok=1;
                pq=pq->getNext();
            }
            if(ok==0)
                noua.adauga_element(pc->getValoare());


            pc=pc->getNext();

        }
        return noua;
    }
}

void Coada::operator=(const Coada &c)
{
    if(c.primul==nullptr)
    {
        primul=nullptr;
        ultimul=nullptr;
    }
    else
    {
        primul=new Nod;
        ultimul=new Nod;
        Nod *p=c.primul;
        int poz=0;
        while(p!=nullptr)
        {
            if(poz==0)
            {
                primul->valoare=p->getValoare();
                primul->next=nullptr;
                ultimul=primul;
                poz++;
            }
            else
            {
                Nod *t=new Nod;
                t->valoare=p->getValoare();
                t->next=nullptr;
                ultimul->next=t;
                ultimul=ultimul->next;
            }
            p=p->getNext();
        }
    }
}

ostream &operator <<(ostream &out,Coada &c)
{
    if(c.primul==nullptr)
        cout<<"Coada este deja goala";
    else
    {
        cout<<"Elementele cozii sunt: ";
        Nod *p=c.primul;
        Nod *a;
        while(p!=nullptr)
        {
            cout<<*p<<" ";
            a=p;
            p=p->getNext();
            c.primul=p;
            delete a;

        }
    }
}

istream &operator >>(istream &in,Coada &c)
{
    Nod p;
    int n,i;
    cout<<"Cate elemente are coada? ";
    cin>>n;
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Sa se dea elementul de pe pozitia "<<i<<": ";
        cin>>p;
        c.adauga_element(p.getValoare());
    }
}

bool operator ==(const Coada &c,const Coada &q)
{
    int verifica=0;
    Nod *pc=c.primul;
    Nod *pq=q.primul;
    while(pc!=nullptr && pq!=nullptr)
    {
        if(pc->getValoare()!=pq->getValoare())
        {
            pc=nullptr;
            verifica=1;
        }
        if(pc!=nullptr)
        {
            pc=pc->getNext();
            pq=pq->getNext();
        }
    }
    if((pc==nullptr && pq!=nullptr) || (pc!=nullptr && pq==nullptr))
        verifica=1;

    if(verifica==0)
        return 1;
    else return 0;

}

bool operator !=(const Coada &c,const Coada &q)
{
    return !(c==q);
}

bool operator <(const Coada &c,const Coada &q)
{
    int nr1=0,nr2=0;
    Nod *pc=c.primul;
    Nod *pq=q.primul;
    while(pc!=nullptr)
    {
        nr1++;
        pc=pc->getNext();
    }
    while(pq!=nullptr)
    {
        nr2++;
        pq=pq->getNext();
    }
    if(nr1<nr2)
    return 1;
    else return 0;

}

bool operator >(const Coada &c,const Coada &q)
{
    int nr1=0,nr2=0;
    Nod *pc=c.primul;
    Nod *pq=q.primul;
    while(pc!=nullptr)
    {
        nr1++;
        pc=pc->getNext();
    }
    while(pq!=nullptr)
    {
        nr2++;
        pq=pq->getNext();
    }
    if(nr1<nr2)
    return 0;
    else return 1;

}

int main()
{
    cout<<"Proiect Programare Orientata pe Obiecte --- Coada de carcatere"<<endl<<endl;
    cout<<"Meniu:  "<<endl<<endl<<"Operatiile intre 1-5 se vor efectua pe o singura coada, iar aceasta se va schimba pe parcurs in functie de operatii. "<<endl;
    cout<<"Operatiile intre 6-9 se vor efectua pe 2 cozi date de utilizator, iar acestea se vor restarta mereu la inceputul operatiei(Adica dupa fiecare operatie, coziile se vor golii)."<<endl<<endl;
    int ok=0,verifica;
    Coada c;
    Coada c1;
    Coada c2;
    Coada c3;
    char caracter;
    while(ok==0)
    {
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"1.Adauga element in coada"<<endl<<"2.Scoate element din coada"<<endl<<"3.Afiseaza varful cozii"<<endl;
        cout<<"4.Afiseaza coada"<<endl<<"5.Afiseaza coada concomitent cu golirea ei"<<endl<<"6.Adunarea doua cozi de caractere";
        cout<<endl<<"7.Scaderea a doua cozi de caractere"<<endl<<"8.Verificarea egalitatii a doua cozi de caractere"<<endl;
        cout<<"9.Compararea numarului de elemente a doua cozi de caractere"<<endl<<"10.Inchidere Program"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<endl<<"Selectati o operatie: ";
        cin>>verifica;
        cout<<endl;
        switch(verifica)
        {
            case 1:
            {
                cout<<endl;
                cout<<"Ati ales optiunea de a adauga in element in coada."<<endl<<endl;
                cout<<"Sa se dea un caracter care sa fie adaugat in coada: ";
                cin>>caracter;
                c.adauga_element(caracter);
                cout<<"Caracterul a fost adaugat!";
                cout<<endl<<endl;
                break;
            }
            case 2:
            {
                cout<<"Ati ales optiunea de a scoate un element din coada."<<endl;
                c.scoate_element();
                cout<<endl<<endl;
                break;
            }
            case 3:
            {
                cout<<"Ati ales optiunea de a afisa varful cozii."<<endl;
                c.afiseaza_varf();
                cout<<endl<<endl;
                break;
            }
            case 4:
            {
                cout<<"Ati ales optiunea de a afisa coada."<<endl;
                c.afiseaza_coada();
                cout<<endl<<endl;
                break;
            }
            case 5:
            {
                cout<<"Ati ales optiunea de a afisa coada concomitent cu golirea ei."<<endl;
                cout<<c;
                cout<<endl<<endl;
                break;
            }
            case 6:
            {
                cout<<"Ati ales optiunea de a aduna doua cozi.Suma a celor doua cozi se va pune in o a treia coada."<<endl<<endl;
                cout<<"Prima Coada: ";
                cin>>c1;
                cout<<endl;
                cout<<"A doua Coada: ";
                cin>>c2;
                cout<<endl;
                c3=c1+c2;
                cout<<"Prima coada: ";
                cout<<c1;
                cout<<endl;
                cout<<"A doua coada: ";
                cout<<c2;
                cout<<endl;
                cout<<"Coada in care s-a pus suma: ";
                cout<<c3;
                cout<<endl<<endl;
                break;
            }
            case 7:
            {
                cout<<"Ati ales optiunea de a scadea doua cozi.Diferenta a celor 2 cozi se va pune in o a treia coada."<<endl;
                cout<<"Prima Coada: ";
                cin>>c1;
                cout<<endl;
                cout<<"A doua Coada: ";
                cin>>c2;
                cout<<endl;
                c3=c1-c2;
                cout<<"Prima coada: ";
                cout<<c1;
                cout<<endl;
                cout<<"A doua coada: ";
                cout<<c2;
                cout<<endl;
                cout<<"Coada in care s-a pus diferenta: ";
                cout<<c3;
                cout<<endl<<endl;
                break;
            }
            case 8:
            {
                cout<<"Ati ales optiunea de a verifica daca doua cozi sunt egale."<<endl;
                cout<<"Prima Coada: ";
                cin>>c1;
                cout<<endl;
                cout<<"A doua Coada: ";
                cin>>c2;
                cout<<endl;
                if(c1==c2)
                    cout<<"Coziile au aceleasi elemente pe aceleasi pozitii.";
                else
                    cout<<"Coziile sunt diferite.";
                cout<<endl<<endl;
                cout<<"Prima coada: ";
                cout<<c1;
                cout<<endl;
                cout<<"A doua coada: ";
                cout<<c2;
                cout<<endl<<endl;
                break;
            }
            case 9:
            {
                cout<<"Ati ales optiunea de a compara doua cozi."<<endl;
                cout<<"Prima Coada: ";
                cin>>c1;
                cout<<endl;
                cout<<"A doua Coada: ";
                cin>>c2;
                cout<<endl;
                if(c1<c2)
                    cout<<"Prima coada are mai putine elemente decat a doua coada.";
                else if(c2<c1)
                    cout<<"Prima coada are mai multe elemente decat a doua coada.";
                else
                    cout<<"Coziile au un numar egal de elemente.";
                cout<<endl<<endl;
                cout<<"Prima coada: ";
                cout<<c1;
                cout<<endl;
                cout<<"A doua coada: ";
                cout<<c2;
                cout<<endl<<endl;
                break;
            }
            case 10:
            {
                ok=1;
                cout<<endl<<endl;
                break;
            }
            default:
            {
                cout<<"Ati selectat gresit, incercati din nou :)";
                cout<<endl<<endl;
                break;
            }
        }
    }
    return 0;
}
