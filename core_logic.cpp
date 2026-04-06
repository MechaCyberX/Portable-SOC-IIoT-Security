#include <vector>
#include <numeric>
#include <cmath>
#include <iostream>

// --- MOTORUL ANALITIC TITAN (CORE LOGIC) ---
// Extras din GardianNode.ino pentru validare automata in CI/CD

class TitanDetector {
public:
    // Calcul Jitter conform logicii tale din GardianNode
    float calculateJitter(const std::vector<unsigned long>& timingHistory) {
        if (timingHistory.empty()) return 0;
        float avg = std::accumulate(timingHistory.begin(), timingHistory.end(), 0.0) / timingHistory.size();
        float jitter = 0;
        for(auto t : timingHistory) jitter += std::abs((float)t - avg);
        return jitter / timingHistory.size();
    }

    // Analiza Z-Score pentru detectie Spoofing
    float calculateZScore(float val, const std::vector<float>& tempHistory) {
        if (tempHistory.size() < 5) return 0;
        float sum = std::accumulate(tempHistory.begin(), tempHistory.end(), 0.0);
        float mean = sum / tempHistory.size();
        float sq_sum = 0;
        for(float v : tempHistory) sq_sum += (v - mean) * (v - mean);
        float stdev = std::sqrt(sq_sum / tempHistory.size());
        return (stdev == 0) ? 0 : std::abs(val - mean) / stdev;
    }

    // Logica de evaluare a riscului (Thresholds)
    int evaluateRisk(float z, float jitter, bool jsonValid, float val, float mean) {
        int risk = 0;
        if (z > 3.2 && std::abs(val - mean) > 8.0) risk += 85;
        else if (z > 2.0) risk += 30;
        
        if (jitter > 3500) risk += 35;
        if (!jsonValid) risk += 75;
        
        return risk;
    }
};
