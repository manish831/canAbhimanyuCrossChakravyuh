#include <iostream>
#include <vector>
using namespace std;

bool canAbhimanyuCrossChakravyuh(int p, vector<int>& enemies, int a, int b) {
    int skipsAvailable = a;         // Skips available
    int rechargesRemain = b;        // Recharges available
    int currentPower = p;           // Abhimanyu's current power

    for (int i = 0; i < 11; i++) {
        if (i == 2 || i == 6) {     // Special case for k3 and k7
            if (currentPower >= enemies[i]) {
                currentPower -= enemies[i];  // Battle and lose power
                int regeneratedPower = enemies[i] / 2;  // Regenerated power

                if (currentPower < regeneratedPower) {
                    // Attack from behind
                    if (skipsAvailable > 0) {
                        skipsAvailable--;  // Use a skip
                    } else if (rechargesRemain > 0) {
                        rechargesRemain--;  // Use a recharge to restore full power
                        currentPower = p;
                    } else {
                        return false;  // Abhimanyu loses
                    }
                }
            } else {
                // Not enough power to defeat k3 or k7 enemy
                if (skipsAvailable > 0) {
                    skipsAvailable--;  // Use a skip
                } else if (rechargesRemain > 0) {
                    rechargesRemain--;  // Use a recharge to restore full power
                    currentPower = p;
                } else {
                    return false;  // Abhimanyu loses
                }
            }
        } else {
            // For all other enemies
            if (currentPower >= enemies[i]) {
                currentPower -= enemies[i];  // Battle and lose power
            } else {
                // Not enough power to defeat the enemy
                if (skipsAvailable > 0) {
                    skipsAvailable--;  // Use a skip
                } else if (rechargesRemain > 0) {
                    rechargesRemain--;  // Use a recharge to restore full power
                    currentPower = p;
                } else {
                    return false;  // Abhimanyu loses
                }
            }
        }
    }

    return true;  // Abhimanyu successfully crosses all circles
}

int main() {
    // Test case 1
    int p1 = 10;
    vector<int> enemies1 =  {0, 10, 2, 3, 9, 5, 6, 7, 8, 4, 1};
    int a1 = 6;
    int b1 = 2;

    if (canAbhimanyuCrossChakravyuh(p1, enemies1, a1, b1)) {
        cout << "Abhimanyu can cross the Chakravyuh.\n";
    } else {
        cout << "Abhimanyu cannot cross the Chakravyuh.\n";
    }

    // Test case 2
    int p2 = 50;
    vector<int> enemies2 = {15, 25, 35, 45, 55, 65, 75, 85, 95, 105, 115};
    int a2 = 1;  
    int b2 = 1;  

    if (canAbhimanyuCrossChakravyuh(p2, enemies2, a2, b2)) {
        cout << "Abhimanyu can cross the Chakravyuh.\n";
    } else {
        cout << "Abhimanyu cannot cross the Chakravyuh.\n";
    }
    return 0;
}

