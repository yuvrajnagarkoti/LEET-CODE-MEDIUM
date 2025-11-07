-- Write your MySQL query statement below
SELECT t1.user_id, 
    ROUND(IFNULL(AVG(action = 'confirmed'), 0), 2) AS confirmation_rate
FROM Signups AS t1
LEFT JOIN Confirmations AS t2
    ON t1.user_id = t2.user_id
GROUP BY t1.user_id;