# Write your MySQL query statement below
SELECT score, DENSE_RANK() OVER(ORDER BY Score DESC) AS `RANK`
FROM Scores