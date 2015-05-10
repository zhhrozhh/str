#ifndef STRHZOI
#define STRHZOI
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
vector<string>rawSplit(string s,string str){
    string s1 = str;
    vector<string>res;
    while(s1.find(s)!=string::npos){
        res.push_back(s1.substr(0,s1.find(s)));
        s1 = s1.substr(s1.find(s)+s.size(),s1.size());
    }
    if(s1.size())
        res.push_back(s1);
    return res;
}
vector<string>split(string s,string str){
    string s1 = str;
    vector<string>res;
    while(s1.find(s)!=string::npos){
        if(s1.find(s)>0)
            res.push_back(s1.substr(0,s1.find(s)));
        s1 = s1.substr(s1.find(s)+s.size(),s1.size());
    }
    if(s1.size())
        res.push_back(s1);
    return res;
}
string replace(string str,string subs1,string subs2){
    vector<string>s = rawSplit(subs1,str);
    string res="";
    for(size_t i=0;i<s.size();i++)
        res=res+s[i]+subs2;
    return res;
}
vector<string>rawSplit(vector<string>s,string str){
    string resstr = str;
    for(size_t i=1;i<s.size();i++)
        resstr = replace(resstr,s[i],s[0]);
    return rawSplit(s[0],resstr);
}
vector<string>split(vector<string>s,string str){
    string resstr = str;
    for(size_t i=1;i<s.size();i++)
        resstr = replace(resstr,s[i],s[0]);
    return split(s[0],resstr);
}
bool hasPrefix(string str,string pfix){
    return str.find(pfix)==0;
}
bool strRemovePrefix(string&str,string pfix){
    if(!hasPrefix(str,pfix))return false;
    str = str.substr(pfix.size(),str.size());
    return true;
}
bool hasSurfix(string str,string sfix){
    return str.substr(str.size()-sfix.size(),str.size()) == sfix;
}
bool strRemoveSurfix(string&str,string sfix){
    if(!hasSurfix(str,sfix))return false;
    str = str.substr(0,str.size()-sfix.size());
    return true;
}
string be_match_1(string str,string begining,string ending){//non recursive (ay1axby2b,a,b)->y1ax
    if(str.find(begining)==string::npos||str.find(ending)==string::npos)
        return "";
    if(str.find(begining)>str.find(ending))
        return be_match_1(str.substr(str.find(ending)+ending.size(),str.size()),begining,ending);
    return str.substr(str.find(begining)+begining.size(),str.find(ending)-1);
}
vector<string>be_match_2_all(string str,string begining,string ending){//non recursive (ay1axby2b,a,b)->x
    vector<string>res = split(begining,str);
    vector<string>rres;
    if(str.find(begining)==string::npos)return rres;
    for(size_t i=0;i<res.size();i++)
        if(res[i].find(ending)!=string::npos)
            rres.push_back(res[i].substr(0,res[i].find(ending)));
    if(str.find(ending)<str.find(begining))
        rres.erase(rres.begin());
    return rres;
}
#endif

