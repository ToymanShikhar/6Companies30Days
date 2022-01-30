class Solution {
   public:
    double r;
    double x;
    double y;

    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }

    double random() {
        return (rand() / (double)RAND_MAX);
    }

    vector<double> randPoint() {
        vector<double> res(2);
        double theta = random() * (2 * M_PI);
        double len = r * sqrt(random());

        res[0] = x + (len * cos(theta));
        res[1] = y + (len * sin(theta));

        return res;
    }
};