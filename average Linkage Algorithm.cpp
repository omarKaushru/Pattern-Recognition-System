/*
Developer: Md Omar Kaushru
Id: 1401020012
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i,j,flagi,flagj,k,run;
    double solution[100][100],x[100],y[100],t1,t2,min,temp[100][100];
    while(cin>>n)
    {
        min=9999;
        for(i=0; i<n; i++)
        cin>>x[i]>>y[i];
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                t1=sqrt(pow((x[j]-x[i]),2)+pow((y[j]-y[i]),2));
                solution[i][j]=t1;
                temp[i][j]=t1;
                if(t1<min && t1!=0)
                {
                    min=t1;
                    flagi=i;
                    flagj=j;
                }
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                printf("%.1lf  ",solution[i][j]);
            cout<<"\n";
        }
        run=n-2;
        while(run)
        {
            min=9999999.0;
            n--;
            cout<<endl<<flagi<<" "<<flagj<<" will merge.\n";
            for(i=flagi; i<=flagi; i++)
            {
                for(j=0; j<n; j++)
                {
                    if(i==j)
                    solution[i][j]=0;
                    else
                    {
                        if(j>flagi)
                        solution[i][j]=(temp[i][j+1]+temp[i+1][j+1])/2.0;
                        else if(j<flagi)
                        solution[i][j]=(temp[i][j]+temp[i+1][j])/2.0;
                    }
                }
            } ///End of merge
            for(i=0; i<n; i++)
            {
                if(i==flagi)
                continue;
                for(j=0; j<n; j++)
                {
                    if(i==j)
                    solution[i][j]=0;
                    else if(j==flagi)
                    solution[i][j]=solution[j][i];
                    else if(j>=flagj)
                    solution[i][j]=temp[i+1][j+1];
                    else if(j<flagj)
                    solution[i][j]=temp[i][j];
                }
            }
            for(i=0; i<n; i++)
            {
                cout<<"\n";
                for(j=0; j<n; j++)
                {
                    temp[i][j]=solution[i][j];
                    if(solution[i][j]<min && solution[i][j]!=0)
                    {
                        min=solution[i][j];
                        flagi=i;
                        flagj=j;
                    }
                    printf("%.1lf  ",solution[i][j]);
                }
            }
            cout<<"\n\n";
            run--;
        }
    }
}
