class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
      return "1";
      
    string prev = countAndSay(n-1);
    string curr = "";
    
    int i = 0,count = 0;
    for(int j = 0;
        j < prev.size();j++){
        
      if(prev[i] != prev[j]){
        //cout << count << prev[i];// << prev[i-1];
        char temp[1000];
        sprintf(temp,"%d%c",count,prev[i]);
        curr += temp;
        i = j;j--;
        count = 0;
      }else{
        count++;
      }
    }
    if(count){
       char temp[1000];
        sprintf(temp,"%d%c",count,prev[i]);
        curr += temp;
    }
    return curr;
    }
};
