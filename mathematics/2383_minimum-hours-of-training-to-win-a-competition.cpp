class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int energySum = 0;
        int hours = 0;        
        for (int val : energy) {
            energySum += val;
        }
        
        if (energySum >= initialEnergy) {
            hours = energySum - initialEnergy + 1;
        }
        
        auto experienceMaxId = max_element(experience.begin(), experience.end());
        
        int experienceSum = initialExperience;
        for (auto iter = experience.begin(); iter <= experienceMaxId; ++iter) {
            if (experienceSum <= *iter) {
                int diff = *iter - experienceSum + 1;
                hours += diff;
                experienceSum += diff;
            }
            experienceSum += *iter;
        }

        return hours;
        
    }
};

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int sum = 0;
        for (int e : energy) {
            sum += e;
        }
        int trainingHours = initialEnergy > sum ? 0 : sum + 1 - initialEnergy;
        for (int e : experience) {
            if (initialExperience <= e) {
                trainingHours += 1 + (e - initialExperience);
                initialExperience = 2 * e + 1;
            } else {
                initialExperience += e;
            }
        }
        return trainingHours;
    }
};
