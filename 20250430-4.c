#include <stdio.h>
#include <string.h>


// 瑪雅月曆對照表
const char* haab_months[] = {
    "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",
    "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
};

const char* tzolkin_names[] = {
    "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",
    "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
};

int get_haab_month_index(const char* month) {
    for (int i = 0; i < 19; i++) {
        if (strcmp(month, haab_months[i]) == 0)
            return i;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    
    for (int i = 0; i < n; i++) {
        int day, year;
        char dot;
        char haab_month[20];
        scanf("%d%c %s %d", &day, &dot, haab_month, &year);

        // 換算曆法日期
        int haab_index = get_haab_month_index(haab_month);
        int total_days = year * 365 + haab_index * 20 + day;

        int tzolkin_day_num = total_days % 13 + 1;
        int tzolkin_name_index = total_days % 20;
        int tzolkin_year = total_days / 260;

        printf("%d %s %d\n", tzolkin_day_num, tzolkin_names[tzolkin_name_index], tzolkin_year);
    }

    return 0;
}
