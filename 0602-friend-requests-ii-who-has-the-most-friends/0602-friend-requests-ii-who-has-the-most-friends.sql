# Write your MySQL query statement below
-- temperory table
WITH temp AS (
    SELECT requester_id AS id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id AS id FROM RequestAccepted 
)

SELECT
    id,
    COUNT(*) AS num
FROM temp
GROUP BY id
ORDER BY num DESC
LIMIT 1;