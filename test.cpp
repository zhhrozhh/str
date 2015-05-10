#include"str.h"
int main(){
    string a = "axbaybazbasb";
    string b = "xsdbasdaxbsdfb";
    string c = "wegfdngf";
    cout<<be_match_1(a,"a","b")<<endl;
    vector<string>v = be_match_2_all(c,"a","b");
    for(size_t i=0;i<v.size();i++)
        cout<<v[i]<<endl;
}
