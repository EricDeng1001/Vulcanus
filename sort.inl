#include <stdlib.h>
namespace Antinux{
	namespace Hephaestus{
		template<class T>
		int cmp_up(const void* a,const void* b)
		{
			return *((T*)a) == *(T*)b ? 0 : *((T*)a) > *(T*)b ? 1 : -1;
		}
		
		template<class T>
		int cmp_down(const void* a,const void* b)
		{
			return *((T*)a) == *(T*)b ? 0 : *((T*)a) > *(T*)b ? -1 : 1;
		}
		
		template <class T>
		void sorter<T>::load(T* base,unsigned int num_of_element)
		{
			this->base = base;
			this->num_of_element = num_of_element;
		}
		
		template <class T>
		void sorter<T>::sort_up()
		{
			qsort(this->base,this->num_of_element,sizeof(T),cmp_up<T>);
		}
		
		template <class T>
		void sorter<T>::sort_down()
		{
			qsort(this->base,this->num_of_element,sizeof(T),cmp_down<T>);
		}
		
		template <class T>
		class cmp_pair{
		public:
			T pivot;
			unsigned int order;
			bool operator == (cmp_pair<T> that){
				return this->pivot == that.pivot;
			}
			bool operator > (cmp_pair<T> that){
				return this->pivot > that.pivot;
			}
		};
		
		
		template <class T> template <class Z>
		void sorter<T>::sort_up_by(Z* base,unsigned int num_of_element)
		{
			if(num_of_element != this->num_of_element){
				throw("cant assign an array which's length isn't eq to the base to be perference");
			}
			else{
				cmp_pair<Z>* P = new cmp_pair<Z>[num_of_element];
				loop(num_of_element){
					P[i].pivot = base[i];
					P[i].order = i;
				}
				qsort(P,this->num_of_element,sizeof(cmp_pair<Z>),cmp_up<cmp_pair<Z>>);
				T* tmp = new T[num_of_element];
				loop(num_of_element){
					tmp[i] = this->base[P[i].order];
				}
				loop(num_of_element){
					this->base[i] = tmp[i];
				}
				delete [] tmp;
				delete [] P;
			}
		}
		
		template <class T> template <class Z>
		void sorter<T>::sort_down_by(Z* base,unsigned int num_of_element)
		{
			if(num_of_element != this->num_of_element){
				throw("cant assign an array which's length isn't eq to the base to be perference");
			}
			else{
				cmp_pair<Z>* P = new cmp_pair<Z>[num_of_element];
				loop(num_of_element){
					P[i].pivot = base[i];
					P[i].order = i;
				}
				qsort(P,this->num_of_element,sizeof(cmp_pair<Z>),cmp_down<cmp_pair<Z>>);
				T* tmp = new T[num_of_element];
				loop(num_of_element){
					tmp[i] = this->base[P[i].order];
				}
				loop(num_of_element){
					this->base[i] = tmp[i];
				}
				delete [] tmp;
				delete [] P;
			}
		}
		template <class T>
		T* sorter<T>::dump()
		{
			return this->base;
		}

	}
}