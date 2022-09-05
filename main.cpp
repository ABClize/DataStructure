#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // visualize `myGraphJson`!
    string myGraphJson = "{\"kind\":{\"graph\":true},"
                         "\"nodes\":[{\"id\":\"12\"},{\"id\":\"2\"}],"
                         "\"edges\":[{\"from\":\"12\",\"to\":\"2\"}]}";
    string nihao="{\"kind\": { \"graph\": true },"
    "\"nodes\":["
        "{\"id\":\"1\",\"label\":\"1\"},"
        "{\"id\":\"2\",\"label\":\"2\",\"color\":\"orange\"},"
        "{\"id\":\"3\",\"label\":\"3\"}],"
    "\"edges\":["
        "{\"from\":\"1\",\"to\":\"2\",\"color\":\"red\"},"
        "{\"from\":\"1\",\"to\":\"3\"}]}";
    cout << myGraphJson;
    cout<<nihao;
    return 0;
}