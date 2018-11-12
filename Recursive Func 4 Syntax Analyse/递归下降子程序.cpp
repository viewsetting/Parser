#include<bits/stdc++.h>
using namespace std;
map<char,set<string>> table;
vector<string> vec;
int num;
bool dfs(string now)
{
    if(now.size()>vec[num].size())
    {
        return 0;
    }

    bool flag=0;
    for(int i=0;i<now.size();i++)
    {
        if(isupper(now[i]))
        {
            for(auto &it : table[now[i]])
            {
                string nxt=now.substr(0,i)+it+now.substr(i+1,now.size()-i-1);
                if(nxt==vec[num]) return 1;
                if(dfs(nxt)) flag=1;
            }
        }
    }
    return flag;

}
int main()
{
    freopen("test_rec.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string ans;
        cin>>ans;
        string tmp="";
        for(int j=3;j<ans.size();j++)
        {
            tmp+=ans[j];
        }
        table[ans[0]].insert(tmp);
    }
    cout<<"VN-Generator Table\n";
    for(auto it: table)
    {
        cout<<it.first<<" ";
        for(auto &pp : it.second )
        {
            cout<<pp<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
    vec.push_back("eadeaa");
    vec.push_back("edeaebd");
    vec.push_back("edeaeaadabacae");

    for(num=0;num<vec.size();num++)
    {
        if(dfs("E")) cout<<"\""<<vec[num]<<"\" is found in the syntax tree.\n";
        else cout<<"Oops!The string : \""<<vec[num]<<"\" can not be generated from the given grammar!\n";
    }
    return 0;
}
