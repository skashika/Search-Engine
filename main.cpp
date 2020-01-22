/*
main.cpp -> CPP file
Author -> Shubham Kashikar
Date -> 10/16/2019
Compiler -> Repl IT (Online Compiler)
*/

#include <iostream> 
#include <fstream> 
#include "searchEngine.h" 
using namespace std; 
 
int main() 
{   
  searchEngine g00gle;   
  ifstream urls("urls.txt");
  string webPage, word;  
  while(urls >> webPage)
   {       
      fstream web(webPage);
      cout << "Crawling the " << webPage << " ..."<<endl; 
      while(web >> word)
        {         
          g00gle.addIndex(word, webPage);      
        }
    } 
 
  string s_term = "";   
  while (s_term != "q" || s_term != "Q")  
    {     
       cout<< "Enter the search term (q for quit):";     
       cin>> s_term;     
       cout << g00gle.result(s_term)<<endl; 
    } 
} 