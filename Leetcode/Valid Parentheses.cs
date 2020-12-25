public class Solution {
    public bool IsValid(string str) {
        Stack<char> s = new Stack<char>();
        
        Dictionary<char,char> pair = new Dictionary<char,char>(){
            {')','('},
            {'}','{'},
            {']','['},
        } ;
        
        foreach(char c in str)
        {
            if(c == '(' || c == '{' || c == '[')
                s.Push(c);
            else if(s.Count == 0 || s.Pop() != pair[c])
                    return false;
        }
        return s.Count == 0;
    }
}