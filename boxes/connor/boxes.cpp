#include <iostream>
#include <vector>
#include <unordered_set>

struct Node
{
    int id;
    std::vector<Node*> contents;
    Node(int id) {this->id = id; };
};

int contents_plus_this(Node* this_node, std::vector<bool>& boxes_seen)
{
    if (!boxes_seen[this_node->id])
    {
        boxes_seen[this_node->id] = true;
        int count = 0;
        for (Node* content : this_node->contents)
        {
            count += contents_plus_this(content, boxes_seen);
        }
        return 1 + count;
    }
    return 0;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Node*> boxes;
    for (int i= 0; i < N; i++)
    {
        boxes.push_back(new Node(i));
    }


   // std::vector<Node*> parents;
    for (int box_i = 0; box_i < N; box_i++)
    {
        int contains_this_box;
        std::cin >> contains_this_box;
        if (contains_this_box==0)
        {
            // nothing contains box_i
            continue;
        }
        boxes[contains_this_box-1]->contents.push_back(boxes[box_i]);
    }

    int Q;
    std::cin >> Q;
    int q_i;
    for (int q = 0 ; q < Q; q++)
    {
        std::cin >> q_i;
        std::unordered_set<int> boxes_to_investigate;
        std::vector<bool> seen(N, false);
        for (int x = 0 ; x < q_i ; x++)
        {
            int v;
            std::cin >> v;
            boxes_to_investigate.insert(v-1);
        }
        int count = 0;
        for (int box_i : boxes_to_investigate)
        {
            count += contents_plus_this(boxes[box_i], seen);
        }
        std::cout << count << std::endl;
    }
    return 0;
}
