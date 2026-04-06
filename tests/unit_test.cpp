#include <cassert>
#include <iostream>
#include "../core_logic.cpp"

int main() {
    // Testam valoarea de atac de 95.5 pe care o foloseste Aggressor-ul
    float z = calculateZScore(95.5, 24.0, 2.0);
    int risk = evaluateRisk(z, true);
    
    std::cout << "Testing Attack Detection: Z-Score = " << z << ", Risk = " << risk << std::endl;
    
    assert(risk >= 70); // Testul trece daca riscul e peste pragul critic
    std::cout << "Unit Test PASSED: Spoofing correctly identified!" << std::endl;
    return 0;
}
