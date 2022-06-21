class Solution {
    stack<char> bracket;
public:
    bool isValid(string s)
    {
        if(s.length()%2 != 0)
            return false;
       for(int i = 0; i<s.length(); i++)
       {
           if(s[i]!= ']' && s[i] != ')' && s[i] != '}')
               bracket.push(s[i]);
           else 
           {
               if(bracket.empty())
                   return false;
               if(s[i] == ')' && bracket.top() == '(' || s[i] == ']' && bracket.top() == '[' || s[i] == '}' && bracket.top() == '{')
                   bracket.pop();
               else 
                   return false;
           }
       }
        if(bracket.empty())
            return true;
        return false;
    }
};