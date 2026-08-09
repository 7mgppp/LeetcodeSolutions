# Write your MySQL query statement below
WITH helperTable AS(
    SELECT 
    d.name AS Department, 
    e.name AS Employee, 
    e.salary AS Salary, 
    DENSE_RANK() OVER (PARTITION BY d.id 
    ORDER BY e.salary DESC) 
    AS rnk 
    FROM employee AS e 
    JOIN department AS d
    ON e.departmentId = d.id
)

SELECT Department, Employee, Salary FROM helperTable 
WHERE rnk = 1
