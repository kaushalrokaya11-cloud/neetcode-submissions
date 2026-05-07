class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int> ogmap, freq;
        int l = 0, r;

        for (r = 0; r < s1.length(); r++) {
            ogmap[s1[r]]++;
        }

        for (r = 0; r < s2.length(); r++) {

            cout << "\n--- Iteration r = " << r << " ---\n";
            cout << "Window before: [" << l << ", " << r << "]\n";
            cout << "Char = " << s2[r] << "\n";

            if (!ogmap.count(s2[r])) {
                cout << "Case: char not in ogmap\n";
                while(l<=r){
                    if(ogmap.count(s2[l])){
                        freq[s2[l]]--;

                    }
                    l=l+1;
                }
            }

           
            
            else {
                cout << "Case: normal increment\n";
                freq[s2[r]]++;
                 if (ogmap.count(s2[r]) && ogmap[s2[r]] < freq[s2[r]]) {
                cout << "Case: char count exceeded\n";
                
                while (freq[s2[r]] > ogmap[s2[r]]) {
                    freq[s2[l]]--;
                    l++;
                }
            }
            }

            cout << "Window after: [" << l << ", " << r << "]\n";
            cout << "Window size: " << (r - l + 1) << "\n";

            cout << "freq map:\n";
            for (auto &p : freq) {
                cout << p.first << " : " << p.second << "\n";
            }

            if (r - l + 1 == s1.length()) {
                cout << "Window size matches s1 length\n";
                
                return true;
                cout<<s2.substr(l,r-l+1);
            }
        }
        cout<<s2.substr(l,r-l+1);
        return false;
    }
};