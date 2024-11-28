//2160. Minimum Sum of Four Digit Number After Splitting Digits
/*
You are given a positive integer num consisting of exactly four digits. Split num into two new integers new1 and new2 by using the digits found in num. Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.
    For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3. Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].
Return the minimum possible sum of new1 and new2.
*/
class Solution {
public:
    int minimumSum(int num) {
        std::vector<std::pair<std::string,std::string>> perm = {{"0","123"}, {"01","23"}, {"012","3"}, {"0","132"}, {"01","32"}, {"013","2"}, {"0","213"}, {"02","13"}, {"021","3"}, {"0","231"}, {"02","31"}, {"023","1"}, {"0","312"}, {"03","12"}, {"031","2"}, {"0","321"}, {"03","21"}, {"032","1"}, {"1","023"}, {"10","23"}, {"102","3"}, {"1","032"}, {"10","32"}, {"103","2"}, {"1","203"}, {"12","03"}, {"120","3"}, {"1","230"}, {"12","30"}, {"123","0"}, {"1","302"}, {"13","02"}, {"130","2"}, {"1","320"}, {"13","20"}, {"132","0"}, {"2","013"}, {"20","13"}, {"201","3"}, {"2","031"}, {"20","31"}, {"203","1"}, {"2","103"}, {"21","03"}, {"210","3"}, {"2","130"}, {"21","30"}, {"213","0"}, {"2","301"}, {"23","01"}, {"230","1"}, {"2","310"}, {"23","10"}, {"231","0"}, {"3","012"}, {"30","12"}, {"301","2"}, {"3","021"}, {"30","21"}, {"302","1"}, {"3","102"}, {"31","02"}, {"310","2"}, {"3","120"}, {"31","20"}, {"312","0"}, {"3","201"}, {"32","01"}, {"320","1"}, {"3","210"}, {"32","10"}, {"321","0"}};
	
	std::map<char,int> chr2num{};
	chr2num['0'] = 0;
	chr2num['1'] = 1;
	chr2num['2'] = 2;
	chr2num['3'] = 3;
	
	
	
	
	std::vector<int> data = digits(num);
	
	for(auto& x: data)
			std::cout << x << ' ';
		
		std::cout << '\n';
	int min,j = 0;
	
	for(auto& p : perm)
	{
		int size = p.first.length();
		//std::cout << "size = " << size << '\n';
		//std::cout << p.first << '\n';
		int d1{0};
		int m = 1;
		for(int i = size - 1;i >= 0;i--)
		{
			//std::cout << "i = " << i << ' ' << data[chr2num[p.first[i]]] << '\n';
			
			d1 += data[chr2num[p.first[i]]]*m;
			m = m*10;
		}
		
		//std::cout << d1 << '\n';
		
		size = p.second.length();
		//std::cout << "size = " << size << '\n';
		//std::cout << "second = " << p.second << '\n';
		int d2{0};
		m = 1;
		for(int i = size - 1;i >= 0;i--)
		{
			//std::cout << "i = " << i << ' ' << data[chr2num[p.first[i]]] << '\n';
			
			d2 += data[chr2num[p.second[i]]]*m;
			m = m*10;
		}
		
		//std::cout << d2 << '\n';
		
		if(0 == j)
			min = d1 + d2;
		else
		{
			if(min > (d1 + d2))
				min = d1 + d2;
		}
		j++;	
		
		//std::cout << "j = " << j << " d1 = " << d1 << " d2 = " << d2 << " sum = " << d1 + d2 << " min = " << min << '\n';
	}
	
	return min;
    }

    std::vector<int> digits(int a)
{
	std::vector<int> d{};
	
	while(a != 0)
	{
		int r = a % 10;
		d.insert(d.begin(),r);
		a = (a-r)/10;
	}
	
	return d;
}
};
