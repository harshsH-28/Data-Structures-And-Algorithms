#include <string>
using namespace std;

template <typename T>
class MapNode
{
public:
    string key;
    T value;
    MapNode<T> *next;

    MapNode(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename T>
class Hashmap
{
    MapNode<T> **Bucket;
    int bucketSize;
    int count;

    int getHashedIndex(string key)
    {
        int hashCode = 0;
        int currCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currCoeff;
            hashCode = hashCode % bucketSize;
            currCoeff *= 41;
            currCoeff = currCoeff % bucketSize;
        }
        return hashCode % bucketSize;
    }

    void rehash()
    {
        MapNode<T> **Temp = Bucket;
        int oldBucketSize = bucketSize;
        count = 0;
        bucketSize *= 2;
        Bucket = new MapNode<T> *[bucketSize];
        for (int i = 0; i < bucketSize; i++)
        {
            Bucket[i] = NULL;
        }
        for (int i = 0; i < oldBucketSize; i++)
        {
            MapNode<T> *temp = Temp[i];
            while (temp != NULL)
            {
                string key = temp->key;
                T value = temp->value;
                insert(key, value);
                temp = temp->next;
            }
        }
        for (int i = 0; i < oldBucketSize; i++)
        {
            MapNode<T> *temp = Temp[i];
            delete temp;
        }
        delete[] Temp;
    }

public:
    Hashmap()
    {
        count = 0;
        bucketSize = 5;
        Bucket = new MapNode<T> *[bucketSize];
        for (int i = 0; i < bucketSize; i++)
        {
            Bucket[i] = NULL;
        }
    }

    ~Hashmap()
    {
        for (int i = 0; i < bucketSize; i++)
        {
            delete Bucket[i];
        }
        delete[] Bucket;
    }

    int size()
    {
        return count;
    }

    T getValue(string key)
    {
        int index = getHashedIndex(key);
        MapNode<T> *head = Bucket[index];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    void insert(string key, T value)
    {
        int index = getHashedIndex(key);
        MapNode<T> *head = Bucket[index];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = Bucket[index];
        MapNode<T> *newNode = new MapNode<T>(key, value);
        newNode->next = head;
        Bucket[index] = newNode;
        count++;
        double loadFactor = (1.0 * count) / bucketSize;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    T remove(string key)
    {
        int index = getHashedIndex(key);
        MapNode<T> *head = Bucket[index];
        MapNode<T> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    Bucket[index] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                T ans = head->value;
                head->next = NULL;
                count--;
                delete head;
                return ans;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};