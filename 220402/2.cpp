#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct coordinate {
    int x = 0;
    int y = 0;
};

coordinate getEnd(string route){
    coordinate end;
    end.y = route.size();
    for (int i = 0; i < route.size(); i++){
        char c = route[i];
        if (c == 'B')
            end.x--;
        else
            end.x++;
    }
    return end;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    coordinate aladar = getEnd(s);
    cin >> s;
    coordinate bela = getEnd(s);
    int farthest = max(aladar.y, bela.y);
    int distance = abs(aladar.x - bela.x);
    distance = distance - abs(aladar.y - bela.y);

    int lazier = min(aladar.y, bela.y);
    int row = lazier - (distance / 2);

    cout << row + 1;
    cout << endl;
}