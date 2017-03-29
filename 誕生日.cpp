#include <iostream>
#include <string>
#include <vector>
//�ݖ�Q�ŉ񓚂��������̒a�����𐼗��W���ɕ��ׂ��l(��F20160215)��6�悵�A����ꂽ���̊e���𑫂����킹���l�����߂�B

int dight(int value) {
	int digit = 0;
	while (value != 0) {
		value /= 10;
		digit++;
	}
	return digit;
}
//����Ȍ����̊|���Z�i�z��g�p�j
void mult(const int& birthday, std::vector<int>& value) {
	
	std::vector<int> result;
	
	for (int i = 0; i < value.size(); i++) {
		result.push_back(0);
	}
	
	
	for (int i = 0; i != value.size(); i++) {
		int buf = value[i] * birthday;
		int dig = dight(buf);
		int buf_dig = dig;
		int carry = 0;
		for (int k = 0; k < dig; k++) {
			if((i + k) >= result.size()) {
				result.push_back(0);
				if (carry != 0)
					dig++;
			}
			result[i + k] += (buf % 10) + carry;
			carry = result[i + k] / 10;
			if(carry != 0)
				result[i + k] = result[i + k] % 10;
			buf /= 10;
			if (k + 1 == dig) {
				if (carry != 0)
					dig++;
			}
		}
		if (buf_dig != dig) {
			if (result.back() == 0) {
				result.pop_back();
			}
		}
	}
	value = result;
}

void square(const int& birthday, std::vector<int>& value) {
	int num = birthday;
	while (num > 0) {
		value.push_back(num % 10);
		num /= 10;
	}
	for (int i = 0; i < 5; i++) {
		mult(birthday, value);
	}
}


////�z��ł̑����Z�̏ꍇ
//void sub(std::vector<int>& value) {
//	std::vector<int> result;
//	int carry = 0;
//	result.push_back(0);
//	for (int i = 0; i != value.size(); i++) {
//
//		 result[0] += value[i];
//		 carry = result[0] / 10;
//		 if (carry != 0)
//			 result[0] = result[0] % 10;
//		 int increment = 1;
//		 while (carry != 0) {
//			 if (increment >= result.size()) 
//				 result.push_back(0);
//			 result[increment] += carry;
//			 carry = result[increment] / 10;
//			 if (carry != 0)
//				 result[increment] = result[increment] % 10;
//			 increment++;
//		 }
//	}
//	value = result;
//}

int  sub(std::vector<int>& value) {
	int buf = 0;
	for (int i = 0; i != value.size(); i++) {
		buf += value[i];
	}
	return buf;
}


void main() {
	int birthday = 19960810;
	std::vector<int> value;

	square(birthday, value);
	for (int i = value.size() - 1; i >= 0; i--) {
		std::cout << value[i];
	}
	std::cout << std::endl;
	//sub(value);
	std::cout << sub(value) << std::endl;
	
}