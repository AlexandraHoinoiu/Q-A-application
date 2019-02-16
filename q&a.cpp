#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<cstring>
using namespace std;

class Question
{
	string a;
	string q;
	string id;
	public:
		Question( string A,  string Q ,string ID)
		{
			a=A;
			q=Q;
			id=ID;
		}
		void display()
		{
			cout<<endl<<q<<endl;
		}
		int name(string anch)
		{
			if(anch==id) return 1;
			else return 0;
			
		}
		string get_ans()
		{
		  return this->a;
		}
};


void filli(int* b)
{
    for(int i=0;i<5;i++)
      b[i]=-1;

}

int* rander(int n)
{
    int*b;
    b=new int[5];
    filli(b);
    for(int i=0;i<4;i++)
    {
        int a=rand()%(n);
       b[i]=a;
     for(int j=0;j<i;j++)
     {
         if(b[j]==b[i])
         {
             b[i]=-1;
             i--;
             break;
         }
     }


    }

    return b;
}
int* rander1(int n=5)
{
    int*b;
    b=new int[6];
    filli(b);
    for(int i=0;i<5;i++)
    {
        int a=rand()%(n);
       b[i]=a;
     for(int j=0;j<i;j++)
     {
         if(b[j]==b[i])
         {
             b[i]=-1;
             i--;
             break;
         }
     }


    }

    return b;
}
int* rerand(int*b)
{
    int *a;

   a=rander1();


    int *c;
    c=new int[5];
    for(int i=0;i<5;i++){
            
         c[a[i]]=b[i];
    }


    return c;
}
void afis_rasp(string *v, string a, int*b,int n)
{
    for(int i=0;i<n;i++)
    {
    	cout<<i+1;
        if(b[i]==-1) cout<<"."<<a<<endl;
        else cout<<"."<<v[b[i]]<<endl;
    }

}

char* convert(int a)
{
    char* c;
    int k=0,i;
    int s=0;
    if(a!=0)
   {
	 while(a)
    {
        s=s*10+a%10;
        a=a/10;
        k++;
    }
   c=new char[k];
   for(i=0;i<k;i++)
   {c[i]='0'+s%10;
     s=s/10;

     }
     c[i]=NULL;

  return c;}
  else 
  {
  	c=new char[2];
  	c[0]='0';
  	c[1]=NULL;
  	return c;
  }
  
}
 
int main()
{
	system("Color 3F");
	Question *v[11];
	string A, Q,answ[10],tmp[3],anchor;
	char ID[20],*c;
	int i,*a,j,*k,*l,ans;
	ifstream file;
	ifstream answer;
	file.open("source.txt");
	if(!file.is_open())
	{
		cout<<"Error file!";
	}
	else
	{
	for(i=0;i<11;i++)
	{
	getline(file,Q);
	getline(file,A);
	c=convert(i+1);
	
	strcpy(ID,"Question");
	strcat(ID,c);
	string str(ID);
	v[i]=new Question(A,Q,str);
	}
    srand( time( NULL ) ); 
    a=rander1(11);
  	for(i=0;i<5;i++)
  	{
  	answer.open("answers.txt");
	
	    v[a[i]]->display();
	    do
			getline(answer,anchor);
	    while(v[a[i]]->name(anchor)!=1);
	    for(j=0;j<9;j++)
	    {
		getline(answer,answ[j]);
		}
		k=rander(9);
		l=rerand(k);
		afis_rasp(answ,v[a[i]]->get_ans(),l,5);
		cin>>ans;
		if(l[ans-1]==-1) cout<<"The answer is correct!"<<endl;
		else cout<<"You are wrong! The answer is incorrect!"<<endl;
		
	
    answer.close();
    }
 cout<<endl<<"Pres any key to exit!"<<endl;		
 } 
 cin.get();
    cin.get();
 return 0;
 system("pause");}
