#define _CRT_SECURE_NO_DEPRECATE
/************************
*创建时间：2021 01 
*文件类型：源代码文件
*题目来源：
*当前状态：
*备忘录：
*作者：双双双
*联系方式：QQ3503871581
************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <unordered_map>
// #include <sys/wait.h>
// #include <sys/types.h>
// #include <unistd.h>
using namespace std;
string word;
static char word2[600000000];
vector <string> query;
struct A 
{
	string id;
	unordered_map <string,int> dic;
	int v;
	A(string id=""):id(id){}
	void getv()
	{
		v=0;
		int times;
		for(int i=0;i<query.size();++i)
		{
			if(dic.count(query[i]))
			{
				times=dic[query[i]];
				v+=times;
			}
		}
	}
	bool operator<(const A&x)const
	{
		return v>x.v;
	}
};
vector <A> q;
/* Variable explain:

*/
void read(char *argv[])
{
	FILE *in=fopen(argv[1],"r");
	int n;
	n=fread(word2,1,600000000,in);
	word=word2;
	return;
}
void part2(A &x,int l,int r)//构建数据结构
{
	string s=word.substr(l,r-l);
	int T=0,n;
	char ls[100];
	while(T<s.length()&&sscanf(s.c_str()+T,"%s",ls)==1)
	{
		T=s.find(ls,T)+strlen(ls);
		n=strlen(ls);
		while(ls[n-1]==','||ls[n-1]==';'||ls[n-1]=='.'||ls[n-1]=='?'||s[n-1]=='!'||s[n-1]=='"'||s[n-1]=='\'')ls[--n]=0;
		for(int i=0;i<n;++i)if(ls[i]<='Z'&&ls[i]>='A')ls[i]+='a'-'A';
		x.dic[ls]++;
	}
}
void part1_2()
{
	int T=0;
	while((T=word.find("<DOCNO> ",T))!=string::npos)//解析文件
	{
		T+=strlen("<DOCNO> ");
		char ls[50];
		sscanf(word.substr(T,20).c_str(),"%s",ls);
		printf("parse:%s\n",ls);
		T=word.find("<TEXT>",T);
		T+=strlen("<TEXT>");
		int ls1=word.find("</TEXT>",T);
		q.push_back(A(ls));
		part2(q.back(),T,ls1);
		T=ls1;
	}
	FILE *out=fopen("output.txt","w");
	for(int i=0;i<q.size();++i)//输出至文件（part2）
	{
		for(unordered_map<string,int>::iterator it=q[i].dic.begin();it!=q[i].dic.end();++it)
		{
			fprintf(out,"%s %d\n",it->first.c_str(),it->second);
		}
	}
	fclose(out);
}
void part3()
{
	while(1)//循环接受询问
	{
		int n;
		scanf("%d",&n);
		query.clear();
		char ls[50];
		for(int i=0;i<n;++i)
		{
			scanf("%s",ls);
			query.push_back(ls);
		}
		deque<int>ansq;
		for(int i=0;i<q.size();++i)
		{
			q[i].getv();
			ansq.push_back(i);
		}
		for(int i=0;i<n;++i)//查询
		{
			sort(ansq.begin(),ansq.end(),[=](int a,int b){return q[a].v>q[b].v;});
		}
		for(int i=0;i<q.size();++i)//输出
		{
			if(!q[ansq[i]].v)break;
			printf("%s %d\n",q[ansq[i]].id.c_str(),q[ansq[i]].v);
		}
	}
}
int main(int argc,char *argv[])
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	if(argc<2)
	{
		printf("你需要将待分析文件添加至运行参数中\n");
		return 0;
	}
	read(argv);
	q.reserve(100000);
	part1_2();
	// char ls[50];
	// int n;
	// FILE *in=fopen("output.txt","r");//
	// while(fscanf(in,"%s%d",ls,&n)==2)
	// {
	// 	q.push_back(A(ls));
	// 	int ls2;
	// 	printf("read:%d %s\n",q.size(),q.back().id.c_str());
	// 	for(int i=1;i<=n;++i)
	// 	{
	// 		fscanf(in,"%s%d",ls,&ls2);
	// 		q.back().dic[ls]=ls2;
	// 	}
	// }
	printf("构建索引完成\n");
	return 0;
}
