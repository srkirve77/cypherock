#include "BTC_btc.h"
#include<iostream>
using namespace std;
void hex_string_to_byte_array(const char *hex_string, uint32_t string_length, uint8_t *byte_array)
{
	for(uint32_t i = 0 ; i < string_length ; i+=2 )
		{
			// string hex_value = "a";
			// hex_value[0] = hex_string[i];
			// hex_value += hex_string[i+1];
			// int temp = stoi(hex_value, 0, 16);
			
			// byte_array[i/2] = 1; 
			//cout<<temp<<" "<<byte_array[i/2]<<endl;
		}

}

void byte_array_to_unsigned_txn(uint8_t *btc_unsigned_txn_byte_array, unsigned_txn *unsigned_txn_ptr)
{
	// uint8_t network_version[4];
 //    uint8_t input_count[1];
 //    unsigned_txn_input *input;
 //    uint8_t output_count[1];
 //    txn_output *output;
 //    uint8_t locktime[4];
 //    uint8_t sighash[4];
	int i = 0;
	int j = 0;
	
	int size =  sizeof(unsigned_txn_ptr->network_version);
	//cout<<"size "<<size<<" "<<sizeof(unsigned_txn_ptr->network_version)<<" "<<sizeof(unsigned_txn_ptr->network_version[0])<<endl;
	
	unsigned_txn_ptr->network_version[j] = btc_unsigned_txn_byte_array[i++];
	
	size =  sizeof(unsigned_txn_ptr->input_count);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->input_count[j] = btc_unsigned_txn_byte_array[i++];
	
	unsigned_txn_ptr->input = new unsigned_txn_input();
	// uint8_t previous_txn_hash[32];
 	//    uint8_t previous_output_index[4];
 	//    uint8_t script_length[1];
 	//    uint8_t script_public_key[25];
 	//    uint8_t sequence[4];

	size =  sizeof(unsigned_txn_ptr->input->previous_txn_hash);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->input->previous_txn_hash[j] = btc_unsigned_txn_byte_array[i++];
	
	size =  sizeof(unsigned_txn_ptr->input->previous_output_index);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->input->previous_output_index[j] = btc_unsigned_txn_byte_array[i++];
	
	size =  sizeof(unsigned_txn_ptr->input->script_length);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->input->script_length[j] = btc_unsigned_txn_byte_array[i++];
	
	size =  sizeof(unsigned_txn_ptr->input->script_public_key);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->input->script_public_key[j] = btc_unsigned_txn_byte_array[i++];
	
	size =  sizeof(unsigned_txn_ptr->input->sequence);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->input->sequence[j] = btc_unsigned_txn_byte_array[i++];
	



	size =  sizeof(unsigned_txn_ptr->output_count);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->output_count[j] = btc_unsigned_txn_byte_array[i++];


	unsigned_txn_ptr->output = new txn_output();

	// 	typedef struct 
	// {
	//     uint8_t value[8];
	//     uint8_t script_length[1];
	//     uint8_t script_public_key[25];
	// }txn_output;

	size =  sizeof(unsigned_txn_ptr->output->value);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->output->value[j] = btc_unsigned_txn_byte_array[i++];

	size =  sizeof(unsigned_txn_ptr->output->script_length);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->output->script_length[j] = btc_unsigned_txn_byte_array[i++];

	size =  sizeof(unsigned_txn_ptr->output->script_public_key);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->output->script_public_key[j] = btc_unsigned_txn_byte_array[i++];

	size =  sizeof(unsigned_txn_ptr->locktime);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->locktime[j] = btc_unsigned_txn_byte_array[i++];

	size =  sizeof(unsigned_txn_ptr->sighash);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->sighash[j] = btc_unsigned_txn_byte_array[i++];

	//cout<<" value of i "<<i<<endl;
	
}