#include <cstring>
#include <iostream>
#include <deque>
using namespace std;

bool is_palin(string s) {
    int li = 0, ri = s.size() - 1;
    while (li < ri) {
        if (s[li++] != s[ri--])
            return false;
    }
    return true;
}

pair<int, int> getMaxPalin(string s) {
    int max_index = -1;
    int max_len = 0;
    
    int ri = s.size();
    while (ri >= 1) {
        int li = 0;
        while (li < ri) {
            if (((ri - li) > max_len) && is_palin(s.substr(li, ri - li))) {
                max_index = li;
                max_len = ri - li;
                break;
            }
            li++;
        }
        ri--;
    }
    return make_pair(max_index, max_len);
}

string longestPalindrome(string s) {
    if (is_palin(s))
        return s;
    else {
        pair<int, int> max = getMaxPalin(s);
        int start = max.first;
        int length = max.second;
        if (start == -1 && length == 1)
            return "";
        else {
            return s.substr(start, length);
        }
    }
}

int main() {

    string str = "cyyoacmjwjubfkzrrbvquqkwhsxvmytmjvbborrtoiyotobzjmohpadfrvmxuagbdczsjuekjrmcwyaovpiogspbslcppxojgbfxhtsxmecgqjfuvahzpgprscjwwutwoiksegfreortttdotgxbfkisyakejihfjnrdngkwjxeituomuhmeiesctywhryqtjimwjadhhymydlsmcpycfdzrjhstxddvoqprrjufvihjcsoseltpyuaywgiocfodtylluuikkqkbrdxgjhrqiselmwnpdzdmpsvbfimnoulayqgdiavdgeiilayrafxlgxxtoqskmtixhbyjikfmsmxwribfzeffccczwdwukubopsoxliagenzwkbiveiajfirzvngverrbcwqmryvckvhpiioccmaqoxgmbwenyeyhzhliusupmrgmrcvwmdnniipvztmtklihobbekkgeopgwipihadswbqhzyxqsdgekazdtnamwzbitwfwezhhqznipalmomanbyezapgpxtjhudlcsfqondoiojkqadacnhcgwkhaxmttfebqelkjfigglxjfqegxpcawhpihrxydprdgavxjygfhgpcylpvsfcizkfbqzdnmxdgsjcekvrhesykldgptbeasktkasyuevtxrcrxmiylrlclocldmiwhuizhuaiophykxskufgjbmcmzpogpmyerzovzhqusxzrjcwgsdpcienkizutedcwrmowwolekockvyukyvmeidhjvbkoortjbemevrsquwnjoaikhbkycvvcscyamffbjyvkqkyeavtlkxyrrnsmqohyyqxzgtjdavgwpsgpjhqzttukynonbnnkuqfxgaatpilrrxhcqhfyyextrvqzktcrtrsbimuokxqtsbfkrgoiznhiysfhzspkpvrhtewthpbafmzgchqpgfsuiddjkhnwchpleibavgmuivfiorpteflholmnxdwewj"; 
    string palin;

    palin = longestPalindrome(str);
    cout << palin << endl;
}