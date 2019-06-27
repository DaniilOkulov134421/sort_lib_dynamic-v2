#include "sort.h"

template<class Type>
using Vector = std::vector<Type>;
using String = std::string;

/****RECURSIVE****/

void internal_qsort_recursive(
	String::iterator left_idx,
	String::iterator right_idx) {

	if(std::distance(left_idx, right_idx) < 1) return;

	auto
		start_idx = left_idx,
		end_idx = right_idx,
		base_idx = left_idx + std::distance(left_idx, right_idx) / 2;

	while(left_idx < right_idx) {
		while(*left_idx < *base_idx && left_idx < base_idx) left_idx++;
		while(*right_idx >= *base_idx && right_idx > base_idx) right_idx--;

		if(left_idx < right_idx) std::iter_swap(left_idx, right_idx);
		if(left_idx == base_idx) base_idx = right_idx;
		else if(right_idx == base_idx) base_idx = left_idx;
	}
	
	if(base_idx > start_idx)
		internal_qsort_recursive(start_idx, base_idx);
	if(base_idx < end_idx)
		internal_qsort_recursive(base_idx + 1, end_idx);
}

void qsort_recursive(std::string& raw)
{
	if (raw.size() > 0)
		internal_qsort_recursive(raw.begin(), raw.end() - 1);
}
