class Solution {
public:
    int totalMoney(int n) {
        int fullweeks=n/7;
        int remdays=n%7;
        int sum_1week=(7*(8))/2;
        int money_lastmon=fullweeks+1;
        int fullweekremsum=((fullweeks-1)*fullweeks)/2;
        int fullweeksum=fullweeks*sum_1week+7*fullweekremsum;
        int money_lastday=money_lastmon+remdays-1;
        int remdaysum=(money_lastday*(money_lastday+1))/2 - 
        ((money_lastmon-1)*(money_lastmon))/2;
        return fullweeksum+remdaysum;
    }
};