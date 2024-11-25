#include <iostream>
#include <cstdint>
#include <vector>

using u64 = uint64_t;
using i64 = int64_t;

constexpr u64 INF = 1e18;


auto func(i64 n, i64 range_len) {
    
    i64 value[n+1][n+1];
    std::vector<i64> moves[n+1][n+1];

    for (i64 len = 0; len <= n; len++) {
        for (i64 begin = 0; begin + len <= n; begin++) {
            auto end = begin + len;
            if (len <= 1) {
                value[begin][end] = 0;
                moves[begin][end] = {};
            }
            else {
                i64 pessimistic_cost = INF;
                for (i64 hit = begin; hit < end - 1; hit++) {
                    auto left_cost = hit + 1 + value[begin][hit + 1];
                    auto right_cost = n - hit - 1 + value[hit + 1][end];
                    auto new_value = std::max(left_cost, right_cost);
                    
                    if (new_value < pessimistic_cost) {
                        pessimistic_cost = new_value;
                        moves[begin][end].clear();
                    }

                    if (pessimistic_cost == new_value) {
                        moves[begin][end].push_back(hit);
                    }
                }
                value[begin][end] = pessimistic_cost;       
            }
        }
    }

    for (i64 b = 0; b + range_len <= n; b++) {
        auto e = b + range_len;
        for (auto m : moves[b][e]) {
            std::cout << m - b << " ";
        }
        std::cout << "\n";   
    }

    // std::cout << value[0][n] << "\n\n";

    // for (i64 i = 0; i <= n; i++) {
    //     for (i64 j = i + 1; j <= n; j++) {
    //         std::cout << i << ", " << j << " move: " << move[i][j] << ",  cost: " << value[i][j] << "\n"; 
    //     }
    // }

    // for (i64 len = 1; len <= n; len++) {
    //     for (i64 begin = 0; begin + len <= n; begin++) {
    //         auto end = begin + len;
    //         std::cout << begin << ", " << end << " move: " << move[begin][end] << ",  cost: " << value[begin][end] << "\n"; 
    //     }
    // }

    // for (i64 begin = 0; begin + print_len <= n; begin++) {
    //     auto end = begin + print_len;
    //     std::cout << value[begin][end] << "\n"; 
    // }

    return value[0][n];
}


int main() {
    func(128, 16);

}