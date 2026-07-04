# Write your MySQL query statement below
#users who visited without making any transactions
#number of times they made these types of visits.
#LEFT JOIN
SELECT v.customer_id, COUNT(*) as count_no_trans
FROM Visits v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY v.customer_id;

