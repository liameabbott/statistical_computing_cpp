//Homework 1, Problem 4
//Compute Predictive Probabilities
//Liam Abbott, leabbott

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


int main(int argc, char * argv[])
{
    int n_predictors = argc - 1;
    double beta_zero_terms[5];
    double beta_one_terms[5];
    double pred_vals[5];
    double pred_vals_sum = 0.0;

    for (int i=0; i<=4; i++)
    {
        beta_zero_terms[i] = pow(2, -(i+1));

        beta_one_terms[i] = 0.0;
        for (int j=0; j<=(n_predictors-1); j++)
        {
            if (j >= 9)
            {
                continue;
            }
            else
            {
                beta_one_terms[i] = beta_one_terms[i] + (pow(2, abs((i+1)-(j+1))) * atof(argv[j+1]));
            }
        }

        pred_vals[i] = exp(beta_zero_terms[i] + beta_one_terms[i]);
        pred_vals_sum = pred_vals_sum + pred_vals[i];
    }

    cout.precision(8);
    for (int i=0; i<=4; i++)
    {
        cout << pred_vals[i]/pred_vals_sum << '\n';
    }

    return 0;
}
