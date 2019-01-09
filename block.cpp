#include "block.h"
#include "picosha2.h"

namespace BlockChain
{

	Block::Block(std::size_t index,const std::string& data,const std::string& previous_hash):
	pindex{index},
	pdata{data},
	pprevious_hash{previous_hash}
	{
		pcurrent_hash = std::move(calculate_hash());
	}

	const std::size_t Block::get_index() const
	{
		return pindex;
	}

	const std::string& Block::get_data() const
	{
		return pdata;
	}

	const std::string& Block::get_hash() const
	{
		return pcurrent_hash;
	}

	const std::string& Block::get_previous_hash() const
	{
		return pprevious_hash;
	}

	const std::string Block::calculate_hash() const
	{
		std::string str = std::to_string(pindex)+get_data()+get_previous_hash();

		std::vector<unsigned char> hash(picosha2::k_digest_size);

		picosha2::hash256(str.begin(), str.end(), hash.begin(), hash.end());

		return picosha2::bytes_to_hex_string(hash.begin(), hash.end());
	}

}


