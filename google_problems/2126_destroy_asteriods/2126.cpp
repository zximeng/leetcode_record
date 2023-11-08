//just sort it and add would solve it easily
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

// not the best/correct answer, only beats 22% ?


