    public class Solution
    {
        public ListNode AddTwoNumbers (ListNode l1, ListNode l2)
        {
            int oc = 0;
            ListNode ans = new ListNode (0);
            ListNode cur = ans;
            while (l1 != null || l2 != null)
            {
                int n = oc;
                if (l1 != null)
                {
                    n += l1.val;
                    l1 = l1.next;
                }
                if (l2 != null)
                {
                    n += l2.val;
                    l2 = l2.next;
                }

                oc = n / 10;

                cur.val = n % 10;
                if (l1 != null || l2 != null || oc != 0)
                {
                    cur.next = new ListNode (oc);
                    cur = cur.next;
                }
            }

            return ans;
        }
    }