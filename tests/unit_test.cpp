#include <cassert>
#include <iostream>
#include <vector>
#include "../core_logic.cpp"

int main() {
    TitanDetector detector;
    // Cream un istoric de temperaturi normale (baseline)
    std::vector<float> history = {23.5, 24.1, 23.8, 24.5, 24.0, 23.9}; 
    
    // Simulam valoarea de atac de 95.5°C
    float attackVal = 95.5;
    float z = detector.calculateZScore(attackVal, history);
    
    // Calculam media pentru evaluarea riscului
    float sum = 0;
    for(float v : history) sum += v;
    float mean = sum / history.size();

    // Evaluam riscul (cu jitter 0 si JSON valid pentru acest test)
    int risk = detector.evaluateRisk(z, 0, true, attackVal, mean);
    
    std::cout << "--- Titan Logic Test ---" << std::endl;
    std::cout << "Valoare testata: " << attackVal << " C" << std::endl;
    std::cout << "Z-Score calculat: " << z << std::endl;
    std::cout << "Scor de Risc: " << risk << std::endl;
    
    // Testul trece daca riscul este peste pragul critic de 70
    assert(risk >= 70); 
    
    std::cout << "REZULTAT: Atacul a fost detectat cu succes!" << std::endl;
    return 0;
}
