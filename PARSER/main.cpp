#include<bits/stdc++.h>
#define pr pair<string,int>
#include "framework.h"
#define AHA parse();
using namespace std;
map<string,int> table= {pr("Int",1),pr("Float",2),pr("Identifier",3),pr("Name",4),pr("Invalid Name",6),pr("Symbol",5)};

struct rec
{
    string typ;
    string str;
    int line;
    rec(string a,string b,int c)
    {
        str=a;
        typ=b;
        line=c;
    }
};
int line_counter=0;
set<string> id= {"int","float","double","char","return","main","std","include"};
set<char> sym= {'+','-','*','/','%','=','#','!','|','{','}','(',')','&','^'};
bool flag_first=1;
char previous=0;
vector<rec> stk;
bool check_num(string num)
{
    for(auto &it: num)
    {
        if(it<'0'||it>'9')
            return 0;
    }
    return 1;
}

bool is_id(string id_new)
{
    if(id.count(id_new)!=0)
        return 1;
    else
        return 0;
}
bool is_sym(char id_new)
{
    if(sym.count(id_new)!=0)
        return 1;
    else
        return 0;
}
void check(string buf)
{
    //cout<<buf<<"  "<<endl;
    if(buf.size()==1)
    {
        if(is_sym(buf[0]))
        {
            stk.push_back(rec(buf,"Symbol",line_counter));
        }
        else if(buf[0]>='0'&&buf[0]<='9')
        {
            stk.push_back(rec(buf,"Int",line_counter));
        }
        else if(isalpha(buf[0])!=0)
        {
            stk.push_back(rec(buf,"Name",line_counter));
        }
        else
        {
            stk.push_back(rec(buf,"Invalid Name",line_counter));
        }
    }
    else if(check_num(buf)||std::count(buf.begin(),buf.end(),'.')==1)
    {
        if(std::count(buf.begin(),buf.end(),'.')==1)
        {
            if(buf[buf.size()-1]!='.')
                stk.push_back(rec(buf,"Float",line_counter));
            else
                stk.push_back(rec(buf,"Invalid Name",line_counter));
        }
        else if(check_num(buf))
        stk.push_back(rec(buf,"Int",line_counter));
    }
    else
    {
        //if()
        if(is_sym(buf[0]))
        {
            stk.push_back(rec(buf,"Symbol",line_counter));
        }
        else if(buf[0]<='9'&&buf[0]>='0')
        {
            stk.push_back(rec(buf,"Invalid Name",line_counter));
        }
        else if(is_id(buf))
        {
            stk.push_back(rec(buf,"Identifier",line_counter));
        }
        else
        {
            stk.push_back(rec(buf,"Name",line_counter));
        }
    }

}
int main()
{
    //cout<<table["symbol"];
    freopen("input.cpp","r",stdin);
    string line_str;
    AHA
    // cout<<isalpha('A')<<isalpha('a')<<isnum('1')<<isalpha('+');

    while(getline(std::cin,line_str))
    {
        line_counter++;
        string buf="";
        //previous=0;
        for(int i=0; i<line_str.size(); i++)
        {
            if(!(line_str[i]>='0'&&line_str[i]<='9')&&isalpha(line_str[i])==0&&line_str[i]!='.')
            {
                if(buf=="")
                {
                    if(is_sym(line_str[i]))
                    {
                        buf+=line_str[i];
                       // cout<<"\n is_sym"<<i<<"--"<<buf<<endl;
                    }

                    else
                    continue;
                }
                else if (line_str[i]==' ')
                {
                    check(buf);
                    buf="";
                }
                else
                {

                    if(line_str[i]=='.')
                    {
                        if(check_num(buf))
                        {
                            buf+=".";
                            continue;
                        }
                        else
                        {
                            {
                                check(buf);
                                buf="";
                            }

                        }
                    }
                    else
                    {
                        if(is_sym(line_str[i]))
                        {
                            if(is_sym(line_str[i-1]))
                                buf+=line_str[i];
                            else
                            {
                                check(buf);
                                buf=line_str[i];
                            }
                         //   cout<<"\n buf"<<buf<<endl;
                        }
                        else
                        {
                            check(buf);
                            buf="";
                        }

                    }

                }

                //buf="";
            }
            else
            {
                if(is_sym(buf[buf.size()-1])&&isalpha(line_str[i])!=0&&(line_str[i]>='0'&&line_str[i]<='9'))
                {
                    //cout<<"oo "<<buf<<endl;
                    check(buf);
                    buf="";
                }
                buf+=line_str[i];
            }
        }
        //buf="";
    }
    for (auto & itt:stk)
    {
        cout<<itt.line<<"  "<<itt.str<<"   "<<itt.typ<<endl;
    }
    return 0;
}
