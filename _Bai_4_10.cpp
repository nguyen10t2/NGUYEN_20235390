//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \|
//                / _||||| -:- |||||- \|
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Dao Trong Nguyen _ 20235390 _ IT2-03 _ IT3040 _ 750829_ 2024.2

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <sstream>

struct Pharagraph {
    std::unordered_map<std::string, int> termFreq_90;
    int totalWords_90 = 0;
    int maxFreg_90 = 0;

    Pharagraph(const std::vector<std::string>& words_90) {
        for (const auto& word_90 : words_90) {
            termFreq_90[word_90]++;
            totalWords_90++;
            maxFreg_90 = std::max(maxFreg_90, termFreq_90[word_90]);
        }
    }

    double tf(const std::string& word_90) const {
        auto it_90 = termFreq_90.find(word_90);
        if (it_90 == termFreq_90.end()) return 0.0;
        if (maxFreg_90 == 0) return 0.0; 
        return static_cast<double>(it_90->second) / maxFreg_90;
    }

    bool contains(const std::string& word_90) const {
        return termFreq_90.count(word_90) > 0;
    }
};

std::vector<Pharagraph> corpus_global_90;

double idf(const std::string& word_90, const std::vector<Pharagraph>& corpus_param_90) {
    int df_90 = 0;
    for (const auto& para_90 : corpus_param_90) {
        if (para_90.contains(word_90)) df_90++;
    }
    if (df_90 == 0) return 0.0;
    return std::log(static_cast<double>(corpus_param_90.size()) / df_90);
}

double tfidf(const std::string& word_90, const Pharagraph& para_90, const std::vector<Pharagraph>& corpus_param_90) { // Renamed parameter
    return para_90.tf(word_90) * idf(word_90, corpus_param_90);
}

int N_90, Q_90;

std::vector<std::string> split(const std::string& str_90) {
    std::vector<std::string> tokens_90;
    std::stringstream ss_90(str_90);
    std::string token_90;
    while(std::getline(ss_90, token_90, ',')) {
        tokens_90.push_back(token_90);
    }
    return tokens_90;
}

void input() {
    std::cin >> N_90;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');
    corpus_global_90.clear();
    for(int i = 0; i < N_90; ++i) {
        std::string str_90;
        std::getline(std::cin, str_90);
        corpus_global_90.push_back(split(str_90));
    }
}

double total_tfidf(const std::vector<std::string>& words_90, const Pharagraph& para_90, const std::vector<Pharagraph>& corpus_param_90) { // Renamed parameter
    double res_90 = 0;
    for(const auto& word_90 : words_90) {
        res_90 += tfidf(word_90, para_90, corpus_param_90);
    }
    return res_90;
}

void output() {
    std::cin >> Q_90;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');
    for(int i = 0; i < Q_90; ++i) {
        std::string str_90;
        std::getline(std::cin, str_90);
        std::vector<std::string> words_90 = split(str_90);
        double max_tfidf_sum_90 = -1.0;
        int best_para_index_90 = -1;
        for(int j = 0; j < corpus_global_90.size(); ++j) {
            double current_tfidf_sum_90 = total_tfidf(words_90, corpus_global_90[j], corpus_global_90);
            if(current_tfidf_sum_90 > max_tfidf_sum_90) {
                max_tfidf_sum_90 = current_tfidf_sum_90;
                best_para_index_90 = j;
            }
        }
        std::cout << best_para_index_90 << '\\n';
    }
}

int main() {
    input();
    output();
}