-- ***********************
-- Name: Abdullah Al Mahfuz
-- ID: 180377236
-- Date: 31 May 2024 (Friday)
-- Purpose: Lab 03 DBS211
-- ***********************
SET AUTOCOMMIT ON;
-- Q1 SOLUTION --
// Creating the movies table
CREATE TABLE L5_MOVIES (
    m_id int PRIMARY KEY,
    title varchar(35) NOT NULL,
    release_year int NOT NULL,
    director int NOT NULL,
    score decimal(3,2) CHECK (score < 5 and score > 0)
    );
 
// Creating the actors table
CREATE TABLE L5_ACTORS (
    a_id int PRIMARY KEY,
    first_name varchar(20) NOT NULL,
    last_name varchar(30) NOT NULL
    );
    
// Creating the castings table
CREATE TABLE L5_CASTINGS (
    movie_id int,
    actor_id int,
    PRIMARY KEY (movie_id, actor_id)
    );
    
// Adding foreign key to the existing table
ALTER TABLE L5_CASTINGS
    ADD CONSTRAINT movie_id_fk
    FOREIGN KEY (movie_id) 
    REFERENCES L5_MOVIES(m_id);
    
ALTER TABLE L5_CASTINGS
    ADD CONSTRAINT actor_id_fk
    FOREIGN KEY (actor_id) 
    REFERENCES L5_ACTORS(a_id);
    
// Creating the directors table
CREATE TABLE L5_DIRECTORS (
    director_id int PRIMARY KEY,
    first_name varchar(20) NOT NULL,
    last_name varchar(30) NOT NULL
    );
    
-- Q2 Solution --
// Modify the L5_MOVIES table to create a foreign key constraint that refers to table L5_DIRECTORS
ALTER TABLE L5_MOVIES
    ADD CONSTRAINT director_fk
    FOREIGN KEY (director) 
    REFERENCES L5_DIRECTORS(director_id);
    
-- Q3 Solution --
// Modify the L5_MOVIES table to create a new constraint so the uniqueness of the movie title is guaranteed. 
ALTER TABLE L5_MOVIES
    ADD CONSTRAINT unq_movie_title
    UNIQUE (title);

-- Q4 Solution --
// Insert information into the L5_DIRECTORS TABLE
// I had to use this command becaue the example command was giving me errors! 
// Eve though the syntax was correct, it kept sayign syntax error
INSERT ALL
INTO L5_DIRECTORS VALUES (1010, 'Rob', 'Minkoff')
INTO L5_DIRECTORS VALUES (1020, 'Bill', 'Condon')
INTO L5_DIRECTORS VALUES (1050, 'Josh', 'Cooley')
INTO L5_DIRECTORS VALUES (2010, 'Brad', 'Bird')
INTO L5_DIRECTORS VALUES (3020, 'Lake', 'Bell')
SELECT * FROM dual;

-- Q5 Solution --
// Insert information into the L5_MOVIES TABLE
INSERT ALL
INTO L5_MOVIES VALUES (100, 'The Lion King', 2019, 3020, 3.50)
INTO L5_MOVIES VALUES (200, 'Beauty and the Beast', 2017, 1050, 4.20)
INTO L5_MOVIES VALUES (300, 'Toy Story 4', 2019, 1020, 4.50)
INTO L5_MOVIES VALUES (400, 'Mission Impossible', 2018, 2010, 5.00) // violates constraint condition ( 0 < score < 5)
INTO L5_MOVIES VALUES (500, 'The Secret Life of Pets', 2016, 1010, 3.90)
SELECT * FROM dual;

-- Q6 Solution -- 
// Delete all tables i just created

// must drop the foreign key constraint in L5_MOVIES
ALTER TABLE L5_MOVIES
    DROP CONSTRAINT DIRECTOR_FK;
    
// DROP the tables in correct order, the child table must be dropped first to prevent orphan tables
DROP TABLE L5_ACTORS;
DROP TABLE L5_MOVIES;  // child table(because it inherited the primary key of L5_DIRECTORS table ("director_id")
DROP TABLE L5_CASTINGS;
DROP TABLE L5_DIRECTORS; // parent table (because its primary key is in reference to L5_MOVIES table

// The order of the table while removing them is important for this one because
// there are foreign key constraints between the tables. The L5_MOVIES table has
// director constraint from L5_DIRECTORS. So i must remove the child table (L5_MOVIES)
// table first to prevent Orphan tables. In order to avoid referential integrity violation
// I must drop the child tables first and the parent table at last. Thats why the order of the 
// the drop sequence is important.
        

