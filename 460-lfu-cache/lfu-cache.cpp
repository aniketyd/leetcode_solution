class MyHeap
{
public:
    struct Item
    {
        int freq;
        int key;
        int value;
        size_t time;
    };

    MyHeap(int capacity) : m_data(capacity), m_pos(0) {}

    void myswap(int a, int b)
    {
        if( a >=0 && a < m_pos && b >= 0 && b < m_pos)
        {
            swap(m_data[a], m_data[b]);
            m_index[m_data[a].key] = a;
            m_index[m_data[b].key] = b;
        }
    }

    void put(int key, int value)
    {
        if(m_index.count(key) == 0)
        {
            if (m_pos >= m_data.size())
            {
                int k = m_data[0].key;
                m_index.erase(k);
                m_data[0] = m_data[m_pos - 1];
                m_pos --;
                heapifyDown(0);                
            }

            m_data[m_pos] = {1, key, value, m_time++};
            m_index[key] = m_pos;
            m_pos++;
            heapifyUp(m_pos - 1);
        }

        else
        {
            int pos = m_index[key];
            m_data[pos].value = value;
            m_data[pos].freq++;
            m_data[pos].time = m_time++;

            heapifyDown(pos);
        }
    }

    int heapifyUp(int pos)
    {
        while(pos > 0 && pos < m_pos)
        {
            int p = (pos - 1 )/ 2;
            if(compare(pos, p))
            {
                myswap(p, pos);
                pos = p;
            }
            else
            {
                break;
            }
        }
        return pos;
    }

    int heapifyDown(int pos)
    {
        while(pos >= 0 && pos < m_pos)
        {
            int c1 = (pos * 2) + 1;
            int c2 = (pos * 2) + 2;
            int smallest = pos;

            if(c1 < m_pos && compare(c1, smallest))
            {
                smallest = c1;    
            }

            if(c2 < m_pos && compare (c2, smallest))
            {
                smallest = c2;    
            }

            if(pos != smallest)
            {
                myswap(pos, smallest);
                pos = smallest;
            }
            else
            {
                break;
            }
        }

        return pos;
    }

    int get(int key)
    {
        if(m_index.count(key) == 0)
            return -1;
        else
        {
            int pos = m_index[key];
            m_data[pos].freq++;
            m_data[pos].time = m_time ++;
            pos = heapifyDown(pos);
            return m_data[pos].value;
        }
    }

    bool compare(int a, int b)
    {
        const Item &ia = m_data[a];
        const Item &ib = m_data[b];
        return ia.freq < ib.freq || (ia.freq == ib.freq && ia.time < ib.time);
    }

    std::vector<Item> m_data;
    std::map<int, int> m_index;
    int m_pos = 0;
    size_t m_time = 0;
};

class LFUCache {
public:
    LFUCache(int capacity) : m_heap(capacity) {
       
    }
    
    int get(int key) {
        return m_heap.get(key);   
    }
    
    void put(int key, int value) 
    {
        return m_heap.put(key, value);
    }

    MyHeap m_heap;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */