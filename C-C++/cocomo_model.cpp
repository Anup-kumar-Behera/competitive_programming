#include<bits/stdc++.h>
using namespace std;

double cd[15][5]={{0.75,0.88,1,1.15,1.40}
            ,{1,0.94,1,1.08,1.16}
            ,{0.70,0.85,1,1.15,1.3}
            ,{1,1,1,1.11,1.30}
            ,{1,1,1,1.06,1.21}
            ,{1,0.87,1,1.15,1.3}
            ,{1,0.87,1,1.07,1.15}
            ,{1.46,1.19,1,0.86,0.71}
            ,{1.29,1.13,1,0.91,0.82}
            ,{1.42,1.17,1,0.86,0.7}
            ,{1.21,1.10,1,0.9,1}
            ,{1.14,1.07,1,0.95,1}
            ,{1.24,1.10,1,0.91,0.82}
            ,{1.24,1.1,1,0.91,0.83}
            ,{1.23,1.08,1,1.04,1.10}
};
double mode_params[3][3]={{3.2,1.05,0.38},{3.0,1.12,0.35},{2.8,1.20,0.32}};
void cost_drivers_assignment(double a[])
{
    cout<<"for very low type 1"<<endl
        <<"for  low type 2"<<endl
        <<"for nominal type 3"<<endl
        <<"for high type 4"<<endl
        <<"for very high type 5"<<endl;

    int p;
    cout<<"enter complexity for required reliability "<<endl;
    cin>>p;
    a[0]=cd[0][p-1];
    cout<<endl;

    cout<<"enter complexity for database size "<<endl;
    cin>>p;
    a[1]=cd[1][p-1];
    cout<<endl;

    cout<<"enter complexity for product complexity "<<endl;
    cin>>p;
    a[2]=cd[2][p-1];
    cout<<endl;

    cout<<"enter complexity for execution time constraint "<<endl;
    cin>>p;
    a[3]=cd[3][p-1];
    cout<<endl;

    cout<<"enter complexity for memory constraint "<<endl;
    cin>>p;
    a[4]=cd[4][p-1];
    cout<<endl;

    cout<<"enter complexity for virtual machine volatility "<<endl;
    cin>>p;
    a[5]=cd[5][p-1];
    cout<<endl;

    cout<<"enter complexity for computer turnaround time "<<endl;
    cin>>p;
    a[6]=cd[6][p-1];
    cout<<endl;

	cout<<"enter complexity for analyist cappability "<<endl;
    cin>>p;
    a[7]=cd[7][p-1];
    cout<<endl;

    cout<<"enter complexity for application experience "<<endl;
    cin>>p;
    a[8]=cd[8][p-1];
    cout<<endl;

    cout<<"enter complexity for programmer capability "<<endl;
    cin>>p;
    a[9]=cd[9][p-1];
    cout<<endl;

    cout<<"enter complexity for virtual machine experience "<<endl;
    cin>>p;
    a[10]=cd[10][p-1];
    cout<<endl;

    cout<<"enter complexity for programmer language experience "<<endl;
    cin>>p;
    a[11]=cd[11][p-1];
    cout<<endl;

    cout<<"enter complexity for modern programming practices  "<<endl;
    cin>>p;
    a[12]=cd[12][p-1];
    cout<<endl;

    cout<<"enter complexity for use of software tools "<<endl;
    cin>>p;
    a[13]=cd[13][p-1];
    cout<<endl;

    cout<<"enter complexity for devlopment schedule "<<endl;
    cin>>p;
    a[14]=cd[14][p-1];
    cout<<endl;
}

double * select_mode()
{
    int p;
    cout<<"type 1 for organic mode"<<endl
        <<"type 2 for semi-detached  mode"<<endl
        <<"type 3 for embedded mode"<<endl;
    cin>>p;

    return mode_params[p-1];
}
void calculation(int kloc,double cost_drivers[],double * model)
{
    double eaf=1;
    for(int i=0;i<15;i++)
        eaf*=cost_drivers[i];
    
    double effort,total_devlopment_time;
    int avg_staff_size;

    effort = eaf*model[0]*pow(kloc,model[1]);
    total_devlopment_time = 2.5*pow(effort,model[2]);
    avg_staff_size = ceil(effort/total_devlopment_time);

    cout<<"total effort : "<<effort<<endl
        <<"total devlopment time : "<<total_devlopment_time<<endl
        <<"average staff size :  "<<avg_staff_size<<endl;
}
int main()
{
    
    int kloc ;
    cout<<"Enter total Lines of Code: "<<endl;
    cin>>kloc;

    double cost_drivers[15];
    double * mode=select_mode();

    cost_drivers_assignment(cost_drivers);

    calculation(kloc,cost_drivers,mode);
    
    return 0;

}

