/*
Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

 

Example 1:



Input: hour = 12, minutes = 30
Output: 165
Example 2:



Input: hour = 3, minutes = 30
Output: 75
Example 3:



Input: hour = 3, minutes = 15
Output: 7.5
Example 4:

Input: hour = 4, minutes = 50
Output: 155
Example 5:

Input: hour = 12, minutes = 0
Output: 0
*/

class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        """
        The minute hand moves by minute_deg_per_min = 360° / 60 = 6° per minute.
    The hour hand moves by hour_deg_per_hour = 360° / 12 = 30° per hour.
    The hour hand has an additional movement of hour_deg_per_min = hour_deg_per_hour / 60 = 30° / 60 = 0.5° per minute.

    Therefore we get the following movements:

    hour_hand_deg = hour * hour_deg_per_hour + minutes * hour_deg_per_min = hour * 30 + minutes * 0.5
    minute_hand_deg = minutes * minute_deg_per_min = minutes * 6
    We need the absolute difference between those two:

    diff_deg = |hour_hand_deg - minute_hand_deg| = |hour * 30 + minutes * 0.5 - minutes * 6| = |hour * 30 - minutes * 5.5|
    As we can easily see when looking at a clock there are two different angles between the hands:
    The minimum angle on one side is between 0° and 180°.
    The maximum angle on the other side is between 180° and 360°.
    We need the minimum angle. If our formular returned a number above 180° we got the maximum angle.
    We can calculate the minimum angle by subtracting the maximum angle from 360°.

    Time and space complexity: O(1)

class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        diff = abs(30 * hour - 5.5 * minutes)
        return diff if diff <= 180 else 360 - diff
        """
        
        
        diff = abs( hour * 30 - minutes *5.5)
        return diff if diff <= 180 else 360-diff
