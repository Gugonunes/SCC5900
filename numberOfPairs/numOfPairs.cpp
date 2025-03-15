#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int arrLen, target;
    cin >> arrLen >> target;
    vector<int> arr(arrLen);

    for (int i = 0; i<arrLen; i++) {
        cin >> arr[i];
    }

    // lógica principal
    map<int, int> compMap;
    int cont=0;
    for (int i=0; i < arrLen; i++) {
        int comp = target - arr[i];
        if (compMap.find(comp) != compMap.end()) {
            cont += compMap[comp];
        }
        compMap[arr[i]]++;
    }
    cout << cont << endl;

    return 0;
}