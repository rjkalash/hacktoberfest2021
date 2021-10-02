#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void visa(int x1, int x2, int y1,int y2, int z1, int z2) {
    if((x1<=x2) && (y1<=y2) && (z1>=z2)){
        std::cout<<"Yes"<<endl;
    }else{
        std::cout<<"No"<<endl;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int x1 = stoi(first_multiple_input[0]);

        int x2 = stoi(first_multiple_input[1]);

        int y1 = stoi(first_multiple_input[2]);

        int y2 = stoi(first_multiple_input[3]);

        int z1 = stoi(first_multiple_input[4]);

        int z2 = stoi(first_multiple_input[5]);
        visa(x1,x2,y1,y2,z1,z2);
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
