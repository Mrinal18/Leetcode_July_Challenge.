"""
You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

You need to return the least number of units of times that the CPU will take to finish all the given tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 

Constraints:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

"""


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        """#lets assume i have a task like this A:3 B:2 C:1
        #then here i will schedule it as : ABCABA
        #here if we notice the ideal time if n = 2 -> 
        #A _ _ A _ _ A -> then fill the blank
        #A B C A B _ _ A -> here we have jsut one ideal 
        
        #now notice that the number of ideal slots = A - 1 -> 3 - 1 -> 2
        #here we need to remember one formula: idle_state = (fmax - 1) * n
        #This idle_state can be reduced because we dont have to keep the CPU ideal, we can schedule different tasks.
        #this is a greedy approch. 
        
        #Now, to compute this, first have a list with all the freq of 26 alphabets 
        
        freq = [0] * 26
        
        #now fill all the freq with number of tasks
        for i in tasks: 
            freq[ord(i) - ord('A')] += 1
            
        #so this will give. me a list like [3, 3, 0,0....]
        
        #now sort list in decreasing order.
        freq.sort()
        
        
        #i will calculate the idle_state using Fmax/
        fmax = freq.pop()
        idle_state = (fmax - 1) * n 
        print(idle_state)
        
        
        #now calc for other tasks as well kmpwing that idle_state > 0:
        #and reduce the idle_state at each step. 
        
        while freq and idle_state > 0:
            idle_state -= min(fmax - 1, freq.pop())
            
            
        idle_state = max(0, idle_state)
        
        #now i will return the total tasks as number of busy tasks and the number of idle tasks
        return len(tasks) + idle_state
        """
        
        """
        this is another way to do this using jsut maths
        """
        
        #make an array of 26 elementw 
        freq = [0] * 26
        
        for i in tasks:
            freq[ord(i) - ord('A')] += 1
            
        max_freq = max(freq)
        #count the most freqeunt tasks 
        
        n_max = freq.count(max_freq)
        
        return max(len(tasks), (max_freq - 1) * (n+1) + n_max)
        

