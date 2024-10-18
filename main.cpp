#include<iostream>
#include <vector>

class A{
private:
    uint64_t _n;
    std::vector<uint64_t> array;
public:
    A(int n): _n(n) {};
    
    std::vector<uint64_t> GetPriority() const{
        std::vector<uint64_t> simple;
        std::vector<bool> is_prime(_n+1, true);
        is_prime[0] = is_prime[1] = false;
        for(int i = 2; i * i <= _n; i++)
            if (is_prime[i])
                for (int j = i * i; j <= _n; j += i)
                    is_prime[j] = false;
        for (int p = 2; p <= _n; p++)
        {
            if (is_prime[p])
            {
                simple.push_back(p);
            }
        }
        return simple;
    };
};


int main(){
    uint64_t n;
    std::cout << "Put number n: ";
    std::cin >> n;

    A array(n);
    
    std::vector<uint64_t> prime =  array.GetPriority();
    for (int p : prime)
    {
        std::cout<< p << " "; 
    }
    std::cout << std::endl;
    return 0;
}