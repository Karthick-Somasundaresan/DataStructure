#include <iostream>
#include <vector>
#include <map>
/*
* Letter combinations of a phone number
*  Given a digit string return all possible letter combinations that the number could represent
+-----+-----+-----+
|     |     |     |
|  1  |  2  |  3  |
|     | abc | def |
+-----------------+
|  4  |  5  |  6  |
| ghi | jkl | mno |
+-----------------+
|  7  |  8  |  9  +
|pqrs | tuv |wxyz |
|     |     |     |
+-----+-----+-----+
Drawn using http://asciiflow.com/

Input string: "23"
output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

*/
using namespace std;

map<int, vector<char> > fillMap()
{
    char c = 65;
    map <int, vector<char> > myMap;
    for (auto i = 0; i <=9; i++)
    {

        vector <char> listOfchars;
        vector <char>::iterator listIter;
        int subIndex  = 3;
        if(i == 0)
        {
            listOfchars.insert(listOfchars.end(), 32);
        } 
        else if(i == 1)
        {
            continue;
        }
        else
        {
            if(i == 7 || i == 9)
            {
                subIndex = 4;
            }
            while(subIndex >= 1)
            {
                listOfchars.insert(listOfchars.end(), c);
                subIndex--;
                c++;
            }
        }
        myMap.insert(pair<int, vector<char> >(i, listOfchars));
        

    }
    return myMap;
}

void printMap(map <int, vector<char> > hashMap)
{
    for(auto it: hashMap)
    {
        cout<<it.first<<" == [";
        for (auto lit: it.second)
        {
            cout<<lit<<",";
        }
        cout<<"\b]";
        cout<<endl;
    }
    return;
}

void printAllStrings(map<int, vector<char> > hashMap, string input, int startIndex, string prefix = "")
{
    int length = input.length();
    if (startIndex == length)
    {
        return;
    }
    else
    {
        vector<char> chList;
        map<int, vector<char> >::iterator mapIter = hashMap.find(input.at(startIndex) - '0');
        if(mapIter == hashMap.end())
        {
            cout<<"Unable to find char"<<input.at(startIndex);
        }
        else
        {
            chList = mapIter->second;
            int listLen = chList.size();
            int curIndex = 0;
            while(curIndex < listLen)
            {
                if(startIndex +1 == length)
                {
                    cout<<prefix + chList.at(curIndex)<<endl;
                }
                printAllStrings(hashMap, input, startIndex + 1, prefix+chList.at(curIndex));
                curIndex++;
            }
        }
        
    }
    
}

int main()
{

    map <int, vector<char> > hashMap;
    hashMap = fillMap();
    printMap(hashMap);
    string input;
    cout<<"Enter the number String:";
    cin>>input;
    printAllStrings(hashMap, input, 0);
    return 0;
}