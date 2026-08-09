# Write your MySQL query statement below
WITH helperTable AS (
    SELECT
        product_id,
        new_price,
        ROW_NUMBER() OVER (
            PARTITION BY product_id
            ORDER BY change_date DESC
        ) AS rnk
    FROM Products
    WHERE change_date <= '2019-08-16'
)

SELECT
    p.product_id,
    COALESCE(h.new_price, 10) AS price
FROM (
    SELECT DISTINCT product_id
    FROM Products
) AS p
LEFT JOIN helperTable AS h
    ON p.product_id = h.product_id
    AND h.rnk = 1;