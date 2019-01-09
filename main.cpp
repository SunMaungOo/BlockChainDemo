#include <string>
#include <iostream>
#include "chain.h"

int main()
{

	BlockChain::Chain chain;

	chain.add_block("hello");
	chain.add_block("world");

	chain.print_block_chain();

	if (chain.is_block_chain_valid()) {

		std::cout << "Chain Status:Valid\n";

	} else {

		std::cout << "Chain Status:Invalid!\n";

	}

	std::cin.get();

	return 0;
}







