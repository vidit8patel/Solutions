class Solution {
public:
    string intToString(int n){
        string ones[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tens[10] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        if(n >= 1000000000) return intToString(n/1000000000) + " Billion" + intToString(n % 1000000000);
        if(n >= 1000000) return intToString(n/1000000) + " Million" + intToString(n % 1000000);
        if(n >= 1000) return intToString(n/1000) + " Thousand" + intToString(n % 1000);
        if(n >= 100) return intToString(n/100) + " Hundred" + intToString(n % 100);
        if(n >= 20) return " " + tens[n / 10 - 2 ] + intToString(n % 10) ;
        if(n >= 1) return " " + ones[n];
        return "";
    }
    
    string numberToWords(int n) {
        if(n == 0) return "Zero";
        return intToString(n).substr(1);  
    }
};