// 7-8.cpp

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "split.h"
#include "find_urls.h"

using namespace std;

static map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    while (getline(in, line)) {
        ++line_number;

        vector<string> words = find_words(line);

        for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
            if (find(ret[*it].begin(), ret[*it].end(), line_number) == ret[*it].end())
                ret[*it].push_back(line_number);
    }
    return ret;
}

int main()
{
    map<string, vector<int> > ret = xref(cin, find_urls);

    for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {

        cout << it->first << " occurs on line" << (it->second.size() > 1 ? "s: " : ": ");

        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it;

        ++line_it;
        while (line_it != it->second.end()) {
            cout << ", ";

            if ((line_it - it->second.begin()) % 15 == 0) {
                cout << endl;
            }
            cout << *line_it;
            ++line_it;
        }
        cout << endl;
    }

    return 0;
}