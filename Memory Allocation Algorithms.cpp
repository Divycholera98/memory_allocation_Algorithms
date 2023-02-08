#include <bits/stdc++.h>

using namespace std;


void first_fit(vector<int> holes,vector<int> process)
{
	vector < vector <int> > v(holes.size());
	for(int i=0;i<process.size();i++)
	{
	  for(int j=0;j<holes.size();j++)
		{
		    if(holes[j] >= process[i])
		    {
		    	holes[j]-=process[i];
		    	v[j].push_back(i+1);
		    	process[i]=0;
				break;
		    	
			}
		}	
	}
	cout<<"---------------------------------------------------------\n";
	cout<<endl<<endl<<"\t";
	for(int i=0;i<holes.size();i++)
		{
		    for(int j=0;j<v[i].size();j++)
		    {
		    	cout<<"P"<<v[i][j]<<" ";
			}
			if(holes[i]!=0)
			{
				cout<<holes[i]<<" || ";
			}
			else
			{
				cout<<" ||  ";
			}
		}
	cout<<endl<<endl;
	cout<<"---------------------------------------------------------\n";
	cout<<"\t memory left is "<<accumulate(holes.begin(),holes.end(),0)<<endl;
	cout<<"\t maximum size of hole is "<<*max_element(holes.begin(),holes.end())<<endl;
	cout<<"\t minimum size of hole is "<<*min_element(holes.begin(),holes.end())<<endl;
	cout<<"---------------------------------------------------------\n";
   	cout<<"\t number of processes not allocated "<<endl;
	for(int i=0;i<process.size();i++)
	{
	   if(process[i])
	   {
	     cout<<"P"<<i+1<<" ";   	
	   }	
	}	
	cout<<"\n---------------------------------------------------------\n";
}

void worst_fit(vector<int> holes,vector<int> process)
{
	vector < vector <int> > v(holes.size());
	for(int i=0;i<process.size();i++)
	{
		    if(*max_element(holes.begin(),holes.end())>= process[i])
		    {
		    	int j=max_element(holes.begin(),holes.end())-holes.begin();
		    	holes[j]-=process[i];
		    	v[j].push_back(i+1);
		    	process[i]=0;
			}
	}
	cout<<"---------------------------------------------------------\n";
	cout<<endl<<endl<<"\t";
	for(int i=0;i<holes.size();i++)
		{
		    for(int j=0;j<v[i].size();j++)
		    {
		    	cout<<"P"<<v[i][j]<<" ";
			}
			if(holes[i]!=0)
			{
				cout<<holes[i]<<" || ";
			}
			else
			{
				cout<<" ||  ";
			}
		}
	cout<<endl<<endl;
	cout<<"---------------------------------------------------------\n";
	cout<<"\t memory left is "<<accumulate(holes.begin(),holes.end(),0)<<endl;
	cout<<"\t maximum size of hole is "<<*max_element(holes.begin(),holes.end())<<endl;
	cout<<"\t minimum size of hole is "<<*min_element(holes.begin(),holes.end())<<endl;
	cout<<"---------------------------------------------------------\n";
	cout<<"\t number of processes not allocated "<<endl;
	for(int i=0;i<process.size();i++)
	{
	   if(process[i])
	   {
	     cout<<"P"<<i+1<<" ";   	
	   }	
	}	
	cout<<"\n---------------------------------------------------------\n";
}


void best_fit(vector<int> holes,vector<int> process)
{
	vector < vector <int> > v(holes.size());
	for(int i=0;i<process.size();i++)
	{
		int j=-1,diff=INT_MAX;
		
		for(int k=0;k<holes.size();k++)
		{
			if(diff>holes[k]-process[i] && holes[k]-process[i]>=0)
			{
				diff=holes[k]-process[i];
				j=k;
			}
		}
		
	            if(j!=-1)
				{
				 holes[j]-=process[i];
		    	 v[j].push_back(i+1);
		    	 process[i]=0;
				}	
		    	
	}
	cout<<"\n---------------------------------------------------------\n";
	cout<<endl<<endl<<"\t";
	for(int i=0;i<holes.size();i++)
		{
		    for(int j=0;j<v[i].size();j++)
		    {
		    	cout<<"P"<<v[i][j]<<" ";
			}
			if(holes[i]!=0)
			{
				cout<<holes[i]<<" || ";
			}
			else
			{
				cout<<" ||  ";
			}
		}
	cout<<endl<<endl;
	cout<<"---------------------------------------------------------\n";
	cout<<"\t memory left is "<<accumulate(holes.begin(),holes.end(),0)<<endl;
	cout<<"\t maximum size of hole is "<<*max_element(holes.begin(),holes.end())<<endl;
	cout<<"\t minimum size of hole is "<<*min_element(holes.begin(),holes.end())<<endl;
	cout<<"---------------------------------------------------------\n";
	cout<<"\t number of processes not allocated "<<endl;
	for(int i=0;i<process.size();i++)
	{
	   if(process[i])
	   {
	     cout<<"P"<<i+1<<" ";   	
	   }	
	}	
	cout<<"\n---------------------------------------------------------\n";	
}

void next_fit(vector<int> holes,vector<int> process)
{
	vector < vector <int> > v(holes.size());
	int x=-1;
	for(int i=0;i<process.size();i++)
	{
		 int j=x+1;
		 while(j!=x)
		 {
		 	if(holes[j]>=process[i])
		 	{
		 	    holes[j]-=process[i];
				 x=j-1;	
				 v[j].push_back(i+1);
				 process[i]=0;
		 		break;
			}
			j=(j+1)%holes.size(); 
		 }
	}
	cout<<"\n---------------------------------------------------------\n";
	cout<<endl<<endl<<"\t";
	for(int i=0;i<holes.size();i++)
		{
		    for(int j=0;j<v[i].size();j++)
		    {
		    	cout<<"P"<<v[i][j]<<" ";
			}
			if(holes[i]!=0)
			{
				cout<<holes[i]<<" || ";
			}
			else
			{
				cout<<" ||  ";
			}
		}
	cout<<endl<<endl;
	cout<<"---------------------------------------------------------\n";
	cout<<"\t memory left is "<<accumulate(holes.begin(),holes.end(),0)<<endl;
	cout<<"\t maximum size of hole is "<<*max_element(holes.begin(),holes.end())<<endl;
	cout<<"\t minimum size of hole is "<<*min_element(holes.begin(),holes.end())<<endl;
	cout<<"---------------------------------------------------------\n";
	cout<<"\t number of processes not allocated "<<endl;
	for(int i=0;i<process.size();i++)
	{
	   if(process[i])
	   {
	     cout<<"P"<<i+1<<" ";   	
	   }	
	}	
	cout<<"\n---------------------------------------------------------\n";
}



int main()
{

	int n,m;
	cout<<"---------------------------------------------------------\n";
    cout<<"\t Enter Number of Holes ";
    cin>>n;
    vector<int> holes(n);
    cout<<"\t Enter size of Holes "<<endl;
    for(int i=0;i<n;i++)cin>>holes[i];
    cout<<"---------------------------------------------------------\n";
	cout<<"\t Enter Number of processes ";
    cin>>m;
    vector<int> process(m);
    cout<<"\t Enter size of Processes "<<endl;
    for(int i=0;i<m;i++)cin>>process[i];
    cout<<"---------------------------------------------------------\n";
    cout<<"\t\t Best fit \n";
    best_fit(holes,process);
    cout<<"---------------------------------------------------------\n";
    cout<<"\t\t Worst fit \n";
    worst_fit(holes,process);
    cout<<"---------------------------------------------------------\n";
    cout<<"\t\t First fit \n";
    first_fit(holes,process);
    cout<<"---------------------------------------------------------\n";
    cout<<"\t\t Next fit \n";
    next_fit(holes,process);
}
