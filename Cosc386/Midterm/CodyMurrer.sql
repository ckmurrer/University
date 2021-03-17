/* 1 */
SELECT maker, speed 
FROM Product, Laptop 
WHERE Product.model = Laptop.model AND hd >= 30;
/* output
+-------+-------+
| maker | speed |
+-------+-------+
| A     |  2.00 |
| A     |  2.16 |
| A     |  2.00 |
| B     |  1.83 |
| E     |  2.00 |
| E     |  1.73 |
| E     |  1.80 |
| F     |  1.60 |
| F     |  1.60 |
| G     |  2.00 |
+-------+-------+
*/

/* 2 */
SELECT Product.model, price 
FROM Product, PC 
WHERE Product.model = PC.model AND maker = 'B' 
UNION 
SELECT Product.model, price 
FROM Product, Laptop 
WHERE Product.model = Laptop.model AND maker = 'B' 
UNION 
SELECT Product.model, price 
FROM Product, Printer 
WHERE Product.model = Printer.model AND maker = 'B';
/* output 
+-------+-------+
| model | price |
+-------+-------+
|  1004 |   649 |
|  1005 |   630 |
|  1006 |  1049 |
|  2007 |  1429 |
+-------+-------+
*/

/* 3 */
SELECT hd 
FROM PC 
GROUP BY hd 
having count(model)>=2;
/* output
+------+
| hd   |
+------+
|   80 |
|  160 |
|  250 |
+------+
*/

/* 4 */
SELECT I.model, J.model 
FROM PC I, PC J 
WHERE I.model > J.model AND I.ram = J.ram AND I.speed = J.speed;
/* output
+-------+-------+
| model | model |
+-------+-------+
|  1012 |  1004 |
+-------+-------+
*/

/* 5 */
SELECT maker
FROM Product
WHERE model IN
    (SELECT model
    FROM PC
    WHERE speed>=3.0)
    UNION
    (SELECT model
    FROM Laptop
    WHERE speed>=3.0);
/* output
+-------+
| maker |
+-------+
| B     |
| E     |
+-------+
*/