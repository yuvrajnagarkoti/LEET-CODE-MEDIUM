class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> forces(n, 0);

        // Left to right pass (apply rightward forces)
        int force = 0;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') force = n;
            else if (dominoes[i] == 'L') force = 0;
            else force = max(force - 1, 0);
            forces[i] += force;
        }

        // Right to left pass (apply leftward forces)
        force = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') force = n;
            else if (dominoes[i] == 'R') force = 0;
            else force = max(force - 1, 0);
            forces[i] -= force;
        }

        // Build final state
        string result;
        for (int f : forces) {
            if (f > 0) result += 'R';
            else if (f < 0) result += 'L';
            else result += '.';
        }

        return result;
    }
};
