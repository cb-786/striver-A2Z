class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        for(const long long &ele : asteroids) {
            if(mass >= ele) {
                mass += ele;
            }
            else return 0;
        }
        return 1;
    }
};