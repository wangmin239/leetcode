class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        
        dp[0] = 1;
        
        for (auto coin : coins) {
            for (int total = coin; total < amount + 1; total++) {
                dp[total] += dp[total - coin];
            }
        }
        
        return dp[amount];
    }
};



template <class, class> class memoize_helper;
template <class Ret, class... Args, class Fun>
class memoize_helper<Ret(Args...), Fun> {
private:
	inline static char buffer[1024 * 256];
	inline static pmr::monotonic_buffer_resource pool { buffer, sizeof(buffer) };
    using _Tup = std::tuple<std::decay_t<Args>...>;
    Fun fun_;
    mutable std::pmr::map<_Tup, Ret> cache_ { &pool };
public:
	template<class _F>
    memoize_helper(_F&& f) : fun_(static_cast<_F&&>(f)) {}
    template <class... _Args>
    Ret const& operator()(_Args&&... args) const {
        auto _tup = _Tup { args... };
        auto _it = cache_.find(_tup);
        if (_it == cache_.end())
			_it = cache_.emplace(static_cast<_Tup&&>(_tup), 
            fun_(*this, static_cast<_Args&&>(args)...)).first;
        return _it -> second;
    }
};
template <class Sign, class F> 
memoize_helper<Sign, decay_t<F>> $lru_cache(F&& f) { return { static_cast<F&&>(f) }; }
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        auto n = static_cast<int>(size(coins));
        auto dfs = [&](auto&& dfs, int amount, int idx)->int {
            if (idx == n) return amount == 0;
            auto ret = 0;
            for (auto coin = coins[idx]; amount >= 0; amount -= coin)
                ret += dfs(amount, idx + 1);
            return ret;
        };
        return $lru_cache<int(int,int)>(dfs)(amount, 0);
    }
};