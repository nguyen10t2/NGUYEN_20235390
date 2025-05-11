#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <sstream>

struct Pharagraph {
    std::unordered_map<std::string, int> termFreq;
    int totalWords = 0;
    int maxFreg = 0; 

    Pharagraph(const std::vector<std::string>& words) {
        for (const auto& word : words) {
            termFreq[word]++;
            totalWords++;
            maxFreg = std::max(maxFreg, termFreq[word]);
        }
    }

    double tf(const std::string& word) const {
        auto it = termFreq.find(word);
        if (it == termFreq.end()) return 0.0;
        return static_cast<double>(it->second) / maxFreg;
    }

    bool contains(const std::string& word) const {
        return termFreq.count(word) > 0;
    }
};

double idf(const std::string& word, const std::vector<Pharagraph>& corpus) {
    int df = 0;
    for (const auto& para : corpus) {
        if (para.contains(word)) df++;
    }
    if (df == 0) return 0.0; // tránh chia cho 0
    return std::log(static_cast<double>(corpus.size()) / df);
}

double tfidf(const std::string& word, const Pharagraph& para, const std::vector<Pharagraph>& corpus) {
    return para.tf(word) * idf(word, corpus);
}


std::vector<Pharagraph> corpus;
int N, Q;
std::vector<std::string> split(const std::string& str) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while(std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }
    return tokens;
}
void input() {
    std::cin >> N;
    for(int i = 0; i < N; ++i) {
        std::string str;
        std::getline(std::cin, str);
        corpus.push_back(split(str));
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double total_tfidf(const std::vector<std::string>& words, const Pharagraph& para, const std::vector<Pharagraph>& corpus) {
    double res = 0;
    for(auto word : words) {
        res += tfidf(word, para, corpus);
    }
    return res;
}

void output() {
    std::cin >> Q;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for(int i = 0; i < Q; ++i) {
        std::string str;
        std::getline(std::cin, str);
        std::vector<std::string> words = split(str);
        double res = -1;
        int index = -1;
        for(int i = 0; i < corpus.size(); ++i) {
            double total = total_tfidf(words, corpus[i], corpus);
            if(total > res) {
                res = total;
                index = i;
            }
        }
        std::cout << index << '\n';
    }
}

int main() {
    input();
    output();
}