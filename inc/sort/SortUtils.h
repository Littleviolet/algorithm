#ifndef SORT_UTILS_H
#define SORT_UTILS_H
namespace sort
{
	class SortUtils
	{
    public:
        // 950. ∞¥µ›‘ˆÀ≥–Úœ‘ æø®≈∆
        vector<int> deckRevealedIncreasing(vector<int>& deck) {
            std::queue<int> index;
            int number = deck.size();
            for (int i = 0; i < number; ++i)
            {
                index.push(i);
            }
            std::sort(deck.begin(), deck.end());
            vector<int> res(number);
            int c = 0;
            while (!index.empty())
            {
                int i = index.front();
                index.pop();
                res[i] = deck[c++];
                index.push(index.front());
                index.pop();
            }
            return res;
        }
	};
}
#endif // SORT_UTILS_H