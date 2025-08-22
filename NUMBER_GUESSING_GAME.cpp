#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

int main() {
    // random number generator
    srand(time(0)); 
    int random_number = rand() % 500 + 1; // Random number between 1 and 500
    int guess, trials= 0;
    cout << "random number is in between 1 and 500, guess\n";

  while (1) {
        cout << "Enter guess: ";
        cin >> guess;
        trials++;
        if (guess <random_number) 
            cout << "Too low\n";
        else if (guess >random_number)  cout << "Too high\n";
         else {
            cout << " Your guess the correct number in " 
                 << trials << "-trails\n";
            break;
        }
    }
    return 0;
}