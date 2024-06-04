#include <iostream>
#include <vector>
using namespace std;
//three towers given, A,B,C
//rule is that the larger disk cannot be on top of the smaller disk
//candidate - smallest disk that wasn't moved on the previous move
//find the candidate, move the candidate to the first available pos ( b or c)
//if not finished, goto step 1


int main() {
    vector<int> t[3]; //three towers A,B,C represented as an array of vectors
    int n;
    cout << "Please enter the number of rings to move: ";
    cin >> n;
    cout << endl;
    int from = 0, to = 0, move = 0, candidate = 1;

    //initializing the three towers
    for (int i = n + 1; i >= 1; i--) {
        t[0].push_back(i);
    }
    t[1].push_back(n + 1);
    t[2].push_back(n + 1);

    if(n % 2 == 1) {
        to = 1;

        while (t[1].size() < n + 1) { //running as long as a tower contains all the rings
            cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from + 'A')
                 << " to tower " << char(to + 'A') << "\n";

            //Move the ring from the "from tower" to the "to tower"
            t[to].push_back(t[from].back());
            t[from].pop_back();

            // Update 'from' tower
            if (t[(to + 1) % 3].back() <
                t[(to + 2) % 3].back()) { //comparison of size of disk, if one is smaller, that is new candidate
                from = (to + 1) % 3; // after new candidate is chosen, it will move one to right of 'from' tower
            } else {
                from = (to + 2) % 3; // else, move to two to right of 'from' tower
            }

            //update candidate
            candidate = t[from].back();

            //update 'to' tower
            if (t[from].back() <
                t[(from + 1) % 3].back()) {///comparison of size of disk, if one is smaller, that is new candidate
                to = (from + 1) % 3; // Move to the tower after 'from'
            } else {
                to = (from + 2) % 3; // Move to the tower two positions after 'from'
            }
        }
    }
    if(n%2 == 0){
        to = 2;
        while (t[1].size() < n + 1) { // while t[1] does not contain all the rings
            cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";

            // Move the ring from the "from tower" to the "to tower" (first copy it, then delete it from the "from tower")
            t[to].push_back(t[from].back());
            t[from].pop_back();

            // from = the index of the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
            if (t[(to + 2) % 3].back() < t[(to + 1) % 3].back())
                from = (to + 2) % 3;
            else
                from = (to + 1) % 3;

            // candidate = the ring on top of the t[from] tower
            candidate = t[from].back();

            // to = the index of the closest tower on which the candidate can be placed: (from+1)%3 or (from+2)%3
            // (compare the candidate with the ring on the closer tower; which tower is "closer" depends on whether n is odd or even)
            if (t[(from + 2) % 3].back() < t[from].back())
                to = (from + 1) % 3;
            else
                to = (from + 2) % 3;
        }
    }
    return 0;
}
