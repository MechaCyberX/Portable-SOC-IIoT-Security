# Portable SOC IIoT Security Briefcase
Overview
Acest proiect reprezintă implementarea unui centru de operațiuni de securitate (SOC) portabil, integrat într-o servietă tactică. Sistemul este proiectat să monitorizeze, detecteze și neutralizeze atacurile cibernetice și fizice în medii de tip Industrial IoT (IIoT).

# Arhitectura Sistemului
Ecosistemul este compus din trei noduri inteligente bazate pe procesorul ESP32-S3:

Nodul Guardian (IDPS): Unitatea centrală de analiză. Utilizează motorul Titan pentru a detecta anomalii folosind euristică Z-Score și monitorizarea jitter-ului de rețea.

Nodul Trusted (Production): Simulează un echipament industrial real (PLC). Publică date de telemetrie (temperatură, umiditate, calitatea aerului) la intervale de 5s prin MQTT securizat (TLS 8883).

Nodul Aggressor (Threat Actor): Unitate de simulare a atacurilor (DoS, Spoofing, Jamming) utilizată pentru testarea rezilienței sistemului.

# Caracteristici Cheie
Detecție Avansată: Analiză statistică în timp real pentru identificarea atacurilor de tip Data Poisoning.

Securitate Fizică: Senzor de Tamper (MC-38) cu alertă instantanee pe buzzer pasiv și feedback vizual NeoPixel.

Observabilitate: Integrare cu InfluxDB și Grafana pentru vizualizarea stocastică a riscurilor.

Autonomie: Management termic și electric optimizat prin sursă externă de capacitate mare (Ugreen 48000mAh).

# Infrastructură Tehnică (CI/CD)
Acest repository utilizează un pipeline automat de Continuous Integration prin GitHub Actions:

Automatic Build: Compilarea automată a nucleului C++ (Titan Engine).

Unit Testing: Validarea logicii de detecție folosind un set de date de test (atac de tip spoofing).

Static Analysis: Verificarea integrității codului prin flag-uri riguroase de compilare.

Deployment Awareness: Pregătirea automată a artefactelor pentru release.

#Resurse Proiect
Management Proiect: [Trello](https://trello.com/b/Ucx4Iop8/my-trello-board)
