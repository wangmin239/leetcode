#include <map>
#include <vector>
#include <tuple>
#include <type_traits>
#include <memory_resource>
#include <iostream>

template<class, class>
class Memorize_helper;

template<typename Ret, typename ... Args, typename Fun>
class Memorize_helper<Ret(Args ...), Fun> {
private:
    inline static char buffer[1024 * 256];
    inline static std::pmr::monotonic_buffer_resource pool {buffer, sizeof(buffer)};
    using _Tup = std::tuple<std::decay_t<Args> ... >;
    Fun _fun;
    std::pmr::map<_Tup, Ret> cache_ {&pool};
    
public:
    
    Memorize_helper(Fun&& fun) : _fun(static_cast<Fun&&>(fun)) { }
    

    Ret const& operator() (Args ... args) {
        auto tup = _Tup(static_cast<Args>(args) ...);
        auto iter = cache_.find(tup);
        
        if (iter == cache_.end()) {
            iter = cache_.emplace(tup, _fun(*this, static_cast<Args&&>(args) ...)).first;
        }
        
        return iter->second;
    }

};

template<class Ret, class Fun>
Memorize_helper<Ret, Fun> create_fun_obj(Fun&& f) {
    return Memorize_helper<Ret, Fun>(static_cast<Fun&&>(f));
}

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        int len = coins.size();
        auto dfs = [&](auto&& funObj, int amount, int id) -> int {
            if (id == len) {
                return amount == 0;
            }
            
            auto ret = 0;
            for (int coin = coins[id]; amount >= 0; amount -= coin) {
                ret += funObj(amount, id + 1);
            }
            return ret;
        };
        
        return create_fun_obj<int(int, int)>(dfs)(amount, 0);
    }
};


int main()
{
    Solution sln;
    std::vector<int> coins {1, 2, 5};
    std::cout << sln.change(20, coins) << std::endl;
    return 0;
}