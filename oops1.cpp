#include <bits/stdc++.h>

using namespace std;

class  student{
	private :
			string first_name, last_name, SID, course_grade;
			int course_score ;
			float cgpa ;
		
	public:
		void input(){
			cout<< "enter first name: "<< endl;
			cin>> first_name;
			cout<< "enter last name: " << endl;
			cin>> last_name;
			cout<< "enter SID: " << endl;
			cin>> SID;
			cout<< "enter the course score of the student: "<< endl;
			cin>> course_score;
			cout << "enter cgpa of the student: "<< endl;
			cin>> cgpa ;
		}
		void update(){
		int x;
		cout<< "if u want to update cg, please enter below, else enter 0 for other changes"<< endl;
		cin>> x;
		if ( x !=  0) cgpa = x;
		else cout<< "if u want to update course score, please enter below, else enter 0 for other changes"<< endl;
			cin>> x;
			if(x!= 0) course_score = x;
	
	        }
		
		
		
		string calc_grade(){
			if( course_score >= 90) return "A";
			else if ( course_score >= 80) return "B";
			else if ( course_score >= 70) return "C";
			else if ( course_score >= 60) return "D";
			else if ( course_score >= 50) return "E";
			else return "F";
		}
		void d_eligible(){
			if( (calc_grade() == "C" || calc_grade() == "B" || calc_grade() == "A") && cgpa >= 7.5 )	
			    cout<< "The student is eligible." << endl;
			else  cout<< SID<< " Not Eligible";
	       } 
				
};
		
		
int main() {
		int n;
		cout<< "entrer number of students: ";
		cin>> n;

		*student st = new student[n];
		for(int i =0; i< n; i++) st[i].input();
		for(int i =0; i< n; i++) st[i].d_eligible();
		
		

	
}
		
			
		
		
			
