#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;
typedef duration<double> DD;
typedef system_clock::time_point S_C_TP;






vector<vector<float>> operator-(const vector<vector<float>>& v1, const vector<vector<float>>& v2){
    int dimention=v1.size();
    vector<vector<float>> result(dimention,vector<float>(dimention));
    for (size_t i = 0; i < dimention; i++)
    {
        vector<float> temp;
        for (size_t j = 0; j < dimention; j++)
        {
            result[i][j]=v1[i][j]-v2[i][j];
        }


    }
    return result;
}
vector<vector<float>> operator+(const vector<vector<float>>& v1, const vector<vector<float>>& v2)
{
    int dimention=v1.size();
    vector<vector<float>> result(dimention,vector<float>(dimention));
    for (size_t i = 0; i < dimention; i++)
    {
        vector<float> temp;
        for (size_t j = 0; j < dimention; j++)
        {

            result[i][j]=v1[i][j]+v2[i][j];
        }

    }
    return result;
}

class algo{
public:
    virtual void operator()( vector<vector<float>>& v1,  vector<vector<float>>& v2,int n){};
    virtual void operator()( vector<vector<float>>& v1,  vector<vector<float>>& v2,int n,int dummy){};
protected:
    vector<vector<float>> spilitor(vector<vector<float>> &A,int row,int column) {
        int size=A.size()/2;
        vector<vector<float>>block(size,vector<float> (size));
        for (int i = 0; i <size; i++) {
            for (int j = 0; j < size; j++) {
                if(row==0&&column==0)
                    block[i][j] = A[i][j];
                else if(row==0&&column==1)
                    block[i][j] = A[i][j +size];
                else if(row==1&&column==0)
                    block[i][j] = A[i + size][j];
                else if(row==1&&column==1)
                    block[i][j] = A[i + size][j +size];
            }
        }
        return block;
    }

/*
    vector<vector<float>>& spilitor(vector<vector<float>> A,int row,int column){

        vector<vector<float>> *result =new vector<vector<float>>;
        int rowbound,columnbound;
        rowbound=columnbound=A.size();
        if(column==1)column=A.size()/2;//00 01
                                        //10 11
        else
            columnbound/=2;
        if(row==1)row=ceil(A.size()/2);
        else
            rowbound/=2;
        for (int i = row; i < rowbound; ++i) {
            vector<float> tmp;
            for (int j = column; j < columnbound; ++j) {
                tmp.push_back(A[i][j]);
            }
            result->push_back(tmp);
        }
        return *result;
    }
*/


    vector<vector<float>> merge(vector<vector<float>> &c11,vector<vector<float>> &c12,vector<vector<float>> &c21
            ,vector<vector<float>> &c22) {
        int size= c11.size()+c12.size();
        vector<vector<float>> result(size,vector<float> (size));
        size/=2;
        for (int i = 0; i < size ; i++) {
            for (int j = 0 ; j < size ; j++) {
                result[i][j] = c11[i][j];
                result[i][j + size] = c12[i][j];
                result[i + size][j] = c21[i][j];
                result[i + size][j + size] = c22[i][j];
            }
        }
        return result;
    }


};
class CdivideAndConquer : public algo
{




    vector<vector<float>> divideAndConquer(vector<vector<float>> &A, vector<vector<float>> &B){
        vector<vector<float>> c11;
        vector<vector<float>> c12;
        vector<vector<float>> c21;
        vector<vector<float>> c22;
        int sizea=A.size();
        if(sizea<=1){
            vector<vector<float>> result(1,vector<float>(1));
            result[0][0]=A[0][0]*B[0][0];
            return result;
        }
        else {
            vector<vector<float>> A1=spilitor(A, 0, 0);
            vector<vector<float>> A2=spilitor(A, 0, 1);
            vector<vector<float>> A3=spilitor(A, 1, 0);
            vector<vector<float>> A4=spilitor(A, 1, 1);

            vector<vector<float>> B1=spilitor(B, 0, 0);
            vector<vector<float>> B2=spilitor(B, 0, 1);
            vector<vector<float>> B3=spilitor(B, 1, 0);
            vector<vector<float>> B4=spilitor(B, 1, 1);

            c11 = divideAndConquer(A1, B1) +
                  divideAndConquer(A2, B3);
            c12 = divideAndConquer(A1, B2) +
                  divideAndConquer(A2,B4);
            c21 = divideAndConquer(A3,B1) +
                  divideAndConquer(A4, B3);
            c22 = divideAndConquer(A3, B2) +
                  divideAndConquer(A4, B4);
            return merge(c11, c12, c21, c22);

        }
    }

public:
    void operator()( vector<vector<float>>& v1,  vector<vector<float>>& v2,int n,int dummy){}

    vector<vector<float>>  multiply(vector<vector<float>> &A, vector<vector<float>> &B,int dummy){
        return divideAndConquer(A,B);
    }
    void operator()( vector<vector<float>>& v1,  vector<vector<float>>& v2,int n){
        multiply(v1,v2,n);
    }
};

class CStrassen: public algo{
    vector< vector<float> > strassen(vector<vector<float>>&A,  vector<vector<float>>&B){
        vector<vector<float>> c11;
        vector<vector<float>> c12;
        vector<vector<float>> c21;
        vector<vector<float>> c22;

        vector<vector<float>> p1;
        vector<vector<float>> p2;
        vector<vector<float>> p3;
        vector<vector<float>> p4;
        vector<vector<float>> p5;
        vector<vector<float>> p6;
        vector<vector<float>> p7;

        int sizea=A.size();
        if(sizea<=1){
            vector<vector<float>> result(1,vector<float>(1));
            result[0][0]=A[0][0]*B[0][0];
            return result;
        }
        vector<vector<float>> f1=spilitor(B,0,1)-spilitor(B,1,1);
        vector<vector<float>> f2=spilitor(A,0,0) + spilitor(A,0,1);
        vector<vector<float>> f3=spilitor(A,1,0) + spilitor(A,1,1);
        vector<vector<float>> f4=spilitor(B,1,0) - spilitor(B,0,0);
        vector<vector<float>> f5=spilitor(A,0,0) + spilitor(A,1,1);
        vector<vector<float>> f6=spilitor(B,0,0) + spilitor(B,1,1);
        vector<vector<float>> f7=spilitor(A,1,1) - spilitor(A,1,1);
        vector<vector<float>> f8=spilitor(B,1,0) + spilitor(B,1,1);
        vector<vector<float>> f9=spilitor(A,0,0) - spilitor(A,1,0);
        vector<vector<float>> f10=spilitor(B,0,0) + spilitor(B,0,1);

        vector<vector<float>> A1=spilitor(A, 0, 0);
        vector<vector<float>> A4=spilitor(A, 1, 1);
        vector<vector<float>> B1=spilitor(B, 0, 0);
        vector<vector<float>> B4=spilitor(B, 1, 1);

        p1 = strassen(A1,f1 );
        p2 = strassen(f2, B4);
        p3 = strassen(f3, B1);
        p4 = strassen(A4, f4);
        p5 = strassen(f5, f6);
        p6 = strassen(f7, f8);
        p7 = strassen(f9, f10);

        c11 = p5 + p4 - p2 + p6;
        c12 = p1 + p2;
        c21 = p3 + p4;
        c22 = p1 + p5 - p3 - p7;

        return merge(c11, c12, c21, c22);

    }


public:
    void operator()( vector<vector<float>>& v1,  vector<vector<float>>& v2,int n){
        multiply(v1,v2);
    }
    void operator()( vector<vector<float>>& v1,  vector<vector<float>>& v2,int n,int dummy){
        ikjalgorithm(v1,v2,n);
    }
    vector< vector<float> > multiply(vector< vector<float> > &A,
    vector< vector<float> > &B){
        return strassen(A,B);
    }

    vector< vector<float> > ikjalgorithm(const vector< vector<float> > &A,
                      const vector< vector<float> > &B,
                      int n) {
    vector< vector<float>> C (n, vector<float> (n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }
};

void input(const int &n, fstream &File,vector<vector<float>>& input)
{
//    File.seekp(ios::beg);
    fstream file("generatednumbers.txt");

    for (int i = 0; i < n; ++i)
    {
        vector<float> tmp;
        for (int j = 0; j < n; ++j) {
            float temp=0;
            stringstream ss;
            ss.precision(8);
            string str;
            file>> str;
            ss<<str;
            ss>>temp;
            tmp.push_back(temp);
        }
        input.push_back(tmp);

    }

}

void writeNRandomlyNumbersInFile(int n, fstream &file)
{
    srand(time(nullptr));
    for (int i = 0; i < n; ++i)
    {
        file <<  static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/1000))<< " ";
    }
    file.seekp(ios::beg);
}


string stoi(long double value){
    string str;
    stringstream ss;
    ss.precision(16);
    ss<<value;
    ss>>str;

    return str;
}//string to number


long double taketime( algo &func,vector<vector<float>>v1
                ,vector<vector<float>>v2,int n,int dummy=0){
    S_C_TP start = system_clock::now();
    if(dummy==0)func(v1, v2,n);
    else func(v1, v2,n,1);
    S_C_TP end = system_clock::now();
    DD elapsed_seconds = duration_cast<milliseconds>(end - start);
    return     elapsed_seconds.count();
}

bool ispowerof2(int i){

    if(log2(i)==ceil(log2(i)))return true;

    return false;
}


int main(){
    srand (static_cast <unsigned> (time(0)));
    fstream file("generatednumbers.txt", ios::out);
    fstream jsonfile("data.json", ios::out);
    writeNRandomlyNumbersInFile(1000000, file);
    string ns="",ss="",s="",dc="";



    vector<vector<float>>v1,v2;
    CStrassen obj1;
    CdivideAndConquer obj2;

    for (int i = 10000; i < 100000; i+=1) {
        if(ispowerof2(i)) {//
            int n = sqrt(i);
            input(n, file,v1);
            input(n, file,v2);
            ns += ::stoi(i) + ",";
            s += ::stoi(taketime(obj1, v1, v2, n, 1)) + ",";
            ss += ::stoi(taketime(obj1, v1, v2, n)) + ",";
            dc += ::stoi(taketime(obj2, v1, v2, n)) + ",";
        }
    }


    string json="{\n"
                "\"n\": ["+(ns.substr(0,ns.length()-1))+"],\n"
                "\"strassen\": ["+(ss.substr(0,ss.length()-1))+"],\n"
                "\"divdeandconquer\": ["+(dc.substr(0,dc.length()-1))+"],\n"
                "\"simple\": ["+(s.substr(0,s.length()-1))+"],\n"
                "}";
    jsonfile<<json;
    jsonfile.close();
    file.close();
                                                                                                                                                                                                "}";

}

