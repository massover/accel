#include <vector>
#include "xcl2.hpp"

using std::vector;

vector<int, aligned_allocator<int>> vector_sub(
	vector<int,aligned_allocator<int>> source_a,
	vector<int,aligned_allocator<int>> source_b
);