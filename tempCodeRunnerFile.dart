#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct ClassInterval {
    double lowerLimit;
    double upperLimit;
    int frequency;
};

double calculateMidpoint(const ClassInterval& interval) {
    return (interval.lowerLimit + interval.upperLimit) / 2.0;
}

double calculateMean(const vector<ClassInterval>& intervals) {
    double totalFrequency = 0;
    double totalSum = 0;
    for (const auto& interval : intervals) {
        double midpoint = calculateMidpoint(interval);
        totalSum += midpoint * interval.frequency;
        totalFrequency += interval.frequency;
    }
    return totalSum / totalFrequency;
}

double calculateMedian(const vector<ClassInterval>& intervals) {
    int totalFrequency = 0;
    for (const auto& interval : intervals) {
        totalFrequency += interval.frequency;
    }
    int cumulativeFrequency = 0;
    double medianClassLowerLimit = 0;
    int medianClassFrequency = 0;
    double medianClassWidth = 0;
    for (const auto& interval : intervals) {
        cumulativeFrequency += interval.frequency;
        if (cumulativeFrequency >= totalFrequency / 2.0) {
            medianClassLowerLimit = interval.lowerLimit;
            medianClassFrequency = interval.frequency;
            medianClassWidth = interval.upperLimit - interval.lowerLimit;
            cumulativeFrequency -= interval.frequency;
            break;
        }
    }
    return medianClassLowerLimit + ((totalFrequency / 2.0 - cumulativeFrequency) / medianClassFrequency) * medianClassWidth;
}

double calculateMode(const vector<ClassInterval>& intervals) {
    int modeIndex = 0;
    int maxFrequency = intervals[0].frequency;
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].frequency > maxFrequency) {
            maxFrequency = intervals[i].frequency;
            modeIndex = i;
        }
    }
    double modeClassLowerLimit = intervals[modeIndex].lowerLimit;
    double modeClassWidth = intervals[modeIndex].upperLimit - intervals[modeIndex].lowerLimit;
    int f1 = intervals[modeIndex].frequency;
    int f0 = (modeIndex > 0) ? intervals[modeIndex - 1].frequency : 0;
    int f2 = (modeIndex < intervals.size() - 1) ? intervals[modeIndex + 1].frequency : 0;
    return modeClassLowerLimit + (double(f1 - f0) / (2 * f1 - f0 - f2)) * modeClassWidth;
}

double calculateQuartile(const vector<ClassInterval>& intervals, double quartile) {
    int totalFrequency = 0;
    for (const auto& interval : intervals) {
        totalFrequency += interval.frequency;
    }
    int cumulativeFrequency = 0;
    double quartileClassLowerLimit = 0;
    int quartileClassFrequency = 0;
    double quartileClassWidth = 0;
    for (const auto& interval : intervals) {
        cumulativeFrequency += interval.frequency;
        if (cumulativeFrequency >= quartile * totalFrequency) {
            quartileClassLowerLimit = interval.lowerLimit;
            quartileClassFrequency = interval.frequency;
            quartileClassWidth = interval.upperLimit - interval.lowerLimit;
            cumulativeFrequency -= interval.frequency;
            break;
        }
    }
    return quartileClassLowerLimit + ((quartile * totalFrequency - cumulativeFrequency) / quartileClassFrequency) * quartileClassWidth;
}

double calculateStdDev(const vector<ClassInterval>& intervals, double mean) {
    double totalFrequency = 0;
    double varianceSum = 0;
    for (const auto& interval : intervals) {
        double midpoint = calculateMidpoint(interval);
        varianceSum += interval.frequency * pow(midpoint - mean, 2);
        totalFrequency += interval.frequency;
    }
    return sqrt(varianceSum / totalFrequency);
}

double calculateCV(double stdDev, double mean) {
    return (stdDev / mean) * 100;
}

int main() {
    vector<ClassInterval> intervals = {
        {0, 10, 5},
        {10, 20, 8},
        {20, 30, 12},
        {30, 40, 15},
        {40, 50, 10}
    };

    double mean = calculateMean(intervals);
    double median = calculateMedian(intervals);
    double mode = calculateMode(intervals);
    double Q1 = calculateQuartile(intervals, 0.25);
    double Q2 = median;
    double Q3 = calculateQuartile(intervals, 0.75);
    double stdDev = calculateStdDev(intervals, mean);
    double cv = calculateCV(stdDev, mean);

    cout << "Mean: " << mean << endl;
    cout << "Median: " << median << endl;
    cout << "Mode: " << mode << endl;
    cout << "Q1 (25th Percentile): " << Q1 << endl;
    cout << "Q2 (Median / 50th Percentile): " << Q2 << endl;
    cout << "Q3 (75th Percentile): " << Q3 << endl;
    cout << "Standard Deviation: " << stdDev << endl;
    cout << "Coefficient of Variation: " << cv << "%" << endl;

    return 0;
}
