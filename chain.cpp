#include "chain.h"

#include <iostream>

namespace BlockChain
{
	Chain::Chain()
	{
		pblocks.push_back(std::move(create_genesis_block()));
	}

	void Chain::add_block(const std::string& data)
	{
		const Block& last_block = pblocks[get_last_index()];

		pblocks.push_back(Block{get_last_index()+1,data,last_block.get_hash()});

	}

	void Chain::print_block_chain() const
	{
		std::cout << "{\n";

		for(const auto& block : pblocks) {

			std::cout << "Index:" << block.get_index() << "\n";
			std::cout << "Previous Block Hash:" << block.get_previous_hash() << "\n";
			std::cout << "Current Block Hash:" << block.get_hash() << "\n";
			std::cout << "Data:" << block.get_data() << "\n";
			std::cout << ",\n";
		}

		std::cout << "}\n";
	}

	bool Chain::is_block_chain_valid() const
	{
		for(std::vector<Block>::size_type i=1;i<pblocks.size();i++) {

			const Block& last_block = pblocks[i-1];

			const Block& current_block = pblocks[i];

			const std::string current_block_hash = current_block.calculate_hash();

			if(current_block.get_hash()!=current_block_hash) {
				return false;
			}

			if(current_block.get_previous_hash()!=last_block.get_hash()) {
				return false;
			}
		}

		return true;
	}

	Block Chain::create_genesis_block()
	{
		return Block{0,"SunMaungOo's Genesis Block",""};
	}

	std::size_t Chain::get_last_index()
	{
		return pblocks.size()-1;
	}
}
