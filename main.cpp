
#include<iostream>
#include <fstream>
#include<vector>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h> 
#include<sstream>
using namespace std;

class degree
{
	public :
	string degrees;
	double min_marks;
    

};
class capacity
{
	public:
	string center_id;
	string course_name;
	int ccapacity;
	int filled_capacity;
	capacity()
	{}
	capacity(string center_id,string course_name,int ccapacity,int filled_capacity)
	{
		this->center_id=center_id;
		this->course_name=course_name;
		this->ccapacity=ccapacity;
		this->filled_capacity=filled_capacity;

	}
		void display()
			{
				cout<<center_id <<setw(20)<<course_name <<setw(10)<<ccapacity <<setw(20)<<filled_capacity<< endl;
			}
};
class preferances
{
	public :
	 int formno;
	 int preferencesno;
  string course_name;
  string center_id;
  preferances()
  {

  }
  preferances(int fno,int pno,string cname,string cid)
  {
	  this->formno=fno;
	  this->preferencesno=pno;
	  this->course_name=cname;
	  this->center_id=cid;
  }
  void display()
  {
	  cout<< formno <<setw(10)<<preferencesno <<setw(10)<<course_name << setw(10)<<center_id << endl;
  }

};
class eligibility
{
	public :
	string course_name;
	string degree;
	float min_percentage;
	eligibility()
	{
		this->course_name="NA";
		this->degree="NA";
		this->min_percentage=0.0;
	}
	eligibility(string course_name,string degree,float min_percentage)
	{
		this->course_name=course_name;
		this->degree=degree;
		this->min_percentage=min_percentage;
	}
	void display()
	{
		cout<<course_name <<setw(20)<<degree <<setw(10)<<min_percentage << endl;
	}
};
class center
{
	public :
	string center_id;
	 string center_name;
	 string address;
	string coordinator;
	string password;
	vector<capacity> ccapacity;
	//map<int,int> courses;
	//int courses[10];
	 center()
	{
        this->center_id="NA";
		this->center_name="NA";
		this->address="NA";
		this->coordinator="NA";
		this->password="NA";
		
	}
	center(	string center_id,string center_name,string address,string coordinator,string password)
	{
         this->center_id=center_id;
		this->center_name=center_name;
		this->address=address;
		this->coordinator=coordinator;
		this->password=password;
	}

		void display_center()
		{
			cout<<endl;
			cout<<center_id<<setw(20)<<center_name<<setw(20)<<address<<setw(20)<<coordinator<<setw(20)<<endl;
		}
		void display_capacity()
		{
			cout<<endl;
			for(unsigned i=0;i<ccapacity.size();i++)
			{
			      ccapacity[i].display();
			}
		}
	/*	void display_center_course()
		{
             map<int,int>::iterator itr = courses.begin();
				while(itr != courses.end()) {
					cout << "\t-";
					sys.capacities[itr->second].display();
					itr++;
				}

		}*/
};
class course
{
	public :
	        int id;
	        string name;
	       float fees;
	       string ccat_section;
	       vector<eligibility> eligibilities;
		 //  map<int,int> centers;
	     //  int centers[10];
	 course()
	{
		this->id=0;
		this->name="NA";
		this->fees=0.0;
		this->ccat_section="NA";


	}
	 course(  int id, string name,float fees,string ccat_section)
	{
		this->id=id;
		this->name=name;
		this->fees=fees;
		this->ccat_section=ccat_section; 
	}

	void display_course()
   {
	   cout<<endl;
	   cout<<id<<setw(10)<<name<<setw(10)<<fees<<setw(10)<<ccat_section<<setw(10)<<endl;
   }
   void display_eligibilty()
   {
	   cout<<endl;
	   for(unsigned i=0;i<eligibilities.size();i++)
	   {
		   eligibilities[i].display();
	   }
   }
};


	/*	center* find_center(string centerid)
	{
       unsigned i;
		for(i=0; i<cens.size(); i++)
		 {
			if(cens[i].center_id.compare(centerid) == 0)
				return &cens[i];
		}
		return NULL

       
	}
	course* find_course(string cid)
	{
         unsigned i;
		for(i=0; i<cous.size(); i++) {
			if(cous[i].name.compare(cid)== 0)
				return &cous[i];
		}
		return NULL

	}
	void load_center_csv(vector<center> cens)
	{
		get_center(cens);
	}
	void load_courses_csv(vector<course> cous)
	{
		get_courses(cous);
	}
	void load_capacities_csv(vector<capacity> cen_capacity,vector<center> cens,vetcor<course> cous)
	{
		ifstream fp;
	string line;
	int i;
	fp.open("capacities.csv");
     //	fp.open("C:\\Users\\Rohan\\Desktop\\soniya\\data_file\\capacities.csv");
	if(!fp) {
		perror("failed to open capacity file");
		return;
	}
    else
	{
		i=0;
	while(getline(fp, line)) {
	stringstream str(line);
	string center_id;
	string course_name;
	int ccapacity;
	int filled_capacity;
		
		char ch;
		
		getline(str, center_id, ',');
		
		getline(str, course_name, ',');
		str >> ccapacity>> ch;
		str>>filled_capacity>>ch;
		
		capacity c(center_id, course_name, ccapacity, filled_capacity);
		cen_capacity.push_back(c);
		i++;
	
	
		center* e = find_center(c.center_id);
		e->courses[c.course_name] = cen_capacity.size()-1;
		// attach invitation to the meeting
		course *m = find_course(c.course_name);
		m->centers[c.center_id] = cen_capacity.size()-1;
	}
       fp.close();
	}
	
*/

class students
{
    public :
	        int id;
	        string name;
	        int rank_a;
	         int rank_b;
	         int rank_c;
            string degree;
	        float percentage;
			int allocated_preferences;
	        string course_name;
            string center_id;
	        float payment;
	        int reported;
	        string prn;
	       vector<preferances> preference;
		    int pref_count;
  students()
   {
     this->allocated_preferences=0;
	 this->course_name="NA";
	 this->center_id="NA";
	 this->payment=0;
	 this->reported=0;
	 this->prn="NA";
   }
   students( int id, string name, int rank_a,  int rank_b,  int rank_c,   string degree, float percentage,int allocated_preferences,string course_name,string center_id,  float payment, int reported,string prn)
   {
       this->id=id;
	   this->name=name;
	   this->rank_a=rank_a;
	   this->rank_b=rank_b;
	   this->rank_c=rank_c;
	   this->degree=degree;
	   this->percentage=percentage;
	   this->allocated_preferences=allocated_preferences;
	   this->course_name=course_name;
	   this->center_id=center_id;
	   this->payment=payment;
	   this->reported=reported;
	   this->prn=prn;
   }
   void display_students()
   {
	   cout<<id<<setw(20)<<name<<setw(20)<<rank_a<<setw(20)<<rank_b<<setw(20)<<rank_c<<setw(20)<<degree<<setw(20)<<
	   allocated_preferences<<setw(20)<<course_name<<setw(20)<<center_id<<setw(20)<<payment<<setw(20)<<reported<<setw(20)<<prn
	   <<endl;
   }
   void display_pre()
   {
	   for(unsigned i=0;i<preference.size();i++)
	   {
		   preference[i].display();
	   }
   }
	
};

/*class admissionSystem
{
    public:
	 vector<center> centers;
	 vector<course> courses;
	 vector<students> students;
	 vector<degree> degrees ;
	 vector<capacity> capacities;

};*/

int main_menu()
{
    int ch;
    printf("\n0.Exit \n 1.student \n 2.admin \n 3.co-orinator");
    printf("\n Enter your choice : ");
    scanf("%d",&ch);
    return ch;

}
int student_menu()
{
    int ch;
    printf("\n0.Exit \n 1.Register \n 2.Sign In ");
    printf("\n Enter your choice : ");
    scanf("%d",&ch);
    return ch;
}

void  Register()
{
     fstream fout; 
	 students s;
     fout.open("C:\\Users\\Rohan\\Desktop\\soniya\\data_file\\students.csv", ios::out | ios::app); 
	 cout<<"Enter students info :"<<endl;
	 cout<<"Form No :";
	 cin>>s.id;
	  cout<<"Name :";
	 cin>>s.name;
	  cout<<"Rank A Section :";
	 cin>>s.rank_a;
	  cout<<"Rank B Section :";
	 cin>>s.rank_b;
	  cout<<"Rank C Section:";
	 cin>>s.rank_c;
	  cout<<"degree:";
	 cin>>s.degree;
	  cout<<"degree marks :";
	 cin>>s.percentage;
	

	 fout << s.id << ", "
             << s.name << ", "
             << s.rank_a << ", "
             << s.rank_b << ", "
             << s.rank_c << ", "
             << s.degree << ","
             <<s.percentage <<"," 
			 <<s.allocated_preferences<<","
			 <<s.course_name<<","
			 <<s.center_id  <<","
			 <<s.payment<<","
			 <<s.reported<<","
			 <<s.prn<<","        
			 << "\n"; 
		 
}
void get_courses(vector<course> &c)
{
    
	 ifstream fp;
	string line;
	int i;
     	fp.open("C:\\Users\\Rohan\\Desktop\\soniya\\data_file\\courses.csv");
	if(!fp) {
		perror("failed to open courses file");
		return;
	}
    else
	{
		i=0;
	while(getline(fp, line)) {
		stringstream str(line);
		  int id;
	      string name;
	       float fees;
	       string ccat_section;
		
		char ch;
		// read id (& discard comma ch)
		str >> id >> ch;
		getline(str, name, ',');
		str>>fees>>ch;
		// read name
		getline(str, ccat_section, ',');
		
		
		// copy the object into array
		course b(id, name, fees, ccat_section);

		c.push_back(b);
		i++;
	}
	fp.close();
    cout<<"courses loaded"<<endl;
	}
	
}

course* find_course_eligibility(vector<course>& c,string  course_name)
{
    unsigned i;

	for(i=0;i<c.size();i++)
	{
		if(c[i].name.compare(course_name)==0)
		 return &c[i];
	}
	return NULL;
}
void get_course_eligibity(vector<course>& c)
{
	 ifstream fp;
	string line;
	int i;
     	fp.open("C:\\Users\\Rohan\\Desktop\\soniya\\data_file\\eligibilities.csv");
	if(!fp) {
		perror("failed to open eligibility file");
		return;
	}
    else
	{
		i=0;
	    while(getline(fp, line)) {
		stringstream str(line);
		string course_name;
	     string degree;
	    float min_percentage;
		char ch;
		
		getline(str, course_name, ',');
		// read subject
		getline(str, degree, ',');
		str >> min_percentage >> ch;
		// copy the object into array
		 eligibility b(course_name, degree,min_percentage);
        //pre.push_back(b);
		course * s=find_course_eligibility(c,b.course_name);
		
		s->eligibilities.push_back(b);
		
		i++;
	}
	fp.close();
    cout<<"eligibility loaded"<<endl;
	}
	
}

void list_courses()
{
    unsigned i;
	vector<course> c;
	get_courses(c);
	get_course_eligibity(c);
	
			for(i=0;i<c.size();i++)
			{
					
					c[i].display_course();
					c[i].display_eligibilty();
					
			}

}

center* find_center_capacity(vector<center>& c,string  center_id)
{
    unsigned i;

	for(i=0;i<c.size();i++)
	{
		if(c[i].center_id.compare(center_id)==0)
		 return &c[i];
	}
	return NULL;
}
void get_center(vector<center>& cen)
{
    ifstream fp;
	string line;
	int i;
     	fp.open("C:\\Users\\Rohan\\Desktop\\soniya\\data_file\\centers.csv");
	if(!fp) {
		perror("failed to open center file");
		return;
	}
    else
	{
		i=0;
	while(getline(fp, line)) {
		stringstream str(line);
		string center_id;
	 string center_name;
	 string address;
	string coordinator;
	string password;
		
		char ch;
		
		getline(str, center_id, ',');
		
		getline(str, center_name, ',');
		getline(str, address, ',');
		getline(str, coordinator, ',');
	    getline(str, password, ',');
		
		center c(center_id, center_name, address, coordinator,password);
		cen.push_back(c);
		i++;
	}
	fp.close();
    cout<<"center loaded"<<endl;
	}
}
void get_center_capacity(vector<center> &c)
{
	 ifstream fp;
	string line;
	int i;
	fp.open("capacities.csv");
    // 	fp.open("C:\\Users\\Rohan\\Desktop\\soniya\\data_file\\capacities.csv");
	if(!fp) {
		perror("failed to open capacity file");
		return;
	}
    else
	{
		i=0;
	while(getline(fp, line)) {
	stringstream str(line);
	string center_id;
	string course_name;
	int ccapacity;
	int filled_capacity;
		
		char ch;
		
		getline(str, center_id, ',');
		
		getline(str, course_name, ',');
		str >> ccapacity>> ch;
		str>>filled_capacity>>ch;
		
		capacity ca(center_id, course_name, ccapacity, filled_capacity);
		center * cc=find_center_capacity(c,center_id);
		cc->ccapacity.push_back(ca);
		i++;
	}
	fp.close();
    cout<<"capacity loaded"<<endl;
	}
	
}
void list_center()
{
      unsigned i;
	vector<center> c;
	get_center(c);
	get_center_capacity(c);
	
			for(i=0;i<c.size();i++)
			{
					
					c[i].display_center();
					c[i].display_capacity();
					
			}
}

void see_allocated_center(students  stud)
{
    cout<<"----------- Allocated center ----------"<<endl;
	cout<<endl;
	cout<<"allocated preferance :  "<<stud.allocated_preferences<<endl;
	cout<<"center id   :  "<<stud.center_id<<endl;
	cout<<"course name  : "<<stud.course_name<<endl;
}
void get_students(vector<students>& stud)
{
	 ifstream fp;
	string line;

	int i;
	fp.open("students.csv");
     //	fp.open("C:\\Users\\Rohan\\Desktop\\soniya\\data_file\\students.csv");
	if(!fp) {
		perror("failed to open students file");
		return;
	}
    else
	{
		i=0;
	while(getline(fp, line)) {
		stringstream str(line);
		int id;
	        string name;
	        int rank_a;
	         int rank_b;
	         int rank_c;
            string sdegree;
	        float spercentage;
			int allocated_preferences;
	        string course_name;
            string center_id;
	        float payment;
	        int reported;
	        string prn;
		
		char ch;
		//read id (& discard comma ch)
		str >> id >> ch;
		getline(str,name,',');
		str>>rank_a>>ch;
		str>>rank_b>>ch;
		str>>rank_c>>ch;
		getline(str,sdegree, ',');
		str>>spercentage>>ch;
		str>>allocated_preferences>>ch;
		getline(str, course_name, ',');
		getline(str,center_id,',');
		str>>payment>>ch;
		str>>reported>>ch;
		getline(str,prn,',');
		
		// copy the object into array
	
	   students b(id,name,rank_a,rank_b,rank_c,sdegree,spercentage,allocated_preferences,course_name,center_id,payment,reported,prn);
	   b.pref_count=0;
		stud.push_back(b);
		i++;
	}
	fp.close();
    cout<<"students  loaded"<<endl;
	}
	
}
void ssign_in()
{
	int formno,count=0,fno,choice,i;
	string sname;
	string n;
	
	cout<<"\nEnter form no :"<<endl;
	cin>>formno;
	cout<<"\nEnter name as password :"<<endl;
	cin>>sname;
     vector<students> stud; 
	 get_students(stud);
	
	
       for( i=0;i<stud.size();i++)
	   {
          
		if(stud[i].id==formno && stud[i].name.compare(sname)==0)
		
		{
              do
			  {
				  printf("\n");
				  printf("\n-------- Welcome to CDAC admission system------");
				  printf("\n 0.Logout \n 1.List Courses \n 2.List Centers \n 3.Give preferences \n 4.see allocated center/course");
				  printf("\nEnter your choice :");
				  scanf("%d",&choice);
				  
				  switch(choice)
				{
				case 0:
				    return;
				case 1:
				 cout<<"------------list  of  courses----------"<<endl;
				    list_courses();
				
					break;
				case 2:
					list_center();
					break;
				case 3:
				//	give_preferences();
					break;
				case 4:
					see_allocated_center(stud[i]);
					break;
				
				default:
					printf("\n Invalid choice....");
					break;
				}

                   
			  }while(choice!=0);
		}
	   }
        
}

void student()
{   
    int choice;

        while((choice=student_menu())!=0)
			{
				
				switch(choice)
				{
				case 0:
				    return;
				case 1:
				    Register();
					break;
				case 2:
					ssign_in();
					break;
				
				default:
					printf("\n Invalid choice....");
					break;
				}
			}
 }


int admin_menu()
{
      int ch;
    printf("\n0.Exit \n   1.List Course and eligibilty \n   2. List centers & capacities  \n 3. List students  \n 4. Update student ranks  \n 5.Allocate centers (Round 1) \n 6.Allocate centers (Round 2)  \n 7. List allocated students \n 8.List paid students \n 9. List reported (at center) students \n10.Generate PRN \n11. List admitted students (with PRN) for given center ");
    printf("\n Enter your choice : ");
    scanf("%d",&ch);
	printf("\n");
    return ch;
}
void get_prefernces(vector<preferances>& pre)
{
	 ifstream fp;
	string line;
	int i;
     	fp.open("C:\\Users\\Rohan\\Desktop\\soniya\\data_file\\preferences.csv");
	if(!fp) {
		perror("failed to open preferences file");
		return;
	}
    else
	{
		i=0;
	while(getline(fp, line)) {
		stringstream str(line);
		int formid,preno;
		string cname, cenid;
		
		char ch;
		// read id (& discard comma ch)
		str >> formid >> ch;
		str>>preno>>ch;
		// read name
		getline(str, cname, ',');
		// read subject
		getline(str, cenid, ',');
		
		// copy the object into array
		preferances b(formid, preno, cname, cenid);

		pre.push_back(b);
		i++;
	}
	fp.close();
    cout<<"preferences loaded"<<endl;
	}
	
}

void get_capacity(vector<capacity>& cen_capacity)
{
	 ifstream fp;
	string line;
	int i;
	fp.open("capacities.csv");
     //	fp.open("C:\\Users\\Rohan\\Desktop\\soniya\\data_file\\capacities.csv");
	if(!fp) {
		perror("failed to open capacity file");
		return;
	}
    else
	{
		i=0;
	while(getline(fp, line)) {
	stringstream str(line);
	string center_id;
	string course_name;
	int ccapacity;
	int filled_capacity;
		
		char ch;
		
		getline(str, center_id, ',');
		
		getline(str, course_name, ',');
		str >> ccapacity>> ch;
		str>>filled_capacity>>ch;
		
		capacity c(center_id, course_name, ccapacity, filled_capacity);
		cen_capacity.push_back(c);
		i++;
	}
	fp.close();
    cout<<"capacity loaded"<<endl;
	}
	
}

bool cmp_rankA(students a, students b)
{
    return a.rank_a < b.rank_a;
}
bool cmp_rankB(students a,students b)
{
	return a.rank_b < b.rank_b;
}

bool cmp_rankC(students a,students b)
{
	return a.rank_c < b.rank_c;

}
students* find_students_preferences(vector<students>& stud,int formid)
{
    unsigned i;
	for(i=0;i<stud.size();i++)
	{
		if(stud[i].id==formid)
		 return &stud[i];
	}
	return NULL;
}
void get_student_preferences(vector<students>& stud)
{
	 ifstream fp;
	string line;
	int i;
     	fp.open("C:\\Users\\Rohan\\Desktop\\soniya\\data_file\\preferences.csv");
	if(!fp) {
		perror("failed to open preferences file");
		return;
	}
    else
	{
		i=0;
	    while(getline(fp, line)) {
		stringstream str(line);
		int formid,preno;
		string cname, cenid;
		
		char ch;
		// read id (& discard comma ch)
		str >> formid >> ch;
		str>>preno>>ch;
		// read name
		getline(str, cname, ',');
		// read subject
		getline(str, cenid, ',');
		
		// copy the object into array
		preferances b(formid, preno, cname, cenid);
        //pre.push_back(b);
		students* s=find_students_preferences(stud,b.formno);
		
		s->preference.push_back(b);
		s->pref_count++;
		i++;
	}
	fp.close();
    cout<<"preferences loaded"<<endl;
	}
	
}

void save_students(vector<students>& stud) {
	ofstream fp;
	unsigned i;
	fp.open("students.csv");
	if(!fp) {
		perror("failed to open studentsfile");
		return;
	}

	for(i=0; i<stud.size(); i++) {
		fp << stud[i].id<< "," <<stud[i].name<< ","
				<< stud[i].rank_a<< "," << stud[i].rank_b << ","<<stud[i].rank_c<<","
				<< stud[i].degree << ","<<stud[i].percentage<<","<<stud[i].allocated_preferences<<","
				<<stud[i].course_name<<","<<stud[i].center_id<<","<<stud[i].payment<<","
				<<stud[i].reported<<","<<stud[i].prn<< endl;
	}

	fp.close();
	cout << "students saved." << endl;

}
void save_capacity(vector<capacity>& cap) {
	ofstream fp;
	unsigned i;
	fp.open("capacities.csv");
	if(!fp) {
		perror("failed to open capacity file");
		return;
	}

	for(i=0; i<cap.size(); i++) {
		fp << cap[i].center_id<< "," <<cap[i].course_name<< ","
				<< cap[i].ccapacity<< "," << cap[i].filled_capacity<< endl;
	}

	fp.close();
	cout << "capacity saved." << endl;

}

void allocate_center_round1()
{
	unsigned i,j,k,n;
     vector<preferances> pre;
	 vector<capacity> cen_capacity;
	 vector<students> stud;
	 vector<center> cen;
	// get_prefernces(pre);
     get_students(stud);
	
	 get_student_preferences(stud);
	 get_capacity(cen_capacity);
	 get_center(cen);
    sort(stud.begin(),stud.end(),cmp_rankA);
	// 		for(i=0;i<stud.size();i++)
		// 	{
		// 			if(stud[i].pref_count>0)
		// 			{
		// 			stud[i].display_students();
		// 			stud[i].display_pre();
		// 			}
		// 	}
    
	  sort(stud.begin(),stud.end(),cmp_rankA);
     for(i=0;i<stud.size();i++)
	 {
		 for(j=0;j<stud[i].preference.size();j++)
		 {
			 if(stud[i].pref_count>0)
			 {
					if(stud[i].allocated_preferences==0)
					{
								if(stud[i].preference[j].course_name.compare("PG-DGI")==0)
								{
									//cout<<stud[i].preference[j].preferencesno<<endl;
									//cout<<stud[i].name<<endl;
									  if(stud[i].preference[j].preferencesno==1)
									  {
										string scenter=stud[i].preference[j].center_id;
										//cout<<scenter<<endl;
											for(k=0;k<cen_capacity.size();k++)
											{   
												if(cen_capacity[k].course_name.compare("PG-DGI")==0)
												{
													if(scenter.compare(cen_capacity[k].center_id)==0)
													{
																if(cen_capacity[k].filled_capacity<cen_capacity[k].ccapacity)
																{
														
																	cen_capacity[k].filled_capacity++;
																	stud[i].allocated_preferences=stud[i].preference[j].preferencesno;
																	stud[i].center_id=cen_capacity[k].center_id;
																	stud[i].course_name=cen_capacity[k].course_name;
																	
																}
													}
												}
											}
									  }
								}
						
					}
			 }
		 }
	 }

	 

    sort(stud.begin(),stud.end(),cmp_rankB);
	  for(i=0;i<stud.size();i++)
	 {
		 for(j=0;j<stud[i].preference.size();j++)
		 {
			 if(stud[i].pref_count>0)
			 {
					if(stud[i].allocated_preferences==0)
					{
						   if(stud[i].preference[j].preferencesno==1)
						   {
								if(stud[i].preference[j].course_name.compare("PG-DAC")==0 || stud[i].preference[j].course_name.compare("PG-DMC")==0 || stud[i].preference[j].course_name.compare("PG-DBDA")==0)
								{
									//cout<<"PG_DAC,PG-DMC,PG-DBDA students.."<<endl;
										string scenter=stud[i].preference[j].center_id;
										//cout<<scenter<<endl;
											for(k=0;k<cen_capacity.size();k++)
											{   
												if(cen_capacity[k].course_name.compare(stud[i].preference[j].course_name)==0 )
												{
													if(scenter.compare(cen_capacity[k].center_id)==0)
													{
																if(cen_capacity[k].filled_capacity<cen_capacity[k].ccapacity)
																{
																	
																	cen_capacity[k].filled_capacity++;
																	stud[i].allocated_preferences=stud[i].preference[j].preferencesno;
																	stud[i].center_id=cen_capacity[k].center_id;
																	stud[i].course_name=cen_capacity[k].course_name;
																	
																}
													}
												}
											}
								}
						   }
					}
			 }
		 }
	 }
     
     sort(stud.begin(),stud.end(),cmp_rankC);
    for(i=0;i<stud.size();i++)
	 {
		 for(j=0;j<stud[i].preference.size();j++)
		 {
			 if(stud[i].pref_count>0)
			 {
					if(stud[i].allocated_preferences==0)
					{
						if(stud[i].preference[j].preferencesno==1)
						{
								if(stud[i].preference[j].course_name.compare("PG-DESD")==0)
								{
									//cout<<"PG_DESD students.."<<endl;
										string scenter=stud[i].preference[j].center_id;
										//cout<<scenter<<endl;
											for(k=0;k<cen_capacity.size();k++)
											{   
												if(cen_capacity[k].course_name.compare("PG-DESD")==0)
												{
													if(scenter.compare(cen_capacity[k].center_id)==0)
													{
																if(cen_capacity[k].filled_capacity<cen_capacity[k].ccapacity)
																{
																	
																	cen_capacity[k].filled_capacity++;
																	stud[i].allocated_preferences=stud[i].preference[j].preferencesno;
																	stud[i].center_id=cen_capacity[k].center_id;
																	stud[i].course_name=cen_capacity[k].course_name;
																	
																}
													}
												}
											}
								}
						}
					}
			 }
		 }
	 }
	 




	 save_students(stud);
	 save_capacity(cen_capacity);
	   sort(stud.begin(),stud.end(),cmp_rankA);
			for(i=0;i<stud.size();i++)
			{
					 if(stud[i].pref_count>0)
					 {
						stud[i].display_students();
						stud[i].display_pre();
					 }
					  
			}
	
}

void list_allocated_students()
{
	unsigned i;
	vector<students> stud;
	get_students(stud);
		for(i=0;i<stud.size();i++)
			{
					 if(stud[i].allocated_preferences!=0)
					 {
						stud[i].display_students();
						stud[i].display_pre();
					 }
					  
			}

}
void list_students()
{
	unsigned i;
	vector<students> stud;
	get_students(stud);
	cout<<endl;
	cout<<"------------------list of students--------------------"<<endl;
	for(i=0;i<stud.size();i++)
			{
					
						stud[i].display_students();
						stud[i].display_pre();
					 
					  
			}

}
void  list_paid_students()
{
	unsigned i;
	vector<students> stud;
	get_students(stud);
	cout<<endl;
	cout<<"------------------list of paid students--------------------"<<endl;
	cout<<endl;

	for(i=0;i<stud.size();i++)
			{
					    if(stud[i].payment==11800 || stud[i].payment==94400)
						{
						 stud[i].display_students();
						}
						
		   }
}
void list_reported_students()
{
	unsigned i;
	vector<students> stud;
	get_students(stud);
	cout<<endl;
	cout<<"------------------list of reported students--------------------"<<endl;
	for(i=0;i<stud.size();i++)
			{
					    if(stud[i].reported!=0)
						{
						  stud[i].display_students();
						}
						
		   }
}
void admin_sign_in()
{
	
	string uname;
	string password;
	int choice;
	cout<<"\nEnter username:"<<endl;
	cin>>uname;
	cout<<"\nEnter  password :"<<endl;
	cin>>password;
	if(uname.compare("admin")==0 && password.compare("admin")==0)
		
		{
               while((choice=admin_menu())!=0)
			{
				
						switch(choice)
						{
						case 0:
							return;
						
						case 1:
							list_courses();
							break;
						case 2:
							list_center();
							break;
						case 3:
							list_students();
							break;
						case 4:
							//update_students_rank();
							break;
						case 5 :
							allocate_center_round1();
							break;
						case 6:
						//  allocate_center_round2();
							break;
						case 7:
						list_allocated_students();
							break;
						case 8:
							list_paid_students();
							break;
						case 9:
						list_reported_students();
							break;
						case 10:
						//  generate_prn();
							break;
						case 11:
						//  list_admitted_list();
							break;
						
						default:
							printf("\n Invalid choice....");
							break;
				}
			}
		}
}
        

void admin()
{
    admin_sign_in();
}

/*void list_center_courses(vector<center> &c)
{
	
	vector<course> cous;
	vector<capacity> cap; 
	load_center_csv(c);
	load_courses_csv(cous);
	load_capacities_csv(cap,c,cous);
	
}*/
int coordinator_menu()
{
    int ch;
	
    printf("\n0.Exit \n 1.List courses (of that center) \n 2. List students (allocated to that center) \n 3.update reported status \n 4. List admitted students (with PRN) ");
    printf("\n Enter your choice : ");
    scanf("%d",&ch);
	printf("\n");
    return ch;
}
void coordinator_signin()
{

  vector<center> c;
  vector<course> cous;
  vector<capacity> cap;
   get_center(c);
   string centerid,password;
	unsigned i;
   int choice;
   cout<<"enter Center Id :  "<<endl;
   cin>>centerid;
   cout<<"enter password  :"<<endl;
   cin>>password;
     for( i=0;i<c.size();i++)
	   {
          
		    cout<<"for.."<<endl;
			if(c[i].center_id.compare(centerid)==0 && c[i].password.compare(password)==0)
		
				{
                           cout<<"if..."<<endl;
						while((choice=coordinator_menu())!=0)
							{
								
								switch(choice)
								{
								case 0:
									return;
								case 1:
										//list_center_courses(c);
										//c.display_center_course();
									break;
								case 2:
										//list_center_students();
									break;
								case 3:
								//	update_reported_status();
									break;
								case 4:
										//list_admitted_students();
									break;
								
								default:
									printf("\n Invalid choice....");
									break;
								}
							}
					}
	   }
    

}
void coordinator()
{
    coordinator_signin();
}
int main()
{
    int choice;
   
    while((choice=main_menu())!=0)
    {
        switch(choice)
		{
		case 0:
			printf("\n Logout.....");
			exit(0);
			break;
		case 1:
			student();
			break;
		case 2:
			admin();
			break;
		case 3:
			coordinator();
			break;
		default:
			printf("\n Invalid choice....");
			break;
		}
         

    }
    return 0;

}