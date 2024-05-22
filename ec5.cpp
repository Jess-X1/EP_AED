#include <iostream>
#include <vector>
using namespace std;
const int MAX=26;

class table{
private:
    int cap=MAX;
public:
    int val[MAX]={};

    int& operator[](char key){
        int id=(key-'a')%cap;
        return val[id];
    }
};

class Solution {
public:
    //ejer 1
    bool count(const string& test){
        table t0;

        for(char c:test) t0[c]++;
        int max=t0[test[0]];
        for(char c:test){
            if (t0[c]!=max)  return false;
        }
        return true;
    }
    bool areOccurrencesEqual(string s) {
        return count(s);
    }

    //ejer 2:
    int numOfPairs(vector<string>& nums, string target) {
        int cont=0;
        for (int i=0;i<nums.size(); i++){
            for (int j=0; j<nums.size(); j++)
                if (i!=j && nums[i]+nums[j]==target) cont+=1;
        }
        return cont;
    }

    //ejer 3:
    int costo(table d){
        int max=0;
        for (char c:"abcdefghijklmnopqrstuvwxyz") if (max<d[c]) max=d[c];
        return max;
    }
    string minimizeStringValue(string test) {
        int j=0,min=0;
        table t0;
        string newtest;
        for(char c:test) if (c!='?') t0[c]++;
        for(char c:test) {
            if (c=='?') {
                while (t0.val[j]!=min && j<26) {
                    j++;
                    if (j==26) {
                        j=0;
                        min++;
                    }
                }
                newtest+=char(j+'a');
                t0[char(j+'a')]++;
            } else newtest+=c;
        }
        return newtest;
        /*table repeticiones;
        table posibles;
        int contsig=0; int veces=0;
        string nuevo;
        for (char c:s) {
            if (c!='?') {
            repeticiones[c]++;
            nuevo+=c;
            }
            else contsig+=1;
        }
        int cost=costo(repeticiones);
        for (char c:"abcdefghijklmnopqrstuvwxyz") if (cost-repeticiones[c]>0) {posibles[c]=cost-repeticiones[c]; veces+=posibles[c];}
        if (veces>=contsig){
            int i=0;
            for (char c:"abcdefghijklmnopqrstuvwxyz"){
                while (repeticiones[c]<cost && i<contsig){
                    nuevo+=c;
                    repeticiones[c]++;
                    i++;
                }
            }
        }
        return nuevo;*/
    }
};

string ola(const string& test){

}

int main(){
    Solution s;
    string ss="aaabc??";
    cout<<s.minimizeStringValue(ss);
}