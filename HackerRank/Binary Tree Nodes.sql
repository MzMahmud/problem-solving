SELECT
    DISTINCT l.N,
    CASE
        WHEN l.P IS NULL THEN 'Root'
        WHEN r.N IS NULL THEN 'Leaf'
        ELSE 'Inner'
    END
FROM 
    BST l LEFT JOIN BST r ON l.N = r.P
ORDER BY
    l.N ASC;