#include <iostream>
using namespace std;
class day{
	private:
		int year;
		int month;
		int day;
	public:
		int set(int y, int m, int d){
			year = y;
			month = m;
			day = d;
		}
		int calc_day_num(int y,int m){
			if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
				return 31;
			}else if(m==4 || m==6 || m==9 || m==11){
				return 30;
			}else if(is_yoon(y)==1){
				return 29;
			}
			else{
				return 28;
			}
		}
		int is_yoon(int y){
			if(y%4==0){
				if(y%100==0 && y%400!=0){
					return 0;
				}
				else{
					return 1;
				}
			}
			return -1;
		}
		String out_day(int num){
			String result = "";
			switch(day_num){
				case 0:
					result = "일";
					break;
				case 1:
					result = "월";
					break;
				case 2:
					result = "화";
					break;
				case 3:
					result = "수";
					break;
				case 4:
					result = "목";
					break;
				case 5:
					result = "금";
					break;
				case 6:
					result = "토";
					break;
				default:
					result = "erro";
					break;
			}
	
			return result;
		}
		
		String calc_day(){
			int temp = 0;
			if(year>=2020){
				for(int i=2020;i<year;i++){
					if(is_yoon(i)==1){
						temp+=366;
					}else{
						temp+=365;
					}
				}
				for(int i=1;i<month;i++){
					temp += calc_day_num(year,i);
				}
				temp += day-1+3;
				temp = temp%7;
			}else{
				for(int i=year;i<2020-1;i++){
					if(is_yoon(i)==1){
						temp+=366;
					}else{
						temp+=365;
					}
				}
				int day_temp = 0;
				for(int i=1;i<month;i++){
					day_temp += calc_day_num(2019,i);
				}
				temp += (365-day_temp);
				temp += (calc_day_num(2019,month)-day+3);
				temp = temp%7;
			}

			return out_day(temp);
		}
	
};
int main(){
	day d;
	d.set(1996,6,3);
	cout << d.calc_day() << endl;
	
	return 0;
}