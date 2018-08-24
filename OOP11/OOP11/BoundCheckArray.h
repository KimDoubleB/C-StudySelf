#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__

template <class T>
class BoundCheckArray {
private:
	T * kBank;
	int arrLen;
public:
	BoundCheckArray(int len = 100) : arrLen(len) {
		kBank = new T[arrLen];
	}

	T& operator[](int idx) {
		if (idx < 0 || idx >= arrLen)
		{
			cout << "Index error ! " << endl;
			exit(1);
		}
		return kBank[idx];
	}
	T operator[](int idx) const {
		if (idx < 0 || idx >= arrLen)
		{
			cout << "Index error ! " << endl;
			exit(1);
		}
		return kBank[idx];
	}

	int getArrLen() { return arrLen; }
	~BoundCheckArray() { delete[] kBank; }
};
#endif