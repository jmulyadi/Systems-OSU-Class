#Josh Mulyadi
def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True
def table_size(dataSize):
    dataSize = dataSize * 2
    while not is_prime(dataSize):
        dataSize += 1
    return  dataSize 
def hash_function(tableSize, key):
    return key % tableSize
def fill_table(data):
    size = table_size(len(data))
    hashTable = [[] for _ in range(size)] 
    for item in data:
        hashTable[hash_function(size, item)].append(item)
    return hashTable
def main():
    hashTable = fill_table([1,2,3, 23, 69, 234, 3243, 3252, 23, 1, 3])
    print(hashTable)
if __name__ == "__main__":
    main()