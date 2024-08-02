#include <bits/stdc++.h>
using namespace std;
void distributeApples(vector<int>& apples, vector<int>& payments) {
    int totalPayment = payments[0] + payments[1] + payments[2];
    vector<double> proportions(3);
    for (int i = 0; i < 3; ++i) {
        proportions[i] = payments[i] / totalPayment;
    }
    vector<int> idealCounts(3);
    int totalApples = apples.size();
    for (int i = 0; i < 3; i++) {
        idealCounts[i] = proportions[i] * totalApples;
    }
    while (accumulate(idealCounts.begin(), idealCounts.end(), 0) < totalApples) {
        for (int i = 0; i < 3; ++i) {
            if (accumulate(idealCounts.begin(), idealCounts.end(), 0) < totalApples) {
                idealCounts[i]++;
            } else {
                break;
            }
        }
    }
    vector<vector<int>> distribution(3);
    int appleIndex = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < idealCounts[i]; ++j) {
            if (appleIndex < totalApples) {
                distribution[i].push_back(apples[appleIndex]);
                appleIndex++;
            }
        }
    }
    string names[] = {"Ram", "Sham", "Rahim"};
    for (int i = 0; i < 3; i++) {
        int totalWeight = accumulate(distribution[i].begin(), distribution[i].end(), 0);
        cout << names[i] << ": ";
        for (int weight : distribution[i]) {
            cout << weight << "g ";
        }
        cout << "(Total: " << totalWeight << "g)" << endl;
    }
}
int main() {
	// your code goes here
	vector<int>arr;
	bool flag = 1;
    while(flag){
         int a = 0;
         cout<<"Enter apple weight in gram (-1 to stop ) :";
         cin>>a;
         arr.push_back(a);
         if(a == -1){
            break;
         }
    }
   
    vector<int>w = {50,30,20};
    distributeApples(arr,w);
}