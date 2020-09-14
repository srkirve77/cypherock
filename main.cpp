#include "BTC_btc.h"
#include "iostream"
using namespace std;
int main()
{
	unsigned_txn obj;
	const char *hex_string = "0200000001748dccb662fd73e8f0d8435132b8528dd3739f55388a15795c7e7afe4f555f9f010000001976a9140ce400ffe51ab038f6134beeb14ef56c683ce00088acfdffffff02204e0000000000001976a914d46d05e6ac27683aa5d63a6efc44969798acf13688ac28b30000000000001976a914dacc24d8b195ce046a40caedd5e2e649beee4e3388ac49211a0001000000";
	uint32_t  i = 0;
	while(hex_string[i]!='\0')
		i++;
	uint8_t a = 1;
	cout<<" a "<<a<<endl;
	uint8_t *byte_array = new uint8_t[i+1];
	hex_string_to_byte_array(hex_string,i,byte_array);

	cout<<byte_array[0]<<endl;

	unsigned_txn *unsigned_txn_ptr = new unsigned_txn();


	byte_array_to_unsigned_txn(byte_array, unsigned_txn_ptr);

 	cout<<unsigned_txn_ptr->network_version<<endl;
	// cout<<unsigned_txn_ptr->input_count<<endl;
	// cout<<unsigned_txn_ptr->input->previous_txn_hash<<endl;
	// cout<<unsigned_txn_ptr->locktime<<endl;
	// cout<<unsigned_txn_ptr->sighash<<endl;
}