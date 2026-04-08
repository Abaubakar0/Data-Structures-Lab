#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	
	float e=200,l=250,c=300;
	
	float *ptre=&e;
	float *ptrl=&l;
	float *ptrc=&c;
	int q1,q2,q3;
	
	
	
	cout<<"Enter Espresso Quantity : "; cin>>q1;
	cout<<"\nEnter Latte Quantity : "; cin>>q2;
	cout<<"\nEnter Cappuccino Quantity : "; cin>>q3;
	
	
	float espresso= *ptre * q1;
	float latte= *ptrl * q2;
	float cappuccino= *ptrc * q3;
	
	cout<<"\n------------Cafe Bill---------------"<<endl;
	cout<<"Espresso (" <<q1 <<" x "<<*ptre <<") = "<<espresso;
	cout<<"\nLatte ("<<q2 <<" x "<<*ptrl<<") = "<<latte;
	cout<<"\nCappuccino ("<<q3 <<" x "<< *ptrc<<") = " <<cappuccino;
	cout<<"\n-----------------------------------------------"<<endl;
	cout<<"Total Bill : "<<espresso+latte+cappuccino;
	return 0;
}