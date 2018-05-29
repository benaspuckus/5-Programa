#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>

using std::ifstream;
using std::string;
using std::cout;
using std::pair;
using std::multimap;
using std::iterator;
int main() {
    ifstream fd("duom.txt");
    string line;
    multimap<string, int> zodis;
    int eilute=1;
    int kartojimas;
    int kiekis;
    string laikinas;
    while (std::getline(fd, line))
    {
        std::istringstream iss(line);
        while(iss >> laikinas)
        {
            zodis.insert(std::pair<string, int>(laikinas, eilute));
        }
        eilute++;
    }
    multimap<string,int>::iterator it;
    for(auto it = zodis.cbegin(), end = zodis.cend(); it != end; it = zodis.upper_bound(it->first))
    {
        if(zodis.count(it->first)>1)
        {
            cout << "zodis '"<<it->first << "' kartojasi " << zodis.count(it->first) << " kartus ";
            pair < multimap<string,int>::iterator,  multimap<string,int>::iterator> range = zodis.equal_range(it->first);
            kiekis = 1;
            for(auto iteratorius = range.first; iteratorius != range.second; ++iteratorius)
            {
                if(kartojimas != iteratorius->second && kiekis > 1)
                    cout<<" ir ";
                if(kartojimas != iteratorius->second)
                cout << ' ' << iteratorius->second;
                kartojimas = iteratorius->second;
                kiekis++;
            }
            kartojimas = NULL;
            cout<<" eiluteje"<<std::endl;

        }

    }

    return 0;
}