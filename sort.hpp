#ifndef _ANTINUX_HEPHAESTUS_SORT_H_
#define _ANTINUX_HEPHAESTUS_SORT_H_
#include "Apollo/loop.hpp"
namespace Antinux{
	namespace Hephaestus{
		template <class T>
		class sorter{
		private:
			T* base;
			unsigned int num_of_element;
		public:
			void load(T* base,unsigned int num_of_element);
		public:
			void sort_up(void);
			void sort_down(void);
		public:
			template<class Z>
			void sort_up_by(Z* base,unsigned int num_of_element);
			template<class Z>
			void sort_down_by(Z* base,unsigned int num_of_element);
		public:
			T* dump();
		};
	}
}


#include "sort.inl"
#endif
