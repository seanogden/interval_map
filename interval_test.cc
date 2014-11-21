#include "interval_map.h"
#include <iostream>

interval_map imap;
block_location location1;
block_location location2;
block_location location3;

int case0()
{
  imap.insert(0, 10, location1);
  std::vector<slice> slices = imap.get_slices(0,10);

  std::cout << "size : " << slices.size();

  for (int i = 0; i < slices.size(); ++i)
  {
    slice s = slices[i];
    std::cout << " location : " << s.location.sid ;
    std::cout << " / length : " << s.length;
    std::cout << " / offset : " << s.offset << std::endl ;
  }
}

int case1()
{
  /*
  imap.insert slice 0-10
  imap.insert slice 3-7
  imap.insert slice 5-6
  get slice 0-10 : should get 5 slices
  */
  imap.insert(0, 10, location1);
  imap.insert(3, 4, location2);
  imap.insert(5, 1, location3);
  std::vector<slice> slices = imap.get_slices(0, 10);
  std::cout << "size : " << slices.size()<<'\n';

  for (int i = 0; i < slices.size(); ++i)
  {
    slice s = slices[i];
    std::cout << "location : " << s.location.sid ;
    std::cout << " / length : " << s.length;
    std::cout << " / offset : " << s.offset << '\n' ;
  }
}

int case11()
{
  /*
  imap.insert slice 0-10
  imap.insert slice 0-6
  imap.insert slice 0-3
  get slice 0-10 : should get 3 slices
  */
  imap.insert(0, 10, location1);
  imap.insert(0, 6, location2);
  imap.insert(0, 3, location3);
  std::vector<slice> slices = imap.get_slices(0, 10);
  std::cout << "size : " << slices.size()<<'\n';

  for (int i = 0; i < slices.size(); ++i)
  {
    slice s = slices[i];
    std::cout << "location : " << s.location.sid ;
    std::cout << " / length : " << s.length;
    std::cout << " / offset : " << s.offset << '\n' ;
  }
}

int case111()
{
  /*
  imap.insert slice 0-10
  imap.insert slice 4-10
  imap.insert slice 7-10
  get slice 0-10 : should get 3 slices
  */
  imap.insert(0, 10, location1);
  imap.insert(4, 6, location2);
  imap.insert(7, 3, location3);
  std::vector<slice> slices = imap.get_slices(0, 10);
  std::cout << "size : " << slices.size()<<'\n';

  for (int i = 0; i < slices.size(); ++i)
  {
    slice s = slices[i];
    std::cout << "location : " << s.location.sid ;
    std::cout << " / length : " << s.length;
    std::cout << " / offset : " << s.offset << '\n' ;
  }
}

int case1111()
{
  /*
  imap.insert slice 0-10
  imap.insert slice 4-10
  imap.insert slice 4-6
  get slice 0-10 : should get 3 slices
  */
  imap.insert(0, 10, location1);
  imap.insert(4, 6, location2);
  imap.insert(4, 2, location3);
  std::vector<slice> slices = imap.get_slices(0, 10);
  std::cout << "size : " << slices.size()<<'\n';

  std::vector<slice>::iterator it;

  for (int i = 0; i < slices.size(); ++i)
  {
    slice s = slices[i];
    std::cout << "location : " << s.location.sid ;
    std::cout << " / length : " << s.length;
    std::cout << " / offset : " << s.offset << '\n' ;
  }
}

int case2()
{

  /*
  imap.insert slice 0-10
  imap.insert slice 10-20
  imap.insert slice 5-15
  get slice 0-20 : should get 5 slices
  */
  imap.insert(0, 10, location1);
  imap.insert(10, 20, location2);
  imap.insert(5, 10, location3);
  std::vector<slice> slices = imap.get_slices(0, 20);
  std::cout << "size : " << slices.size()<<'\n';

  std::vector<slice>::iterator it;

  for (int i = 0; i < slices.size(); ++i)
  {
    slice s = slices[i];
    std::cout << "location : " << s.location.sid ;
    std::cout << " / length : " << s.length;
    std::cout << " / offset : " << s.offset << '\n' ;
  }
}

int case235()
{

  /*
  imap.insert slice 0-10
  imap.insert slice 10-20
  imap.insert slice 20-30
  imap.insert slice 5-25
  get slice 0-20 : should get 3 slices
  */
  imap.insert(0, 10, location1);
  imap.insert(10, 20, location2);
  imap.insert(20, 30, location3);
  imap.insert(5, 25, location4);
  std::vector<slice> slices = imap.get_slices(0, 30);
  std::cout << "size : " << slices.size()<<'\n';

  std::vector<slice>::iterator it;

  for (int i = 0; i < slices.size(); ++i)
  {
    slice s = slices[i];
    std::cout << "location : " << s.location.sid ;
    std::cout << " / length : " << s.length;
    std::cout << " / offset : " << s.offset << '\n' ;
  }
}

int main()
{
  location1.sid = 1100;
  location1.bid = 1100;
  location2.sid = 1200;
  location2.bid = 1200;
  location3.sid = 1300;
  location3.bid = 1300;

  case2();
}

