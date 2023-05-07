#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Pixel {
    int x;
    int y;
    int brightness;
    Pixel() {}
    Pixel(int x, int y) : x(x), y(y) {}
};

struct Group {
    vector<Pixel> pixels;
    int minBrightness;
    int maxBrightness;
};

int main() {
    int columns, rows;
    cin >> rows >> columns;

    vector<Pixel> pixels(columns * rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            Pixel pixel(j, i);
            cin >> pixel.brightness;
            pixels[i * columns + j] = pixel;
        }
    }

    // sort by brightness
    sort(pixels.begin(), pixels.end(), [](Pixel a, Pixel b) {
        return a.brightness < b.brightness;
        });

    // group neighbours that are max 1 apart
    vector<Group> groups;
    groups.push_back(Group());
    groups[0].pixels.push_back(pixels[0]);
    int currentGroup = 0;
    for (int i = 1; i < pixels.size(); i++)
    {
        if (pixels[i].brightness - pixels[i - 1].brightness <= 1)
        {
            groups[currentGroup].pixels.push_back(pixels[i]);
        }
        else
        {
            currentGroup++;
            groups.push_back(Group());
            groups[currentGroup].pixels.push_back(pixels[i]);
            groups[currentGroup].minBrightness = pixels[i].brightness;
        }
        groups[currentGroup].maxBrightness = pixels[i].brightness;
    }
    cout << groups.size() << endl;

    // max number of different brightness values in a group
    Group largestGroup;
    int largestSize = 0;
    for (int i = 0; i < groups.size(); i++)
    {
        int size = groups[i].maxBrightness - groups[i].minBrightness + 1;
        if (largestSize < size) {
            largestSize = size;
            largestGroup = groups[i];
        }
    }
    cout << largestGroup.maxBrightness - largestGroup.minBrightness + 1 << endl;

    Pixel first = largestGroup.pixels[0];
    int x0 = first.x, y0 = first.y, x1 = first.x, y1 = first.y;

    for (int i = 0; i < largestGroup.pixels.size(); i++) {
        Pixel pixel = largestGroup.pixels[i];
        x0 = min(x0, pixel.x);
        y0 = min(y0, pixel.y);
        x1 = max(x1, pixel.x);
        y1 = max(y1, pixel.y);
    }

    cout << y0 + 1 << " " << x0 + 1 << " " << y1 + 1 << " " << x1 + 1;
    cout << endl;
}