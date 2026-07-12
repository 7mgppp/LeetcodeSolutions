# Write your MySQL query statement below
SELECT u.name, SUM(t.amount) AS balance FROM users AS u
JOIN  Transactions AS t
ON u.account = t.account
GROUP BY name
HAVING sum(amount) > 10000