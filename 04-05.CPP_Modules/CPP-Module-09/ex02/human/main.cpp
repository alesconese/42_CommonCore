#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

void	ft_pairs(std::vector<int> &og_seq)
{
	std::vector<int>::iterator	it;

	std::cout << "* * * PAIRS * * *\n";
	//Recursion level 1
	it = og_seq.begin();
	while (it < og_seq.end())
	{
		if (*it > *(it + 1))
			std::iter_swap(it, it + 1);
		it += 2;
	}
	std::cout << "* Recursion level 1 (2 numbers):\n";
	for (it = og_seq.begin(); it < og_seq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	//Recursion level 2
	it = og_seq.begin();
	while (it < og_seq.end())
	{
		if (og_seq.end() - it < 4)
			break;
		if (*(it + 1) > *(it + 3))
		{
			std::iter_swap(it, it + 2);
			std::iter_swap(it + 1, it + 3);
		}
		it += 4;
	}
	std::cout << "* Recursion level 2 (4 numbers):\n";
	for (it = og_seq.begin(); it < og_seq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	//Recursion level 3
	it = og_seq.begin();
	while (it < og_seq.end())
	{
		if (og_seq.end() - it < 8)
			break;
		if (*(it + 3) > *(it + 7))
		{
			std::iter_swap(it, it + 4);
			std::iter_swap(it + 1, it + 5);
			std::iter_swap(it + 2, it + 6);
			std::iter_swap(it + 3, it + 7);
		}
		it += 8;
	}
	std::cout << "* Recursion level 3 (8 numbers):\n";
	for (it = og_seq.begin(); it < og_seq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	//Recursion level 4
	it = og_seq.begin();
	while (it < og_seq.end())
	{
		if (og_seq.end() - it < 16)
			break;
		if (*(it + 7) > *(it + 15))
		{
			std::iter_swap(it, it + 8);
			std::iter_swap(it + 1, it + 9);
			std::iter_swap(it + 2, it + 10);
			std::iter_swap(it + 3, it + 11);
			std::iter_swap(it + 4, it + 12);
			std::iter_swap(it + 5, it + 13);
			std::iter_swap(it + 6, it + 14);
			std::iter_swap(it + 7, it + 15);
		}
		it += 16;
	}
	std::cout << "* Recursion level 4 (16 numbers):\n";
	for (it = og_seq.begin(); it < og_seq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";
}

int		get_Jacobsthal(int k)
{
	return((pow(2, k + 1) + pow(-1, k)) / 3);
}

std::vector<int>::iterator	my_upper_bound(std::vector<int>::iterator first, std::vector<int>::iterator last, int value, int cmp_size)
{
    // Start position is determined by cmp_size
    first += (cmp_size - 1);

    ptrdiff_t low = 0, high = std::distance(first, last) / cmp_size;
	std::cout << "low: " << low << "\n";
	std::cout << "high: " << high << "\n";

    while (low < high) {
        ptrdiff_t mid = low + (high - low) / 2;
		std::cout << "mid: " << mid << "\n";
        std::vector<int>::iterator midIt = first + mid * cmp_size;
		std::cout << "midIt: " << *midIt << "\n";

        if (*midIt <= value)
            low = mid + 1; // Continue searching in the upper half
        else
            high = mid; // Continue in the lower half
    }

    return first + low * cmp_size; // Return position of upper bound
}


void	ft_insert(std::vector<int> &og_seq)
{
	std::vector<int>	main;
	std::vector<int>	pend;
	std::vector<int>	extra;

	std::vector<int>::iterator	og_it = og_seq.begin();
	
	int		cmp_size = 8;
	int		jaco;
	int		inserted = 0;

	std::vector<int>::iterator	insert_pos;
	std::vector<int>::iterator	b_last;
	std::vector<int>::iterator	a_first;


	std::cout << "* * * INSERTION * * *\n";
	//recursion level 4
	//nothing to do?
	std::cout << "* Recursion level 4 (elements of 8 numbers):\n";
	std::cout << "NOTHING TO BE DONE\n\n";

	//recursion level 3 (elements of 4 numbers)
	std::cout << "* Recursion level 3 (elements of 4 numbers):\n";
	std::cout << "BEFORE: ";
	for (og_it = og_seq.begin(); og_it < og_seq.end(); og_it++)
		std::cout << *og_it << " ";
	std::cout << "\n";
	cmp_size = 4;
	//b1,a1..n >> main
	//b2..n >> pend
	main.insert(main.end(), og_seq.begin(), og_seq.begin() + cmp_size * 2);

	for(og_it = og_seq.begin() + cmp_size * 2; og_it < og_seq.end(); og_it += cmp_size)
	{
		if (og_seq.end() - og_it < cmp_size)
			extra.insert(extra.end(), og_it, og_seq.end());
		else if ((og_it - og_seq.begin()) % (cmp_size * 2) == 0)
			pend.insert(pend.end(), og_it, og_it + cmp_size);//bn >> pend
		else
			main.insert(main.end(), og_it, og_it + cmp_size);//an >> main
	}
	
	std::cout << "MAIN: ";
	for (std::vector<int>::iterator it = main.begin(); it < main.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nPEND: ";
	for (std::vector<int>::iterator it = pend.begin(); it < pend.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nEXTRA: ";
	for (std::vector<int>::iterator it = extra.begin(); it < extra.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";
	
	//insert bs from pend to main, starting with jacobsthal 3 
	jaco = 2;
	//insert b3 -> {b1,a1,a2}
	b_last = pend.begin() + cmp_size * (get_Jacobsthal(jaco) - get_Jacobsthal(jaco - 1)) - 1;
	std::cout << "b_last: " << *b_last << "\n";

	insert_pos = std::upper_bound(main.begin(), main.end(), *b_last);
	std::cout << "insert_pos: " << *insert_pos << "\n";

	main.insert(insert_pos - (cmp_size - 1), b_last - (cmp_size - 1), b_last + 1);
	pend.erase(b_last - (cmp_size - 1), b_last + 1);

	std::cout << "MAIN: ";
	for (std::vector<int>::iterator it = main.begin(); it < main.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nPEND: ";
	for (std::vector<int>::iterator it = pend.begin(); it < pend.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	//insert b2 -> {b1,a1,b3}
	b_last = pend.begin() + cmp_size * (get_Jacobsthal(jaco) - get_Jacobsthal(jaco - 1) - 1) - 1;
	std::cout << "b_last: " << *b_last << "\n";
	a_first = std::find(main.begin(), main.end(), *(og_seq.begin() + (get_Jacobsthal(jaco) - 1) * cmp_size * 2 - cmp_size));
	std::cout << "a_first: " << *a_first << "\n";
	insert_pos = std::upper_bound(main.begin(), a_first, *b_last);
	std::cout << "insert_pos: " << *insert_pos << "\n";
	main.insert(insert_pos - (cmp_size - 1), b_last - (cmp_size - 1), b_last + 1);
	pend.erase(b_last - (cmp_size - 1), b_last + 1);
	std::cout << "MAIN: ";
	for (std::vector<int>::iterator it = main.begin(); it < main.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nPEND: ";
	for (std::vector<int>::iterator it = pend.begin(); it < pend.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	og_seq = main;
	og_seq.insert(og_seq.end(), extra.begin(), extra.end());
	main.clear();
	pend.clear();
	extra.clear();
	std::cout << "AFTER: ";
	for (og_it = og_seq.begin(); og_it < og_seq.end(); og_it++)
		std::cout << *og_it << " ";
	std::cout << "\n\n";

	//recursion level 2 (elements of 2 numbers)
	std::cout << "* Recursion level 2 (elements of 2 numbers):\n";
	std::cout << "BEFORE: ";
	for (og_it = og_seq.begin(); og_it < og_seq.end(); og_it++)
		std::cout << *og_it << " ";
	std::cout << "\n";

	cmp_size = 2;

	//b1,a1 >> main
	main.insert(main.end(), og_seq.begin(), og_seq.begin() + cmp_size * 2);
	for(og_it = og_seq.begin() + cmp_size * 2; og_it < og_seq.end(); og_it += cmp_size)
	{
		if (og_seq.end() - og_it < cmp_size)
			extra.insert(extra.end(), og_it, og_seq.end());
		else if ((og_it - og_seq.begin()) % (cmp_size * 2) == 0)
			pend.insert(pend.end(), og_it, og_it + cmp_size);//bn >> pend
		else
			main.insert(main.end(), og_it, og_it + cmp_size);//an >> main
	}
	std::cout << "MAIN: ";
	for (std::vector<int>::iterator it = main.begin(); it < main.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nPEND: ";
	for (std::vector<int>::iterator it = pend.begin(); it < pend.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nEXTRA: ";
	for (std::vector<int>::iterator it = extra.begin(); it < extra.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	//insert bs from pend to main, starting with jacobsthal 3 
	jaco = 2;
	
	while (!pend.empty())
	{
		inserted = 0;
		while (inserted < (get_Jacobsthal(jaco) - get_Jacobsthal(jaco - 1)))
		{
			b_last = pend.begin() + cmp_size * (get_Jacobsthal(jaco) - get_Jacobsthal(jaco - 1) - inserted) - 1;
			std::cout << "b_last: " << *b_last << "\n";
			a_first = std::find(main.begin(), main.end(), *(og_seq.begin() + (get_Jacobsthal(jaco) - inserted) * cmp_size * 2 - cmp_size));
			std::cout << "a_first: " << *a_first << "\n";
			insert_pos = my_upper_bound(main.begin(), a_first, *b_last, cmp_size);
			if (insert_pos == a_first)
				insert_pos++;
			std::cout << "insert_pos: " << *insert_pos << "\n";
			main.insert(insert_pos - (cmp_size - 1), b_last - (cmp_size - 1), b_last + 1);
			pend.erase(b_last - (cmp_size - 1), b_last + 1);
			std::cout << "MAIN: ";
			for (std::vector<int>::iterator it = main.begin(); it < main.end(); it++)
				std::cout << *it << " ";
			std::cout << "\nPEND: ";
			for (std::vector<int>::iterator it = pend.begin(); it < pend.end(); it++)
				std::cout << *it << " ";
			std::cout << "\n\n";
			inserted++;
		}
		jaco++;
	}
	//after finishing jacobsthal 5 insertions there is 1 element left in pend -> segfault
}

int	main()
{
	int	arr[] = {11,2,17,0,16,8,6,15,10,3,21,1,18,9,14,19,12,5,4,20,13,7};

	std::vector<int>	og_seq;

	for (int i=0; i<22; i++)
		og_seq.push_back(arr[i]);

	std::cout << "* Original sequence:\n";
	for (std::vector<int>::iterator it = og_seq.begin(); it < og_seq.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	ft_pairs(og_seq);

	ft_insert(og_seq);
	

	return 0;
}
