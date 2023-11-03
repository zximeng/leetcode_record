class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long newMass = mass;

        for(int i = 0; i < asteroids.size(); i++)
        {
           if (newMass < asteroids[i]) {
               return false;
           } else {
               newMass += asteroids[i]; 
           }  
        }
        return true;
        
    }
};