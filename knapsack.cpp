#include "knapsack.h"


//.................................cunsrtuctors......................

Knapsack::Knapsack(){
    objects_count=0;
    max_weight=0;
    max_value=0;
    sum_of_weights=0;
    dynamic_step=0;
    backtrack_proccess="";
    set_objects_ptr();
}

Knapsack::Knapsack(int _objects_count,int _max_weight)
{
    objects_count=_objects_count;
    max_weight=_max_weight;
    max_value=0;
    sum_of_weights=0;
    dynamic_step=0;

    if(objects_count<0)
    {
        objects_count=0;
    }
    if(max_weight<0)
    {
        max_weight=0;
    }

    backtrack_proccess="";
    set_objects_ptr();
    set_binary_of_each_states();
}

//...........................functions........................

int Knapsack::compute_max_value_dynamic_programming()
{
    dynamic_step=0;

    return s(objects_count-1,max_weight);

    //the other way
    /*
    int sum_of_value=0;
    int last_max_value=0;
    for(int j=0;j<=max_weight;j++)
    {
        cout<<"j:  "<<j<<"\n";
        sum_of_weights=0;
        last_max_value=sum_of_value;
        sum_of_value=0;
        for(int i=0;i<objects_count;i++)
        {
            sum_of_weights+=objects_ptr[i].get_weight();
            sum_of_value+=objects_ptr[i].get_value();
            if(sum_of_weights>j)
            {
                sum_of_weights-=objects_ptr[i].get_weight();
                sum_of_value-=objects_ptr[i].get_value();
            }
            cout<<"\n sum of weight is: "<<sum_of_weights<<'\n';

        }

        if(max_value<sum_of_value){
            max_value=sum_of_value;
        }
        if(max_value<last_max_value)
        {
            max_value=last_max_value;
        }

            //push changes
            string temp="weight: ";
            for(int k=0;k<temp.size();k++)
            {
                dynamic_programming_proccess.push_back(temp[k]);
            }
            temp=to_string(j);
            for(int k=0;k<temp.size();k++)
            {
                dynamic_programming_proccess.push_back(temp[k]);
            }
            temp="   max value changes to : ";
            for(int k=0;k<temp.size();k++)
            {
                dynamic_programming_proccess.push_back(temp[k]);
            }
            temp=to_string(max_value);
            for(int k=0;k<temp.size();k++)
            {
                dynamic_programming_proccess.push_back(temp[k]);
            }
            dynamic_programming_proccess.push_back('\n');
            cout<<dynamic_programming_proccess<<"\n";




    }
*/
}

int Knapsack::s(int i, int j){

    //stop
    if(i==-1)
    {
        dynamic_step++;
        return 0;
    }

    int s1=s(i-1,j);

    if(objects_ptr[i].get_weight()<=j)
    {
        int s2=s(i-1,j-objects_ptr[i].get_weight());
        if(s1>(s2+objects_ptr[i].get_value()))
        {
            return s1;
        }
        else
        {
            return s2+objects_ptr[i].get_value();
        }
    }
    else
    {
        return s1;
    }

}

void Knapsack::compute_max_value_backtrack()
{
    max_value=0;
    int count=0;
    string temp;
    backtrack_proccess.resize(0);

    for(int i=0;i<binary_of_each_states.size();i++)
    {
        bool flag=true;
        sum_of_weights=0;
        int test_value=0;

        for(int j=0;j<objects_count && flag;j++)
        {
            if(binary_of_each_states[i][j]=='1')
            {
                if(is_valid_backtrack(objects_count-j-1))
                {
                    test_value+=objects_ptr[objects_count-j-1].get_value();
                }
                else if(!is_valid_backtrack(objects_count-j-1))
                {
                    flag=false;
                }
            }
        }
        count++;
        if(max_value<test_value && flag)
        {
            max_value=test_value;

            //cout<<"max_value:  "<<max_value<<"   with "<<state<<"\n";
            temp="\n ---> max value:  ";
            for(int n=0;n<temp.size();n++)
            {
              backtrack_proccess.push_back(temp[n]);
            }
            temp=to_string(max_value);
            for(int n=0;n<temp.size();n++)
            {
              backtrack_proccess.push_back(temp[n]);
            }
            temp="  with: ";
            for(int n=0;n<temp.size();n++)
            {
              backtrack_proccess.push_back(temp[n]);
            }

            for(int k=objects_count-1;k>=0;k--)
            {
                backtrack_proccess.push_back(binary_of_each_states[i][k]);
            }

        }
        if(!flag)
        {
            //cout<<"\n deadlock   left to wright<-- : "<<temp<<"\n";
            temp="\ndeadlock   :";
            for(int n=0;n<temp.size();n++)
            {
              backtrack_proccess.push_back(temp[n]);
            }
            for(int n=objects_count-1;n>=0;n--)
            {
              backtrack_proccess.push_back(binary_of_each_states[i][n]);
            }
            backtrack_proccess.push_back(' ');

            //jump
             i++;
        }
    }

    //add the number of backtrack steps to backtrack proccess
    temp="\n\nthe number of backtrack steps: ";
    for(int n=0;n<temp.size();n++)
    {
      backtrack_proccess.push_back(temp[n]);
    }
    temp=to_string(count);
    for(int n=0;n<temp.size();n++)
    {
      backtrack_proccess.push_back(temp[n]);
    }
    backtrack_proccess.push_back('\n');
    //end result
    temp="max_value:  ";
    for(int n=0;n<temp.size();n++)
    {
      backtrack_proccess.push_back(temp[n]);
    }
    temp=to_string(max_value);
    for(int n=0;n<temp.size();n++)
    {
      backtrack_proccess.push_back(temp[n]);
    }

}

bool Knapsack::is_valid_backtrack(int i){
    sum_of_weights+=objects_ptr[i].get_weight();
    if(sum_of_weights<=max_weight)
    {

        return true;
    }

    sum_of_weights-=objects_ptr[i].get_weight();
    return false;
}

//..............................operators............................

void Knapsack::set_objects_ptr(){
    objects_ptr= new Object[objects_count];
}

void Knapsack::set_binary_of_each_states(){
    int t=1;
    for(int k=0;k<objects_count;k++){
    t= (t*2);
    }

    if(objects_count==0)
    {

    }

    else if(objects_count>0){
        binary_of_each_states.resize(t);
        int i=2;
        binary_of_each_states[0].push_back('1');
        binary_of_each_states[1].push_back('0');
        while(i< (t))
        {
            i=i*2;
            for(int j=i/2;j<i;j++)
            {
                 binary_of_each_states[j]=binary_of_each_states[j-(i/2)];
            }

            for(int j=0;j<i/2;j++)
            {
                 binary_of_each_states[j].push_back('1');
            }
            for(int j=i/2;j<i;j++)
            {
                 binary_of_each_states[j].push_back('0');
            }

        }
    }
}

int Knapsack::get_objecs_count()
{
    return objects_count;
}

string Knapsack::get_backtrack_proccess()
{
    return backtrack_proccess;
}

int Knapsack::get_dynamic_steps()
{
    return dynamic_step;
}

istream & operator>>(istream & in,Knapsack &e){
    in>>e.objects_count>>e.max_weight;
    e.set_objects_ptr();
    e.set_binary_of_each_states();
    for(int i=0;i<e.get_objecs_count();i++)
    {
        in>>e.objects_ptr[i];
    }
    return in;
}

ostream & operator<<(ostream & out,Knapsack &e){
    out<<"the object count is: ";
    out<<e.objects_count;
    out<<"\nthe max weight is: ";
    out<<e.max_weight;

    out<<"\nthe objects are: (weight/value)\n";
    for(int i=0;i<e.get_objecs_count();i++)
    {
        out<<e.objects_ptr[i]<<"\n";
    }

    out<<"\nthe binary of each states are:\n";
    for(int i=0;i<(e.binary_of_each_states.size());i++)
    {
        for(int j=e.get_objecs_count()-1;j>=0;j--){
        out<<e.binary_of_each_states[i][j];
        }
        cout<<"/";
    }
    cout<<"\n";
    return out;


    return out;
}
