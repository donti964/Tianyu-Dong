# Tianyu-DongDeveloping  environment：mac os  C++11  
Program function：Realize the input of "Wall Street Journal" xml file，analyze and store the content of the article in an efficient data structure, and support query according to word frequency, sort related articles by relevance and output article title and relevance.

file program is Whole program which iclude index and research。 file index only include index and part 2.  file research include the part3


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

...*//
