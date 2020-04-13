class Solution {
    public String entityParser(String text) {
        String[] key = {"&quot;","&apos;","&amp;","&gt;","&lt;","&frasl;"};
        String[] val = {"\"","'","&",">","<","/"};
        
        for(int i = 0;i < key.length;i++){
            text = text.replace(key[i],val[i]);
        }
        return text;
    }
}