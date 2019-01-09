#ifndef CHAIN_H_
#define CHAIN_H_

#include <vector>

#include "block.h"


namespace BlockChain
{
	class Chain
	{
	public:

		Chain();

		void add_block(const std::string& data);

		void print_block_chain() const;

		bool is_block_chain_valid() const;

	private:

		std::vector<Block> pblocks;

	private:

		Block create_genesis_block();

		std::size_t get_last_index();

	};
}

#endif /* CHAIN_H_ */
