#include "BTC_btc.h"

void hex_string_to_byte_array(const char *hex_string, uint32_t string_length, uint8_t *byte_array)
{
	for(uint32_t i = 0 ; i < string_length ; i+=2 )
		{
			char* hex_value = (char*)malloc(3*sizeof(char));
			hex_value[0] = hex_string[i];
			hex_value[1]= hex_string[i+1];
			hex_value[2] = '\0';
			byte_array[i/2] = (int)strtol(hex_value, NULL, 16);
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
	for(j=0;j<size;j++)
		unsigned_txn_ptr->network_version[j] = btc_unsigned_txn_byte_array[i++];
	

	size =  sizeof(unsigned_txn_ptr->input_count);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->input_count[j] = btc_unsigned_txn_byte_array[i++];
	
	
	unsigned_txn_ptr->input = (unsigned_txn_input*)malloc(sizeof(unsigned_txn_input));
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


	unsigned_txn_ptr->output[0] = (txn_output*)malloc(sizeof(txn_output));

	// 	typedef struct 
	// {
	//     uint8_t value[8];
	//     uint8_t script_length[1];
	//     uint8_t script_public_key[25];
	// }txn_output;

	size =  sizeof(unsigned_txn_ptr->output[0]->value);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->output[0]->value[j] = btc_unsigned_txn_byte_array[i++];

	size =  sizeof(unsigned_txn_ptr->output[0]->script_length);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->output[0]->script_length[j] = btc_unsigned_txn_byte_array[i++];

	size =  sizeof(unsigned_txn_ptr->output[0]->script_public_key);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->output[0]->script_public_key[j] = btc_unsigned_txn_byte_array[i++];

	unsigned_txn_ptr->output[1] = (txn_output*)malloc(sizeof(txn_output));

	size =  sizeof(unsigned_txn_ptr->output[1]->value);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->output[1]->value[j] = btc_unsigned_txn_byte_array[i++];

	size =  sizeof(unsigned_txn_ptr->output[1]->script_length);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->output[1]->script_length[j] = btc_unsigned_txn_byte_array[i++];

	size =  sizeof(unsigned_txn_ptr->output[1]->script_public_key);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->output[1]->script_public_key[j] = btc_unsigned_txn_byte_array[i++];
	

	size =  sizeof(unsigned_txn_ptr->locktime);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->locktime[j] = btc_unsigned_txn_byte_array[i++];

	size =  sizeof(unsigned_txn_ptr->sighash);
	for(j=0;j<size;j++)
		unsigned_txn_ptr->sighash[j] = btc_unsigned_txn_byte_array[i++];
}