# Write your MySQL query statement below
#find the names of all the salespersons who did not have any orders related to the company with the name "RED".
#HINT : query who sold to company 'RED' first, then output the sales person who is not in the first query result.

SELECT name FROM salesperson
WHERE sales_id NOT IN (SELECT sales_id from orders
WHERE com_id = (SELECT com_id FROM company
WHERE name = 'red'))

