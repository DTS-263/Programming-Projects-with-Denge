#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct element
{
	string name;
	string symbol;
	int atom_no;
	float atomic_weight;
	element *next;
};
class Linklist{
    private:
    element *tail;
    element *head;
    public:
     Linklist()
    {
        head=NULL;
        tail=NULL;
    }
    element *gethead()
    {
        return head;
    }
    element *gettail()
    {
        return tail;
    }
    void front(element *newNode)
    {
        if(head==NULL)
        {
            newNode->next=head;
            head=newNode;
            tail=newNode;
        }
        else
        {
            newNode->next=head;
            head=newNode;
        }
    }
    void last(element *newNode)
    {
        if(head==NULL)
        {
            newNode->next=NULL;
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
            newNode->next=NULL;
        }
    }
    void after(element *a,element *newNode)
    {
        newNode->next=a->next;
        a->next=newNode;
    }
};
class Hash: public Linklist{
    private:
        Linklist *chain = new Linklist[10];
    public:
        void insert(string name,string symbol,int atom_no,float atomic_weight)
        {
            int index=atom_no%10;
            element *newNode=new element;
            newNode->name=name;
            newNode->symbol=symbol;
            newNode->atom_no=atom_no;
            newNode->atomic_weight=atomic_weight;
            if(chain[index].gethead()==NULL)
            {
                chain[index].front(newNode);
            }
            else
            {
                element *temp=chain[index].gethead();
                element *prev=new element;
                while(temp!=NULL)
                {
                    prev=temp;
                    temp=temp->next;
                }
                if(temp==NULL)
                {
                    chain[index].last(newNode);
                }
                else if(chain[index].gethead()==temp)
                {
                    chain[index].front(newNode);
                }
                else
                {
                    chain[index].after(prev,newNode);
                }
            }
        }
        void displayHash()
        {
            for(int i=0;i<10;i++)
            {
                element *temp=chain[i].gethead();
                cout<<"chain["<<i<<"]-->";
                while(temp!=NULL)
                {
                    cout<<temp->name<<"-->";
                    temp=temp->next;
                }
                printf("NULL\n");
            }
        }
        void search_name(string name)
        {
            int index=0;
            int flag=0,flagi=0;
            while(index>=0 && index<=9)
            {
            	element *temp=chain[index].gethead();
            	while(temp!=NULL)
            	{
                	if(temp->name==name)
                	{
                    	cout<<"Name: "<<temp->name<<endl;
                    	cout<<"Atomic Number: "<<temp->atom_no<<endl;
                    	cout<<"Symbol: "<<temp->symbol<<endl;
                    	cout<<"Atomic Weight: "<<temp->atomic_weight<<endl;
                    	flag=1;
                    	flagi=1;
                    	break;
                	}
                	else
                	{
                    	temp=temp->next;
                	}
            	}
            	index=index+1;
			}
            if(flag==0)
            {
                cout<<"Not Found"<<endl;
            }
        }
        void search_number(int atm_no)
        {
            int index=atm_no%10;
            int flag=0;
            element *temp=chain[index].gethead();
            while(temp!=NULL)
            {
                if(temp->atom_no==atm_no)
                {
                    cout<<"Name: "<<temp->name<<endl;
                    cout<<"Atomic Number: "<<temp->atom_no<<endl;
                    cout<<"Symbol: "<<temp->symbol<<endl;
                    cout<<"Atomic Weight: "<<temp->atomic_weight<<endl;
                    flag=1;
                    break;
                }
                else
                {
                    temp=temp->next;
                }
            }
            if(flag==0)
            {
                cout<<"Not Found"<<endl;
            }
        }
        void search_symbol(string symbol)
        {
            int index=0;
            int flag=0,flagi=0;
            while(index>=0 && index<=9)
            {
            	element *temp=chain[index].gethead();
            	while(temp!=NULL)
            	{
                	if(temp->symbol==symbol)
                	{
                    	cout<<"Name: "<<temp->name<<endl;
                    	cout<<"Atomic Number: "<<temp->atom_no<<endl;
                    	cout<<"Symbol: "<<temp->symbol<<endl;
                    	cout<<"Atomic Weight: "<<temp->atomic_weight<<endl;
                    	flag=1;
                    	flagi=1;
                    	break;
                	}
                	else
                	{
                    	temp=temp->next;
                	}
            	}
            	index=index+1;
			}
            if(flag==0)
            {
                cout<<"Not Found"<<endl;
            }
        }
        void search_weight(float weight)
        {
            int index=0;
            int flag=0,flagi=0;
            while(index>=0 && index<=9)
            {
            	element *temp=chain[index].gethead();
            	while(temp!=NULL)
            	{
                	if(temp->atomic_weight==weight)
                	{
                    	cout<<"Name: "<<temp->name<<endl;
                    	cout<<"Atomic Number: "<<temp->atom_no<<endl;
                    	cout<<"Symbol: "<<temp->symbol<<endl;
                    	cout<<"Atomic Weight: "<<temp->atomic_weight<<endl;
                    	flag=1;
                    	flagi=1;
                    	break;
                	}
                	else
                	{
                    	temp=temp->next;
                	}
            	}
            	index=index+1;
            }
            if(flag==0)
            {
                cout<<"Not Found"<<endl;
            }
        }
};
class database:public Hash
{
	public:
		void d_insert(string name,string symbol,int no,float weight,Hash h)
		{
			h.insert(name,symbol,no,weight);
		}
		void d_search_name(string name,Hash h)
		{
			h.search_name(name);
		}
		void d_search_symbol(string symbol,Hash h)
		{
			h.search_symbol(symbol);
		}
		void d_search_number(int no,Hash h)
		{
			h.search_number(no);
		}
		void d_search_weight(float weight,Hash h)
		{
			h.search_weight(weight);
		}
		void d_displayHash(Hash h)
		{
			h.displayHash();
		}
};
void mainfunction()
{
		cout<<"Enter the corresponding choices: "<<endl;
		cout<<"1. Add an element: "<<endl;
		cout<<"2. Explore or search for an element: "<<endl;
		cout<<"3. Quit the program"<<endl;		
}
int main()
{
	database d;
	Hash h1;
	string name[6]={"Hydrogen","Helium","Lithium","Beryllium","Boron","Sodium"};
		string symbol[6]={"H","He","Li","Be","B","Na"};
		int num[6]={1,2,3,4,5,11};
		float w[6]={1.0079,4.0026,6.941,9.01218,10.811,22.9897};
		for(int i=0;i<6;i++)
		{
			d.d_insert(name[i],symbol[i],num[i],w[i],h1);
		}
		
		cout<<setw(50)<<"Modern Periodic Table"<<endl<<endl<<endl;
		mainfunction();
		int choices;
		cin>>choices;
		if(choices==1)
		{
			string name;
			string symbol;
			int atom_no;
			float atomic_weight;
			cout<<"Enter the required information for adding a element:"<<endl<<"Name,Symbol,Atomic Number and Atomic weight of that element in order"<<endl;
			cin>>name;
			cin>>symbol;
			cin>>atom_no;
			cin>>atomic_weight;
			d.d_insert(name,symbol,atom_no,atomic_weight,h1);
		}
		else if(choices==2)
		{
			int n;
			cout<<"Enter the corresponding choice for exploring an element: "<<endl;
			cout<<"1. Search by name of the element: "<<endl;
			cout<<"2. Search by the atomic number of the element: "<<endl;
			cout<<"3. Search by the symbol of the element: "<<endl;
			cout<<"4. Search by the atomic weight of the element: "<<endl;
			cin>>n;
			if(n==1)
			{
				string name;
				cin>>name;
				d.d_search_name(name,h1);
			}
			else if(n==2)
			{
				int atom_no;
				cin>>atom_no;
				d.d_search_number(atom_no,h1);
			}
			else if(n==3)
			{
				string sym;
				cin>>sym;
				d.d_search_symbol(sym,h1);
			}
			else if(n==4)
			{
				float weight;
				cin>>weight;
				d.d_search_weight(weight,h1);
			}
		}
		else
		{
			cout<<"Good Bye!!!! :) :) :)"<<endl;
		}
}

