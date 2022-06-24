class Solution {
public:
    string addBinary(string a, string b) {
 
        string ans= "";
        int carry=0;
        int n= a.length()-1;
        int m= b.length()-1;
        while(n>=0||m>=0||carry!=0)
        {
            if(m>=0)
            {
            carry=  carry+( b[m]- '0');
                m--;
            }
            if(n>=0)
            {
                carry= carry+ (a[n]-'0');
                    n--;
            }
          
           ans= ans+ (to_string(carry%2) );
            carry= carry/2;
       
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};







class Solution {
public:
    string addBinary(string a, string b) {
        string binary_string;
        if (a.empty()) return b;
        if (b.empty()) return a;
        int temporary_sum, binary_digit_to_carry = 0, a_digit_pointer = a.size()-1, b_digit_pointer = b.size()-1;
        while (a_digit_pointer >= 0 || b_digit_pointer >= 0) {
            temporary_sum = binary_digit_to_carry;
            if (a_digit_pointer >= 0) temporary_sum = temporary_sum + a.at(a_digit_pointer) - '0';
            if (b_digit_pointer >= 0) temporary_sum = temporary_sum + b.at(b_digit_pointer) - '0';
            binary_digit_to_carry = temporary_sum / 2;
            binary_string = binary_string + to_string(temporary_sum % 2);
            a_digit_pointer --;
            b_digit_pointer --; }
        if (binary_digit_to_carry != 0) binary_string = binary_string + '1';
        reverse(binary_string.begin(),binary_string.end());
        return binary_string;
        
    }
};












class Solution {
    void addZeros(string &S , int diff){
        reverse(S.begin() , S.end());
        for(int i = 0 ; i < diff ; ++i){
            S.push_back('0');
        }
        reverse(S.begin() , S.end());
    }
public:
    string addBinary(string a, string b) {
        if(a.size() != b.size()){ 
            if(a.size() < b.size()) swap(a , b);
            addZeros(b , a.size() - b.size()); // adding zeros so that both are of the same length
			//eg: if a = 1011 and b = 01 then after the above operation b becomes 0001
			//Makes addition process simpler
        }
                        
        int N = a.size();
        int M = b.size();
        
        string res = "";
        char carry = '0';
        for(int i = N - 1 ; i >= 0 ; --i){
            char c1 = a[i];
            char c2 = b[i]; 
            
            if(carry == '1'){
                if(c1 == '0' && c2 == '0'){ 
                    res.push_back('1');
                    carry = '0';
                }
                else if(c1 == '1' && c2 == '1'){ 
                    res.push_back('1');
                    carry = '1';       
                }
                else{
                    res.push_back('0');
                    carry = '1';
                }
            }
            else {
                if(c1 == '0' && c2 == '0') res.push_back('0');
                else if(c1 == '1' && c2 == '1'){ 
                    res.push_back('0');
                    carry = '1' ;       
                }
                else{
                    res.push_back('1');
                }
            }
        }
        
        if(carry == '1') res.push_back('1');
        
        reverse(res.begin() , res.end());
        
        return res;
    }
};


















class Solution {
    public:
	//modifying the original strings is not prohibited so passing reference to them is better
	//futhermore, we can modify the longer string and return a reference to it rather than constructing a new one and implicitly copying it again at last
    string &addBinary(string &a, string &b) {
		//if a and b differ in size, then the index should be taken care of
		//to avoid testing index twice within a single iteration, once for string a and once for string b, which is redundant, we can traverse them using the size of the shorter one first, then traverse the reamaining part of the longer one
		
		//obtain two string references with known size order
		//assign the longer string to x and the shorter to y
        auto temp = a.size() >= b.size();
        string &x = temp? a : b;
        string &y = temp? b : a;
		
        string::size_type i;    //index
        bool carry = false;
		//traverse using the shorter size
        for (i = 0; i != y.size(); ++i) {
            auto pos_x = x.size() - i - 1;
            auto pos_y = y.size() - i - 1;
            char sum = x[pos_x] + y[pos_y] + carry;    //no need to subtract '0'
			//if-else use conditional jump, which causes measurable performance drawback upon branch prediction failure on modern CPUs
			//switch uses address table thus eliminates the potential performance issue on CPUs with pipelines
            switch(sum){
				//see below for definitions of case labels
				//pre-calculate case labels: minor optimization
                case ZERO1:
                    break;    //the sum is 0 if and only if two digits and carry are all 0 so no action is required
                case ONE1:
                    x[pos_x] = '1';
                    carry = false;
                    break;
                case TWO1:
                    x[pos_x] = '0';
                    carry = true;
                    break;
                case THREE:
                    x[pos_x] = '1';
                    carry = true;
                    break;
            }
        }
		//traverse the remaining part of the longer string
        for (; i != x.size(); ++i) {
            auto pos_x = x.size() - i - 1;
            char sum = x[pos_x] + carry;
            switch(sum){
                case ZERO2:
                    break;
                case ONE2:
                    x[pos_x] = '1';
                    carry = false;
                    break;
                case TWO2:
                    x[pos_x] = '0';
                    carry = true;
                    break;
            }
        }
        if (carry)
            return x = '1' + x;
        return x;
    }
private:
	//static const integral types
	//true and false coercion to 1 and 0 respectively
    static constexpr char ZERO1 = '0' + '0' + false;    //in-class initializer for static constant expression
    static constexpr char ONE1 = '0' + '1' + false;
    static constexpr char TWO1 = '1' + '1' + false;    //'1' + '0' + true yields the same result on machines with contiguously encoded alphabet
    static constexpr char THREE = '1' + '1' + true;

	//needed when we traverse the remaining of the longer string
    static constexpr char ZERO2 = '0' + false;
    static constexpr char ONE2 = '1' + false;    //'0' + true yields the same result
    static constexpr char TWO2 = '1' + true;
};





















Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
