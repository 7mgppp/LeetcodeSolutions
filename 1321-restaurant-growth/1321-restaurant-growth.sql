# Write your MySQL query statement below
#Compute the moving average of how much the customer paid in a seven days window
#Return the result table ordered by visited_on in ascending order.

SELECT
A.visited_on,
SUM(B.daily_amount) AS amount,
ROUND(SUM(B.daily_amount) / 7, 2) AS average_amount
FROM
(SELECT visited_on, SUM(amount) AS daily_amount
FROM Customer
GROUP BY visited_on) A
JOIN
(SELECT visited_on, SUM(amount) AS daily_amount
FROM Customer
GROUP BY visited_on) B
ON B.visited_on BETWEEN DATE_SUB(A.visited_on, INTERVAL 6 DAY) AND A.visited_on
GROUP BY A.visited_on
HAVING COUNT(*) = 7
ORDER BY A.visited_on;