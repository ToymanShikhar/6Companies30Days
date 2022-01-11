class Solution {
   public:
    void linkdelete(struct Node* head, int M, int N) {
        Node* temp = new Node(0);
        Node* curr = temp;

        while (head != NULL) {
            for (int i = 1; i <= M and head != NULL; i++) {
                curr->next = head;
                curr = curr->next;
                head = head->next;
            }
            for (int i = 1; i <= N and head != NULL; i++) {
                head = head->next;
            }
        }

        curr->next = NULL;
        head = temp->next;
    }
};