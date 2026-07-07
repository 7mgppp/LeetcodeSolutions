# Write your MySQL query statement below
#the number of approved transactions and their total amount.
SELECT DATE_FORMAT(trans_date, '%Y-%m') AS month, country, count(*) as trans_count, count(CASE WHEN STATE = 'approved' THEN 1 END) as approved_count, SUM(amount) as trans_total_amount, SUM(CASE WHEN STATE = 'approved' THEN amount ELSE 0 END) as approved_total_amount 
FROM Transactions
GROUP BY country, DATE_FORMAT(trans_date, '%Y-%m')