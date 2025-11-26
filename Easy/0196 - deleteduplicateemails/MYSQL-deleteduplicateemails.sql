--Creating Two References To The Same Table.
--A Reference To The Data We Want To Keep While The Other To Remove
--Self Join O(n²), VERY VERY BAD on large databases

DELETE alias1 FROM Person alias1
INNER JOIN Person alias2
WHERE alias2.id < alias1.id
AND alias2.email = alias1.email

--Creating Temporary Table
--Group By Hashing o(log(n)) - o(n)

DELETE FROM Person
WHERE id NOT IN (
    SELECT * FROM (
        SELECT MIN(id)
        FROM Person
        GROUP BY email
    ) AS tempTable
);