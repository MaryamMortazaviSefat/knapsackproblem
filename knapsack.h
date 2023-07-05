#ifndef KNAPSACK_H
#define KNAPSACK_H
#include "object.h"
#include "iostream"
#include <vector>
using namespace std;
class Knapsack
{
    friend istream & operator>>(istream & in,Knapsack &e);
    friend ostream & operator<<(ostream & out,Knapsack &e);

public:
    Knapsack();
    Knapsack(int _objects_count,int _max_weight);
    void set_objects_ptr();
    void set_binary_of_each_states();

    int compute_max_value_dynamic_programming();
    void compute_max_value_backtrack();


    string get_backtrack_proccess();
    int get_objecs_count();
    int get_dynamic_steps();

    //utility functions
protected:
    bool is_valid_backtrack(int i);
    int s(int i,int j);  //dynamic programming function
private:
    int objects_count;
    Object* objects_ptr;
    vector<vector<char>> binary_of_each_states;  //use for backtrack
    int max_weight;
    int max_value;   //result at end
    int sum_of_weights;   //in the proccess
    int dynamic_step;
    string backtrack_proccess;
};

#endif // KNAPSACK_H
