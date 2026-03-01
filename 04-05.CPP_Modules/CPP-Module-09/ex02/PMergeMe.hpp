#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <climits>
# include <cmath>
# include <iomanip>

class PMergeMe
{
	private:
			PMergeMe();
			PMergeMe(const PMergeMe &src);
			PMergeMe &operator=(const PMergeMe &src);
			~PMergeMe();

			static void	FJ_vec(std::vector<int> &og_vec);
			static void FJ_deq(std::deque<int> &og_deq);

			static int	get_Jacobsthal(int k);

			template <typename C>
			static  typename C::iterator	my_upper_bound(typename C::iterator first, typename C::iterator last, int value, int cmp_size);

	public:
			static void	FJ(char **argv);
};

#endif
