#include <iostream>
using namespace std;

// https://dmoj.ca/problem/quine

int main(){
    string arr[] = {
        "#include <iostream>",
        "using namespace std;",
        "int main(){",
        "    string arr[] = {",
        "        ",
        "    };",
        "    for(int i = 0; i<4; i++)",
        "        cout<<arr[i]<<endl;",
        "    for(int i = 0; i<13; i++)",
        "        cout<<arr[4]<<(char)34<<arr[i]<<(char)34<<','<<endl;",
        "    for(int i = 5; i<13; i++)",
        "        cout<<arr[i]<<endl;",
        "}",
    };
    for(int i = 0; i<4; i++)
        cout<<arr[i]<<endl;
    for(int i = 0; i<13; i++)
        cout<<arr[4]<<(char)34<<arr[i]<<(char)34<<','<<endl;
    for(int i = 5; i<13; i++)
        cout<<arr[i]<<endl;
}