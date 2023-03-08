#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops, int n) {
    // write your code here
    int numberOfStops = 0;
    stops.push_back(dist);
    int temp = 0;    //index of starts
    
    int left, right = 0;
    while(right < dist){
        if(numberOfStops == 0){
            left = 0;
            right = left + tank;
        }
        else{
            left = stops[temp];
            right = left + tank;
        }
        
        if(left < dist)
            numberOfStops++;
        
        if(stops[temp + 1] - stops[temp] > tank)
            return -1;
        
        for(int i = temp; stops[i] <= right; i++)
                temp = i;
        
    }
    
    return numberOfStops - 1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops, n) << "\n";

    return 0;
}
