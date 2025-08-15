class Solution
{
public:
    string largestGoodInteger(string num)
    {
        if (num.find("999") != string::npos) return "999";
        if (num.find("888") != string::npos) return "888";
        if (num.find("777") != string::npos) return "777";
        if (num.find("666") != string::npos) return "666";
        if (num.find("555") != string::npos) return "555";
        if (num.find("444") != string::npos) return "444";
        if (num.find("333") != string::npos) return "333";
        if (num.find("222") != string::npos) return "222";
        if (num.find("111") != string::npos) return "111";
        if (num.find("000") != string::npos) return "000";
        return "";
    }
};