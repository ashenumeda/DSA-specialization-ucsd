#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    stops.push_back(dist);

    int position = 0;
    int fillings = 0;
    int current_stop = 0;
    int last_stop = 0;

    while (dist - position > tank) {

        while (current_stop < stops.size() && stops[current_stop] - position <= tank) {
            last_stop = current_stop;
            current_stop++;
        }

        if (stops[current_stop] - stops[last_stop] > tank) {
            return -1;
        }

        position = stops[last_stop];
        fillings++;
    }

    return fillings; 
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

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
