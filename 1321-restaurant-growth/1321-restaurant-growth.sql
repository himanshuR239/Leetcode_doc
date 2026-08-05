# Write your MySQL query statement below
WITH DailyTotal AS (
    SELECT
        visited_on, 
        SUM(amount) AS total_amount
        FROM Customer
        GROUP BY visited_on
)
SELECT
    a.visited_on,
    SUM(b.total_amount) AS amount,
    ROUND(AVG(b.total_amount), 2) AS average_amount
FROM DailyTotal a
JOIN DailyTotal b
    ON b.visited_on BETWEEN DATE_SUB(a.visited_on, INTERVAL 6 DAY) AND a.visited_on
GROUP BY a.visited_on
HAVING COUNT(b.visited_on) = 7
ORDER BY a.visited_on ASC;