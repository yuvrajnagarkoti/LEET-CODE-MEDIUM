class Solution
{
    public:
    string addStrings(const string &a, const string &b)
    {
        string result;
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string multiply(string num1, string num2)
    {
        if(num1 == "0" || num2 == "0") return "0";
        int n1 = num1.size(), n2 = num2.size();
        vector<string> product;
        for(int i = n2 - 1; i >= 0; i--)
        {
            int carry = 0;
            string number = "";
            for(int j = n1 - 1; j >= 0; j--)
            {
                int num = (num1[j] - '0') * (num2[i] - '0') + carry;
                carry = num / 10;
                number = char(num % 10 + '0') + number;
            }
            if(carry) number = to_string(carry) + number;
            number += string(n2 - 1 - i, '0');
            product.push_back(number);
        }
        string sum = "0";
        for(const string &num : product)
        {
            sum = addStrings(sum, num);
        }
        return sum;
    }
};