#Josh Mulyadi
import unittest
import chain_hash
import random

class TestChainHash(unittest.TestCase):
    #test1
    def test_fill_table(self):
        #test1
        data = [1, 2, 3, 23, 69, 234, 3243, 3252, 23, 1, 3]
        hashTable = chain_hash.fill_table(data)
        for item in data:
            index = chain_hash.hash_function(len(hashTable), item)
            self.assertIn(item, hashTable[index]) 
        print(hashTable)
        #test2
        data = [69, 32, 34, 1, -1, 32, -23423, 3214]
        hashTable = chain_hash.fill_table(data)
        for item in data:
            index = chain_hash.hash_function(len(hashTable), item)
            self.assertIn(item, hashTable[index]) 
        print(hashTable)
        #test3
        data = []
        for i in range(0, 105):
            data.append(random.randint(0, 3214))
        hashTable = chain_hash.fill_table(data)
        for item in data:
            index = chain_hash.hash_function(len(hashTable), item)
            self.assertIn(item, hashTable[index]) 
        print(hashTable)

if __name__ == "__main__":
    unittest.main()