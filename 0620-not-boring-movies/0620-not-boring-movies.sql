# Write your MySQL query statement below
# movies with an odd-numbered ID and a description that is not "boring".
# result table ordered by rating in descending order.
SELECT * FROM Cinema
WHERE id % 2 != 0 AND description NOT LIKE 'boring'
ORDER BY rating DESC;
