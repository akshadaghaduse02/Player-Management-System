/*Development of a Double Circular Linked List for Managing Player Data in C++"
Create a program to manage a double circular linked list of Players using C++. Each player has a name, jersey number, and age. The list must support various operations:

Create List: Initialize the list with a specified number of players.
Show List: Display all players in the list.
Search Data:
By jersey number
By name
Count Nodes: Count and return the number of players in the list.
Add Data:
At the beginning of the list
At the end of the list
At a specified position in the list
Sort Data:
By name
By jersey number
By age
Delete Data: Remove the player at the beginning of the list.
The program should present a menu to the user to choose from these operations and perform the selected action.*/

#include<iostream>
#include<string.h>
using namespace std;

class Players
{
	public:
		char name[30];
		int jerseyn,age;
		Players * prev,*next;
		
		Players()
		{
		//	name = NULL;
			jerseyn = 0;
			age = 0;
			prev = NULL;
			next = NULL;
		}
		Players(char * p,int cjerseyn,int cage)
		{
			strcpy(name,p);
			jerseyn = cjerseyn;
			age = cage;
			prev = NULL;
			next = NULL;
		}
};
class DCLL
{
	Players * front;
	Players * rear;
	
	public:
		DCLL()
		{
			front = NULL;
			rear = NULL;
		}
		void create()
		{
			int n,age,jerseyn;
			char name[30];
			cout<<"\nEnter how many Node of class Players you want create = ";
			cin>>n;
			cout<<"\nEnter data for first Player : ";
			cout<<"\nEnter Name = ";
			cin.ignore(1);
			cin.getline(name,30);
			cout<<"\nEnter Jersy Number = ";
			cin>>jerseyn;
			cout<<"\nEnter Age = ";
			cin>>age;
			front = new Players(name,jerseyn,age);
			Players * p;
			p=front;
			for(int i=1;i<=n-1;i++)
			{
				cout<<"\nEnter data for next player : ";
				cout<<"\nEnter Name = ";
				cin.ignore(1);
				cin.getline(name,30);
				cout<<"\nEnter Jersey Number = ";
				cin>>jerseyn;
				cout<<"\nEnter Age = ";
				cin>>age;
				p->next = new Players(name,jerseyn,age);
				p->next->prev = p;
				p=p->next;
			}
			p->next=front;
			rear = front;
			front->prev = rear;
		}
		
		void show()
		{
			
			if(front==NULL)
			{
				cout<<"\nList empty.";
				return;
			}
			Players * p;
			p=front;
			do
			{
				cout<<"\n\nName = "<<p->name;
				cout<<"\nJersey Number = "<<p->jerseyn;
				cout<<"\nAge = "<<p->age;
				p=p->next;
			}while(p!=front);
			
		}
		
		int jsearch(int sjerseyn)
		{
			if(front!=NULL)
			{
				Players * p;
				p=front;
				do
				{
					if(p->jerseyn == sjerseyn)
					{
						return 1;
					}
					p=p->next;
				}while(p!=front);
				return 0;
			}
			else
			{
				cout<<"\nlist empty.";
			}
		}
		
		int nsearch(char * sn)
		{
			if(front!=NULL)
			{
				Players * p;
				p=front;
				do
				{
					if(strcmp(p->name,sn)==0)
					{
						return 1;
					}
					p=p->next;
				}while(p!=front);
				return 0;
			}
			cout<<"\nList empty.";
		}
		
		int count()
		{
			int cnt=0;
			Players * p;
			p = front;
			do
			{
				cnt++;
				p=p->next;
			}while(p!=front);
			return cnt;
		}
		
		void addatbeg(char * an,int ajersey,int age)
		{
			Players * p;
			p = new Players(an,ajersey,age);
			if(front==NULL)
			{
				front=p;
				front->next=front;
				front->prev=front;
				rear=front;
			}
			else
			{
				p->next=front;
				p->prev=rear;
				front->prev=p;
				rear->next=p;
				front=p;
			}
		}
		
		void addatend(char * an,int ajersey,int age)
		{
			Players *p,*q;
			q=new Players(an,ajersey,age);
			if(front == NULL)
			{
				front = rear = q;
				rear->next = front;
				rear->prev =front;
			}
			else
			{
				p=front;
				while(p->next!=front)
				{
					p=p->next;
				}
				q->next=p->next;
				q->prev=p;
				p->next=q;
				rear=q;
				front->prev=q;
			}
		}
		
		void addbypos(int pos,char * an,int ajerseyn,int age)
		{
			int n;
			n=count();
			Players *p,*q;
			q=new Players(an,ajerseyn,age);
			if(pos<1 || pos>n+1)
			{
				cout<<"\nInvalid Position.";
				return;
			}
			if(pos == 1)
			{
				addatbeg(an,ajerseyn,age);
				return;
			}
			else
			{
				p=front;
				for(int i=1;i<pos-1;i++)
				{
					p=p->next;
				}
				q->next = p->next;
				q->prev = p;
				p->next=q;
				if(p!=rear)
				{
					q->next->prev=q;
				}
				else
				{
					rear=q;
					front->prev=rear;
				}
			}
		}
		
		void nsort()
		{
			Players *i,*j;
			
			for(i=front;i->next!=front;i=i->next)
			{
				for(j=i->next;j!=front;j=j->next)
				{
					if(strcmp(i->name,j->name)==1)
					{
						Players temp;
						strcpy(temp.name,i->name);
						temp.jerseyn = i->jerseyn;
						temp.age = i->age;
						
						strcpy(i->name,j->name);
						i->jerseyn = j->jerseyn;
						i->age= j->age;
						
						strcpy(j->name,temp.name);
						j->jerseyn = temp.jerseyn;
						j->age = temp.age;
					}
				}
			}
		}
		
		void jsort()
		{
			Players *i,*j;
			
			for(i=front;i->next!=front;i=i->next)
			{
				for(j=i->next;j!=front;j=j->next)
				{
					if(i->jerseyn>j->jerseyn)
					{
						Players temp;
						strcpy(temp.name,i->name);
						temp.jerseyn = i->jerseyn;
						temp.age = i->age;
						
						strcpy(i->name,j->name);
						i->jerseyn = j->jerseyn;
						i->age= j->age;
						
						strcpy(j->name,temp.name);
						j->jerseyn = temp.jerseyn;
						j->age = temp.age;
					}
				}
			}
		}
		
		void asort()
		{
			Players *i,*j;
			
			for(i=front;i->next!=front;i=i->next)
			{
				for(j=i->next;j!=front;j=j->next)
				{
					if(i->age>j->age)
					{
						Players temp;
						strcpy(temp.name,i->name);
						temp.jerseyn = i->jerseyn;
						temp.age = i->age;
						
						strcpy(i->name,j->name);
						i->jerseyn = j->jerseyn;
						i->age= j->age;
						
						strcpy(j->name,temp.name);
						j->jerseyn = temp.jerseyn;
						j->age = temp.age;
					}
				}
			}
		}
		
		void delatbeg()
		{
			Players * p;
			p=front;
			if(front == NULL)
			{
				cout<<"\nList is empty";
				return;
			}
			else
			{
				if(front==rear)
				{
					front=rear=NULL;
					delete front;
					return;
				}
				else
				{
					front = front->next;
			 		front->prev=p->prev;
					rear->next=p->next;
					delete p;
				}
			}
		}
};
int main()
{
	Players pobj;
	DCLL obj;
	int choice;
	
	do
	{
		cout<<"\n\nPress :-";
		cout<<"\n1. Create list.";
		cout<<"\n2. Show list.";
		cout<<"\n3. Search data.";
		cout<<"\n4. Count nodes.";
		cout<<"\n5. Add data at begin.";
		cout<<"\n6. Add data at end.";
		cout<<"\n7. Add data by position.";
		cout<<"\n8. To sort data.";
		cout<<"\n9. Delete data at begin.";
		cout<<"\n\nEnter your choice = ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				obj.create();
				cout<<"\nList created.";
				break;
				
			case 2:
				cout<<"\nShowing list = ";
				obj.show();
				break;
			
			case 3:
				cout<<"\nHow you want search data : ";
				cout<<"\n1. By jersey number.";
				cout<<"\n2. By Name.";
				cout<<"\nEnter your search choice = ";
				int schoice,res;
				cin>>schoice;
				switch(schoice)
				{
					case 1:
						cout<<"\nEnter jersey number you want search = ";
						int jerseyn;
						cin>>jerseyn;
						res = obj.jsearch(jerseyn);
						if(res == 1)
						{
							cout<<"\nJersey number is present.";
						}
						else if(res == 0)
						{
							cout<<"\nJersey number is not present.";
						}
						break;
						
					case 2:
						cout<<"\nEnter name you want to search = ";
						char sname[30];
						cin.ignore(1);
						cin.getline(sname,30);
						res = obj.nsearch(sname);
						if(res == 1)
						{
							cout<<"\nName is present.";
						}
						else if(res == 0)
						{
							cout<<"\nName is not present.";
						}
						break;
						
					default:
						cout<<"\nYou entered invalid choice ";
						break;
				}
				break;
			
			case 4:
				res=obj.count();
				cout<<"\nTotal number of Nodes are = "<<res;
				break;
				
			case 5:
				cout<<"\nEnter data to add at begin :";
				char aname[30];
				int jerseyn,age;
				cout<<"\nEnter Name = ";
				cin.ignore(1);
				cin.getline(aname,30);
				cout<<"\nEnter jersey number = ";
				cin>>jerseyn;
				cout<<"\nEnter Age = ";
				cin>>age;
				obj.addatbeg(aname,jerseyn,age);
				break;
				
			case 6:
				cout<<"\nEnter data to add at end :";
				cout<<"\nEnter Name = ";
				cin.ignore(1);
				cin.getline(aname,30);
				cout<<"\nEnter jersey Number = ";
				cin>>jerseyn;
				cout<<"\nEnter Age = ";
				cin>>age;
				obj.addatend(aname,jerseyn,age);
				break;
			
			case 7:
				cout<<"\nEnter data to add by positon :";
				cout<<"\nEnter position to add data = ";
				int pos;
				cin>>pos;
				cout<<"\nEnter Name =";	
				cin.ignore(1);
				cin.getline(aname,30);
				cout<<"\nEnter jersey number =";
				cin>>jerseyn;
				cout<<"\nEnter Age = ";
				cin>>age;
				obj.addbypos(pos,aname,jerseyn,age);
				break;
				
			case 8:
				cout<<"\n\nHow you want sort data = ";
				cout<<"\n1. By Name.";
				cout<<"\n2. By Jersey Number.";
				cout<<"\n3. By Age.";
				cin>>schoice;
				switch(schoice)
				{
					case 1:
						obj.nsort();
						cout<<"\nYour data is sorted by name";
						break;
						
					case 2:
						obj.jsort();
						cout<<"\nYour data is sorted by Jersey Number.";
						break;
					
					case 3:
						obj.asort();
						cout<<"\nYour data is sorted By Age.";
						break;
						
					default:
						cout<<"\nYou entered Invalid choice.";
						break;
				}
				break;
				
			case 9:
				obj.delatbeg();	
				cout<<"\nYour delatbeg() fuction is completed.";
				break;			
		}
	}while(choice!=0);
	cout<<"\nCode Terminated";
}
