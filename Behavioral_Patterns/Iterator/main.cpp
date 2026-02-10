#include <iostream>
#include <vector>
#include <string>
#include <any>

class Iterator {
	virtual void first() =0;
	virtual void end() =0;
	virtual void next() =0;
	virtual bool done() =0;
	virtual void* get() =0;
};

template <typename T, typename U>
class ConcreteIterator : public Iterator {
	public:
		typedef typename std::vector<T>::iterator iter;
		
		ConcreteIterator(U *data_i, bool a = false) : data_ptr(data_i) {
			it = (data_ptr->data).begin();
		}
		void first() override {
			it = (data_ptr->data).begin();
		}
		void end() override {
			it = (data_ptr->data).end();
		}
		void next() override {
			it++;
		}
		bool done() override {
			return (it == (data_ptr->data).end());
		}
		void* get() override {
			return &it;
		}
		/*iter_t* get() {
			return &it;
		}*/
	private:
		U *data_ptr;
		iter it;
};

template <class T>
class ConcreteAggregator {
	friend class ConcreteIterator<T,ConcreteAggregator>;
	private:
		std::vector<T> data;
	public:
		void addData(T val) {
			data.push_back(val);
		}
		ConcreteIterator<T,ConcreteAggregator> *createIterator() {
			return new ConcreteIterator<T,ConcreteAggregator>(this);
		}
};

int main() {
	ConcreteAggregator<int> ca;

	for (int i = 0; i < 10; i++) {
		ca.addData(i);
	}

	ConcreteIterator<int,ConcreteAggregator<int>> *ci = ca.createIterator();

	for (ci->first(); !ci->done(); ci->next()) {
		std::cout << **(int **)(ci->get()) << std::endl;
	}

	return 0;
}
