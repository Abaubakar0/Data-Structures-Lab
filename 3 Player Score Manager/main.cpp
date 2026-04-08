#include <iostream>
using namespace std;
int main() {

int n;
    cout << "How many Player are Participating : ";
    cin >> n;

    int *score = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Player " << i+1 <<" score :" ;
        cin >> score[i];
    }

    for (int i = 0; i < n; i++) {
        cout<<"player " <<i+1 <<" score :"<< score[i] <<endl;
    }

delete [] score;
    return 0;
}