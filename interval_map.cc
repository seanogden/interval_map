#include "interval_map.h"

interval_map :: interval_map()
    : slice_map()
{

}

interval_map :: ~interval_map()
{

}

void
interval_map :: insert(unsigned int insert_address, unsigned int insert_length)
{
    //case 1: wholely contained within a larger block
    //case 2: overlaps right of another block
    //case 3: overlaps left of another block
    //case 4: new block at end, no overlap
    //case 5: exactly same size as existing block
    //case 6: larger than a whole block (combo of 2, 3 and 5)

    slice_iter_t it = slice_map.lower_bound(insert_address);
    unsigned int block_start;
    
    if(slice_map.size() == 0)
    {
        /* If inserting into empty map at > 0 offset, fill the hole with
           empty block */
        if (insert_address > 0)
        {
            slice empty_slice;
            empty_slice.length = insert_address;
            slice_map.insert(std::make_pair(0, empty_slice));
        }
        
        //case 4
    }

    else if (it == slice_map.end())
    {
        --it;
        unsigned int offset = it->first;
        unsigned int length = it->second.length;

        if (offset + length < insert_address)
        {
            slice empty_slice;
            empty_slice.length = insert_address - offset + length;
            slice_map.insert(std::make_pair(offset + length, empty_slice));
            //case 4
        }

        else if (offset + length == insert_address) 
        {
            //case 4
        }

        else
        {
            //case 2
        }
            
    }

    else
    {
        if (it->first != insert_address)
        {
            --it;
        }

        unsigned int offset = it->first;
        unsigned int length = it->second.length;
    }


}

//case 1: wholely contained within a larger block
void
interval_map :: insert_contained(
    unsigned int block_start_address,
    unsigned int block_length,
    unsigned int insert_address,
    unsigned int insert_length)
{
  block_location slice_location = slice_map[block_start_address].location;

  unsigned int new_length = insert_address - block_start_address;
  slice_map[block_start_address].length = new_length;

  unsigned int new_block_start = block_start_address + new_length + insert_length;
  unsigned int new_block_length = block_length - new_length - insert_length;

  slice new_slice;
  new_slice.location = slice_location;
  new_slice.offset = new_length + insert_length;
  new_slice.length = new_block_length;

  slice_map.insert(
      std::pair<unsigned int, slice>(new_block_start, new_slice));
}

//case 2: overlaps right of another block
void
interval_map :: insert_right(
    unsigned int block_start_address,
    unsigned int insert_address)
{
  unsigned int new_length = insert_address - block_start_address;
  slice_map[block_start_address].length = new_length;
};

//case 3: overlaps left of another block
void
interval_map :: insert_left(
    unsigned int block_start_address,
    unsigned int block_length,
    unsigned int insert_address,
    unsigned int insert_length)
{
  unsigned int new_offset = insert_address + insert_length - block_start_address;
  unsigned int new_length = block_length - new_offset;
  slice_map[block_start_address].offset = new_offset;
  slice_map[block_start_address].length = new_length;
}

//case 5: exactly same size as existing block
void
interval_map :: insert_overwrite_interval(
    unsigned int block_start_address)
{
  //delete mapping of block_start_address
  slice_map.erase(block_start_address);
}

//insert the new interval into slice map
void
interval_map :: insert_interval(
    unsigned int insert_address,
    unsigned int insert_length,
    block_location insert_location)
{
  slice new_slice;
  new_slice.location = insert_location;
  new_slice.offset =  0;
  new_slice.length = insert_length;

  slice_map.insert(std::pair<unsigned int, slice>(insert_address, new_slice));
}

