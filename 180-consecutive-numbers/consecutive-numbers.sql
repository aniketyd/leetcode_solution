SELECT DISTINCT num AS consecutiveNums
FROM (
    SELECT num,
           LEAD(num, 1) OVER (ORDER BY id) AS next1,
           LEAD(num, 2) OVER (ORDER BY id) AS next2
    FROM logs
) t
WHERE num = next1 AND num = next2;