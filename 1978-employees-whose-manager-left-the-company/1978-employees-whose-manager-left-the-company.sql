# Write your MySQL query statement below
#Find the IDs of the employees whose salary is strictly less than $30000

#When a manager leaves the company, their information is deleted from the Employees table, but the reports still have their manager_id set to the manager that left.

SELECT employee_id
FROM Employees
WHERE salary < 30000 AND manager_id IS NOT NULL
AND manager_id NOT IN (
SELECT employee_id
FROM Employees
)
ORDER BY employee_id;