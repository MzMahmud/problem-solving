class Solution {
public:
    string defangIPaddr(string ip) {
        int a,b,c,d;
        sscanf(ip.c_str(),"%d.%d.%d.%d",&a,&b,&c,&d);
        return to_string(a) + "[.]" 
             + to_string(b) + "[.]"
             + to_string(c) + "[.]"
             + to_string(d);
    }
};