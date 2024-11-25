#include <iostream>
#include <cstdint>

using u64 = uint64_t;
using i64 = int64_t;

constexpr u64 INF = 1e18;

// enum class Hit {
//     Left, Right
// };

auto func(i64 n) {
    
    // std::cin >> n;
    // std::cin >> print_len;

    i64 value[n+1][n+1];
    i64 move[n+1][n+1];

    for (i64 len = 0; len <= n; len++) {
        for (i64 begin = 0; begin + len <= n; begin++) {
            auto end = begin + len;
            if (len <= 1) {
                value[begin][end] = 0;
                move[begin][end] = -1;
            }
            else {
                i64 pessimistic_cost = INF;
                for (i64 hit = begin; hit < end - 1; hit++) {
                    auto left_cost = hit + 1 + value[begin][hit + 1];
                    auto right_cost = n - hit - 1 + value[hit + 1][end];
                    auto new_value = std::max(left_cost, right_cost);
                    pessimistic_cost = std::min(
                        pessimistic_cost,
                        new_value
                    );
                    if (pessimistic_cost == new_value) {
                        move[begin][end] = hit;
                    }
                }
                value[begin][end] = pessimistic_cost;       
            }
        }
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

    for (int i = 2; i < 40; i += 2) {
        std::cout << func(i) << ", ";
    }
    std::cout << "\n";

}