#ifndef BLOCK_H_
#define BLOCK_H_

#include <string>

namespace BlockChain
{
	class Block
	{
	public:

		Block(std::size_t index,const std::string& data,const std::string& previous_hash);

		const std::size_t get_index() const;

		const std::string& get_data() const;

		const std::string& get_hash() const;

		const std::string& get_previous_hash() const;

		const std::string calculate_hash() const;

	private:

		std::size_t pindex;

		std::string pdata;

		std::string pprevious_hash;

		std::string pcurrent_hash;
	};

}

#endif /* BLOCK_H_ */
