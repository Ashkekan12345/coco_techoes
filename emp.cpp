
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;


double random_comm() {
    return (rand() % 4001) + 1000; 
}

int main() {
    
    srand(static_cast<unsigned int>(time(0)));
    const int emp = 100;
    const int months = 12;

   
    string emp_names[emp];
    double comm_data[emp][months];

    for (int i = 0; i < emp; ++i) {
        emp_names[i] = "Employee" +to_string(i + 1);

        for (int j = 0; j < months; ++j) {
            comm_data[i][j] = random_comm();
        }
    }

   
  pair<string, double> average_commissions[emp];

    for (int i = 0; i < emp; ++i) {
        double sum = 0.0;
        for (int j = 0; j < months; ++j) {
            sum += comm_data[i][j];
        }

        double average_commission = sum / months;
        average_commissions[i] = make_pair(emp_names[i], average_commission);
    }

    
    
  cout << "Top 5 Employees with the Highest Average Commission:" <<endl;
    for (int i = 0; i < min(5, emp); ++i) {
       cout << i + 1 << ". " << average_commissions[i].first << ": $"
                  << average_commissions[i].second << endl;
    }

    return 0;
}


