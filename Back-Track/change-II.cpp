#include <tuple>
#include <iostream>
#include <memory_resource>
#include <map>
#include <vector>
#include <type_traits>

template<class, class>
class Memorize_helper;

template<typename Ret, typename ... Args, typename Fun>
class Memorize_helper<Ret(Args ...), Fun> {
private:
    inline static char buffer[1024 * 256];
    inline static std::pmr::monotonic_buffer_resource pool {buffer, sizeof(buffer)};
    using _Tup = std::tuple<std::decay_t<Args> ...>;
    Fun fun_;
    mutable std::pmr::map<_Tup, Ret> cache_ {&pool};

public:
    template<typename _Fun>
    Memorize_helper(_Fun&& fun): fun_(static_cast<_Fun&&>(fun)) { };
    
    template<typename ... _Args>
    Ret const& operator()(_Args&& ... args) const {
        auto _tup = _Tup {args ...};
        auto _iter = cache_.find(_tup);
        
        if (_iter == cache_.end()) {
            _iter = cache_.emplace(static_cast<_Tup&&>(_tup), fun_(*this, static_cast<_Args&&>(args) ...)).first;
        }
        
        return _iter->second;
    }
    
};



class Solution{
public:
    int change(int target, std::vector<int>& coins) {
        int len = coins.size();
        auto dfs = [&] (auto&& dfs, int amount, int id) -> int {
                if (id == len) {
                    return amount == 0;
                }
                
                auto ret = 0;
                for (int coin = coins[id]; amount >= 0; amount -= coin) {
                    ret += dfs(amount, id + 1);
                }
                
                return ret;
        };
    
        Memorize_helper<int(int, int), decltype(dfs)> memory_help(dfs);
        return memory_help(target, 0);
    }
};


int main()
{
    Solution sln;
    std::vector<int> coins {1, 2, 5};
    std::cout << sln.change(20, coins) << std::endl;
    return 0;
}