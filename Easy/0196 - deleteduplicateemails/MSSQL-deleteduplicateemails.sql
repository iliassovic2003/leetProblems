DELETE alias1 FROM Person alias1
INNER JOIN Person alias2
ON alias2.id < alias1.id
AND alias2.email = alias1.email