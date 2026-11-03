class Solution {
private:
    unordered_map<string, string> urlMap; // ShortUrl , LongUrl
    string chars =
        "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string getRandom() {
        string code = "";
        for (int i = 0; i < 6; i++) {
            code += chars[rand() % 62];
        }
        return code;
    }

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code = getRandom();
        while (urlMap.count("http://tinyurl.com/" + code)) {
            code = getRandom();
        }
        string shortUrl = "http://tinyurl.com" + code;
        urlMap[shortUrl] = longUrl;

        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) { return urlMap[shortUrl]; }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));