class Solution {
    public int distinctEchoSubstrings(String s) {
	Set<String> set = new HashSet<>();
	for (int len = 1; len <= s.length() / 2; len++) {
		for (int l = 0, r = len, count = 0; l < s.length() - len; l++, r++) {
			if (s.charAt(l) == s.charAt(r)) count++;
			else count = 0;

			if (count == len) {
				set.add(s.substring(l - len + 1, l + 1));
				count--;
			}
		}
	}

	return set.size();
}
}