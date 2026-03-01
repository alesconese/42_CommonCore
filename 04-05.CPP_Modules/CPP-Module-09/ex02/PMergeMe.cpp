#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe &src) { (void)src; }

PMergeMe &PMergeMe::operator=(const PMergeMe &src)
{
	(void)src;
	return *this;
}

PMergeMe::~PMergeMe() {}

void	PMergeMe::FJ(char **argv)
{
	std::vector<int>	og_vec;
	std::deque<int>		og_deq;

	//push arguments to vector and deque while checking for errors
	for (int i = 1; argv[i]; i++)
	{
		char		*endptr;
		long		nbr = std::strtol(argv[i], &endptr, 10);

		if (nbr < 0 || nbr > INT_MAX || *endptr != '\0' || !*argv[i])
			throw std::invalid_argument("arguments must be positive integers.");
		if (std::find(og_vec.begin(), og_vec.end(), static_cast<int>(nbr)) != og_vec.end())
			throw std::invalid_argument("numbers cannot be repeated.");
		
		og_vec.push_back(static_cast<int>(nbr));
		og_deq.push_back(static_cast<int>(nbr));
	}

	std::cout << "* Original sequence:\n";
	for (std::vector<int>::iterator it = og_vec.begin(); it < og_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	//run algorithm using std::vector and save time
	clock_t	start = clock();
	FJ_vec(og_vec);
	clock_t	end = clock();

	for (std::vector<int>::iterator it = og_vec.begin() + 1; it < og_vec.end(); it++)
	{
		if (*it < *(it - 1))
			throw std::runtime_error("sequence is not sorted.");
	}

	std::cout << "* Sorted sequence using std::vector :\n";
	for (std::vector<int>::iterator it = og_vec.begin(); it < og_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n* Time to process a range of " << std::setw(5) << og_vec.size() << " elements with std::vector : " << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 << " us\n\n";

	//run algorithm using std::deque and save time
	start = clock();
	FJ_deq(og_deq);
	end = clock();

	for (std::deque<int>::iterator it = og_deq.begin() + 1; it < og_deq.end(); it++)
	{
		if (*it < *(it - 1))
			throw std::runtime_error("sequence is not sorted.");
	}

	std::cout << "* Sorted sequence using std::deque :\n";
	for (std::deque<int>::iterator it = og_deq.begin(); it < og_deq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n* Time to process a range of " << std::setw(5) << og_deq.size() << " elements with std::deque : " << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 << " us\n\n";
}

void	PMergeMe::FJ_vec(std::vector<int> &og_vec)
{
	static int	cmp_size = 1;
	
	if (og_vec.size() / cmp_size < 2)
		return ;

	for (std::vector<int>::iterator it = og_vec.begin(); it < og_vec.end(); it += cmp_size * 2)
	{
		if (og_vec.end() - it < cmp_size * 2)
			break ;
		if (*(it + (cmp_size - 1)) > *(it + cmp_size * 2 - 1))
			for (std::vector<int>::iterator it2 = it; it2 < it + cmp_size; it2++)
				std::iter_swap(it2, it2 + cmp_size);
	}

	cmp_size *= 2;
	FJ_vec(og_vec);
	cmp_size /= 2;

	//merge insert with jacobsthal optimization
	//start at last recursion level that was able to make a pair
	//can have 2 or 3 pairs and may or may not have extra elements
	//if only 2 full elements they will already be sorted so we don't need to do anything
	if (og_vec.size() / cmp_size <= 2)
		return ;

	//initialize main with {b1,a1..an}, pend with {b2..bn}, extra with non-participating
	std::vector<int>	main;
	std::vector<int>	pend;
	std::vector<int>	extra;

	//move first 2 elements to main (b1,a1)
	main.insert(main.end(), og_vec.begin(), og_vec.begin() + cmp_size * 2);

	//move rest of elements to pend (odd elements / b's) and main (even elements / a's)
	//if not enough numbers for a full element, move to extra
	for (std::vector<int>::iterator it = og_vec.begin() + cmp_size * 2; it < og_vec.end(); it += cmp_size)
	{
		if (og_vec.end() - it < cmp_size)
			extra.insert(extra.end(), it, og_vec.end());//if not enough numbers for an element >> extra
		else if ((it - og_vec.begin()) % (cmp_size * 2) == 0)
			pend.insert(pend.end(), it, it + cmp_size);//bn >> pend
		else
			main.insert(main.end(), it, it + cmp_size);//an >> main
	}
	
	//insertion from pend in reeverse order, with jacobsthal optimization
	//start at 2nd jacobsthal nbr (3)
	int jaco = 2;

	std::vector<int>::iterator	b_last;
	std::vector<int>::iterator	a_first; 
	std::vector<int>::iterator	insert_pos;

	size_t 	insertions;
	int		offset = 0;

	//at each step we insert the full element into main and erase it from pend, so we continue until nothing left in pend
	while (!pend.empty())
	{
		//need jaco(n) - jaco(n-1) elements for jacobsthal optimization, otherwise insert in reverse order
		insertions = get_Jacobsthal(jaco) - get_Jacobsthal(jaco - 1);
		if (insertions * cmp_size > pend.size())
			insertions = pend.size() / cmp_size;
	
		//go from right to left until we've done all our current insertions
		while (insertions)
		{
			//we need to compare the biggest number in each element, which will always be the rightmost
			//so we jump as many elements as insertions and then -1 to get the last element
			b_last = pend.begin() + insertions * cmp_size - 1;

			//second parameter of my_upper_bound should be ax (original pair corresponding to bx, the element we are inserting)
			//if bx is an odd element (has no pair), we have to search in the entire main, so we pass main.end()
			//the index of bx is the current jacobsthal decreased by each element inserted in the current jacobsthal
			//since instertions is initialized as current - previous jacobsthal, here we use the previous and the insertions left
			//when there aren't enough elements left for a full jacobsthal sequence, insertions dictates the last index
			a_first = main.begin() + (cmp_size * (get_Jacobsthal(jaco - 1) + insertions + offset));

			//use binary search to find the insert position, which will always be to the left of ax 
			//my_upper_bound will return the rightmost (biggest) number of the corresponding element
			//if the element we're inserting is bigger than all the elements in the range, it will return a_first
			insert_pos = my_upper_bound<std::vector<int> >(main.begin(), a_first, *b_last, cmp_size);
			
			//if a bigger element was found, we move insert_pos to the leftmost number in the element to start inserting from there
			//we use offset in order to increase the search range of the next element, as there will be one more element to the left of its pair
			if (insert_pos != a_first)
			{
				insert_pos -= (cmp_size - 1);
				offset++;
			}
			
			//insert the full element into main and erase it from pend
			main.insert(insert_pos, b_last - (cmp_size - 1), b_last + 1);
			pend.erase(b_last - (cmp_size - 1), b_last + 1);

			insertions--;
		}

		//when we've finished our current insertion, we continue with the next jacobsthal number
		//we also need to update the offset, as all previous elements have been inserted to the left of the next group of elements
		offset = get_Jacobsthal(jaco) - 1;
		jaco++;
	}

	//when we're done, we move the main container to the original for the next recursion level and insert any extra numbers we had
	og_vec = main;
	og_vec.insert(og_vec.end(), extra.begin(), extra.end());
}

void	PMergeMe::FJ_deq(std::deque<int> &og_deq)
{
	static int	cmp_size = 1;

	if (og_deq.size() / cmp_size < 2)
		return ;

	for (std::deque<int>::iterator it = og_deq.begin(); it < og_deq.end(); it += cmp_size * 2)
	{
		if (og_deq.end() - it < cmp_size * 2)
			break ;
		if (*(it + (cmp_size - 1)) > *(it + cmp_size * 2 - 1))
			for (std::deque<int>::iterator it2 = it; it2 < it + cmp_size; it2++)
				std::iter_swap(it2, it2 + cmp_size);
	}

	cmp_size *= 2;
	FJ_deq(og_deq);
	cmp_size /= 2;

	if (og_deq.size() / cmp_size <= 2)
		return ;

	std::deque<int>	main;
	std::deque<int>	pend;
	std::deque<int>	extra;

	main.insert(main.end(), og_deq.begin(), og_deq.begin() + cmp_size * 2);

	for (std::deque<int>::iterator it = og_deq.begin() + cmp_size * 2; it < og_deq.end(); it += cmp_size)
	{
		if (og_deq.end() - it < cmp_size)
			extra.insert(extra.end(), it, og_deq.end());
		else if ((it - og_deq.begin()) % (cmp_size * 2) == 0)
			pend.insert(pend.end(), it, it + cmp_size);
		else
			main.insert(main.end(), it, it + cmp_size);
	}

	int jaco = 2;

	std::deque<int>::iterator	b_last;
	std::deque<int>::iterator	a_first;
	std::deque<int>::iterator	insert_pos;

	size_t 	insertions;
	int		offset = 0;

	while (!pend.empty())
	{
		insertions = get_Jacobsthal(jaco) - get_Jacobsthal(jaco - 1);
		if (insertions * cmp_size > pend.size())
			insertions = pend.size() / cmp_size;
		
		while (insertions)
		{
			b_last = pend.begin() + insertions * cmp_size - 1;

			a_first = main.begin() + (cmp_size * (get_Jacobsthal(jaco - 1) + insertions + offset));
			
			insert_pos = my_upper_bound<std::deque<int> >(main.begin(), a_first, *b_last, cmp_size);
			
			if (insert_pos != a_first)
			{
				insert_pos -= (cmp_size - 1);
				offset++;
			}
			
			main.insert(insert_pos, b_last - (cmp_size - 1), b_last + 1);
			pend.erase(b_last - (cmp_size - 1), b_last + 1);

			insertions--;
		}

		offset = get_Jacobsthal(jaco) - 1;
		jaco++;
	}

	og_deq = main;
	og_deq.insert(og_deq.end(), extra.begin(), extra.end());
}

//return the kth jacobsthal number, defined as J(k) = (2^(k+1) + (-1)^k) / 3
int		PMergeMe::get_Jacobsthal(int k)
{
	return((pow(2, k + 1) + pow(-1, k)) / 3);
}

//binary search function, works as std::upper_bound but only comparing the last number of the element
template <typename C>
typename C::iterator	PMergeMe::my_upper_bound(typename C::iterator first, typename C::iterator last, int value, int cmp_size)
{
	typename C::iterator low = first + (cmp_size - 1);
	typename C::iterator high = last - 1;

	//if value is higher than all numbers in the range, return last
	if (value > *high)
		return last;

	while (low < high)
	{
		typename C::iterator mid = low + ((std::distance(low, high) / cmp_size) / 2) * cmp_size; // 0

		if (*mid < value)
			low = mid + cmp_size; // Continue searching in the upper half
		else
			high = mid; // Continue in the lower half
	}

	return low; // Return position of upper bound
}
