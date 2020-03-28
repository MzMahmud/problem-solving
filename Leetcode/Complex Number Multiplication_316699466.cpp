class Solution {
public:
    string complexNumberMultiply(string c1, string c2) {
        int a,b,c,d;
        
        sscanf(c1.c_str(),"%d+%di",&a,&b);
        sscanf(c2.c_str(),"%d+%di",&c,&d);
        
        char out[100];
        sprintf(out,"%d+%di",a*c - b*d,a*d + b*c);
        
        return string(out);
    }
};
