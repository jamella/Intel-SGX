#include "Enclave2_u.h"

typedef struct ms_foo_t {
	char* ms_buf;
	size_t ms_len;
} ms_foo_t;

static const struct {
	size_t nr_ocall;
	void * func_addr[1];
} ocall_table_Enclave2 = {
	0,
	{ NULL },
};

sgx_status_t foo(sgx_enclave_id_t eid, char* buf, size_t len)
{
	sgx_status_t status;
	ms_foo_t ms;
	ms.ms_buf = buf;
	ms.ms_len = len;
	status = sgx_ecall(eid, 0, &ocall_table_Enclave2, &ms);
	return status;
}

