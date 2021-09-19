SELECT
    salary * months as earings,
    COUNT(*)
FROM
    Employee
GROUP BY earings
ORDER BY earings DESC
LIMIT 1
