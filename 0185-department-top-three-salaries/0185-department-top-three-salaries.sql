# Write your MySQL query statement below
# return top three unique salaries

WITH helpertable AS (
    SELECT
        d.name AS Department,
        e.name AS Employee,
        e.salary AS Salary,
        DENSE_RANK() OVER (
            PARTITION BY d.id
            ORDER BY e.salary DESC
        ) AS rnk
    FROM Employee AS e
    JOIN Department AS d
        ON e.departmentId = d.id
)
SELECT Department, Employee, Salary
FROM helpertable
WHERE rnk <= 3;


