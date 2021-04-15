# Tianyu-DongDeveloping  environment：mac os  C++11  
Program function：Realize the input of "Wall Street Journal" xml file，analyze and store the content of the article in an efficient data structure, and support query according to word frequency, sort related articles by relevance and output article title and relevance.



programming method: g++ main.cpp -std=c++11

execution method: (mas os)        ./a.out wsj.xml
 (windows)                        main.exe wsj.xml

execution steps: 
1.take all articles as inputs and the titles of the articles will be generated as outputs
2. save relevant information in a file named "output.txt" according to the data structure.
3. indexing completed and enable search function after taking search command.
4. Index in structure A, it is q.
5. The output be sorted from highest to lowest rsv


structure of searching command:
[number of word searched] [word1] [word2] ... [word n]
example: 2 and to
num word1 word2...

//*编译方法：g++ main.cpp -std=c++11
执行方法：(mas os)        ./a.out wsj.xml
 (windows)                                main.exe wsj.xml
执行流程，首先会读入所有文章，在stdout输出文章标题，然后将文章存入数据结构中，并将摘要信息存入output.txt中，最后提示”构建索引完成“，输入查询指令即可查询
查询指令格式：
[单词数] [单词1] [单词2] [单词3]...
例：2 and to
num word1 word2...
输出格式：
[标题1] [相关度1]
[标题2] [相关度2]
[标题3] [相关度3]
...*//
