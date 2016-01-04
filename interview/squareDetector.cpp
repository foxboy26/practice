#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool squareDetector(const vector<string>& image) {
    int n = image.size();
    int count = 0;
    for (int i = 0; i < image.size(); i++)
        for (int j = 0; j < image[i].length(); j++)
            if (image[i][j] == '#') count++;

    bool found = false;
    int width = 0;
    int height = 0;
    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < n && !found; j++) {
            if (image[i][j] == '#') {
                found = true;
                int x = i, y = j;
                // find width
                while (y < n && image[i][y] == '#') {
                    y++;
                    width++;
                }
                // find height
                while (x < n && image[x][j] == '#') {
                    x++;
                    height++;
                }

                if (height != width || height * height != count) return false;

                // check square
                for (x = i; x < i + height; x++) {
                    for (y = j; y < j + width; y++) {
                        if (image[x][y] != '#') return false;
                    }
                }
            }
        }
    }

    return true;
}

int main()
{
    int T;
    int n;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        string line;
        vector<string> image;
        for (int i = 0; i < n; i++) {
            cin >> line;
            image.push_back(line);
        }

        string res = (squareDetector(image))? "YES" : "NO";
        cout << "Case #" << t << ": " << res << endl;
    }

    return 0;
}
