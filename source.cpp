#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

struct nod
{
	int inf;
	nod *urm;
};

int n;
nod *p,*u;

void creare()
{
	ifstream f("lista.in");
	int i,x;
	nod *q;
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>x;
		if(p==NULL)
		{
			p=new nod;
			p->inf=x; // (*p).inf=x;
			p->urm=NULL;
			u=p;
		}
		else
		{
			q=new nod;
			q->inf=x;
			u->urm=q;
			u=q;
		}
	}
	u->urm=NULL;
}

void afisare()
{
	nod *q;
	if(n==0)
		cout<<"Lista vida"<<endl;
	else
	{
		for(q=p;q;q=q->urm)
			cout<<q->inf<<" ";
		cout<<endl;
	}
}

void afisare_recursiv(nod *q)
{
	if(q)
	{
		afisare_recursiv(q->urm);
		cout<<q->inf<< " ";
	}
	else
		cout<<endl;
}

void add_poz()
{
	int poz,x,i;
	do
	{
		cout<<"Pozitia de inserat este: ";
		cin>>poz;
	}while(poz<1 || poz>n+1);
	cout<<"Elementul de adaugat: ";
	cin>>x;
	nod *r,*q=new nod;
	q->inf=x;
	if(poz==1)
	{
		q->urm=p;
		p=q;
		u=p;
		u->urm=NULL;
	}
	else
		if(poz==n+1)
		{
			u->urm=q;
			u=q;
			u->urm=NULL;
		}
		else
		{
			for(i=1,r=p;i<poz-1;i++,r=r->urm);
			q->urm=r->urm;
			r->urm=q;
		}
	n++;
}

void add_inainte()
{
	int x,y;
	nod *r,*q;
	cout<<"Elementul in fata caruia adaug: ";
	cin>>x;
	cout<<"Elementul de adaugat: ";
	cin>>y;
	r=p;
	if(p->inf==x)
	{
		q=new nod;
		q->inf=y;
		q->urm=p;
		p=q;
		r=r->urm;
		n++;
	}
	for(;r->urm!=NULL;r=r->urm)
		if(r->urm->inf==x)
		{
			q=new nod;
			q->inf=y;
			q->urm=r->urm;
			r->urm=q;
			r=r->urm;
			n++;
		}
	n++;
}

void add_dupa()
{
	int x,y;
	nod *r,*q;
	cout<<"Elementul dupa care adaug: ";
	cin>>x;
	cout<<"Elementul de adaugat: ";
	cin>>y;
	if(u->inf==x)
	{
		q=new nod;
		q->inf=y;
		q->urm=q;
		u=q;
		u->urm=NULL;
		n++;
	}
	for(r=p;r->urm!=NULL;r=r->urm)
		if(r->inf==x)
		{
			q=new nod;
			q->inf=y;
			q->urm=r->urm;
			r->urm=q;
			r=r->urm;
			n++;
		}
	n++;
}

void delete_poz()
{
	int poz,i=1;
	do
	{
		cout<<"Pozitia de sters este: ";
		cin>>poz;
	}while(poz<1 || poz>n);
	nod *r,*q;
	if(poz==1)
	{
		q=p;
		p=p->urm;
		delete q;
		n--;
	}
	else
	{
		for(r=p;i<poz-1 && r->urm;i++,r=r->urm);
			q=r->urm;
		r->urm=q->urm;
		delete q;
		n--;
	}
}

void delete_element()
{
	int el;
	nod *r,*q;
	cout<<"Elementul de sters: ";
	cin>>el;
	if(n && p->inf==el)
	{
		q=p;
		p=p->urm;
		delete q;
		n--;
	}
	if(n)
	{
		r=p;
		while(r->urm!=u && r)
			if(r->urm->inf==el)
			{
				q=r->urm;
				r->urm=q->urm;
				delete q;
				n--;
			}
			else
				r=r->urm;
	}
	if(n && u->inf==el)
	{
		q=u;
		u=r;
		u->urm=NULL;
		delete q;
		n--;
	}
}

int main()
{
	int op;
	char rasp[10];
	do
	{
		cout<<"1. Creare de lista cu nr dat de elemente."<<endl;
		cout<<"2. Adaugare de element pe o pozitie."<<endl;
		cout<<"3. Adaugare de element inainte unui element dat."<<endl;
		cout<<"4. Adaugare de element dupa un element dat."<<endl;
		cout<<"5. Stergere element de pe o pozitie data."<<endl;
		cout<<"6. Stergerea unui element dat."<<endl;
		do
		{
			cout<<endl<<"Operatia de executat: ";cin>>op;
		}while(op<1 || op>6);
		switch(op)
		{
			case 1:{creare();afisare();break;}
			case 2:{add_poz();afisare();break;}
			case 3:{add_inainte();afisare();break;}
			case 4:{add_dupa();afisare();break;}
			case 5:{delete_poz();afisare();break;}
			case 6:{delete_element();afisare();break;}
		}
		cin.get();
		cout<<"Mai rulati maniul ? (Da/Nu)"<<endl;
		cin.get(rasp,10);
		strupr(rasp);
		system("cls");
	}while(strcmp(rasp,"DA")==0);
	return 0;
}
