#ifndef __BANK_COMMON_H__
#define __BANK_COMMON_H__

const int NAME_LENGTH = 20;

namespace BANK_REQUEST {
	enum {
		MAKE = 1,
		DEPOSIT,
		WITHDRAW,
		INQUIRE,
		EXIT
	};
}

namespace CREDIT_RATE {
	enum {
		RATE_A = 1,
		RATE_B = 2,
		RATE_C = 3
	};
}

#endif