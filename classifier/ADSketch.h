#ifndef _ADSKETCH_H
#define _ADSKETCH_H

#include <sstream>
#include <algorithm>
#include <iostream>
#include "murmur3.h"


using namespace std;

class ADSketch
{

private:
	unsigned int HASH_NUM;
	unsigned int LENGTH;
	double interval_;

	unsigned int* counter;
	double* arrive;
public:
	ADSketch(double interval, unsigned int _HASH_NUM =4, unsigned int _LENGTH =6401):
		interval_(interval), HASH_NUM(_HASH_NUM), LENGTH(_LENGTH){
		counter = new unsigned int [LENGTH];
		arrive = new double [LENGTH];
		memset(counter, 0, sizeof(unsigned int)*LENGTH);
		for(int i=0; i<LENGTH; i++)
			arrive[i] = -1;
	}

	~ADSketch(){
		clear();
	}

	bool init(unsigned int flow_id, double now)
	{
		bool ret = false;
		for(unsigned int i=0; i<HASH_NUM; i++){
			unsigned int position = Hash(flow_id, 0, seed)%LENGTH;
			if(now - arrive[position] > interval_){
				counter[position] = 0;
				ret = true;
			}

			counter[position] += 1460;
			arrive[position] = now;
		}

		return ret;
	}

	void clear()
	{
		delete [] counter;
		delete [] arrive;
	}
	
	int query(unsigned int flow_id)
	{
		unsigned int ret = 0x7fffffff;
		for(unsigned int i=0; i<HASH_NUM; i++){
			unsigned int position = Hash(flow_id,0,seed_)%LENGTH;
			ret = min(ret, counter[position]);
		}
		return ret;

	}

	static unsigned int Hash(unsigned int x, unsigned int y, uint32_t seed){
		unsigned int arr[] = {x, y};
		return HashString((char *)arr, 8, seed);
	}

	static unsigned int HashString(const char *bytes, int length, uint32_t seed){
		unsigned int result;
		int i;
		result =0;

		MurmurHash3_x86_32(bytes, length, seed, &result);	//result in 32bit hash value

		return result;
	}
};



#endif		//_ADSKETCH_H
	
