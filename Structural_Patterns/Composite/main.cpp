#include <iostream>
#include <vector>

using namespace std;

class LeafObj {
	public:
		virtual void Add(LeafObj l) {}
		virtual void Remove(LeafObj l) {}
};

class Leaf: public LeafObj {
	public:
		void Add(LeafObj l) {
			cout << "Hi! I'm a leaf!" << endl;
		}
		void Remove(LeafObj l) {
			cout << "This leaf has been plucked" << endl;
		}
};

class Bush: public LeafObj {
	vector<LeafObj> listLeaves;
	public:
		void AddLeaf(LeafObj l) {
			listLeaves.push_back(l);
		}
		void Add(LeafObj l) {
			cout << "This bush has been added!" << endl;
		}
		void Remove(LeafObj l) {
			cout << "This bush has been removed!" << endl;
		}
		
};

int main() {
	Leaf l1,l2;
	Bush b;
	
	b.AddLeaf(l1);
	b.AddLeaf(l2);

	l1.Add(l1);
	b.Add(b);

	l2.Remove(l2);
	b.Remove(l2);

	return 0;
}
