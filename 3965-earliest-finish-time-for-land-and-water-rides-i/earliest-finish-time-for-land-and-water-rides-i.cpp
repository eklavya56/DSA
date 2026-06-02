class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int ans = INT_MAX;

        for(int i = 0; i < landStartTime.size(); i++) {

            for(int j = 0; j < waterStartTime.size(); j++) {

                // Land -> Water
                int landFinish =
                    landStartTime[i] + landDuration[i];

                int waterStart =
                    max(landFinish, waterStartTime[j]);

                int finish1 =
                    waterStart + waterDuration[j];

                ans = min(ans, finish1);

                // Water -> Land
                int waterFinish =
                    waterStartTime[j] + waterDuration[j];

                int landStart =
                    max(waterFinish, landStartTime[i]);

                int finish2 =
                    landStart + landDuration[i];

                ans = min(ans, finish2);
            }
        }

        return ans;
    }
};