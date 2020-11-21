#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;
#define START_YEAR 1971
#define DAYS_IN_NON_LEAP_YEAR 365
#define DAYS_IN_LEAP_YEAR 366

// Q23 : https://leetcode.com/problems/day-of-the-week/
class Q23 {
public:
	static string get_day(int n) {
		switch (n) {
		case 0: return "Friday";// 1st Jan 1971 was a Friday. Hence taking it as reference
		case 1: return "Saturday";
		case 2: return "Sunday";
		case 3: return "Monday";
		case 4: return "Tuesday";
		case 5: return "Wednesday";
		case 6: return "Thursday";		
		}
		return "Invalid";
	}	
	static int get_days_in_month(int n) {
		switch (n) {
		case 1: return 31;
		case 2: return 28;
		case 3: return 31;
		case 4: return 30;
		case 5: return 31;
		case 6: return 30;
		case 7: return 31;
		case 8: return 31;
		case 9: return 30;
		case 10: return 31;
		case 11: return 30;
		case 12: return 31;
		}
		return -1;
	}
	static bool is_leap_year(int year) {
		if (year % 400 == 0) {
			return  true;
		}
		else if (year % 100 == 0) {
			return false;
		}
		else if (year % 4 == 0) {
			return true;
		}
		return false;
	}
	static int number_of_leap_years_before(int year) {
		int c = 0;
		for (int i = START_YEAR; i < year; i++) {
			if (is_leap_year(i)) {
				c++;
			}
		}
		return c;
	}
	static int days_int_current_year(int day, int month, int year) {
		int days = 0;
		int months = 1;
		
		while (months < month) {
			days += get_days_in_month(months);
			months++;
		}
		days += (day-1);
		if (month > 2) {
			if (is_leap_year(year)) {
				days++;
			}
		}
		return days;
	}
	static string dayOfTheWeek(int day, int month, int year) {
		if (month > 12 || month < 1) {
			return "Invalid Date";
		}
		else if (month == 2) {
			if (day > (get_days_in_month(month)+ 1) || day < 1) {
				return "Invalid Date";
			}
		}
		else if (day > get_days_in_month(month) || day < 1) {
			return "Invalid Date";
		}
			
		int leap_count = number_of_leap_years_before(year);
		int non_leap_count = year - START_YEAR - leap_count;
		int non_leap_days = non_leap_count * DAYS_IN_NON_LEAP_YEAR;
		int leap_days = leap_count * DAYS_IN_LEAP_YEAR;
		int total_days = non_leap_days + leap_days;

		/* Still need to include the final year */
		int days_in_cur_year = days_int_current_year(day, month, year);
		total_days += days_in_cur_year;
		int today = total_days % 7;
		return get_day(today);

	}
	static void init() {
		auto res = Q23::dayOfTheWeek(30, 9 , 2100);
		cout << "Result : " << res << endl;
	}
};