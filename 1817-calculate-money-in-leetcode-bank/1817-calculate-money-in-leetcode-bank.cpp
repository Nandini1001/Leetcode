class Solution {
public:
    int totalMoney(int n) {
        // int fullweeks=n/7;
        // int remdays=n%7;
        // int sum_1week=(7*(8))/2;
        // int money_lastmon=fullweeks+1;
        // int fullweekremsum=((fullweeks-1)*fullweeks)/2;
        // int fullweeksum=fullweeks*sum_1week+7*fullweekremsum;
        // int money_lastday=money_lastmon+remdays-1;
        // int remdaysum=(money_lastday*(money_lastday+1))/2 - 
        // ((money_lastmon-1)*(money_lastmon))/2;
        // return fullweeksum+remdaysum;


        int fullWeeks = n / 7;
        int remainingDays = n % 7;

        // Sum for all full weeks
        int fullWeeksSum = 28 * fullWeeks + 7 * (fullWeeks * (fullWeeks - 1)) / 2;

        // Sum for remaining days (arithmetic progression)
        int remainingSum = (remainingDays * (2 * fullWeeks + 1 + remainingDays)) / 2;

        return fullWeeksSum + remainingSum;
    }
};


//line6=28
//line8=(fullWeeks * (fullWeeks - 1)) / 2
//fullweeksum is same but in remdaysum can be done using AP
// If there are remainingDays after the full weeks,
// the money deposited on those days will be:
// (fullWeeks+1),(fullWeeks+2),…,(fullWeeks+remainingDays)
// This is an arithmetic progression (AP) with:
// first term \U0001d44e=\U0001d453\U0001d462\U0001d459\U0001d459\U0001d44a\U0001d452\U0001d452\U0001d458\U0001d460+1
// last term l=\U0001d453\U0001d462\U0001d459\U0001d459\U0001d44a\U0001d452\U0001d452\U0001d458\U0001d460+remainingDays
// number of terms n=remainingDays
// Recall the sum formula for an arithmetic progression
// S=n(a+l)/2