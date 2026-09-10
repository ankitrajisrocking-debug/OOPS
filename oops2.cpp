#include <bits/stdc++.h>
using namespace std;
class Books{
	string title, author, publisher;
	float price;
	int stock;
	
	
	void update_price(float x){
		price = x;
	}
	
	public:
	
	static int success, fail;

	// constructor	
	Books( string t, string a, string pb, float pr, int s): title(t), author(a), publisher(pb), price(pr), stock(s) {}
		
	// destructor
	~Books() {}
	
	void search( string t, string a, int copies ){
		if( title != t || author != a ){
			cout<< "book not found."<< endl;
			fail++;
		}
		else if ( copies > stock ) {
			cout<< "this book is not in stock."<< endl;
			fail++;
		}
		else{
			cout<< "tiltle: " << title << "  author: " << author << "  price per unit: " << price<< endl;
			cout<< "total cost: " << price * copies << endl;
			stock-= copies;
			success++;
			cout<< endl;
		}
	}
	
	void update( float pr){
		update_price( pr );
	}
	

	
	
	void showTransactions(){
		cout<< "successfull: " << success << endl;
		cout<< "unsuccessfull: " << fail<< endl;
	}

		

	
};


int Books :: success = 0;
int Books :: fail = 0;



int main(){

	Books b[2] = { Books( "psychology", "ankit", "xyz", 500, 100), Books( "chemistry", "sachin", "xyz", 700, 200) };


	b[0].update(1000);
	
	string t, a; int copies;
	cout<< "enter title: " ;
	getline( cin, t);
	cout<< "enter author: ";
	getline( cin, a);
	cout<< "enter number of copies: ";
	cin>> copies;
	cout << endl;
	
	
	
	
	for ( int i = 0; i< 2; i++ ){
		b[i].search(t, a, copies);
		b[i].showTransactions();
		cout<< endl;
		
	}
	
}

