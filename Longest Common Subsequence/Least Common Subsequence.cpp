#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

int i = 0;
int j = 0;
int m = 0;
int n = 0;
int LCS[20][20];

bool validation(const string &dna)
{
    for(char c : dna)
    {
        if(c != 'A' && c != 'C' && c != 'T' && c != 'G')
        {
            return false;
        }
    }
    return true;
}

void lcs_algo(const string &X, const string &Y)
{
    m = X.length();
    n = Y.length();

    for(i = 0; i < m; i++)
    {
        LCS[i][0] = 0;
    }

    for(j = 0; j < n; j++)
    {
        LCS[0][j] = 0;
    }

    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(X[i-1] == Y[j-1])
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else if(LCS[i-1][j] >= LCS[i][j-1])
            {
                LCS[i][j] = LCS[i-1][j];
            }
            else
            {
                LCS[i][j] = LCS[i][j-1];
            }
        }
    }

    int index = LCS[m][n];
    char* lcsalgo = new char[index + 1];
    lcsalgo[index] = '\0';

    i = m;
    j = n;

    while(i > 0 && j > 0)
    {
        if(X[i-1] == Y[j-1])
        {
            lcsalgo[index - 1] = X[i-1];
            i--;
            j--;
            index--;
        }

        else if(LCS[i-1][j] > LCS[i][j-1])
        {
            i--;
        }

        else
        {
            j--;
        }
    }

    cout<<"DNA Sequence 1: "<<X<<endl<<"DNA Sequence 2: "<<Y<<endl;
    cout<<"Longest Common Subsequence: "<<lcsalgo<<endl<<endl;
}

int main()
{
    int choice;
    string dna1;
    string dna2;

    while(choice != 3)
    {
        cout<<"Choose Input Method: "
        <<endl<<"1. Input Sequences Manually."
            <<endl<<"2. Input Sequence from a File."
                    <<endl<<"3. Exit.";
        cout<<endl<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter first DNA Sequence: ";
                cin>>dna1;

                cout<<"Enter second DNA Sequence: ";
                cin>>dna2;

                if(!validation(dna1) || !validation(dna2))
                {
                    cout<<endl<<"Wrong Sequence of DNA entered. Sequence should only contain A,G,T or C."<<endl<<endl;
                    break;
                }

                lcs_algo(dna1, dna2);
                break;
            }

            case 2:
            {
                string filename;
                cout<<"Enter file name: ";
                cin>>filename;

                ifstream file(filename);
                if (!file)
                {
                    cout<<"Error opening file."<<endl<<endl;
                    break;
                }
                else
                {
                    file>>dna1>>dna2;
                    file.close();
                }
                if(!validation(dna1) || !validation(dna2))
                {
                    cout<<endl<<"Wrong Sequence of DNA entered. Sequence should only contain A,G,T or C."<<endl<<endl;
                    break;
                }

                lcs_algo(dna1, dna2);
                break;
            }

            case 3:
            {
                cout<<endl<<"Exiting..";
                break;
            }

            default:
            {
                cout<<"Invalid Choice.";
                break;
            }
        }
    }

    return 0;
}
