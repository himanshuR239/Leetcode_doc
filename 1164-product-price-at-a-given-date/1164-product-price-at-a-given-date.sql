# Write your MySQL query statement below
SELECT 
    product_id,
    new_price AS price
FROM Products
WHERE (product_id, change_date) IN (
    SELECT
        product_id,
        MAX(change_date)
        FROM Products
        WHERE change_date <= '2019-08-16'
        GROUP BY product_id
)

-- If we don't want to remove duplicates OR we know there are no duplicates so it is faster than UNION
UNION ALL

SELECT 
    product_id,
    10 AS price
FROM Products
GROUP BY Product_id
HAVING MIN(change_date) > '2019-08-16';