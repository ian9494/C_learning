#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    // 建構子
    Date(int m, int d, int y) {
        setMonth(m);
        setDay(d);
        setYear(y);
    }

    // 月份 setter + 檢查
    void setMonth(int m) {
        if (m >= 1 && m <= 12)
            month = m;
        else {
            cout << "[警告] 月份錯誤，自動設定為1" << endl;
            month = 1;
        }
    }

    // 日期 setter，會依照自訂規則檢查合法性
    void setDay(int d) {
        int maxDay = getMaxDays(month);
        if (d >= 1 && d <= maxDay)
            day = d;
        else {
            cout << "[警告] 日期不合法，設定為1" << endl;
            day = 1;
        }
    }

    // 年份 setter
    void setYear(int y) {
        if (y >= 1000 && y <= 9999)
            year = y;
        else {
            cout << "[警告] 年份不是四位數，設定為2024" << endl;
            year = 2024;
        }
    }

    // Getter
    int getMonth() { return month; }
    int getDay() { return day; }
    int getYear() { return year; }

    // 顯示日期格式 mm/dd/yyyy
    void displayDate() {
        cout << month << "/" << day << "/" << year << endl;
    }

private:
    // 根據題目規則判斷每月最大天數
    int getMaxDays(int m) {
        if (m == 2) return 29;
        else if (m >= 1 && m <= 7) {
            return (m % 2 == 1) ? 31 : 30;
        } else {
            return (m % 2 == 1) ? 30 : 31;
        }
    }
};

int main() {
    int m, d, y;
    cout << "請輸入年（4位數）月 日：";
    cin >> y >> m >> d;

    // 建立物件 + 自動驗證
    Date myDate(m, d, y);

    cout << "你輸入的日期是：";
    myDate.displayDate();

    return 0;
}
