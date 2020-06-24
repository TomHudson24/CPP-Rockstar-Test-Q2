#include <iostream>
#include <vector>
#include <map>

int solution(std::vector<int>& A, int M)
{
	std::map<int, int> valuesInA;//first int is the key into hash map and the second is the coordinate
	std::vector<int> subset;
	int N = A.size();

	for (int i = 0; i < N; i++)//adding to the hash map for comparison in next loop
	{
		valuesInA.insert(std::pair<int, int>(i,A[i]));
	}
#if 0
	for (auto elem : valuesInA)//for debugging, to check the values in the hashmap are there correctly
	{
		std::cout << elem.first << " " << elem.second << " " << "\n";
	}
#endif
	for (int i = 0; i < N; i++)//adding to the subset
	{
		if (A[i] == M)
		{
			subset.push_back(i);
		}
		for (int j = i + 1; j < N; j++)
		{
#if 0
			if(A[i] + A[j] % M == 0)
			{
				subset.push_back(valuesInA[i]);
				subset.push_back(valuesInA[j]);
				std::cout << A[i] << " " << A[j] << "\n";
			}
#endif
			if (((valuesInA[i] + valuesInA[j]) % M) == 0)
			{
				subset.push_back(valuesInA[i]);
				//subset.push_back(valuesInA[j]);
			}


#if 0
			
			if ((valuesInA.find((A[i] + A[j] % M)) == 0))/*compare to all others using hash map*/
			{
				subset.push_back(valuesInA[i]);
				subset.push_back(valuesInA[j]);
			}
#endif
		}
		
	}
	

	return subset.size() - 1;
}

int main()
{
	std::vector<int> A = { -3, -2 ,1 , 0 , 8 , 7 , 1 };
	int M = 3;
	int largestSet = solution(A, M);
	std::cout << largestSet << std::endl; //should print out 4
	return 0;
}