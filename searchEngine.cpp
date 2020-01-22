/*
searchEngine.cpp -> CPP file
Author -> Shubham Kashikar
Date -> 10/16/2019
Compiler -> Repl IT (Online Compiler)
*/

#include <iostream>
#include "searchEngine.h"
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iterator> 
using namespace std;

map<string, vector<string> > mp; //map
map<string, vector<string> >::iterator it; //iterator

//Function to convert string to lower case
string toLower(string word)
{
  for_each(word.begin(), word.end(), [](char & c) {
		c = tolower(c);
  });
  return word;
}


// Method to add the key value pair to the map
void searchEngine::addIndex(string word,string url)
{
  vector<string> sentence;
  if(word != "." && word != ",")
  {  
    word = toLower(word);
    //cout << word;
    it = mp.find(word);
    if (it != mp.end())
      {
          sentence = mp.find(word)->second;
          if(sentence.size() == 0)
          {
            mp[word].push_back(url);
          }
          else{
            if(find(sentence.begin(), sentence.end(), url.c_str()) == sentence.end())
            {
              mp[word].push_back(url);
            }
          }         
      }
    else
      {
        sentence.push_back(url);
        mp.insert(pair<string, vector<string> >(word, sentence));
      }
  }
}

//retrieval
string searchEngine::result(string find_word)
{
  string bb;
  ostringstream vts;
  find_word = toLower(find_word);
  if(find_word == "q" || find_word == "Q")
  { 
    cout << "Bye"<< endl;
    exit(0);
  }
  else
  {
    it = mp.find(find_word);
    vector<string> sentence1;
    sentence1 = it->second;
    if (!sentence1.empty()) 
      { 
        copy(sentence1.begin(), sentence1.end(), 
        ostream_iterator<string>(vts, "\n"));  
      } 
    else
    {
      return "Word Not Found";
    }
  }
  return vts.str();
}