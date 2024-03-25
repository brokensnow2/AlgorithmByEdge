#include <iostream>
#include <unordered_set>
#include <cstdio>
#include <sstream>

using namespace std;

int main()
{
    // count word
    unordered_set<string> s;
    string words,word;
    while (getline(cin, words))
    {
        if (words == "#")
        	break;
		istringstream iss(words);
        while (getline(iss, word, ' '))
        {
            if (word != "") // getline的特性
            	s.insert(word);
        }
		cout << s.size() << endl;
        s.clear();
    }
}