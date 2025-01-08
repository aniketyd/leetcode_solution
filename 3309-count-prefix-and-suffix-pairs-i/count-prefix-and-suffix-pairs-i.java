class Solution {
    public int countPairs(String[] words) {
        int len=words.length;
        int count=0;
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(words[j].endsWith(words[i]) && words[j].startsWith(words[i]) ){
                    count++;
                }
            }
        }
        return count;
    }

    public int countPrefixSuffixPairs(String[] words) {
        return countPairs(words);
    }
}